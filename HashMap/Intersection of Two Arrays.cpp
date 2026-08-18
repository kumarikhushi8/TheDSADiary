/*
Problem: Intersection of Two Arrays
LeetCode: 349

Approach:
- Store the elements of nums1 in a hash map.
- Traverse nums2 and check whether each element exists in nums1.
- Insert matching elements into an unordered_set to ensure
  every intersection element appears only once.
- Convert the set into a vector and return it.

Time Complexity: O(n + m) average
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums1.size();i++){
            freq[nums1[i]]++;
        }
        unordered_set<int>ans;
        for(int i=0;i<nums2.size();i++){
            if(freq.count(nums2[i])){
                ans.insert(nums2[i]);
            }
        }
        return vector<int>(ans.begin(),ans.end());
    }
};
