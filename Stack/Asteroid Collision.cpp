/*
Problem: Asteroid Collision
LeetCode: 735
Approach: Stack Simulation
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int i=0;
        while(i<asteroids.size()){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
                i++;
            }else{
                while(!st.empty()&&st.top()<abs(asteroids[i])&&st.top()>0){
                    st.pop();
                }
                if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
                else if(st.top()==abs(asteroids[i])){
                    st.pop();
                }
                i++;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
