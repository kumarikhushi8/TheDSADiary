/*
Problem: Baseball Game
LeetCode: 682
Approach: Stack Simulation
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int sum=0;
        for(auto i=0;i<operations.size();i++){
                if(operations[i]=="C"){
                    st.pop();
                }else if(operations[i]=="D"){
                    st.push(st.top()*2);
                }else if(operations[i]=="+"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.push(a);
                    st.push(a+b);
                }else{
                    st.push(stoi(operations[i]));
                }
        }
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
