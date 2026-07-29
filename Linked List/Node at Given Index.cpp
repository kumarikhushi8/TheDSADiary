/*
Problem: Node at Given Index
Platform: GeeksforGeeks
Approach: Traverse the linked list until the required position.
Time Complexity: O(n)
Space Complexity: O(1)
*/

/* Node Structure
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    int getNode(Node* head, int k) {
        if(head==nullptr) return -1;
        Node* curr=head;
        while(curr->next!=nullptr && k>1){
            curr=curr->next;
            k--;
        }
        if(k>1 and curr->next==nullptr) return -1;
        return curr->data;
    }
};
