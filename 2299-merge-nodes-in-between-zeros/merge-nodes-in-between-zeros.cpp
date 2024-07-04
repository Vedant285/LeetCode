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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* t2 = head;
        long long cnt = 0;
        while (temp) {
            if (temp->val == 0) {
                t2->next->val = cnt;
                if (temp->next == NULL) {
                    t2->next->next = NULL;
                }
                t2= t2->next;
                cnt = 0;
                
            }
            else {
                cnt += temp->val;
            }
            temp= temp->next;
        }
        return head->next;
    }
};