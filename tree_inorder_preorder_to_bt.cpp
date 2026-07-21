class Solution {
  public:
    Node* buildTree(vector<int> &preorder,int preSt,int preEnd,vector<int> &inorder,
                    int inSt,int inEnd,map<int,int> inmap){
        if(preSt>preEnd || inSt>inEnd) return NULL;
        Node* root=new Node(preorder[preSt]);
        int inroot=inmap[root->data];
        int numLeft=inroot-inSt;
        root->left=buildTree(preorder,preSt+1,preSt+numLeft,inorder,inSt,inroot-1,inmap);
        root->right=buildTree(preorder,preSt+numLeft+1,preEnd,inorder,inroot+1,inEnd,inmap);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        Node* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
};
