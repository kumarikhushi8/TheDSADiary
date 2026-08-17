/*
Problem: Compare Version Numbers
LeetCode: 165

Approach:
- Use two pointers to traverse both version strings.
- Parse each revision number between two dots.
- Compare the corresponding revision numbers.
- If one version has fewer remaining revisions, treat the missing
  revisions as 0.
- Continue until both strings are completely processed.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        while(i<version1.size() || j<version2.size()){
            int num1=0;
            int num2=0;
            while(i<version1.size() && version1[i]!='.'){
                //building the number
                num1=(num1*10)+(version1[i]-'0');
                i++;
            }
            while(j<version2.size() && version2[j]!='.'){
                num2=(num2*10)+(version2[j]-'0');
                j++;
            }
            if(num1>num2) return 1;
            if(num1<num2) return -1;
            i++;
            j++;
        }
        return 0;

    }
};
