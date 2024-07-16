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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }
        int len = 1;
        ListNode* temp = head;
        while (temp->next) {
            len++;
            temp = temp->next;
        }
        ListNode* t = head;
        k = k % len;
        if (k == 0) {
            return head;
        }
        len -= k;
        while (t && len > 1) {
            t = t->next;
            len--;
        }
        ListNode* newHead;
        if (t->next) {
            newHead = t->next;
        }
        t->next = NULL;
        temp->next = head;
        return newHead;

    }
};