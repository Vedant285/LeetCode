class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* t = new ListNode(-1);
        ListNode* temp = t;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1) temp->next = l1;
        else if(l2) temp->next = l2;

        return t->next;
    }
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if  (!head || !head->next)return head;

        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};