class Solution {
public:
    void solve(int row,int col, vector<vector<int>>& image, int sr, int sc,int srcColor, int newColor){
        if(sr<0 || sc<0 || sr>=row || sc>=col || image[sr][sc] == newColor || image[sr][sc] != srcColor){
            return;
        }
        
        if(image[sr][sc] == srcColor){
            image[sr][sc] = newColor;
        }
        
        solve(row,col,image,sr+1,sc,srcColor,newColor);
        solve(row,col,image,sr,sc+1,srcColor,newColor);
        solve(row,col,image,sr-1,sc,srcColor,newColor);
        solve(row,col,image,sr,sc-1,srcColor,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int col = image[0].size();
        int row = image.size();
        
        solve(row,col,image,sr,sc,image[sr][sc],newColor);
        
        return image;
    }
};