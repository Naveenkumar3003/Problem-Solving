class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            ans.push_back(front->data);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return ans;
    }
};
