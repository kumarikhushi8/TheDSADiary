/*
Problem: H-Index II
LeetCode: 275

Approach:
- Binary search on the possible H-index.
- For a candidate h, count how many papers have at least h citations.
- If at least h papers satisfy this condition, h is possible,
  so search for a larger value.
- Otherwise, search for a smaller value.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
bool isPossible(int mid, vector<int>&arr){
    int paper=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=mid){
            paper++;
        }
    }
    return paper>=mid;
}
    int hIndex(vector<int>& citations) {

        int low=0;
        int high=*max_element(citations.begin(),citations.end());
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,citations)){
                low=mid+1;
                ans=mid;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};
