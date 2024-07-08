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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        ListNode* t2 = head->next;
        while (temp->next != NULL) {
            int a = temp->val;
            int b = t2->val;
            int c = gcd(a, b);
            ListNode* curr = new ListNode(c);
            temp->next = curr;
            curr->next = t2;
            temp = t2;
            t2 = t2->next;
        }
        return head;
    }
};