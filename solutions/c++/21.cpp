//98% speed
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 and !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* root=nullptr;
        if (l2->val < l1->val) {
            root=l2;
            l2=l2->next;
            root->next=nullptr;
        } else {
            root=l1;
            l1=l1->next;
            root->next=nullptr;
        }
        ListNode* ans=root;
        while (l1 && l2) {
            if (l2->val < l1->val) {
                root->next=l2;
                l2=l2->next;
                root=root->next;
            } else {
                root->next=l1;
                l1=l1->next;
                root=root->next;
            }
        }
        if (l1) {
            root->next=l1;
        } else if (l2) {
            root->next=l2;
        } else {
            root->next=nullptr;
        }
        return ans;
    }
};
