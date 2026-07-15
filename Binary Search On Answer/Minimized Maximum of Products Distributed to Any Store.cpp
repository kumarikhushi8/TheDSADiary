/*
Problem: Minimized Maximum of Products Distributed to Any Store
LeetCode: 2064
Approach: Binary Search on Answer
Time Complexity: O(m * log(max(quantities)))
Space Complexity: O(1)
*/

class Solution {
public:
bool canDistribute(int mid, vector<int>&quantities,int n){
    int shop=0;
    for(int i=0;i<quantities.size();i++){
        shop+=(quantities[i]+mid-1)/mid;
    }
    return shop<=n;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canDistribute(mid,quantities,n)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
