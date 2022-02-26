// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 20/02/2022

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> heap;
        for(auto list : lists){
            while(list){
                heap.push_back(list->val);
                list = list->next;
            }
        }
        if(heap.size()==0) return nullptr;

        make_heap(heap.begin(),heap.end());
        
        ListNode* root = new ListNode(heap.front());
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();

        for(auto element : heap){
            ListNode* newNode = new ListNode(root->val);
            newNode->next = root->next;
            root->next = newNode;
            root->val = heap.front();
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
        return root;
    }
};