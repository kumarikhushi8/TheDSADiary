/*
Problem: Minimum Add to Make Parentheses Valid
LeetCode: 921
Approach: Greedy
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int countOpen=0;
        int countClose=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                countOpen++;
            }else if(s[i]==')'){
                if(countOpen>0) countOpen--;
                else countClose++;
            }
        }
        return countOpen+countClose;
    }
};
