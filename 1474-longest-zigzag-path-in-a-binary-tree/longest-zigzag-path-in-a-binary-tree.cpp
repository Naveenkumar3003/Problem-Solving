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
    int longestZigZag(TreeNode* root) {
        int maxi = 0;   
        dfs(root, true, 0, maxi);
        dfs(root, false, 0, maxi);
        return maxi;
    }

    void dfs(TreeNode* root, bool isLeft, int step, int &maxi) {
        if (!root) return;

        maxi = max(maxi, step);

        if (isLeft) {
            dfs(root->left, false, step + 1, maxi);
            dfs(root->right, true, 1, maxi);   
        } 
        else {
            dfs(root->left, false, 1, maxi);    
            dfs(root->right, true, step + 1, maxi);
        }
    }
};
