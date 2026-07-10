void preOrder_helper(Node* root,vector<int> &arr){
    if(root==nullptr){
        return ;
    }
    arr.push_back(root->data);
    preOrder_helper(root->left,arr);
    preOrder_helper(root->right,arr);
}

class Solution {
  public:
    vector<int> preOrder(Node* root) {
       vector<int> arr;
       preOrder_helper(root,arr);
       return arr;
    }
};
