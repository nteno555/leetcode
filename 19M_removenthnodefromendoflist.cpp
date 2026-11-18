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
        if (head==nullptr) return head;

        head = reverseLinkedList(head);

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* cur = head;

        for (int i=1; i<n; i++) {
            prev = cur;
            cur = cur->next;
        }

        ListNode* newHead;
        ListNode* del = cur;
        prev->next = cur->next;
        cur = cur->next;
        delete del;

        newHead = dummy->next;
        delete dummy;


        return reverseLinkedList(newHead);
    }

    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* reversedList = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return reversedList;
    }
};