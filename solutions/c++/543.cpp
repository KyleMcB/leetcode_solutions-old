//%68 speed
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
    int longest=0;
public:
    int diameterOfBinaryTree(const TreeNode* root) {
        if (!root) return 0;
        if (!root->right and !root->left) return 0;
        //cout << "test1\n";
        recur(root);
        return longest-1;
    }
    int recur(const TreeNode* root) {
        if (!root) return 0;
        int left, right;
        left= recur(root->left);
        right= recur(root->right);
        int templongest = max(left+1, max(right+1, right+left+1));
        if (templongest > longest) longest=templongest;
        return max(left, right)+1;
    }
};
