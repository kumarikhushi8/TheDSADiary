/*
Problem: Reverse Nodes in k-Group
LeetCode: 25

Approach:
- First check whether at least k nodes are available.
- If fewer than k nodes remain, return the current head unchanged.
- Reverse the current group of k nodes.
- Recursively process the remaining list.
- Connect the tail of the reversed group to the result of the
  recursive call.

Time Complexity: O(n)
Space Complexity: O(n/k) recursion stack
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* recursion(ListNode* head, int k){
    ListNode* check=head;
    for(int i=0;i<k;i++){
        if(!check) return head;
        check=check->next; 
    }
    ListNode* curr=head;
    ListNode* prev=nullptr;
    for(int i=0;i<k;i++){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=recursion(curr,k);
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        return recursion(head,k);
    }
};
