void inOrder_helper(Node* root, vector<int> &arr){
    if(root==NULL){
        return ;
    }
    inOrder_helper(root->left,arr);
    arr.push_back(root->data);
    inOrder_helper(root->right,arr);
}

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> arr;
        inOrder_helper(root,arr);
        return arr;
    }
};
