/*
Problem: Single Element in a Sorted Array
LeetCode: 540
Approach: Binary Search (My initial accepted approach)
Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int low=0;
       int high=nums.size()-1;
       while(low<high){
        int mid=low+(high-low)/2;
        if(nums[mid]==nums[mid+1]){
            int size=nums.size()-mid-1;
            if(size%2==0){
                low=mid+2;
            }else{
                high=mid-1;
            }
        }else{
            int size=nums.size()-mid-1;
            if(size%2==0){
                high=mid;
            }else{
                low=mid+1;
            }
        }
       }
       return nums[high];
    }
};
