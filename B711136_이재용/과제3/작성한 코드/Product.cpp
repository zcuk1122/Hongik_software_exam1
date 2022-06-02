#include "Product.h"

string Product::getName() { return this->name; }


// 상품의 상세정보를 파일 출력 형식에 맞춰 string으로 반환 ([판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도])
string Product::getProductDetails()
{
	string details = this->sellerID + " " + this->name + " " + this->prodCompany + " " + to_string(this->price) + " " + to_string(this->quantity) + " " + to_string(this->avgRating) + "\n";
	return details;
}

// print (productName, productComany, price, quantity)
string Product::getProductOnSaleDetails() {
    string details = this->name + " " + this->prodCompany + " " + to_string(this->price) + " " + to_string(this->quantity);
    return details;
}

int Product::getQuantity() {
    return this->quantity;
}

// print (productName, whole price, avgRating)
string Product::getProductStatistics() {
    int price = sold * this->price;
    string statistics = this->name + " " + to_string(price) + " " + to_string(avgRating);
    return statistics;
}
