/*
Problem: Linked List Insertion At Beginning
Platform: GeeksforGeeks
Approach: Create a new node and make it the new head.
Time Complexity: O(1)
Space Complexity: O(1)
*/

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        Node* temp=new Node(x);
        temp->next=head;
        head=temp;
    }
};
