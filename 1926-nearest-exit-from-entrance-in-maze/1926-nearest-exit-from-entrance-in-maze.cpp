class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int xx = entrance[0];
        int yy = entrance[1];
        
        int n = maze.size();
        int m = maze[0].size();
        
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        distance[xx][yy] = 0;
        
        queue<pair<int,int>>q;
        q.push({xx,yy});
        visited[xx][yy] = 1;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int new_x = x+dx[k];
                int new_y = y+dy[k];
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<m && !visited[new_x][new_y] && maze[new_x][new_y] == '.'){
                    distance[new_x][new_y] = min(distance[new_x][new_y],distance[x][y]+1);
                    q.push({new_x,new_y});
                    visited[new_x][new_y] = 1;
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j =0;j<m;j++){
        //         cout<<distance[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int mini = INT_MAX;
        
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(a==0 || a==n-1 || b==0 || b==m-1){
                    // cout<<a<<" "<<b<<" "<<xx<<" "<<yy<<" "<<distance[a][b]<<" "<<mini<<"\n";
                    if(distance[a][b]<mini){
                        if(a==xx && b==yy){
                            
                        }else
                            mini = distance[a][b];
                    }
                }
            }
        }
        
        if(mini == INT_MAX)return -1;
        
        return mini;
    }
};