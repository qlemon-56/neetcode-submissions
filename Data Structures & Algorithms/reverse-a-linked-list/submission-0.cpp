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

        if (head == NULL) return NULL;        
        vector<ListNode*> ptrs = {};
        while (head != NULL) {
            ptrs.push_back({head});
            head = head->next;
        }

        for (int i = (ptrs.size()-1); i > 0; i--) {
            ptrs[i]->next = ptrs[i-1];
        }
        ptrs[0]->next = NULL;

        return ptrs[ptrs.size()-1];

    }
};
