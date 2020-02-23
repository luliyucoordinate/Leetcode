class Cashier 
{
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) 
    {
        for (int i = 0; i < products.size(); i++) price[products[i]] = prices[i];
        this->n = n, this->discount = discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) 
    {
        this->cnt++;
        double total = 0;
        
        for (int i = 0; i < product.size(); i++) total += price[product[i]] * amount[i];
        return cnt % n ? total : total * (1 - discount/100.0);
    }
private:
    int n, discount, cnt = 0;  
    unordered_map<int, int> price;
};