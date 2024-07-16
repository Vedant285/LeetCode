class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverse(head->next);
        ListNode* temp = head->next;
        temp->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* kthElement(ListNode* head, int k) {
        ListNode* len = head;
        while (len && k > 1) {
            len = len->next;
            k--;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            ListNode* len = kthElement(temp, k);

            if (!len) {
                if (prev){
                    prev->next = temp;
                }
                break;
            }
            ListNode* nxt = len->next;
            len->next = NULL;
            ListNode* newHead = reverse(temp);
            if (temp == head) {
                head = newHead;
            }
            else {
                prev->next = newHead;
            }
            prev = temp;
            temp = nxt;
        }
        return head;
    }
};