class Solution {
public:
    int max_area = 0;
    int area = 0;
    int rows, cols;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0)return 0;
        rows = grid.size();
        cols = grid[0].size();
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1){
                    area = 0;
                    findArea(grid, row, col, area);
                    if(area > max_area)max_area = area;
                }
            }
        }
        return max_area;
    }
    void findArea(vector<vector<int>>& grid, int row, int col, int& area){
        if(row < 0 || col < 0 || row >= rows || col >= cols)return;
        
        if(grid[row][col] == 0)return;
        grid[row][col] =0;
        area++;
        // traverse in all directions and calculate area
        findArea(grid, row+1, col, area);
        findArea(grid, row-1, col, area);
        findArea(grid, row, col+1, area);
        findArea(grid, row, col-1, area);
    }
};