#pragma once

#include <string>
#include "Product.h"
#include "ProductCollection.h"

class User
{
private:
    Product productOnSale[1000]; // 판매중인 상품 배열
    int productOnSaleCount = 0; // 판매중인 상품의 개수 (위 배열에 대한 포인터)
    Product productBought[1000];
    Product soldProductOnSale[1000]; // 판매 완료한 상품 배열
    int soldProductOnSaleCount = 0; // 판매 완료한 상품의 개수 (위 배열에 대한 포인터)
public:
    
    Product* getProductOnSale(); // 판매중인 상품 배열 반환 함수
    int getProdcutOnSaleCount(); // 판매중인 상품 개수 반환 함수
    
    Product* getSoldProductOnSale(); // 판매 완료한 상품 배열 반환 함수
    int getSoldProductOnSaleCount(); // 판매 완료한 상품 개수 반환 함수
    
    void addProduct(Product newProduct); // productOnSale에 상품 추가하는 함수
    
    
};

