/*
Problem: Search in Rotated Sorted Array II
LeetCode: 81

Approach:
- Use modified binary search.
- If nums[low], nums[mid], and nums[high] are equal,
  shrink both boundaries because the sorted half cannot be determined.
- Otherwise, identify the sorted half.
- Check whether the target lies within that half and eliminate
  the other half.

Time Complexity: O(log n) average, O(n) worst case due to duplicates.
Space Complexity: O(1)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            //duplicate case
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                high--;
                low++;
                continue;
            }
            //left half sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};
