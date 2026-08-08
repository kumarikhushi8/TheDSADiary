/*
Problem: Find Minimum in Rotated Sorted Array II
LeetCode: 154

Approach:
- Use modified binary search.
- Compare nums[mid] with nums[high].
- If nums[mid] > nums[high], the minimum lies on the right.
- If nums[mid] < nums[high], the minimum lies at mid or on the left.
- If nums[mid] == nums[high], duplicates make the side ambiguous,
  so safely reduce high by one.

Time Complexity: O(log n) average, O(n) worst case due to duplicates.
Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else if(nums[mid]<nums[high]){
                high=mid;
            }else{
                high--;
            }
        }
        return nums[low];
    }
};
