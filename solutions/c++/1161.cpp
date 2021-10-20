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
    struct item {
        TreeNode* node;
        int depth;
    };
    vector<int> level;
public:
    int maxLevelSum(TreeNode* root) {
        queue<item> q;
        q.push({root,0});
        while (!q.empty()) {
            auto [node, depth]  = q.front();
            q.pop();
            try {
                level.at(depth)+=node->val;
            } catch (out_of_range) {
                level.push_back(0);
                level.at(depth)+=node->val;
            }
            if (node->left) q.push({node->left, depth+1});
            if (node->right) q.push({node->right, depth+1});
        }
        return distance(level.begin(),max_element(level.begin(), level.end()))+1;
    }
};
