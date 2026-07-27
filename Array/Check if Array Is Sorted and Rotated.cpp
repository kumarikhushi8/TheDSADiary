/*
Problem: Check if Array Is Sorted and Rotated
LeetCode: 1752
Approach: Count the number of decreasing adjacent pairs.
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0]) count++;
        return count<=1;
    }
};
