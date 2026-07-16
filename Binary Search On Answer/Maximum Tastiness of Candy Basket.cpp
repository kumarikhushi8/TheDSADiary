/*
Problem: Maximum Tastiness of Candy Basket
LeetCode: 2517
Approach: Binary Search on Answer + Greedy
Time Complexity: O(n log n + n log(maxDifference))
Space Complexity: O(1)
*/

class Solution {
public:
    bool canAchieve(int mid,vector<int>& price, int k){
        int candy=1;
        int j=0;
        for(int i=1;i<price.size();i++){
            if(abs(price[j]-price[i])>=mid){
                j=i;
                candy++;
            }
        }
        return candy>=k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int low=0;
        int high=price[price.size()-1]-price[0];
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canAchieve(mid,price,k)){
                low=mid+1;
                ans=mid;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};
