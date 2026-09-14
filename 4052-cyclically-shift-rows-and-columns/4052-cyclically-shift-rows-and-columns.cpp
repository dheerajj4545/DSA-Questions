class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>ans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int newC=(j-rowShift[i]+n)%n;
                int newR=(i-colShift[newC]+n)%n;
                ans[newR][newC]=grid[i][j];
            }
        }
        return ans;
    }
};