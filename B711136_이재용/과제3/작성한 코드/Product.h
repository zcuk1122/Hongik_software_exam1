#pragma once

#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
	string name;				// 상품명
	string sellerID;			// 판매자의 ID
	string prodCompany;			// 제작회사명
	int price;					// 상품 가격
	int quantity;				// 남은 수량
    int sold;
	double avgRating = 0;		// 평균 구매 만족도

public:
	// 생성자
	Product(){}
    
	Product(string name, string sellerID, string prodCompany, int price, int quantity){
		this->name = name;
		this->sellerID = sellerID;
		this->prodCompany = prodCompany;
		this->price = price;
		this->quantity = quantity;
	}

	// Getter
	string getName();

	// 상품의 상세정보를 파일 출력 형식에 맞춰 string으로 반환 ([판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도])
	string getProductDetails();
    
    
    string getProductOnSaleDetails();
    
    string getProductStatistics();
    
    int getQuantity();
};

