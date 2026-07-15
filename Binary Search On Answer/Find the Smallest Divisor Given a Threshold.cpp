/*
Problem: Find the Smallest Divisor Given a Threshold
LeetCode: 1283
Approach: Binary Search on Answer
Time Complexity: O(n * log(max(nums)))
Space Complexity: O(1)
*/

class Solution {
public:
bool canDivide(vector<int>& nums, int threshold, int mid){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        int divide=(nums[i]+mid-1)/mid;
            sum+=divide;
    }
    return sum<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canDivide(nums,threshold,mid)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
