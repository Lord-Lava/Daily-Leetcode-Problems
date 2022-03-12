class Solution {
    void bfs(vector<vector<int>>&grid,int n,int m,bool& flag){
        queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        
        if(q.size() == 0 || q.size() == n*m){
            flag = 1;
            return;
        }
        
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        int dist = 0;
        while(!q.empty()){
            dist++;
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int new_x = x+dx[i];
                    int new_y = y+dy[i];
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]==0){
                        q.push({new_x,new_y});
                        grid[new_x][new_y] = dist;
                    }
                }
            }
        }
    }
    public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        bool flag = 0;
 
        bfs(grid,n,m,flag);
        
        if(flag)return -1;
        
        int ans = INT_MIN;
        
        for(auto it:grid){
            for(auto i:it){
                // cout<<i<<" ";
                ans = max(ans,i);
            }
            // cout<<endl;
        }
        return ans;
    }
};