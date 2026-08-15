/*
Problem: Word Pattern
LeetCode: 290

Approach:
- Split the string into individual words.
- If the number of words differs from the pattern length, return false.
- Maintain a mapping from word -> pattern character.
- Maintain a set of characters that are already assigned to a word.
- For each position, ensure that the existing mapping is consistent.
- This guarantees a one-to-one correspondence between pattern
  characters and words.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string token;
        vector<string>words;
        int countWords=0;
        while(getline(ss,token,' ')){
            words.push_back(token);
            countWords++;
        }
        if(pattern.size()!=words.size()) return false;
        unordered_map<string,char>mapped;
        set<char>usedChar;
        for(int i=0;i<pattern.size();i++){
            string word=words[i];
            char ch=pattern[i];
            if(usedChar.find(ch)==usedChar.end() && mapped.find(word)==mapped.end()){
                usedChar.insert(ch);
                mapped[word]=ch;
            }
            if(mapped[word]!=pattern[i]) return false;
        }
        return true;
    }
};
