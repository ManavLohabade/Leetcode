// Product of the Last K numbers

class ProductOfNumbers {
    public:
        vector<int> prefix;
    
        // Constructor: Initializes the prefix product vector with 1.
        ProductOfNumbers() {
            prefix.push_back(1);    
        }
        
        // Adds a number to the stream.
        void add(int num) {
            if (num == 0) {
                // Reset the prefix product list if the number is 0.
                prefix.clear();
                prefix.push_back(1);
            } else {
                // Append the product of num and the last element in prefix.
                prefix.push_back(num * prefix.back());
            }
        }
        
        // Returns the product of the last k numbers.
        int getProduct(int k) {
            int n = prefix.size();
            
            // If k is greater than or equal to the number of elements in prefix,
            // it means the range includes a zero, so the product is 0.
            if (k >= n) {
                return 0;
            }
            
            // The product of the last k numbers is the ratio of the cumulative products.
            return prefix.back() / prefix[n - 1 - k];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */