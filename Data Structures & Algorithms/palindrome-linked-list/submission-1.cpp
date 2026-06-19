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
    bool isPalindrome(ListNode* head) {
        vector <int> skids {}, box {};
        while (head != nullptr) {
            skids.push_back(head -> val);
            head = head -> next;
        }

        box = {skids};

        reverse(box.begin(), box.end());
        if (box != skids) return false;
        return true;

    }
};