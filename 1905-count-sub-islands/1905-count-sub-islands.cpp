class Solution {
public:
    void bfs(vector<vector<int>>& grid1,int n,int m,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid1[i][j] = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k =0;k<4;k++){
                int new_x = x + dx[k];
                int new_y = y + dy[k];
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<m && grid1[new_x][new_y] == 1){ 
                    grid1[new_x][new_y] = 0;
                    q.push({new_x,new_y});
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid2, vector<vector<int>>& grid1) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid1[i][j] == 1 && grid2[i][j] == 0){
                    bfs(grid1,n,m,i,j);
                }
            }
        }
        
        int ans = 0;
        
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid1[i][j] == 1){
                    bfs(grid1,n,m,i,j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};