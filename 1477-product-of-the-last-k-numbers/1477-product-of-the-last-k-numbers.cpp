class ProductOfNumbers {
public:
    vector<int> StreamOfNumber;
    vector<int> Product;
    ProductOfNumbers() {
        Product.push_back(1);
    }
    void add(int num) {
        StreamOfNumber.push_back(num);
        if (num == 0) {
            Product.clear();
            Product.push_back(1);
        } else {
            Product.push_back(Product.back() * num);
        }
    }
    int getProduct(int k) {
        int PSize = Product.size();
        if (k >= PSize) {
            return 0; 
        }
        return Product.back() / Product[PSize - k - 1];  
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

 