/*
Problem: Kth Smallest Number in Multiplication Table
LeetCode: 668

Approach:
- Binary Search on Answer.
- For each mid, count how many numbers in the multiplication table are <= mid.

Time Complexity: O(m log(m*n))
Space Complexity: O(1)
*/

class Solution {
public:
bool countLessthanMid(int mid,int m, int n, int k){
    int count=0;
    for(int i=1;i<=m;i++){
        count+=min(mid/i,n);
    }
    return count>=k;
}
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(countLessthanMid(mid,m,n,k)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
