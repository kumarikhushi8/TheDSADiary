/*
Problem: Find All Duplicates in an Array
LeetCode: 442

Approach:
- Use an unordered_map to store the frequency of each number.
- Traverse the frequency map.
- Add numbers whose frequency is exactly 2 to the answer.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i:nums){
            freq[i]++;
        }
        vector<int>ans;
        for(auto i:freq){
            if(i.second==2){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
