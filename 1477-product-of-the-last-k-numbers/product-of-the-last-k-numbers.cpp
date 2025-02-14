class ProductOfNumbers {
public:
    vector<int>s{1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num)
        s.push_back(s.back()*num);
        else
            s={1};
    }
    
    int getProduct(int k) {
        int n=s.size();
        return k<n?s[n-1]/s[n-k-1]:0;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */