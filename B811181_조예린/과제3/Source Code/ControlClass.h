#pragma once

#include <string>
#include "ProductCollection.h"
#include "Product.h"
#include "User.h"

using namespace std;

// 4.1 상품 검색을 위한 control class
class SearchProduct
{
private:
    ProductCollection* prodCollection;
    Product* foundProd;

public:

    // 생성자
    SearchProduct(ProductCollection* prodCollection)
    {
        this->prodCollection = prodCollection;

    }

    string searchProductName(string prodName);
    Product* getFoundProd() { return foundProd; }
};

// 4.2 상품 구매를 위한 control class
class PurchaseProduct 
{
private:
    Product* foundProd;
    PurchaseProductUI* boundary;
    User* user;

public:

    //생성자
    PurchaseProduct(Product* foundProd, User* user, PurchaseProductUI* purchaseProductUI)
    {
        this->foundProd = foundProd;
        this->boundary = purchaseProductUI;
        this->user = user;

        foundProd->reduceQuantity();
        user->addToPurchaseList(*foundProd);
        string result = foundProd->getSellerID() + " " + foundProd->getName() + "\n";
        boundary->writeToFile(result);
    }
};

// 4.3 구매 상품 조회를 위한 control class
class ListPurchaseHistory
{
private:
    ListPurchaseHistoryUI* boundary;
    User* user;

public:
    ListPurchaseHistory(User* user, ProductCollection* prodCollection, ListPurchaseHistoryUI* listPurchaseHistoryUI)
    {
        this->user = user;
        this->boundary = listPurchaseHistoryUI;

        string result = user->getPurchaseList(prodCollection);
        boundary->writeToFile(result);
    }
};

// 4.4 구매 만족도 평가를 위한 control class
class EvaluatePurchaseRating
{
private:
    ProductCollection* prodCollection;

public:

    // 생성자
    EvaluatePurchaseRating(ProductCollection* prodCollection)
    {
        this->prodCollection = prodCollection;
    }

    string evaluateRating(string prodName, double rating);
};


// 판매 의류 등록 control
class RegisterProduct
{
private:
    ProductCollection* prodCollection; // prodCollection에 대한 레퍼런스
    User* user; // user에 대한 레퍼런스
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
    User* user; // user에 대한 레퍼런스
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
    User* user; // user에 대한 레퍼런스
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
    User* user; // user에 대한 레퍼런스
public:
    // 생성자
    PrintSalesHistory(User* user) {
        this->user = user;
    };

    // UI에서 부를 통계 함수
    string getHistory();
};

