/*
Problem: Count the Number of Good Partitions
LeetCode: 2963

Approach:
- Store the last occurrence index of every element.
- Scan the array and maintain the farthest last occurrence
  among all elements in the current partition.
- Whenever the current index moves beyond this boundary,
  a valid partition can end.
- Every valid boundary gives two choices:
  - Place the partition boundary here.
  - Do not place the partition boundary here.
- Therefore, multiply the answer by 2 for every valid boundary.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

class Solution {
public:
int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>lastIndex;
        for(int i=0;i<n;i++){
            lastIndex[nums[i]]=i;
        }
        int i=0;
        int j=0;
        j=max(j,lastIndex[nums[0]]);
        int result=1;
        while(i<n){
            if(i>j){  //we got a partition
            result=(result*2)%M;
            }
            j=max(j,lastIndex[nums[i]]);
            i++;
        }
        return result;
    }
};
