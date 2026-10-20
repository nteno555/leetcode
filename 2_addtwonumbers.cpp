
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = (l1->val + l2->val) % 10, carryover = 0;
        if (l1->val + l2->val > 9) carryover = 1;

        if (l1->next == nullptr && l2->next == nullptr) {
            if (carryover == 1) return new ListNode(sum, new ListNode(carryover));
            return new ListNode(sum);
        }

        if (l1->next == nullptr) return new ListNode(sum, addTwoNumbers(new ListNode(carryover), l2->next));

        if (l2->next == nullptr) return new ListNode(sum, addTwoNumbers(l1->next, new ListNode(carryover)));

        return new ListNode(sum, addTwoNumbers(new ListNode(l1->next->val + carryover, l1->next->next), l2->next));
    }
};