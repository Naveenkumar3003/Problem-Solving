class Solution {
public:
    bool isSameTree(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL) return true;
        if(a==NULL || b==NULL) return false;
        if(a->val!=b->val) return false;
        return isSameTree(a->left,b->left) && isSameTree(a->right,b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        if(root==NULL) return false;
        if(isSameTree(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
