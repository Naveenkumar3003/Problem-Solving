void helper(Node* root,vector<int> & arr, int level){
    if(root==nullptr) return;
    if(level==arr.size()) arr.push_back(root->data);
    helper(root->left,arr,level+1);
    helper(root->right,arr,level+1);
}
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> arr;
        helper(root,arr,0);
        return arr;
    }
};
