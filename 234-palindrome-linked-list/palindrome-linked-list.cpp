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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverse(head->next);
        ListNode* temp = head->next;
        temp->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode* t1 = head, *t2 = newHead;
        while (t2){
            if (t1->val != t2->val) {
                ListNode* temp = reverse(slow->next);
                return false;
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        ListNode* k = reverse(slow->next);
        return true;
    }
};