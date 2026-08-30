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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry{0};
        // set up dummy and node
        ListNode dummy(0);
        ListNode* currNode = &dummy;

        while (l1!=nullptr || l2!=nullptr) {
            // process nodes
            int sum {0};
            if (l1!=nullptr) {
                sum += l1->val;
                l1=l1->next;
            }
            if (l2!=nullptr) {
                sum +=l2->val;
                l2=l2->next;
            }
            
            currNode->next = new ListNode ((sum+carry)%10);
            carry = (sum+carry)/10;

            // move currNode
            currNode = currNode->next;
        }
        if (carry!=0) currNode->next = new ListNode(carry);
        return dummy.next;
    }
};
