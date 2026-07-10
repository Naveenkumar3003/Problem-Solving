void helper(Node* root,vector<int> &arr){
    if(root==nullptr){
        return ;
    }
    helper(root->left,arr);
    helper(root->right,arr);
    arr.push_back(root->data);
}

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> arr;
        helper(root,arr);
        return arr;
    }
};
