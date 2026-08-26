class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Code here
        vector<vector<int>> adj(n);
        for(auto list: pre){
            adj[list[0]].push_back(list[1]);
        }
        
        vector<int> list;
        queue<int> q;
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto node: adj[i]){
                indegree[node]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            list.push_back(top);
            for(int next: adj[top]){
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }
        }
        
        if(list.size()==n) return true;
        return false;
        
    }
};
