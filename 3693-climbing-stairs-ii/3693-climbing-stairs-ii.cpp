
class Solution {
public:
    vector<int> memo;

    int solve(int i, int n, vector<int>& costs) {

        if (i == n) return 0;

        if (memo[i] != -1)
            return memo[i];

        int cost = INT_MAX;

        for (int jump = 1; jump <= 3; jump++) {

            int j = i + jump;

            if (j <= n) {

                int curr = solve(j, n, costs)
                         + costs[j - 1]
                         + (j - i) * (j - i);

                cost = min(cost, curr);
            }
        }

        return memo[i] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {

        memo.assign(n + 1, -1);

        return solve(0, n, costs);
    }
};
