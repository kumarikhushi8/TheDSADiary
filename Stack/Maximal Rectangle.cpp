/*
Problem: Maximal Rectangle
LeetCode: 85
Approach:
1. Convert each row into a histogram.
2. Apply Largest Rectangle in Histogram using a monotonic stack.
Time Complexity: O(rows × cols)
Space Complexity: O(cols)
*/

class Solution {
public:
int findLargestArea(vector<int>&compressCol){
    stack<int>st;
    int ans=0;
    for(int i=0;i<=compressCol.size();i++){
        while(!st.empty() &&(i==compressCol.size() || compressCol[st.top()]>compressCol[i])){
            int height=compressCol[st.top()];
            st.pop();
            int width;
            if(st.empty()){
                width=i;
            }else{
                width=i-st.top()-1;
            }
            ans=max(ans,height*width);
        }
        st.push(i);
    }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>compressCol(col,0);
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    compressCol[j]++;
                }else{
                    compressCol[j]=0;
                }
            }
            int area=findLargestArea(compressCol);
            ans=max(area,ans);
        }
        return ans;
    }
};
