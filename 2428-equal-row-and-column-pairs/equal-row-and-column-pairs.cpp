class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> freq_row;
        for(auto &row:grid) freq_row[row]++;
        int cnt=0;
        for(int c=0;c<grid.size();c++){
            vector<int> col;
            for(int r=0;r<grid.size();r++){
                col.push_back(grid[r][c]);
            }
            cnt+=freq_row[col];
        }
        return cnt;
    }
};