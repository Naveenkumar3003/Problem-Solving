class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int top=0;
        int bottom=n-1;
        while(top<bottom){
            if(mat[top][bottom]==1) top++;
            else bottom--;
        }
        int candidate=top;
        for(int i=0;i<n;i++){
            if(i==candidate) continue;
            // Everyone should know candidate
            if(!mat[i][candidate]) return -1;
            // Candidate should know nobody
            if(mat[candidate][i]) return -1;
        }
        return candidate;
    }
};
