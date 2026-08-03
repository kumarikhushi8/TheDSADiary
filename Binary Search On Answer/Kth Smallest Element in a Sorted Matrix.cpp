/*
Problem: Kth Smallest Element in a Sorted Matrix
LeetCode: 378
Approach:
- Binary Search on Answer
- Count elements <= mid using bottom-left traversal.
Time Complexity: O(n log(maxValue - minValue))
Space Complexity: O(1)
*/

class Solution {
public:
bool isPossible(int mid, vector<vector<int>>& matrix, int k){
    //bottom left
    int row=matrix.size()-1;
    int col=0;
    int count=0;
    while(row>=0 && col<matrix.size()){
        if(matrix[row][col]<=mid){
            count+=row+1;
            col++;
        }else{
            row--;
        }
    }
    return count>=k;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,matrix,k)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
