#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
int main(){
	vector<int> v = {1,1,0,0};
	sort(v.begin(), v.end());
	do{
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}while( next_permutation(v.begin(), v.end()) );
	return 0;
}
