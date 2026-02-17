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
    int maxLevelSum(TreeNode* root) {
        int maxlevel=0,currlevel=0,maxi=INT_MIN,levelsum=0;
        if(!root) return currlevel;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            currlevel++;
            levelsum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                levelsum+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            if(levelsum>maxi){
                maxi=levelsum;
                maxlevel=currlevel;
            }
        }
        return maxlevel;
    }
};