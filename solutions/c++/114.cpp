//%54 speed
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
    void flatten(TreeNode* root) {
        while (root) {
            if (root->right and root->left){
                TreeNode* pred=root->left;
                while (pred->right){
                    pred=pred->right;
                }
                pred->right=root->right;
            }
            if (root->left)
            root->right=root->left;
            root->left=nullptr;
            root=root->right;
        }
    }

    void predr(TreeNode* root, TreeNode* data) {
        if (!root->left) {
            root->left=data;
            return;
        }
        root=root->left;
        while (root->right) {
            root=root->right;
        }
        root->right=data;
    }

};
