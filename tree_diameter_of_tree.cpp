class Solution {
  public:
    int hieght(Node* root, int &diam){
        if(!root) return 0;
        int lh=hieght(root->left,diam);
        int rh=hieght(root->right,diam);
        diam=max(diam,lh+rh);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
        // code here
        int diam=0;
        hieght(root,diam);
        return diam;
    }
};
