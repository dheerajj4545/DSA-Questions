class Solution {
public:
    long long dfs(int row,int col,int n,int m,vector<vector<int>>&vis,vector<vector<int>>& grid){
        vis[row][col]=1;
        long long sum=grid[row][col];
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=row+dx[i];
            int nc=col+dy[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&!vis[nr][nc]&&grid[nr][nc]>0){
                sum+=dfs(nr,nc,n,m,vis,grid);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0&&!vis[i][j]){
                    long long sum=dfs(i,j,n,m,vis,grid);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};