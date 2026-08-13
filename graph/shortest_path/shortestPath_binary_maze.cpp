class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        // If source or destination already blocked
        if (mat[src[0]][src[1]] == 0 ||
            mat[dest[0]][dest[1]] == 0) {
            return -1;
        }
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src[0],src[1]}});
        dis[src[0]][src[1]]=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            auto [r,c]=top.second;
            int dist=top.first;
            if(r==dest[0] && c==dest[1]){
                return dist;
            }
            for(int i=0;i<4;i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1 
                   && dist+1<dis[nr][nc]){
                    dis[nr][nc]=dist+1;
                    q.push({dist+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};
