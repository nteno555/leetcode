class Solution {
public:
    int n, m;

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        n = grid.size();
        if (n==0) return ans;
        m = grid[0].size();

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }

    int dfs(vector<vector<char>>& arr, int x, int y) {
        if (isValid(arr, x, y)) {
            arr[x][y] = '2';
            dfs(arr, x+1, y);
            dfs(arr, x-1, y);
            dfs(arr, x, y+1);
            dfs(arr, x, y-1);
        }
        return 0;
    }

    bool isValid(vector<vector<char>>& arr, int x, int y) {
        if (!( (x >= 0) && (x < n) && (y >= 0) && (y < m))) return false;

        return (arr[x][y] == '1');
    }
};