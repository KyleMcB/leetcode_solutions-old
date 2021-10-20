//%62 speed. I have a lot of solutions for this one. Just going to post one.
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
    bool first=true;
    int lastnode;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        TreeNode * cur= root;
        stack<TreeNode*> s;
        while (cur->left != nullptr) {
            s.push(cur);
            cur=cur->left;
        }
        s.push(cur);
        while (!s.empty()) {
            cur=s.top();
            s.pop();
            if (first) {
                lastnode=cur->val;
                first=false;
            } else {
              //  cout << lastnode << " " << cur->val << endl;
                if (lastnode >= cur->val) {
                    return false;
                }
                lastnode=cur->val;
            }

            if (cur->right) {
                cur=cur->right;
                while (cur) {
                    s.push(cur);
                    cur=cur->left;
                }
            }
        }
        return true;
    }
};
