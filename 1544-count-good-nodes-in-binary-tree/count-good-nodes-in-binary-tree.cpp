/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
private:
    int helper(TreeNode* root,int maxSoFar){
        if(!root) return 0;
        int cnt=0;
        if(root->val>=maxSoFar) cnt=1;

        maxSoFar=max(root->val,maxSoFar);
        cnt+=helper(root->left,maxSoFar);
        cnt+=helper(root->right,maxSoFar);
        return cnt;
    }
};