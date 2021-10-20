//slow runtime
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode(1);
        ListNode* p=head;

        int sum=0,carry=0;
        while (l1 || l2 || carry) {
            if (l1) sum+=l1->val;
            if (l2) sum+=l2->val;
            sum+=carry;
            carry=sum/10;
            p->val=sum%10;
            sum=0;
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
            if (l1 || l2 || carry) {
                p->next= new ListNode(1);
                p=p->next;
            }
        }
        return head;
    }
};
