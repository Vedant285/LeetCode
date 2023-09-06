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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k,NULL);
        int i=0;
        ListNode* curr=head;
        while(curr){
            i++;
            curr=curr->next;
        }
        int eachsize=i/k;
        int left=i%k;
        curr=head;
        ListNode* prev=NULL;
        for(int c=0;c<k;c++){
            ans[c]=curr;
            for(int j=1;j<=eachsize+(left>0?1:0);j++){
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL){
                prev->next=NULL;
            }
            left--;
        }
        return ans;
    }
};