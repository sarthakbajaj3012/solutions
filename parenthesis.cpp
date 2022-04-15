#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i< s.size(); i++){
            if(s.at(i) == '{' || s.at(i) == '(' || s.at(i) == '[') {
                stk.push(s.at(i));
            }
            else{
                if(stk.empty()) return false;
                if(s.at(i) == '}'  && stk.top() != '{') return false;
                if(s.at(i) == ')'  && stk.top() != '(') return false;
                if(s.at(i) == ']'  && stk.top() != '[') return false;
                stk.pop();
            }
            
        }
        return stk.empty();
    }
};

int main(){
    string s;
    cin  >> s;

    Solution sd;
    bool ans = sd.isValid(s);
    cout << ans;
    return 0;
}