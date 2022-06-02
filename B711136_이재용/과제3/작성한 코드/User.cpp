#include "User.h"

Product* User::getProductOnSale() {
    return productOnSale;
};

int User::getProdcutOnSaleCount() {
    return productOnSaleCount;
};

Product* User::getSoldProductOnSale() {
    // product 엔티티로 가서 남은 수량을 확인해주고 0일 경우 판매완료되었다고 판단한다.
    int j = 0;
    for (int i = 0; i < productOnSaleCount; i++) {
        if (productOnSale[i].getQuantity() == 0) {
            soldProductOnSale[j] = productOnSale[i];
            soldProductOnSaleCount += 1;
            j++;
        }
    }
    
    return soldProductOnSale;
};

int User::getSoldProductOnSaleCount() {
    return soldProductOnSaleCount;
};

void User::addProduct(Product newProduct) {
    productOnSale[productOnSaleCount] = newProduct;
    productOnSaleCount += 1;
};
