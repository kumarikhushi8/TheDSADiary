/*
Problem: Number of Recent Calls
LeetCode: 933
Approach: Queue
Time Complexity: O(1) amortized per ping()
Space Complexity: O(n)
*/

class RecentCounter {
public:
queue<int>que;
//think about what we del first is what came first 
//time  is always in increasing order
    RecentCounter() {
        
    }
    
    int ping(int t) {
        que.push(t);
        int low=t-3000;
        int high=t;
        while(!que.empty() && que.front()<low){
            que.pop();
        }
        return que.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
