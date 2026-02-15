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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix_sums;
        prefix_sums[0] = 1;
        return dfs(root, 0, targetSum, prefix_sums);
    }
private:
    int dfs(TreeNode* root,long long current_sum,int target,
        unordered_map<long long,int> prefixSum){
        if(!root) return 0;
        current_sum+=root->val;
        int cnt=prefixSum[current_sum-target];
        prefixSum[current_sum]++;

        cnt+=dfs(root->left,current_sum,target,prefixSum);
        cnt+=dfs(root->right,current_sum,target,prefixSum);
        prefixSum[current_sum]--;
        return cnt;
    }
};