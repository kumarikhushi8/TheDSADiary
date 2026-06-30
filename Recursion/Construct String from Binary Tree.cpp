/*
Problem: Construct String from Binary Tree
LeetCode: 606
Approach: Recursive DFS (Preorder Traversal)
Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root==nullptr) return "";
        string result=to_string(root->val);
        //root (left) (right) 
        string left = tree2str(root->left);
        string right = tree2str(root->right);

        if(root->left==NULL && root->right==NULL) return result;

        // root->left==null
        if(root->left==nullptr){
            return result+"()"+"("+right+")";
        }
        if(root->right==nullptr) return result+"("+left+")";
        
        return result+"("+left+")"+"("+right+")";
    }
};
