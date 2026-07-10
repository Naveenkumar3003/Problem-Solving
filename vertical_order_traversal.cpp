class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            Node* node=front.first;
            int col=front.second;
            mp[col].push_back(node->data);
            if(node->left){
                q.push({node->left,col-1});
            }
            if(node->right){
                q.push({node->right,col+1});
            }
        }
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
