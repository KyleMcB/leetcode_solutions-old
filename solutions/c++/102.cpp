//%93 speed
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
        int level;
    };
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
      queue<item> q;
       vector<vector<int>> ans;
        q.push({root, 0});
      while (!q.empty()) {
          auto cur = q.front(); q.pop();
          if (cur.level >= ans.size()) {
              ans.push_back({});
          }
          ans.at(cur.level).push_back(cur.node->val);
          if (cur.node->left) {
              q.push({cur.node->left, cur.level+1});
          }
          if (cur.node->right) {
              q.push({cur.node->right, cur.level+1});
          }
      }
        return ans;
    }
};
