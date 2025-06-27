#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int n; cin >> n;
	
	vector<long long> res;

	for(int i = 0; i < n; ++i){
		int y, x; cin >> y >> x;
		
		// Determine which layer we are currently at
		// Layer start with 1 located at (1.1)
		int layer = max(y, x);
		long long value;
		// break into even and odd case
		if(layer % 2 == 0){
			// even layer
			/* If x == layer, we are on the side of the layer
			 * we attempt to walk from the ending point of previous layer y steps
			 *
			 * If y == layer, we are at the bottom of the layer
			 * the easiest way is to walk from current layer's max L^2
			 */
			if(x == layer){
				value = ((long long)(layer -1)*(layer-1)) + y;
			}else{
				value = (((long long)layer * layer)) - x + 1 ;
			}
		}else{
			// odd layer
			/* If x == layer, we are on the side of the layer
			 * we attempt to walk down from the current layer's maximum L^2
			 *
			 * If y == layer, we are at the bottom of the layer
			 * the easiest way is to walk from the end of previous layer x distance
			 */
			if(x == layer){
				value = (((long long)layer * layer)) - y + 1 ;
			}else{
				value = ((long long)(layer -1)*(layer-1)) + x;
			}
		}

		res.push_back(value);
	}

	for(auto i : res){
		cout << i << '\n';
	}
	
	return 0;
}


