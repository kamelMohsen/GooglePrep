// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 09/02/2022

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // no trees at all return null
        if (!root1 && !root2) return root1;
        // create the initial new tree node
        TreeNode* root3 = new TreeNode(0);
        mergeTreeR(root1,root2,root3);
        
        return root3;
    }
    void mergeTreeR(TreeNode* &r1, TreeNode* &r2, TreeNode* &r3 ){
        
        // if after leaves go back
        if(r1 == nullptr && r2 == nullptr) return;
        else if(r1 != nullptr && r2 != nullptr){ // if both have values sum and add to new tree
            r3->val = r1->val += r2->val;  
        } 
        if(r1==nullptr) {// if left tree is chopped of, then take a copy from the right one
            r3=r2;
            return;
        }
        else if(r2==nullptr) {// if right tree is chopped of, then take a copy from the left one
            r3=r1;
            return;
        }
        
        if(r1->left || r2->left){ // iff right or left trees have left child create a left child for the new tree
            TreeNode* l = new TreeNode(0);
            r3->left = l;
        
        }
        if(r1->right || r2->right){ // iff right or left trees have right child create a right child for the new tree
            TreeNode* r = new TreeNode(0);
            r3->right = r;
        }

        // recurse for the tree left and right
        mergeTreeR(r1->left,r2->left,r3->left);
        mergeTreeR(r1->right,r2->right,r3->right);
        
        
    }
};




// You are given two binary trees root1 and root2.

// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

// Return the merged tree.

// Note: The merging process must start from the root nodes of both trees.

 

// Example 1:


// Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
// Output: [3,4,5,5,4,null,7]
// Example 2:

// Input: root1 = [1], root2 = [1,2]
// Output: [2,2]