#include <iostream>
using namespace std;

void rodCutting(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);
    vector<int> firstCut(n + 1, 0); // store first cut length

    // Build DP
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[i] < price[j] + dp[i - j - 1]) {
                dp[i] = price[j] + dp[i - j - 1];
                firstCut[i] = j + 1;
            }
        }
    }

    // Output max profit
    cout << "Maximum profit: " << dp[n] << endl;

    // Recover cuts
    cout << "Cuts: ";
    while (n > 0) {
        cout << firstCut[n] << " ";
        n -= firstCut[n];
    }
    cout << endl;
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;

    rodCutting(price, n);

    return 0;
}