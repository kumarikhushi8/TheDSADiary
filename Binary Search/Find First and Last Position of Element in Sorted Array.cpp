/*
Problem: Find First and Last Position of Element in Sorted Array
LeetCode: 34
Approach: Binary Search (Two Passes)
Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        if(nums.size()<=0) return res;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target) high=mid-1;
            else if(nums[mid]<target) low=mid+1;
            else{
                int i=mid;
                high=mid-1;
                res[0]=i;
            }
        }
        low=0;
        high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target) high=mid-1;
            else if(nums[mid]<target) low=mid+1;
            else{
                int j=mid;
                low=mid+1;
                res[1]=j;
            }
        }
        return res;
    }
};
