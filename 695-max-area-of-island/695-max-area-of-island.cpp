class Solution {
public:
    int bfs(vector<vector<int>>&grid,int n,int m,int i,int j){
        int area = 1;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = 0;
        while(!q.empty()){
            pair<int,int>node = q.front();
            q.pop();
            grid[node.first][node.second] = 0;
            for(int k=0;k<4;k++){
                int x = node.first+dx[k];
                int y = node.second+dy[k];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1){
                    grid[x][y] = 0;
                    q.push({x,y});
                    area++;
                }
            }
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]!=0){
                    area = max(area,bfs(grid,n,m,i,j));
                }
            }
        }
        return area;
    }
};