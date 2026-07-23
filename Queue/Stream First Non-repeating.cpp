/*
Problem: Stream First Non-Repeating
Platform: GeeksforGeeks
Approach: Queue + Frequency Array
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
  public:
    string firstNonRepeating(string &s) {
        string ans="";
        vector<int>freq(26,0);
        queue<char>que;
        for(auto i=0;i<s.size();i++){
            auto current=s[i];
            freq[current-'a']++;
            que.push(current);
            while(!que.empty() && freq[que.front()-'a']>1){
                que.pop();
            }
            if(que.empty()) ans+="#";
            else ans+=que.front();
        }
        return ans;
    }
};
