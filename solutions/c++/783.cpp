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
    int lastnode=INT_MAX, currentnode=-1;
public:

    int minDiffInBST(TreeNode* root) {
        int leftres=INT_MAX, rightres=INT_MAX, currentres=INT_MAX;
        //go left
        if (root->left) leftres= minDiffInBST(root->left);

        //operate current node
        //if (lastnode ==-1) {
       //     lastnode = root->val;
        //    return INT_MAX;
        //}
        currentres= abs(lastnode - root->val);
        lastnode=root->val;

        //go right
        if (root->right) rightres= minDiffInBST(root->right);
        return min(leftres, min(rightres,currentres));
    }
};
