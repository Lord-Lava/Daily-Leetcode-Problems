class Solution {
public:
    void bfs(vector<vector<int>>& grid,int n,int m,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = 1;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0;k<4;k++){
                int new_x = x+dx[k];
                int new_y = y+dy[k];
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y] == 0){
                    grid[new_x][new_y] = 1;
                    q.push({new_x,new_y});
                }
            }
        }
    }
        
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j] == 0)
                        bfs(grid,n,m,i,j);
                }   
            }
        }
        
        int ctr=0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0){
                    bfs(grid,n,m,i,j);
                    ctr++;
                }
            }
        }
        
        return ctr;
    }
};