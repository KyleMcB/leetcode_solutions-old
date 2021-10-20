//%30 speed
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root){
            return {};
        }
        set<TreeNode*> unfinished, finished;
        vector<TreeNode*> nstack;
        vector<int> istack;
        vector<vector<int>> ans;
        nstack.push_back(root);
        istack.push_back(root->val);
        while (!nstack.empty()) {
            TreeNode* node = nstack.back();
            if (node->left and unfinished.count(node) == 0) {
                nstack.push_back(node->left);
                istack.push_back(node->left->val);
                unfinished.insert(node);
                continue;
            } else {
                unfinished.insert(node);
            }
            if (node->right and finished.count(node)==0) {
                nstack.push_back(node->right);
                istack.push_back(node->right->val);
                finished.insert(node);
                continue;
            } else {
                finished.insert(node);
            }
            if (!node->left and !node->right) {
                int total= accumulate(istack.begin(),istack.end(),0);
                if (total == sum) {
                    ans.push_back(istack);
                }
            }
            istack.pop_back();
            nstack.pop_back();

        }

        return ans;
    }
};
