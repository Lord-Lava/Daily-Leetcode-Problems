class Solution {
    void bfs(vector<vector<int>>&heights,int i,int j,vector<vector<int>>&vis,int n,int m){
        queue<pair<int,int>>q;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k =0;k<4;k++){
                int new_x = x+dx[k];
                int new_y = y+dy[k];
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<m 
                   && !vis[new_x][new_y] && heights[new_x][new_y]>=heights[x][y]){
                     vis[new_x][new_y] = 1;
                     q.push({new_x,new_y});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        
        for( int i = 0; i < n; i++ ) {
            for(int j =0;j<m;j++){
                if(i==0 || j==0){
                    if(!pacific[i][j]){
                        bfs(heights,i,j,pacific,n,m);
                    }
                }
                if(i==n-1 || j==m-1){
                    if(!atlantic[i][j]){
                        bfs(heights,i,j,atlantic,n,m);
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(pacific[i][j] ==1 && atlantic[i][j]==1){
                    vector<int>x;
                    x.push_back(i);
                    x.push_back(j);
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};