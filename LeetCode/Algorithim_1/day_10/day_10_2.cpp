// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 14/02/2022

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
    ListNode* reverseList(ListNode* head) {
        ListNode* iterator = head;
        ListNode* temp;
        while(iterator && iterator->next){
            iterator = iterator->next;
        }
        while(head && head != iterator){
            temp = iterator->next;
            iterator->next = head;
            head = head->next;
            iterator->next->next = temp;
        }
        return head;
    }
};


// Given the head of a singly linked list, reverse the list, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:


// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []
