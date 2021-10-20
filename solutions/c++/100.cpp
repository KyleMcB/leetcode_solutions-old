//4ms runtime (slow, but without percentages comparison)
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!q && !p) {
            return true;
        }
        if (!p != !q) {
            cout << "one" << q << " " << p << "\n";
            return false;
        }
        cout << "vlue:" << p->val << q->val << endl;
        if (p->val != q->val) {
            cout <<"two\n";
            return false;
        }
         if (!isSameTree(q->left, p->left)) {
             cout <<"left\n";
             return false;
         }
        if (!isSameTree(q->right, p->right)) {
            cout << "right\n";
            return false;
        }
        return true;
    }
};
