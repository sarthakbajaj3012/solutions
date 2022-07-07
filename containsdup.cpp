#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int , int > tab;
        for(int i = 0; i < nums.size(); i++){
            if(tab.find(nums.at(i)) != tab.end()) return true;
            else tab[nums.at(i)] = nums.at(i);
        }
        return false;
    }
    
};


int main(){

    vector<int> hello;
    hello.push_back(1);
    hello.push_back(2);
    hello.push_back(3);
    hello.push_back(4);
    Solution he = Solution();
    bool ans = he.containsDuplicate(hello);
    cout << ans;
    return 0;
}