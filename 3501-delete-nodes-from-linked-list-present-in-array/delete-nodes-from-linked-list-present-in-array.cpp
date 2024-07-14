class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(begin(nums), end(nums));
        ListNode* newHead = new ListNode(-1);
        ListNode* t = newHead;
        ListNode* temp = head;
        while (temp) {
            int val = temp->val;
            if (st.find(val) == st.end()) {
                ListNode* h = new ListNode(val);
                t->next = h;
                t = t->next;
            }
            temp = temp->next;
        }
        return newHead->next;
    }
};