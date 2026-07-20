class Solution {
public:
    void rev(int i,int j,vector<vector<int>>& grid,int row,int col){
        while(i<j){
            swap(grid[i/col][i%col],grid[j/col][j%col]);
            i++;
            j--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        int n=row*col;
        k=k%n;
        if(k == 0) return grid;
        rev(0,n-1,grid,row,col);
        rev(0,k-1,grid,row,col);
        rev(k,n-1,grid,row,col);
        return grid;
    }
};