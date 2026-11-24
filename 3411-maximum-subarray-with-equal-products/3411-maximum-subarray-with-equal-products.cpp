class Solution {
public:
    int maxLength(vector<int>& nums) {
        
        int length = 2 ;
        for(int i = 0 ; i < nums.size() ; i++){
            long long product = 1 ;
            long long LCM = 1 ;
            long long HCF = 0 ;
            
            for(int j = i ; j < nums.size() ; j++){
                product *= nums[j] ;
                LCM = lcm(LCM , (long long)nums[j]) ;
                HCF = gcd(HCF , (long long)nums[j]) ;

                if(product == LCM * HCF) length = max(length , j - i + 1) ;
                else if(product > LCM * HCF) break ;
            }
        }
        return length ;
    }
};