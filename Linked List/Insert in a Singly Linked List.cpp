/*
Problem: Insert in a Singly Linked List
Platform: GeeksforGeeks
Approach: Traverse to the (pos-1)th node and insert the new node.
Time Complexity: O(n)
Space Complexity: O(1)
*/

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertPos(Node* head, int pos, int val) {
        Node* newNode=new Node(val);
        if (pos==1){
            newNode->next=head;
            head=newNode;
            return head;
        }
        Node* curr=head;
        for(int i=1;i<pos-1 && curr!=nullptr; i++){
            curr=curr->next;
        }
        if(curr==nullptr) return head;
        newNode->next=curr->next;
        curr->next=newNode;
        return head;
    }
};
