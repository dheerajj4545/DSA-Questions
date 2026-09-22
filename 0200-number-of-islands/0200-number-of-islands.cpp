class Solution {
public:
    void dfs(int r,int c,int n,int m,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[r][c]=1;
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nR=r+delrow[i];
            int nC=c+delcol[i];
            if(nR>=0&&nR<n&&nC>=0&&nC<m&&!vis[nR][nC]&&grid[nR][nC]=='1'){
                vis[nR][nC]=1;
                dfs(nR,nC,n,m,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,n,m,vis,grid);
                }
            }
        }
        return cnt;
    }
};