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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
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
    int pairSum(ListNode* head) {
        if (!head || !head->next) {
            return head->val;
        }
        int cnt = 0;
        int ans = INT_MIN;
        ListNode* midd = findMiddle(head);
        ListNode* s = head;
        ListNode* l = midd->next;
        ListNode* newHead = reverse(l);
        l = newHead;
        while (s && l) {
            int a = s->val + l->val;
            ans = max(a, ans);
            s = s->next;
            l = l->next;
        }
        return ans;
    }
};