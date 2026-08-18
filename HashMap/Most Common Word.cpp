/*
Problem: Most Common Word
LeetCode: 819

Approach:
- Convert all uppercase letters to lowercase.
- Replace every non-alphabetic character with a space.
- Tokenize the paragraph into words.
- Count the frequency of every word using a hash map.
- Store banned words in an unordered_set.
- Find the most frequent word that is not banned.

Time Complexity: O(n + m) average
Space Complexity: O(n + m)
*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(char &c:paragraph){
            if(isalpha(c)){
                c=tolower(c);
            }else{
                c=' ';
            }
        }
      //"bob hit a ball  the hit ball flew far after it was hit "
        stringstream ss(paragraph);
        string token;
        vector<string>words;
        unordered_map<string,int>freqWords;
        while(getline(ss,token,' ')){
            if(token!=""){ 
                words.push_back(token);
                freqWords[token]++;
            }
        }
        unordered_set<string>ban(banned.begin(),banned.end());
        string ans="";
        int maxFreq=0;
        for(int i=0;i<words.size();i++){
            if(ban.find(words[i])==ban.end() && freqWords[words[i]]>maxFreq){
                ans=words[i];
                maxFreq=freqWords[words[i]];
            }
        }
        return ans;
    }
};
