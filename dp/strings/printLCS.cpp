#include <bits/stdc++.h>
using namespace std;

string printLCS(string &text1, string &text2) {
    int m = text1.size(), n = text2.size();

    // Step 1: build the full dp table (same as standard LCS tabulation)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 2: backtrack from dp[m][n] to reconstruct the string
    int i = m, j = n;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            // this character is part of the LCS
            lcs += text1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;   // this cell's value came from above → move up
        }
        else {
            j--;   // this cell's value came from the left → move left
        }
    }

    // Step 3: we built the string backward, so reverse it
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";

    cout << "LCS: " << printLCS(text1, text2) << "\n";   // "ace"
    return 0;
}
