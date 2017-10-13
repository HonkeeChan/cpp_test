#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
void swap(vector<int>& nums, int pos1, int pos2);
void myPermute(vector<vector<int>> &ans, vector<int>& nums, int startPos);
bool findDuplicate(vector<int> &nums, int pos1, int pos2);


int main(){
    vector<int> vi = {1, 1, 2};
    vector<vector<int> > vvi;
    myPermute(vvi, vi, 0);

    for(int i = 0; i < vvi.size(); ++i){
        copy(vvi[i].begin(), vvi[i].end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
}


void myPermute(vector<vector<int>> &ans, vector<int>& nums, int startPos) {  
        if (startPos == nums.size()-1) {  
            ans.push_back(nums);  
        }  
        else {  
            for (int i = startPos; i < nums.size(); ++i) {  
                if (!findDuplicate(nums, startPos, i)) {  
                    swap(nums, startPos, i);  
                    myPermute(ans, nums, startPos+1);  
                    swap(nums, startPos, i);  
                }  
            }  
        }  
    }  
 bool findDuplicate(vector<int> &nums, int pos1, int pos2) {  
        for (; pos1 < pos2; ++pos1) {  
            if (nums[pos1] == nums[pos2]) {  
                return true;  
            }  
        }  
        return false;  
    }  
void swap(vector<int>& nums, int pos1, int pos2) {  
        int tmp = nums[pos2];  
        nums[pos2] = nums[pos1];  
        nums[pos1] = tmp;  
    }  