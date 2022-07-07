#include <iostream>
#include <vector> 
using namespace std;
 
vector<int> twoSum(vector<int>& nums, int target) {
   vector<int> array;
    for(int i  = 0;  i < nums.size(); i++) {
        for(int j =  i ;  j < nums.size(); j++) {
            if( i == j ) continue;
            if(nums.at(i) + nums.at(j) == target ) {
                array.push_back(i);
                array.push_back(j);
                return array;
            }
        }
    }
    return array;   
}

int main () {

    return 0;
}