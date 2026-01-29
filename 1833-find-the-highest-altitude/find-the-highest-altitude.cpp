class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int alt=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            alt=alt+gain[i];
            maxi=max(maxi,alt);
        }
        return maxi;
    }
};