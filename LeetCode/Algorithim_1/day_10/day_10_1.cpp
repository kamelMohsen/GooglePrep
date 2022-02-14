// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 13/02/2022

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return list1;
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode * l1P = list1; // list1 pointer
        ListNode * l2P = list2; // list1 pointer
        ListNode * temp;
        ListNode * temp1;
        while(true){
            if(!l1P){
                l1P = l2P;
                break;
            }
            if(!l2P){
                break;
            }
            if(l1P->val <= l2P->val){
                while(l1P->next != nullptr && l1P->next->val <= l2P->val){
                    cout<<l1P->val;
                    l1P = l1P->next;    
                }
                temp = l1P->next;
                temp1 = l2P->next;
                l1P->next = l2P;
                l2P = temp1;
                l1P->next->next = temp;
                l1P = l1P->next;
            }else{
                temp = l2P->next;
                l2P->next = l1P;
                list1 = l2P;
                l1P = l2P;
                l2P = temp;

            }
        }
        return list1;
    }
};




// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]