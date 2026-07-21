
class Solution {
  public:
    Node* build(vector<int>& pre,int &i,int ub){
        if(i==pre.size() || pre[i]>ub) return nullptr;
        Node* root=new Node(pre[i++]);
        root->left=build(pre,i,root->data);
        root->right=build(pre,i,ub);
        return root;
    }
    Node* preToBST(vector<int>& pre) {
        // code here
        int i=0;
        return build(pre,i,INT_MAX);
    }
};
