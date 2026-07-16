/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */
bool isLeaf(Node* root){
    if(!root->left && !root->right) return true;
    else return false;
}
void addLeft(Node* root,vector<int> &res){
    Node* cur=root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
}

void addLeaves(Node* root,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}
void addRight(Node* root, vector<int> &res){
    Node* cur=root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)){
            temp.push_back(cur->data);
        }
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeft(root,res);
        addLeaves(root,res);
        addRight(root,res);
        return res;
    }
};
