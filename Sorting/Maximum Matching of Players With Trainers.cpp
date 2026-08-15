/*
Problem: Maximum Matching of Players With Trainers
LeetCode: 2410

Approach:
- Sort players and trainers in ascending order.
- Use two pointers:
  - i -> current player
  - j -> current trainer
- If the current trainer cannot train the player, move to the
  next trainer.
- Otherwise, match them and move both pointers.
- Always matching the smallest possible trainer to the current
  weakest player leaves larger trainers available for stronger
  players.

Time Complexity: O(n log n + m log m)
Space Complexity: O(1) auxiliary space
*/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int count=0;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(players[i]>trainers[j]){
                j++;
            }else{
                count++;
                i++;
                j++;
            }
        }
        return count;
    }
};
