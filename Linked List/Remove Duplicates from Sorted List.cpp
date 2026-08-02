/*
Problem: Remove Duplicates from Sorted List
LeetCode: 83
Approach: Traverse the sorted list and remove adjacent duplicate nodes.
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
        ListNode* curr=head;
        if(head==nullptr) return head;
        while(curr && curr->next){
            if(curr->val==curr->next->val){
                curr->next=curr->next->next;
            }
            else curr=curr->next;
        }
        return head;
    }
};
