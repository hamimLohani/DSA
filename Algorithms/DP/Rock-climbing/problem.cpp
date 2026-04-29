#include <iostream>
using namespace std;

int rockClimbing(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp = grid;

    // Build DP from 2nd row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = dp[i-1][j];
            int leftDiag = (j > 0) ? dp[i-1][j-1] : 0;
            int rightDiag = (j < m-1) ? dp[i-1][j+1] : 0;

            dp[i][j] += max({up, leftDiag, rightDiag});
        }
    }

    // Find max in last row
    return *max_element(dp[n-1].begin(), dp[n-1].end());
}

int main() {
    vector<vector<int>> grid = {
        {3, 1, 7, 4, 2},
        {2, 1, 3, 1, 1},
        {1, 2, 2, 1, 8},
        {2, 2, 1, 5, 3}
    };

    cout << "Maximum points: " << rockClimbing(grid) << endl;

    return 0;
}