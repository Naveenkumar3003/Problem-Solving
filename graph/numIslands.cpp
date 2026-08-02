// class Solution {
//     void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
//         vis[row][col] = 1;
//         queue<pair<int, int>> q;
//         q.push({row, col});
//         int n = grid.size();
//         int m = grid[0].size();

//         int drow[] = {-1, 0, 1, 0};
//         int dcol[] = {0, 1, 0, -1};

//         while (!q.empty()) {
//             int r = q.front().first;
//             int c = q.front().second;
//             q.pop();

//             for (int i = 0; i < 4; i++) {
//                 int nrow = r + drow[i];
//                 int ncol = c + dcol[i];

//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
//                     grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
//                     vis[nrow][ncol] = 1;
//                     q.push({nrow, ncol});
//                 }
//             }
//         }
//     }

// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int cnt = 0;
//         vector<vector<int>> vis(n, vector<int>(m, 0));

//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < m; col++) {
//                 if (!vis[row][col] && grid[row][col] == '1') {
//                     cnt++;
//                     bfs(row, col, vis, grid);
//                 }
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[row][col] = 1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr=row+dr[k];
            int nc=col+dc[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' && !vis[nr][nc]) 
                dfs(nr,nc,vis,grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};
