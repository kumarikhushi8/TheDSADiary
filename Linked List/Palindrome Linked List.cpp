/*
Problem: Palindrome Linked List
LeetCode: 234
Approach:
1. Find the middle using slow and fast pointers.
2. Reverse the second half.
3. Compare both halves.
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHalf=slow;
        ListNode* firstHalf=head;
        ListNode* prev=nullptr;
        while(slow!=nullptr){
            ListNode* next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        secondHalf=prev;
        while(secondHalf){
            if(firstHalf->val!=secondHalf->val) return false;
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }
        return true;
    }
};





/*
Problem: Palindrome Linked List
LeetCode: 234
Approach: Store linked list values in a vector and check palindrome using two pointers.
Time Complexity: O(n)
Space Complexity: O(n)
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
    bool isPalindrome(ListNode* head) {
        vector<int>arr;
        ListNode* curr=head;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            if(arr[i]!=arr[j]){
               return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
