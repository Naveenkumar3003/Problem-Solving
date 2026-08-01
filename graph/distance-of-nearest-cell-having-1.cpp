class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> q;

        // Push all 1's into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()) {

            auto [r,c] = q.front().first;
            int dist = q.front().second;
            q.pop();

            ans[r][c] = dist;

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }

        return ans;
    }
};
