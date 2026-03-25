class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        long long total = 0;  // 🔥 FIX

        for(auto &row : grid)
            for(int x : row)
                total += x;

        if(total % 2 != 0) return false;

        long long target = total / 2;

        // Horizontal
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
            if(sum == target) return true;
        }

        // Vertical
        sum = 0;
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                sum += grid[i][j];
            }
            if(sum == target) return true;
        }

        return false;
    }
};