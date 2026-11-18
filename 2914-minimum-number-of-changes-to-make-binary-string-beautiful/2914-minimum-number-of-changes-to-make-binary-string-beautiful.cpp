class Solution {
public:
    int minChanges(string s) {
        if(s.size() == 2){
            if(s[0] == s[1]) return 0 ;
            else return 1 ;
        }
        int cnt = 0;
        for(int i = 0 ; i < s.size() - 1 ; i += 2){
            if(s[i] != s[i+1]) cnt++ ;
        }
        return cnt ;
    }
};