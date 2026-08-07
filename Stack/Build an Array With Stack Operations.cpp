/*
Problem: Build an Array With Stack Operations
LeetCode: 1441

Approach:
- Simulate reading numbers from 1 to n.
- Always Push.
- Pop immediately if the current number is not needed.
- Stop after building the target array.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int i=0;
        int stream=1;
        while(i<target.size() && i<=n){
            ans.push_back("Push");
            if(stream==target[i]){
                i++;
            }else{
                ans.push_back("Pop");
            }
            stream++;
        }
        return ans;
    }
};
