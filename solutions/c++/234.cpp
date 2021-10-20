//%92 speed
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* midpoint(ListNode* node) {
        ListNode* slow=node,*fast=node;
        while (fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* node) {
        if (!node) return nullptr;
        ListNode* prev=nullptr, *cur=node, *next=cur->next;
        while (cur->next) {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        cur->next=prev;
        return cur;
    }
    void printlist(ListNode* node) {
        while (node) {
            cout << node->val << " ";
            node=node->next;
        }
        cout << endl;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* first=head, *second=reverse(midpoint(head));
        while (second) {
            if (first->val != second->val) {
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
    }
};
