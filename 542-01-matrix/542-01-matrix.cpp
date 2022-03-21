class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>>q;
        
        vector<vector<int>>dist(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        int level = 0;
        while(!q.empty()){
            level++;
            int sz = q.size();
            for(int j =0;j<sz;j++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int new_x = x+dx[i];
                    int new_y = y+dy[i];
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && dist[new_x][new_y]==-1){
                      dist[new_x][new_y]=level;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
        
        return dist;
    }
};