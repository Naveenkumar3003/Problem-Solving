void helper(Node* root, vector<int> &arr,int level){
    if(root==nullptr) return;
    if(arr.size()==level) arr.push_back(root->data);
    helper(root->right,arr,level+1);
    helper(root->left,arr,level+1);
}
class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> arr;
        helper(root,arr,0);
        return arr;
    }
};
