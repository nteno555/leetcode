/**
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==nullptr || head->next==nullptr) return false;
        ListNode* i=head;
        ListNode* j=head->next->next;
        while (i!= nullptr && j!= nullptr && i->next != nullptr && j->next != nullptr) {
            if (i==j) return true;
            i = i->next;
            j = j->next->next;
        }

        return false;
    }
};