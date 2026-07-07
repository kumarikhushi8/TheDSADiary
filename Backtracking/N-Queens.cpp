/*
Problem: N-Queens
LeetCode: 51
Approach: Backtracking with Row and Diagonal Hashing
Time Complexity: O(N!)
Space Complexity: O(N²)
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
void backtrack(int col, vector<int>&rowFlag, vector<int>&upperDiagonal, vector<int>&lowerDiagonal ,int n,vector<vector<string>>&res, vector<vector<char>>&temp){
    if(col==n){
        vector<string> arr=convert(temp);
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
        backtrack(col+1,rowFlag,upperDiagonal,lowerDiagonal,n,res,temp);
        temp[row][col]='.';
        rowFlag[row]=0;
        upperDiagonal[row+col]=0;
        lowerDiagonal[n-1+col-row]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>temp;
        if(n==1){
            temp.push_back("Q");
            res.push_back(temp);
            return res;
        }
        if(n<=3 && n>1){
            return res;
        }
        vector<vector<char>>board(n,vector<char>(n,'.'));
        //calculate position of upper and lower diagonal
        vector<int>rowFlag(n,0);
        vector<int>upperDiagonal(2*n,0);
        vector<int>lowerDiagonal(2*n,0);
        backtrack(0,rowFlag,upperDiagonal,lowerDiagonal,n,res,board);
        return res;
    }
};
