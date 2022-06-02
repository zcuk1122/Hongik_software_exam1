#include "ControlClass.h"
#include "BoundaryClass.h"
#include <iostream>

using namespace std;

string SearchProduct::searchProductName(string prodName) 
{
	Product* targetProduct = prodCollection->findProduct(prodName);
	return targetProduct->getProductDetails();

};

void ListProductOnSale::getProductOnSale() {
    // 사용자가 등록 상품에 대한 조회
    // 개수까지 함께 호출한다.
    Product* products = user->getProductOnSale();
    int count = user->getProdcutOnSaleCount();
    
    // UI의 startInterface를 부르기 위해 생성한다.
    // 출력형식에 맞게 구성한다.
    ListProductOnSaleUI listProductOnSaleUI;
    string result = "< ";
    for (int i = 0; i < count; i++) {
        result += ("{ " + products->getProductOnSaleDetails() + " } ");
    }
    listProductOnSaleUI.startInterface(result);
};

void RegisterProduct::addProduct(string productName, string sellerName, int price, int quantity) {
    // 새로운 상품을 생성한다.
    Product newProduct = Product(productName, sellerName, "", price, quantity);
    // prodCollection의 productCollection 배열과 user의 productOnSale 배열에 추가한다.
    prodCollection->addProduct(&newProduct);
    user->addProduct(newProduct);
    
}

string ListSoldProduct::getProductOnSale() {
    // 사용자가 등록하고 판매완료한 상품에 대해 조회한다.
    // 개수까지 함께 호출한다.
    Product* products = user->getSoldProductOnSale();
    int count = user->getSoldProductOnSaleCount();
    
    // UI 쪽에 결과를 반환한다.
    // 결과는 상품명, 제작회사명, 가격, 남은 수량, 평균 구매 만족도 이다.
    string result = "> ";
    for (int i = 0; i < count; i++) {
        result += ("{ " + products[i].getProductDetails() + " } ");
    }
    return result;
    
}

string PrintSalesHistory::getHistory() {
    // 유저가 등록하고 판매완료한 상품에 대해 조회한다.
    Product* products = user->getSoldProductOnSale();
    int count = user->getSoldProductOnSaleCount();
    
    // UI 쪽에 결과를 반환한다.
    // 결과는 상품명 상품판매총액, 평균구매만족도 이다.
    string result = "> ";
    for (int i = 0; i < count; i++) {
        result += ("{ " + products[i].getProductStatistics() + "} ");
    }
    return result;
}
