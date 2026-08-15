class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>
        > pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int effort=top.first;
            auto [r,c]=top.second;
            
            if(r==n-1 && c==m-1) return effort;
            if(effort > dist[r][c]) continue;
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int currEffort=abs(mat[r][c]-mat[nr][nc]);
                    int newEffort=max(effort,currEffort);
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};
