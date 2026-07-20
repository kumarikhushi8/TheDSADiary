/*
Problem: Daily Temperatures
LeetCode: 739
Approach: Monotonic Decreasing Stack
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
stack<int>st;
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
