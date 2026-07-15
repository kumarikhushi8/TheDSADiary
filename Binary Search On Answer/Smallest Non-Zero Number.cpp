/*
Problem: Smallest Non-Zero Number
Platform: GeeksforGeeks
Approach: Binary Search on Answer
Time Complexity: O(n * log(max(arr)))
Space Complexity: O(1)
*/

class Solution {
  public:
  bool canProcess(vector<int>&arr, int mid){
      long long ele=mid;
      for(int i=0;i<arr.size();i++){
          ele=2LL*ele-arr[i];
          if(ele<0) return false;
          if (ele > 1000000000000000000LL)
            ele = 1000000000000000000LL;
      }
      return true;
  }
    int find(vector<int>& arr) {
        long long low=1;
        long long high=*max_element(arr.begin(),arr.end());
        long long ans=low;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(canProcess(arr,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
    }
};
