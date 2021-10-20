//%95 speed
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        int length=listlength(head);
        if (length == 1) {
            return new TreeNode(head->val);
        }
        ListNode* mid = midelement(head);
        ListNode* temp=head;
        while (temp->next != mid) {
            temp=temp->next;
        }
        temp->next=nullptr;
        TreeNode* root=new TreeNode(mid->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        //cout << mid->val;
        return root;
    }
    ListNode* midelement(ListNode * head) {
        ListNode * slow, * fast;
        slow=head;
        fast=head->next;
        while (fast) {
            slow=slow->next;
            if (!fast->next) {
                break;
            }
            fast=fast->next->next;
        }
        return slow;
    }
    int extract(ListNode*& head, int index) {
        //we are indexing off 1
        if (index == 1) {
            int val=head->val;
            head=head->next;
            return val;
        }
        ListNode* cur=head;
        for (int i=1; i<index-1;i++) {
            cur=cur->next;
        }
        //cur should be the item before the one we want now
        int val=cur->next->val;
        cur->next=cur->next->next;
        return val;
    }
    TreeNode* insert(TreeNode* root, TreeNode* node) {
        if (root == nullptr) {
            //cout << "made root\n";
            return node;
        }
        //cout << node->val << " ";
        //cout << root->val;
        if (node->val >= root->val) {
            root->right=insert(root->right, node);
            return root;
        } else {
            root->left=insert(root->left, node);
            return root;
        }

    }
    int listlength(ListNode* head) {
        int sum=0;
        while (head) {
            sum++;
            head=head->next;
        }
        return sum;
    }
};
