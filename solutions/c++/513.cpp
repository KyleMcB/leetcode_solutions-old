//%27 speed
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
    struct ans {
        int val;
        int dist;
    };
public:
    int findBottomLeftValue(TreeNode* root) {
        ans result = recur(root);
        return result.val;
    }
    ans recur(TreeNode* root) {
        if (root == nullptr) {
            return {0,0};
        }
        auto left= recur(root->left);
        auto right= recur(root->right);
        ans max;
        if (right.dist > left.dist) {
            max=right;
        } else {
            max=left;
        }
        if (max.dist == 0) {
            return {root->val, 1};
        } else {
            return {max.val, max.dist+1};
        }
    }
};
