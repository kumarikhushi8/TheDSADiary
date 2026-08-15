/*
Problem: Find Players With Zero or One Losses
LeetCode: 2225

Approach:
- Use a hash map to count the number of losses for each player.
- Players who never appear as a loser have zero losses.
- Players with exactly one loss are added to the second result.
- Sort both result arrays as required.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lostMap;
        for(int i=0;i<matches.size();i++){
            int player=matches[i][1];
            lostMap[player]++;
        }
        vector<int>notLost;
        vector<int>lostOnce;
        for(int i=0;i<matches.size();i++){
            int winner=matches[i][0];
            int loser=matches[i][1];
            if(lostMap.find(winner)==lostMap.end()){
                notLost.push_back(winner);
                lostMap[winner]+=2;
            }
            if(lostMap[loser]==1){
                lostOnce.push_back(loser);
            }
        }
        sort(lostOnce.begin(),lostOnce.end());
        sort(notLost.begin(),notLost.end());
        return {notLost,lostOnce};
    }
};
