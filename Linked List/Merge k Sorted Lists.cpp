/*
Problem: Merge k Sorted Lists
LeetCode: 23

Approach:
- Divide and Conquer (Merge Sort).
- Recursively divide the list of linked lists.
- Merge two sorted lists at each level.

Time Complexity: O(N log k)
Space Complexity: O(log k)
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
ListNode* mergeTwo(ListNode* left, ListNode* right){
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
ListNode* merge(vector<ListNode*>& lists, int i, int j){
    if(i==j) return lists[i];
    int mid=i+(j-i)/2;
    ListNode* left=merge(lists,i,mid);
    ListNode* right=merge(lists,mid+1,j);
    ListNode* head=mergeTwo(left,right);
    return head;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        return merge(lists,0,lists.size()-1);
    }
};
