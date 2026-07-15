/*
Problem: Painter's Partition Problem
Platform: GeeksforGeeks
Approach: Binary Search on Answer + Greedy
Time Complexity: O(n * log(sum(arr)))
Space Complexity: O(1)
*/

class Solution {
  public:
  bool canPaint(vector<int>&arr, int k, int mid){
      int painters=1;
      int boards=0;
      for(int i=0;i<arr.size();i++){
          if(boards+arr[i]<=mid){
              boards+=arr[i];
          }else{
              painters++;
              boards=arr[i];
          }
      }
      return painters<=k;
  }
    int minTime(vector<int>& arr, int k) {
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPaint(arr,k, mid)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
