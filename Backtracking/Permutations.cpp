/*
Problem: Permutations
Platform: LeetCode
Approach: Backtracking + Swapping
Time Complexity: O(n × n!)
Space Complexity: O(n) (excluding output)
*/
class Solution {
public:
void backtrack(vector<vector<int>>&res,vector<int>& nums,int index){
    if(index==nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[i],nums[index]);
        func(res,nums,index+1);
        swap(nums[i],nums[index]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        func(res,nums,0);
        return res;
    }
};
