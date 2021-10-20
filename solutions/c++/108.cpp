//%98 speed
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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        if (nums.size()==1){
            return new TreeNode(nums[0]);
        }
        int middleindex=(nums.size()-1)/2;
        TreeNode * root=new TreeNode(nums[middleindex]);
        root->left=sortedArrayToBST(vector<int>(nums.begin(),nums.begin()+middleindex));
        root->right=sortedArrayToBST(vector<int>(nums.begin()+middleindex+1,nums.end()));
        return root;
    }
};
