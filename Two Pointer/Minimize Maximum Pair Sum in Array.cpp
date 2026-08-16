/*
Problem: Minimize Maximum Pair Sum in Array
LeetCode: 1877

Approach:
- Sort the array.
- Pair the smallest element with the largest element,
  the second smallest with the second largest, and so on.
- Track the maximum pair sum.
- This pairing minimizes the maximum pair sum.

Time Complexity: O(n log n)
Space Complexity: O(1) auxiliary space
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        int j=nums.size()-1;
        int result=0;
        while(i<j){
            int sum=nums[i]+nums[j];
            result=max(result, sum);
            i++;
            j--;
        }
        return result;
    }
};
