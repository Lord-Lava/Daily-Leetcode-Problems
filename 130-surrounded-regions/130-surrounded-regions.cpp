class Solution {
public:
    void bfs(vector<vector<char>>&board,int n,int m,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        board[i][j] = 'Y';
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            board[x][y] = 'Y';
            int dx[] = {0,0,-1,1};
            int dy[] = {-1,1,0,0};
            for(int k =0;k<4;k++){
                int new_x = x+dx[k];
                int new_y = y+dy[k];
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && board[new_x][new_y] == 'O'){
                    q.push({new_x,new_y});
                    board[new_x][new_y] = 'Y';
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j] == 'O'){
                    bfs(board,n,m,i,j);
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'Y') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};