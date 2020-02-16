class ProductOfNumbers {

    public ProductOfNumbers() {
        pre.add(1);
    }
    
    public void add(int num) {
        if (num == 0) {
            pre.clear();
            pre.add(1);
        } else {
            pre.add(pre.get(pre.size() - 1) * num);
        }
    }
    
    public int getProduct(int k) {
        if (pre.size() <= k) return 0;
        return pre.get(pre.size() - 1) / pre.get(pre.size() - k - 1);
    }
    
    private List<Integer> pre = new ArrayList();
}