/*
Problem: Remove Nth Node From End of List
LeetCode: 2
Approach: Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int carry=0;
        while(l1 || l2 || carry){
            int x=(l1?l1->val:0);
            int y=(l2?l2->val:0);
            int sum=x+y+carry;
            ListNode* curr=new ListNode(sum%10);
            temp->next=curr;
            temp=temp->next;
            carry=sum/10;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return dummy->next;
    }
};
