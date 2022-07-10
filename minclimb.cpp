#include <iostream>
#include <vector>
using namespace std;

int min(int a , int b){
    if( a > b) return b;
    else a;
}

int helper(vector<int> cost, int index, int total_cost){
       
        if(index == cost.size() - 1 || index == cost.size() - 2){
            return total_cost;
        }
        else {
            return min(helper(cost,index + 1,total_cost + cost.at(index + 1)),helper(cost, index + 2, total_cost + cost.at(index + 2)));
        }
}

int minCostClimbingStairs(vector<int> cost) {
    
    return min(helper(cost,0,cost.at(0)), helper(cost, 1,cost.at(1)));
}

    

int main(){
    vector<int> hi;
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        hi.push_back(temp);
    }

    cout << minCostClimbingStairs(hi);

    return 0;

}