// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 15/02/2022

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
    TreeNode* buildTreeR(vector<int>& preorder, int preorderStart, int preorderEnd, vector<int>& inorder, int inorderStart, int inorderEnd){
        if(preorderStart>preorderEnd) return nullptr;
        
        int i=0;
        while(inorder[inorderStart+i]!=preorder[preorderStart]) i++;
        
        TreeNode* root = new TreeNode(preorder[preorderStart]);
        
        root->left = helpreorderEndr(preorder, preorderStart+1, preorderStart+i, inorder, inorderStart, inorderStart+i-1);
        root->right = helpreorderEndr(preorder, preorderStart+i+1, preorderEnd, inorder, inorderStart+i+1, inorderEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeR(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};