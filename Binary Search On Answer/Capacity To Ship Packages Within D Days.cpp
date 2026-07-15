/*
Problem: Capacity To Ship Packages Within D Days
LeetCode: 1011
Approach: Binary Search on Answer + Greedy
Time Complexity: O(n * log(sum(weights)))
Space Complexity: O(1)
*/

class Solution {
public:
bool canShip(int mid, vector<int>& weights, int days){
int day=1;
long long sum=weights[0];
for(long long i=1;i<weights.size();i++){
    if(weights[i]>mid) return false;
    if(sum+weights[i]<=mid){
        sum+=weights[i];
    }else{
    day++;
    sum=weights[i];
    }
}
return day<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canShip(mid,weights,days)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
