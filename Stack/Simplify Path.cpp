/*
Problem: Simplify Path
LeetCode: 71

Approach:
- Split the path using '/'.
- Ignore empty strings and ".".
- Pop the last directory for "..".
- Push valid directory names.
- Reconstruct the canonical path.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string simplifyPath(string path) {
        //tokenize string based on delimator /
        // home , user , Documents , .. , Pictures
        //... , a , .. , b , c , .. , d , . 
        // if empty or dot (.) -> do nothing 
        //push in stack , if (..) pop
        stringstream ss(path);
        string token="";
        stack<string>st;
        while(getline(ss,token,'/')){
            if(token=="" || token==".") continue;
            if(token!=".."){
                st.push(token);
            }else if(!st.empty()){
                st.pop();
            }
        }
        if(st.empty()) return "/";
        string ans="";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
