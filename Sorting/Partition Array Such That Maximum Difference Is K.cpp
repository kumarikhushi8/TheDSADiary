/*
Problem: Partition Array Such That Maximum Difference Is K
LeetCode: 2294

Approach:
- Sort the array.
- Start a group with the smallest ungrouped element.
- Keep adding elements while the difference between the current
  element and the group's minimum is at most k.
- If the difference becomes greater than k, start a new group.
- Greedily making each group as large as possible minimizes the
  total number of groups.

Time Complexity: O(n log n)
Space Complexity: O(1) auxiliary space
*/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=1;
        int minVal=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]-minVal>k){
                count++;
                minVal=nums[i];
            }
        }
        return count;
    }
};
