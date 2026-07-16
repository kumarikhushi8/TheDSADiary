/*
Problem: Minimum Limit of Balls in a Bag
LeetCode: 1760
Approach: Binary Search on Answer
Time Complexity: O(n * log(max(nums)))
Space Complexity: O(1)
*/

class Solution {
public:
bool canDistribute(int mid,vector<int>& nums, int maxOperations){
    long long countAfterDivide=0;
    for(int i=0;i<nums.size();i++){
            countAfterDivide+=(nums[i]-1)/mid;
    }
    return countAfterDivide<=maxOperations;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canDistribute(mid,nums,maxOperations)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
