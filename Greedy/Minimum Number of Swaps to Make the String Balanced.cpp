/*
Problem: Minimum Number of Swaps to Make the String Balanced
LeetCode: 1963

Approach:
- Count unmatched opening brackets.
- Match every closing bracket whenever possible.
- Minimum swaps = (unmatchedOpen + 1) / 2.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minSwaps(string s) {
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                open++;
            }else if(open>0){
                open--;
            }
        }
        int ans=(open+1)/2;
        return ans;
    }
};
