class Solution {
    void bfs(vector<vector<char>>&grid,int n,int m,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = '0';
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            grid[x][y] = '0';
            q.pop();
            for(int k = 0;k<4;k++){
                int new_x = x+dx[k];
                int new_y = y+dy[k];
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]=='1'){
                    q.push({new_x,new_y});
                    grid[new_x][new_y] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    bfs(grid,n,m,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};