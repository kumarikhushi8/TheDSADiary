/*
Problem: Linked List End Insertion
Platform: GeeksforGeeks
Approach: Traverse to the last node and append the new node.
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* temp=new Node(x);
        if(head==nullptr){
            return temp;
        }
        if(head!=nullptr){
        Node* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=temp;
        }
        return head;
    }
};
