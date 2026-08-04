/*
Problem: Sort List
LeetCode: 148

Approach:
- Use Merge Sort on the linked list.
- Split the list into two halves using slow and fast pointers.
- Recursively sort both halves.
- Merge the sorted halves.

Time Complexity: O(n log n)
Space Complexity: O(log n)
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
ListNode* mergeBoth(ListNode* left, ListNode* right){
    ListNode* dummy=new ListNode(-1);
    ListNode* curr=dummy;
    while(left && right){
        if(left->val<=right->val){
            curr->next=left;
            left=left->next;
        }else{
            curr->next=right;
            right=right->next;
        }
        curr=curr->next;
    }
    if(left!=nullptr){
        curr->next=left;
    }else{
        curr->next=right;
    }
    return dummy->next;
}
ListNode* mergeSort(ListNode* head){
    if(head->next==nullptr) return head;
    ListNode* slow=head;
    ListNode*fast=head;
    ListNode* prev=nullptr;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=nullptr;
    ListNode* left=mergeSort(head);
    ListNode* right=mergeSort(slow);
    ListNode* newLL=mergeBoth(left,right);
    return newLL;
}
    ListNode* sortList(ListNode* head) {
        if(head==nullptr) return head;
        return mergeSort(head);
    }
};
