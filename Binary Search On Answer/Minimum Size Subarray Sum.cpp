/*
Problem: Minimum Size Subarray Sum
LeetCode: 209

Approach:
- Binary search on the subarray length.
- For a candidate length mid, check whether any subarray
  of exactly mid elements has sum >= target.
- Use a sliding window to perform this check in O(n).
- If such a window exists, try a smaller length.
- Otherwise, search for a larger length.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
bool makeWindow(int mid, vector<int>& nums, int target){
    //Is there any subarray of exactly mid elements whose sum is at least target
    long long sum=0;
    for(int i=0;i<mid;i++){
        sum+=nums[i];
    }
    if(sum>=target) return true;
    for(int i=mid;i<nums.size();i++){
        sum+=nums[i];
        sum-=nums[i-mid];
        if(sum>=target) return true;
    }
    return false;
}
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=1;
        int high=nums.size();
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(makeWindow(mid,nums,target)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;   
    }
};
