#pragma once

#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
	string name;				// 제품의 이름
	string sellerID;			// 판매자 ID
	string prodCompany;			// 제작회사명
	int price;					// 상품 가격
	int quantity;				// 상품의 잔여 수량
	int sold;					// 상품의 판매 수량

	double avgRating = 0;		// 평균 구매 만족도
	int ratingCount = 0;		// 구매 만족도 평가자 수

public:

	// 생성자
	Product() {}
	Product(string name, string sellerID, string prodCompany, int price, int quantity) {
		this->name = name;
		this->sellerID = sellerID;
		this->prodCompany = prodCompany;
		this->price = price;
		this->quantity = quantity;
		this->sold = 0;
	}

	// Getter
	string getName();
	string getSellerID();
	int getQuantity();


	// 4.1 
	// 4.3
	// 상품을 검색하여 상세정보를 출력하는 함수 ([판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도])
	string getProductDetails();

	// 4.2 
	// 상품 구매 후 해당 상품의 양을 감소 시키는 함수 
	void reduceQuantity();

	// 4.4
	// 평균 만족도를 계산하여 상품 정보에 반영하는 함수
	void putRating(double rating);



	// 자신의 판매 상품 조회를 출력하는 함수 (productName, productComany, price, quantity)
	string getProductOnSaleDetails();

	// 통계 내역 출력 함수 (productName, whole price, avgRating)
	string getProductStatistics();
};

