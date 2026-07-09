/*
Problem: Backspace String Compare
LeetCode: 844
Approach: Stack
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>stackS;
        stack<char>stackT;
        for(int i=0;i<s.size();i++){
if(s[i]=='#'){
    if(!stackS.empty())
    stackS.pop();
}else{
    stackS.push(s[i]);
}
        }
        for(int i=0;i<t.size();i++){
if(t[i]=='#'){
    if(!stackT.empty())
    stackT.pop();
}else{
    stackT.push(t[i]);
}
        }
        string new_S="";
        string new_T="";
        while(!stackS.empty()){
            new_S+=stackS.top();
            stackS.pop();
        }
        while(!stackT.empty()){
            new_T+=stackT.top();
            stackT.pop();
        }
        return new_S==new_T;
    }
};
