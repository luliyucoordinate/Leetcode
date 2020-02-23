/**
 * @param {number} n
 * @param {number} discount
 * @param {number[]} products
 * @param {number[]} prices
 */
var Cashier = function(n, discount, products, prices) {
    this.n = n, this.discount = discount, this.cnt = 0;
    this.price = new Map();
    for (let i = 0; i < products.length; ++i)
        this.price.set(products[i], prices[i]);
};

/** 
 * @param {number[]} product 
 * @param {number[]} amount
 * @return {number}
 */
Cashier.prototype.getBill = function(product, amount) {
    let total = 0;
    for (let i = 0; i < product.length; ++i)
        total += this.price.get(product[i]) * amount[i];
    return total * (++this.cnt % this.n == 0 ? 1 - this.discount / 100.0 : 1);
};