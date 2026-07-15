/*
Problem: WoodCutting Made Easy!
Platform: InterviewBit
Approach: Binary Search on Answer
Time Complexity: O(n * log(maxHeight))
Space Complexity: O(1)
*/

bool canCut(int mid,vector<int> &A, int B){
        long long wood=0;
        for(int i=0;i<A.size();i++){
            if(A[i]>mid){
                wood+=A[i]-mid;
            }
        }
        return wood>=B;
    }
int Solution::solve(vector<int> &A, int B) {
    long long low=0;
    long long high=*max_element(A.begin(),A.end());
    long long ans=low;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(canCut(mid,A,B)){
            low=mid+1;
            ans=mid;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

