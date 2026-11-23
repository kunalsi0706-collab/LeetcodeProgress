class Solution {
public:
    int reverse(int x) {
        if (x < 0) {
            string s = to_string(-(long long)x);
            std::reverse(s.begin(), s.end());
            long long ans = -stoll(s);
            if (ans < INT_MIN) return 0;
            return ans;
        } else {
            string s = to_string(x);
            std::reverse(s.begin(), s.end());
            long long ans = stoll(s);
            if (ans > INT_MAX) return 0;
            return ans;
        }
    }
};