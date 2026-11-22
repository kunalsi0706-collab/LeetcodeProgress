class Solution {
public:
    bool checkString(string s) {
        int a_ind = -1 ;
        int b_ind = s.size() ;
        for(int i = 0 ;  i < s.size() ; i++){
            if(s[i] == 'a') a_ind = max(a_ind , i) ;
            else b_ind = min(b_ind , i) ;
        }
        return b_ind > a_ind ;
    }
};