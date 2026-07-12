class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(root==nullptr) return ans;
        unordered_map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int minhd=0,maxhd=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            Node* node=front.first;
            int hd=front.second;
            mp[hd]=node->data;
            minhd=min(minhd,hd);
            maxhd=max(maxhd,hd);
            if(node->left) q.push({node->left,hd-1});
            if(node->right) q.push({node->right,hd+1});
        }
        for(int i=minhd;i<=maxhd;i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
