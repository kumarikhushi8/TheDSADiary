/*
Problem: Intersection of Two Linked Lists
LeetCode: 160

Approach:
- Use two pointers, one starting at each linked list.
- Move each pointer one step at a time.
- When a pointer reaches the end of its list, move it to the
  head of the other list.
- After traversing both lists, both pointers have traveled the
  same total distance.
- Therefore, if an intersection exists, they meet at the
  intersection node; otherwise, both become nullptr.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A=headA;
        ListNode* B=headB;
        while(A!=B){
            if(A){
                A=A->next;
            }else{
                A=headB;
            }
            if(B){
                B=B->next;
            }else{
                B=headA;
            }
        }
        return A;
    }
};
