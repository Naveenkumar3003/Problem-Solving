class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int minutes=0;

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        while(!q.empty()){
            int size=q.size();
            bool rotten=false;
            while(size--){
                auto [r,c] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];

                    if(nr>=0 && nr<n &&
                        nc>=0 && nc<m &&
                        grid[nr][nc]==1){
                            grid[nr][nc]=2;
                            rotten=true;
                            q.push({nr,nc});
                            fresh--;
                    }
                }
            }
            if(rotten) minutes++;
        }
        return (fresh==0)?minutes:-1;
    }
};
