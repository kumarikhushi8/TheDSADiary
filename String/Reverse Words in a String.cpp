/*
Problem: Reverse Words in a String
LeetCode: 151

Approach:
- Use stringstream-style tokenization to extract words.
- Ignore empty tokens caused by multiple spaces.
- Store all words in a vector.
- Reverse the vector of words.
- Join the reversed words using a single space.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        vector<string>arr;
        while(getline(ss,token,' ')){
            if(!token.empty()) arr.push_back(token);
        }
        reverse(arr.begin(),arr.end());
        string ans="";
        for(auto i=0;i<arr.size();i++){
            ans+=arr[i];
            if(i!=arr.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};
