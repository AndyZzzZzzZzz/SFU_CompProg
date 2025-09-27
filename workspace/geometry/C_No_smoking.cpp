
/**
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Class to handle points in the plane.
 * 	T can be e.g. double or long long. (Avoid int.)
 * Status: Works fine, used a lot
 */
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <assert.h>
#include <iterator>

using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};


const double EPS = 1E-9;

typedef long long ll;
double sweep_x;

struct seg {
    Point<ll> p, q;
    int id; // keep track of unique segments

    /*
        Linear interpolation:
        y = y_1 + \frac{(y_2 - y_1)}{(x_2 - x_1)} \cdot (x - x_1)

        estimates a value y between two known data points given an x value
    */
    double get_y(double x ) const {
        // If vertical line, just return y value 
        if(abs(p.x - q.x) < EPS) return p.y;
        return p.y + (q.y - p.y) * (x - p.x)/(q.x - p.x);
    }

    bool operator<(const seg& other) const {
        double y1 = get_y(sweep_x), y2 = other.get_y(sweep_x);
        if (abs(y1 - y2) > EPS) return y1 < y2;
        return id < other.id;
    }
};

struct event {
    double x;       // The x-coordinate of the event (where the sweep line is)
    int type;       // Type of event: 0 = insert/start, 1 = delete/end
    int id;         // Segment ID (to refer back to the original segment)

    event(){}
    event(double x, int type, int id): x(x), type(type), id(id) {}

    // Events are ordered by their x values in priority queue
    bool operator<(const event& e) const {
        if(abs(x - e.x) > EPS) // Check if they are different points
            return x < e.x;
        return type < e.type;
    }

};

// checks if target x and y value is within range of segments
bool on_segments(ll x1, ll y1, ll x2, ll y2, ll targ_x, ll targ_y){
    return min(x1, x2) <= targ_x && targ_x <= max(x1, x2) && targ_y >= min(y1, y2) && targ_y <= max(y1, y2);
}

// cross product
ll cross(ll x1, ll y1, ll x2, ll y2){
    return (x1 * y2) - (x2 * y1);
}

bool intersect(const seg& a, const seg& b){
    ll x1 = a.p.x, y1 = a.p.y;
    ll x2 = a.q.x, y2 = a.q.y;
    ll x3 = b.p.x, y3 = b.p.y;
    ll x4 = b.q.x, y4 = b.q.y;
     ll sideA = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
        ll sideB = cross(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
        ll sideC = cross(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
        ll sideD = cross(x4 - x3, y4 - y3, x2 - x3, y2 - y3);

        if ((sideA > 0 && sideB < 0 || sideA < 0 && sideB > 0) &&
            (sideC > 0 && sideD < 0 || sideC < 0 && sideD > 0)) {
            return true;
        }

        // Colinear or endpoint touch cases
        if (sideA == 0 && on_segments(x1, y1, x2, y2, x3, y3)) { return true; }
        else if (sideB == 0 && on_segments(x1, y1, x2, y2, x4, y4)) { return true;}
        else if (sideC == 0 && on_segments(x3, y3, x4, y4, x1, y1)) { return true;}
        else if (sideD == 0 && on_segments(x3, y3, x4, y4, x2, y2)) { return true; }
        return false;
}

// set holding segments when sweeping
set<seg> segments;


int main(){

    int n; cin >> n;
    vector<seg> original_segments(n);
    // vector of pointers and points to positions of segment in the set
    vector<set<seg>::iterator> where(n);

    // events: start and end of a line segments
    vector<event> e;


    // read in all segments
    for(int i = 0; i < n; ++i){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point<ll> p1(x1,y1), p2(x2, y2);
        seg s; s.p = p1; s.q = p2; s.id = i;
        original_segments[i] = s;

        // append events
        // start of the event is marked by lowest x value
        e.push_back(event(min(s.p.x, s.q.x), 0, i));
        // end of the event of marked by highest x value
        e.push_back(event(max(s.p.x, s.q.x), 1, i));
    }
    //if(!intersect(original_segments[0], original_segments[1])){
        //cout << "NOT SAME" <<'\n';
    //}

    // sort the events by x values
    sort(e.begin(), e.end());
    //cout << "EVENTS: " << '\n';
    //for(auto m : e){
    //    cout  << "X: " << m.x << " TYPE: " << m.type << " SEG: " << m.id <<'\n';
    //}

    int count = 0;
    // process events
    for(int i = 0; i < e.size(); ++i){
        int id = e[i].id;
        sweep_x = e[i].x;

        if(e[i].type == 0){

            //cout << "Successful Initialize" << endl;
            if(segments.empty()) {
            //cout << "empty" << endl;
                segments.insert(original_segments[id]);
                continue;
            }
            // check if the segment we are inserting will intersect with its neighbor

            //cout << "not empty" << endl;
            auto nxt = segments.lower_bound(original_segments[id]);
            auto prv = prev(nxt); 
            if(nxt != segments.end() && intersect(*nxt, original_segments[id])){
                cout << "YES" <<'\n';
                cout << id+1 << ' ' << (*nxt).id+1 << '\n';
                return 0;
            }
            if(prv != segments.end() && intersect(*prv, original_segments[id])){
                cout << "YES" <<'\n';
                //for(auto k : (segments)){
                //    cout << k.id << " - "; 
                //}
                //cout <<'\n';
                cout << id+1 << ' ' << (*prv).id+1 << '\n';
                return 0;
            }
            // Track the position of where we inserted this segments
            segments.insert(original_segments[id]);
        }else{
            
            
            //cout << "SIZE: " << segments.size() << '\n';

            auto where1 = segments.lower_bound(original_segments[id]);
            
            if(where1 == prev(segments.end()) || where1 == segments.begin()){
                //cout << "REMOVING" << '\n';
                segments.erase(where1);
                continue;
            }

            //cout << "remove" << endl;
            set<seg>::iterator nxt = next(where1);
            set<seg>::iterator prv = prev(where1);
            
            //cout << "try intersect" << endl;
            if(intersect(*nxt, *prv)){
                cout << "YES" <<'\n';
                cout << (*prv).id+1 << ' ' << (*nxt).id+1 << '\n';
                return 0;
            }
            // remove this segment in set
            segments.erase(where1);
        }
    }
    cout << "NO" << '\n';
    return 0;
}