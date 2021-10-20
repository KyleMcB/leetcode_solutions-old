//%89 speed
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int left, right;
        if (root->left) {
            left=rangeSumBST(root->left, L, R);
        } else {
            left=0;
        }
        if (root->right) {
            right=rangeSumBST(root->right, L, R);
        } else {
            right=0;
        }
        if (root->val <= R && root->val >= L) {
            return root->val + left + right;
        }
        return left + right;
    }
};
