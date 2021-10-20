//%41 speed
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
    bool hasPathSum(TreeNode* root, int sum) {
        return recur(root, 0, sum);
    }
    bool recur(TreeNode* root, int sum, int target) {
                //base cases
        if (!root) {
            //if ()
            return false;
        }
        if (!root->left and !root->right) {
            if ((root->val + sum) == target){
                return true;
            }  else {
                return false;
            }
        }
        //traverse the tree
        bool left=false,right=false;
        if (root->left) {
            left=recur(root->left, sum+ root->val, target);
        }
        if (root->right) {
            right=recur(root->right, sum + root->val, target);
        }
        //return results in OR
        return left || right;
    }
};
