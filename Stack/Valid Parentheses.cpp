/*
Problem: Valid Parentheses
LeetCode: 20
Approach: Stack
Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && ((st.top()=='{' && s[i]=='}') || (st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']'))){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
