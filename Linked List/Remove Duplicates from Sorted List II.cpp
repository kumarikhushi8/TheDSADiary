/*
Problem: Remove Duplicates from Sorted List II
LeetCode: 82
Approach:
- Use a dummy node and two pointers.
- Skip entire groups of duplicate values.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode*curr=head;
        while(curr && curr->next){
            ListNode* temp= curr;
            while(curr->next && curr->val==curr->next->val){
                curr=curr->next;
            }
            if(temp==curr){
                prev=curr;
            }else{
                prev->next=curr->next;
                
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};
