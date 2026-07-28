/*
Problem: Find Median from Data Stream
LeetCode: 295
Approach: Two Heaps (Max Heap + Min Heap)
Time Complexity:
    addNum(): O(log n)
    findMedian(): O(1)
Space Complexity: O(n)
*/

class MedianFinder {
public:
priority_queue<int>leftMaxHeap;
priority_queue<int, vector<int>, greater<int>>rightMinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty() || num< leftMaxHeap.top()){
            leftMaxHeap.push(num);
        }else{
            rightMinHeap.push(num);
        }
        if(leftMaxHeap.size()>rightMinHeap.size()+1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        if(leftMaxHeap.size()<rightMinHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if(rightMinHeap.size()==leftMaxHeap.size()){
            double mean=(leftMaxHeap.top()+rightMinHeap.top())/2.0;
            return mean;
        }
        return leftMaxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
