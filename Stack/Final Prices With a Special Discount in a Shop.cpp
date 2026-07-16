/*
Problem: Final Prices With a Special Discount in a Shop
LeetCode: 1475
Approach: Monotonic Increasing Stack
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>ans=prices;
        for(int i=0;i<prices.size();i++){
            while(!st.empty() && prices[st.top()]>=prices[i]){
                ans[st.top()]-=prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
