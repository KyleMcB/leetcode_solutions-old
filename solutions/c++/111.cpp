//%6 speed
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
        int dist;
    };
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<item> q;
        set<TreeNode*> visited;
        q.push({root,1});
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (!node->left and !node->right) {
                return dist;
            }
            if (node->left) {
                q.push({node->left, dist+1});
            }
            if (node->right) {
                q.push({node->right, dist+1});
            }
        }
        return -1;
    }
};
