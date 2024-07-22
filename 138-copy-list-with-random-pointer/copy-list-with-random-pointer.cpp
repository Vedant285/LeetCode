class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
        temp = head;
        while (temp) {
            Node* copy = temp->next;
            if(temp->random)copy->random = temp->random->next;
            else copy->random = NULL;
            temp = temp->next->next;
        }
        Node* ans = new Node(-1);
        Node* dummy = ans; 
        temp = head;
        while (temp) {
            dummy->next = temp->next;
            dummy = dummy->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return ans->next;
    }
};