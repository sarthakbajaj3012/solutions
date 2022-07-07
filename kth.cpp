#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.begin() + nums.size() );
    return nums.at(nums.size() - k);

}
int main(){

    vector<int> hello;
    hello.push_back(3);
    hello.push_back(2);
    hello.push_back(1);
    hello.push_back(5);
    hello.push_back(6);
    hello.push_back(4);
    int h = findKthLargest(hello,2);
    cout << h;
    return 0;
}