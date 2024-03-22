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
    bool isPalindrome(ListNode* head) {
        vector<int>k;
        if(head==NULL || head->next==NULL)return true;
        while(head!=NULL){
            k.push_back(head->val);
            head=head->next;
        }
        int s=0,l=k.size()-1;
        while(s<l){
            if(k[s]!=k[l]){
                return false;
            }
            else{
                s++;l--;
            }
        }
        return true;
    }
};