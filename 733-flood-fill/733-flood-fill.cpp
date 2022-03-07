class Solution {
public:
    void bfs(vector<vector<int>>& image, int color, int newColor,int i,int j,int n,int m,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = 1;
        image[i][j] = newColor;
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int new_x = x+dx[k];
                int new_y = y+dy[k];
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && !vis[new_x][new_y] && image[new_x][new_y] == color){
                    image[new_x][new_y] = newColor;
                    q.push({new_x,new_y});
                    vis[new_x][new_y] = 1;
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        
        bfs(image,image[sr][sc],newColor,sr,sc,n,m,vis);
        
        return image;
    }
};