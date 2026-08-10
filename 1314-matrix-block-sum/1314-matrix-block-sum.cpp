class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>prefix(m,vector<int>(n+1,0));
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefix[i][j+1]=prefix[i][j]+mat[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r1=max(0,i-k);
                int r2=min(m-1,i+k);
                int c1=max(0,j-k);
                int c2=min(n-1,j+k);
                int sum = 0;
                for(int r=r1;r<=r2;r++){
                    sum+=prefix[r][c2+1]-prefix[r][c1];
                }
                ans[i][j]=sum;
            }
        }
        return ans;

    }
};