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
        ListNode*temp=head;
        ListNode* t2=head;
        while(n--){
            temp=temp->next;
        }
        if(temp==NULL)return head->next;

        while(temp && temp->next){
            temp=temp->next;
            t2=t2->next;
        }
        t2->next=t2->next->next;
        return head;
    }
};