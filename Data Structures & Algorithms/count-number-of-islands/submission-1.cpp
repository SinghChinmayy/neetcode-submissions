class Solution {
public:
    int rows, cols;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size(), 
        cols = grid[0].size();
        int  islands = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] - '0' == 1){
                    islands++;
                    traceIsland(grid, i, j);
                }
            }
        }
        return islands;
    }
    // check four sides and itteratively make 1 to zero
    void traceIsland(vector<vector<char>>& grid, int x, int y){
        // check out of bound
        if( x < 0 || x >= rows || y < 0 || y >= cols){
            return;
        }
        // when 0 encountered
        if(grid[x][y] -'0' == 0) return;

        // when 1 encountered
        if(grid[x][y] - '0' == 1){
            // current to 0
            grid[x][y] = 0;
            // go right 
            traceIsland(grid, x+1, y);
            // go left
            traceIsland(grid, x, y-1);
            // go down
            traceIsland(grid, x, y+1);
            // go up
            traceIsland(grid, x-1, y);
        }
    }
};
