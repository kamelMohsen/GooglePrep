// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 15/02/2022

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <string>
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized = "";
        serializeR(root,serialized);
        cout<<serialized;
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "n,") return nullptr;
        
        int pos = 0 ;


        return deserialaizeR(data, pos);

    }
    TreeNode * deserialaizeR(string serialized, int &pos){ // desrialize recursive
        if(pos >= serialized.size() - 1) return nullptr;

        string temp = "";
        while(serialized[pos] != ',' ){
            temp += serialized[pos++];
        }
        pos++;
        if(temp == "n") return nullptr;
        TreeNode * r = new TreeNode(stoi(temp));

        r->left = deserialaizeR(serialized, pos);  
        r->right = deserialaizeR(serialized, pos); 
        return r;

    }

    void serializeR(TreeNode * root, string &serialized){
        if(root == nullptr){
            serialized += "n,";
            return;
        }else{
            serialized += to_string(root->val) + ",";	
        }

        serializeR(root->left, serialized);
        serializeR(root->right, serialized);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));







// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

// Example 1:


// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []