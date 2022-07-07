#include <iostream>
#include <vector>
using namespace std;



 int helper(vector<int> temp , int sum, int n) {
    if(n == - 1){
        return sum;
    }

    return max(helper(temp,sum + temp.at(n),n - 1), helper(temp,sum,n-1));
}
int maxSubArray(vector<int>& nums) {
        
    return helper(nums,0,nums.size() -1);
}

int main() {
    vector<int> hi;
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        hi.push_back(temp);
    }

    cout << maxSubArray(hi);

    return 0;


}