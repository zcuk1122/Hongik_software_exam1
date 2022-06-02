#pragma once

#include <string>
#include "ProductCollection.h"
#include "Product.h"
#include "User.h"

using namespace std;

class SearchProduct
{
private:
	ProductCollection* prodCollection;

public:

	SearchProduct(){}
	SearchProduct(ProductCollection* prodCollection) 
	{ 
		this->prodCollection = prodCollection; 

	}

	string searchProductName(string prodName);
	
};

class PurchaseProduct {

};

// 판매 의류 등록 control
class RegisterProduct
{
private:
    ProductCollection* prodCollection; // prodCollection에 대한 레퍼런스
    User *user; // user에 대한 레퍼런스
public:
    // 생성자
    RegisterProduct(ProductCollection* prodCollection, User* user)
    {
        this->prodCollection = prodCollection;
        this->user = user;
    }
    
    // UI에서 부를 상품 등록 함수
    void addProduct(string productName,
                    string sellerName,
                    int price,
                    int quantity);
};

// 등록 상품 조회 control
class ListProductOnSale
{
private:
    User *user; // user에 대한 레퍼런스
public:
    // 생성자
    ListProductOnSale(User* user) {
        this->user = user;
    }
    // UI에서 불릴 등록 상품 조회 함수
    void getProductOnSale();
};

// 판매 완료 상품 조회 control
class ListSoldProduct {
private:
    User *user; // user에 대한 레퍼런스
public:
    // 생성자
    ListSoldProduct(User* user) {
        this->user = user;
    };
    
    // UI에서 부를 판매 완료 상품 조회 함수
    string getProductOnSale();
};

// 판매 상품 통계 control
class PrintSalesHistory {
private:
    User *user; // user에 대한 레퍼런스
public:
    // 생성자
    PrintSalesHistory(User* user) {
        this->user = user;
    };
    
    // UI에서 부를 통계 함수
    string getHistory();
};
