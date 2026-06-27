/*
Problem: Permutations II
Platform: LeetCode
Status: Accepted
Approach: Backtracking + duplicate check using find()
Note: This is my initial accepted solution. I plan to add more optimized approaches later.
*/

class Solution {
public:
void func(vector<vector<int>>&res,vector<int>& nums,int index){
    if(index==nums.size()){
        res.push_back(nums);
        return;
    }
    if(find(res.begin(),res.end(),nums)!=res.end()) return;
    for(int i=index;i<nums.size();i++){
        swap(nums[i],nums[index]);
        func(res,nums,index+1);
        swap(nums[i],nums[index]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        func(res,nums,0);
        return res;
    }
};
