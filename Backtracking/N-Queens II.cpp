/*
Problem: N-Queens II
LeetCode: 52
Approach: Backtracking with row and diagonal hashing
Time Complexity: O(N!)
Space Complexity: O(N²)

Note:
This is my initial accepted solution. It stores each valid board before counting.
A later optimized version can count solutions directly without constructing boards.
*/


class Solution {
public:
vector<string> convert(vector<vector<char>>&temp){
int n=temp.size();
vector<string>ans;
for(int i=0;i<n;i++){
    string str="";
    for(int j=0;j<n;j++){
        str+=temp[i][j];
    }
    ans.push_back(str);
}
return ans;
}
void backtrack(int col, vector<int>&rowFlag, vector<int>&upperDiagonal, vector<int>&lowerDiagonal ,int n,vector<vector<string>>&res, int& count, vector<vector<char>>&temp){
    if(col==n){
        count++;
        vector<string>arr=convert(temp);
        res.push_back(arr);
        return;
    }
    for(int row=0;row<n;row++){
        if(rowFlag[row]==0
        && upperDiagonal[row+col]==0
        && lowerDiagonal[n-1+col-row]==0){
            temp[row][col]='Q';
            rowFlag[row]=1;
            upperDiagonal[row+col]=1;
            lowerDiagonal[n-1+col-row]=1;
        backtrack(col+1,rowFlag,upperDiagonal,lowerDiagonal,n,res,count,temp);
        temp[row][col]='.';
        rowFlag[row]=0;
        upperDiagonal[row+col]=0;
        lowerDiagonal[n-1+col-row]=0;
        }
    }
}
    int totalNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int count=0;
        vector<vector<string>>res;
        //calculate position of upper and lower diagonal
        vector<int>rowFlag(n,0);
        vector<int>upperDiagonal(2*n,0);
        vector<int>lowerDiagonal(2*n,0);
        backtrack(0,rowFlag,upperDiagonal,lowerDiagonal,n,res,count,board);
        return count;
    }
};
