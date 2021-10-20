//0ms runtime
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
    bool isSymmetric(TreeNode* root) {
        return ismirror(root, root);
    }
    bool ismirror(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        }
        if (!a ^ !b) {
            return false;
        }
        return (a->val == b->val) && ismirror(a->left, b->right) && ismirror(b->left, a->right);
    }
};

//8ms runtime
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else if (!root->left xor !root->right) {
            return false;
        }else if (!root->left and !root->right) {
            return true;
        }
        stack<TreeNode*> ls, rs;
        ls.push(root->left);
        rs.push(root->right);
        while(!ls.empty() and !rs.empty()) {
            TreeNode* left=ls.top();
            TreeNode* right=rs.top();
            ls.pop(); rs.pop();
            if (!eq(left,right)) {
                return false;
            }
            if (!left and !right){
                continue;
            }
            ls.push(left->left);
            ls.push(left->right);
            rs.push(right->right);
            rs.push(right->left);
        }
        return true;
    }
    bool eq(TreeNode* a, TreeNode* b) {
        if (!a and !b) {
            return true;
        }
        if (!a xor !b) {
            return false;
        }
        return a->val == b->val;
    }

};
