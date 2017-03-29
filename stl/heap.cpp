#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
int main(){
    int myints[] = {10,20,30,5,15};
    std::vector<int> v(myints,myints+5);
    std::make_heap (v.begin(),v.end());
    std::cout << "initial max heap   : " << v.front() << '\n';
    cout << "after make heap" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    std::pop_heap (v.begin(),v.end());
     cout << "after pop heap" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    v.pop_back();
    cout << "after vector pop back" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    v.push_back(99); 
    cout << "after vector push back" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    std::push_heap (v.begin(),v.end());
    cout << "after push heap" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}