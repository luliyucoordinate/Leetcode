type Cashier struct {
    n, discount, cnt int
    price map[int]int
}


func Constructor(n int, discount int, products []int, prices []int) Cashier {
    this := new(Cashier)
    this.n, this.discount, this.cnt = n, discount, 0
    this.price = make(map[int]int)
    
    for i := 0; i < len(products); i++ {
        this.price[products[i]] = prices[i]
    }
    return *this
}


func (this *Cashier) GetBill(product []int, amount []int) float64 {
    var total float64 = 0
    for i := 0; i < len(product); i++ {
        total += float64(this.price[product[i]] * amount[i])
    }
    
    this.cnt++
    if this.cnt % this.n == 0 {
        return total * float64(100 - this.discount) / 100.0
    }
    return total
}
