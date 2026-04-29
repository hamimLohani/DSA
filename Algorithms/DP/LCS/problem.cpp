#include <iostream>
using namespace std;

string LCS(string X, string Y) {
    int n = X.size(), m = Y.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Backtrack to get LCS string
    string lcs = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs += X[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";
    string lcs = LCS(X, Y);

    cout << "LCS: " << lcs << endl;
    cout << "LCS length: " << lcs.length() << endl;

    return 0;
}