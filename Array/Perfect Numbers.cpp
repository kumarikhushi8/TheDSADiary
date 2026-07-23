/*
Problem: Perfect Numbers
Platform: GeeksforGeeks
Approach: Iterate through divisors up to sqrt(n)
Time Complexity: O(sqrt(n))
Space Complexity: O(1)
*/

class Solution {
  public:
    bool isPerfect(int n) {
        int sum=0;
        for(int i=1;i*i<n;i++){
            if(n%i==0) sum+=i+n/i;
        }
        return sum-n==n;
    }
};
