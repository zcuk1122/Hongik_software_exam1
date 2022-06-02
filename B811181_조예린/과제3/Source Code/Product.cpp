#include "Product.h"

// Getter
string Product::getName() { return this->name; }
string Product::getSellerID() { return this->sellerID; }
int Product::getQuantity() { return this->quantity; }


// 4.1
// 4.3 
// 상품을 검색하여 상세정보를 출력하는 함수 ([판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도])
string Product::getProductDetails()
{
    string details = this->sellerID + " " + this->name + " " + this->prodCompany + " " + to_string(this->price) + " " + to_string(this->quantity) + " " + to_string(this->avgRating) + "\n";
    return details;
}

// 4.2 
// 상품 구매 후 해당 상품의 양을 감소 시키는 함수 
void Product::reduceQuantity()
{
    if ((this->quantity) != 0)
    {
        (this->quantity)--;
        (this->sold)++;
    }
}

// 4.4
// 평균 만족도를 계산하여 상품 정보에 반영하는 함수
void Product::putRating(double rating)
{
    double sum = ratingCount * avgRating + rating;      // sum = (평가자수) * (평균 만족도) + (rating)
    avgRating = sum / (++ratingCount);                  // 평가자 수 증가
                                                        // (평균 만족도) = sum / (평가자수)
    // 평균 계산
}



// 자신의 판매 상품 조회를 출력하는 함수 (productName, productComany, price, quantity)
string Product::getProductOnSaleDetails() {
    string details = this->name + " " + this->prodCompany + " " + to_string(this->price) + " " + to_string(this->quantity);
    return details;
}

// 통계 내역 출력 함수 (productName, whole price, avgRating)
string Product::getProductStatistics() {
    int price = sold * this->price;
    string statistics = this->name + " " + to_string(price) + " " + to_string(avgRating);
    return statistics;
}
