/*
Problem: Count the Number of Fair Pairs
LeetCode: 2563
Approach: Sorting + Two Pointers + Inclusion-Exclusion
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
long long countPairs(vector<int>&arr, int target){
    long long pairs=0;
    int left=0;
    int right=arr.size()-1;
    while(left<right){
        if(arr[left]+arr[right]<=target){
            pairs+=(right-left);
            left++;
        }
        else right--;
    }
return pairs;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long count=0;
    sort(nums.begin(),nums.end());
    long long right=countPairs(nums,upper);
    long long left=countPairs(nums,lower-1);
    count=right-left;
    return count;
    }
};
