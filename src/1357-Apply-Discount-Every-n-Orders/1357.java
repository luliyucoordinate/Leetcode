class Cashier {
    private int cnt = 0, n, discount;
    private Map<Integer, Integer> price = new HashMap();
    
    public Cashier(int n, int discount, int[] products, int[] prices) {
        this.n = n;
        this.discount = discount;
        for (int i = 0; i < products.length; ++i)
            price.put(products[i], prices[i]);
    }
    
    public double getBill(int[] product, int[] amount) {
        double total = 0.0;
        
        for (int i = 0; i < product.length; ++i)
            total += price.get(product[i]) * amount[i];
        return total * (++cnt % n == 0 ? 1 - discount / 100.0 : 1);
    }
}