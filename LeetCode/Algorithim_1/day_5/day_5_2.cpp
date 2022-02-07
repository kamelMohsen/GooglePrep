// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 07/02/2022

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if a single node, delete it 
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return head;
        }
        // count the list
        ListNode* tempHead = head;
        int c = 1; 
        while(tempHead->next != nullptr){
            tempHead = tempHead->next;
            c++;
        }
        // Start deleting
        tempHead = head;
        ListNode* toDelete;
        int j = 1;
        // Traverse to the node before one to be deleted
        while(j<c-n){
            j++;
            tempHead = tempHead->next;
        }
        // check wether the first node is the one to be deleted
        if(c-n>0){
            toDelete = tempHead->next;
            tempHead->next = toDelete->next;
            delete toDelete;            
        }
        else{ // first node deletion
            toDelete = head;
            head = head->next;
            delete toDelete;     
            return head;
        }
        return head;
        
    }
};