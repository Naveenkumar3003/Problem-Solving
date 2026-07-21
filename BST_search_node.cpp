class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        while(root){
            if(root->data==key) return true;
            if(key<root->data) root=root->left;
            else root=root->right;
        }
        return false;
    }
};
