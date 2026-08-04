/*
Problem: Rotate List
LeetCode: 61

Approach:
1. Find the length and tail.
2. Connect tail to head to form a circular list.
3. Reduce k using modulo.
4. Move to the new tail.
5. Break the circle.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0) return head;
        ListNode* curr=head;
        int length=1;
        while(curr->next){
            length++;
            curr=curr->next;
        }
     k=k%length;
     if(k==0) return head;
     curr->next=head;
     ListNode* temp=head;
        for(int i=0;i<length-k-1;i++){
            temp=temp->next;
        }
        ListNode* newLL=temp->next;
        temp->next=nullptr;
        return newLL;
    }
};
