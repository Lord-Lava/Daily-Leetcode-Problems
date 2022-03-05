class Solution {
public:
    void bfs(vector<vector<int>>& grid,int n,int m,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k =0;k<4;k++){
                int n_x = x+dx[k];
                int n_y = y+dy[k];
                if(n_x>=0 && n_x<n && n_y>=0 && n_y<m && grid[n_x][n_y]==1){
                    grid[n_x][n_y] = 0;
                    q.push({n_x,n_y});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans=0;
        
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 || i == n-1|| j == 0 || j == m-1){
                    if(grid[i][j] == 1){
                        bfs(grid,n,m,i,j);
                    }
                }
            }
        }
        
        for(auto it:grid){
            for(auto i:it){
                if(i==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};