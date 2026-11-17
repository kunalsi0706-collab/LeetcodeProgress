
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // cost[i][j] = minimum changes to make s[i...j]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int mini = n;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0) continue;

                    int changes = 0;

                    // Check each group
                    for (int offset = 0; offset < d; offset++) {

                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        while (l < r) {
                            if (s[l] != s[r])
                                changes++;

                            l += d;
                            r -= d;
                        }
                    }

                    mini = min(mini, changes);
                }

                cost[i][j] = mini;
            }
        }

        // dp[i][parts] = minimum changes to divide
        // first i characters into exactly parts pieces
        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, 1e9));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {

            for (int i = 2 * parts; i <= n; i++) {

                for (int j = 2 * (parts - 1);
                     j < i - 1; j++) {

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[j][parts - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
