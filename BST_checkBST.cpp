class Solution {
  public:
    bool isBST(Node* root, int min,int max){
        if(!root) return true;
        if(root->data >= max || root->data <= min) return false;
        return isBST(root->left,min,root->data) && isBST(root->right,root->data,max);
    }
    bool isBST(Node* root) {
        // code here
        return isBST(root,INT_MIN,INT_MAX);
    }
};
