class ProductOfNumbers {
public:
    vector<int> prefix ;
    ProductOfNumbers() {
        prefix = {1} ;
    }
    
    void add(int num) {
        if(num == 0) prefix = {1} ;
        else{
            prefix.push_back(num * prefix.back()) ;
        } 
    }
    
    int getProduct(int k) {
        int n = prefix.size() ;
        if(n > k) return prefix.back()/prefix[n - k - 1] ;
        else return 0 ;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */