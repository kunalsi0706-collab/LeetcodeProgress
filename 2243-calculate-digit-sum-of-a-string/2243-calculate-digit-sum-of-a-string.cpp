
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k) {
            string ans = "";
            int n = 0;
            int cnt = 0;

            for(int i = 0; i < s.length(); i++) {
                n += s[i] - '0';
                cnt++;

                if(cnt == k || i == s.length() - 1) {
                    ans += to_string(n);
                    n = 0;
                    cnt = 0;
                }
            }

            s = ans;
        }

        return s;
    }
};
