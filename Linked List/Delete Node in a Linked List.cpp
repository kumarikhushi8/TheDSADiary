/*
Problem: Delete Node in a Linked List
LeetCode: 237
Approach: Copy next node value and bypass next node
Time Complexity: O(1)
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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         ListNode* prev=NULL;
//         while(node!=NULL && node->next!=NULL){
//             node->val=node->next->val;
//             prev=node;
//             node=node->next;
//         }
//         prev->next=NULL;
//         // delete(node);
//     }
// };
