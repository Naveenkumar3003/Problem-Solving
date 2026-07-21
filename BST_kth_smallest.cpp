class Solution {
  public:
    int ans=-1;
    int cnt=0;
    void inorder(Node* root,int k){
        if(!root || cnt>=k) return;
        inorder(root->left,k);
        cnt++;
        if(cnt==k) {
            ans=root->data;
            return;
        }
        inorder(root->right,k);
    }
    int kthSmallest(Node *root, int k) {
        // code here
        inorder(root,k);
        return ans;
    }
};
