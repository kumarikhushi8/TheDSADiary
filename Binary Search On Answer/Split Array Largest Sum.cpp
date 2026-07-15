/*
Problem: Split Array Largest Sum
LeetCode: 410
Approach: Binary Search on Answer + Greedy
Time Complexity: O(n * log(sum(nums)))
Space Complexity: O(1)
*/

class Solution {
public:
bool canSplit(int mid,vector<int>& nums, int k){
    int arr=1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid) return false;
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }else{
            arr++;
            sum=nums[i];
        }
    }
    return arr<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSplit(mid,nums,k)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
