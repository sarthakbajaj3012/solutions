#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator new_end = nums.begin() + nums.size();
        for(int i  = 0; i < std::distance( nums.begin(), new_end ); i++){
            new_end = remove(nums.begin() + i + 1 ,new_end,nums.at(i));
        }
        return std::distance( nums.begin(), new_end );
    }
};

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    int ans;

    Solution sol =  Solution();
    ans = sol.removeDuplicates(num);
    cout << ans;

    return 0;
}