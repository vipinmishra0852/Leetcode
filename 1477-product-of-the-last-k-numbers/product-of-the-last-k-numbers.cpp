class ProductOfNumbers {
public:
vector<int>v;
vector<int>prefix;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
       v.push_back(num); 
    }
    
    int getProduct(int k) {
        prefix.resize(v.size(),0);
        prefix[v.size()-1] = v[v.size() - 1];
       for(int i = v.size() - 2 ; i >= 0 ; i--)
       {
       prefix[i] = prefix[i+1] * v[i];
       } 
       return prefix[v.size() - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */