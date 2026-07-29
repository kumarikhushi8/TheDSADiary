/*
Problem: Remove Nth Node From End of List
LeetCode: 19
Approach: Two pointers with a dummy node
Time Complexity: O(n)
Space Complexity: O(1)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=new ListNode(-1);
        curr->next=head;
        ListNode* slow=curr;
        ListNode* fast=curr;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return curr->next;
    }
};
