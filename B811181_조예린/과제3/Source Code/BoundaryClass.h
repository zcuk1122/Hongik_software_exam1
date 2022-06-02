#pragma once

#include <string>
#include "ControlClass.h"

// 4.1 상품 검색을 위한 boundary class
class SearchProductUI
{
private:
    FILE* in_fp;
    FILE* out_fp;
    SearchProduct* control;
    Product* foundProd;

public:
    SearchProductUI(FILE* in_fp, FILE* out_fp, SearchProduct* searchProduct) {
        this->in_fp = in_fp;
        this->out_fp = out_fp;
        this->control = searchProduct;
    }

    Product* enterProductName();
};

// 4.2 상품 구매를 위한 boundary class
class PurchaseProductUI
{
private:
    FILE* in_fp;
    FILE* out_fp;

public:

    PurchaseProductUI(FILE* in_fp, FILE* out_fp) {
        this->in_fp = in_fp;
        this->out_fp = out_fp;
    }

    void writeToFile(string result);
};

// 4.3 구매 상품 조회를 위한 boundary class
class ListPurchaseHistoryUI
{
private:
    FILE* in_fp;
    FILE* out_fp;

public:

    ListPurchaseHistoryUI(FILE* in_fp, FILE* out_fp) {
        this->in_fp = in_fp;
        this->out_fp = out_fp;
    }

    void writeToFile(string result);
};

// 4.4 구매 만족도 평가를 위한 boundary class
class EvaluatePurchaseRatingUI
{
private:
    FILE* in_fp;
    FILE* out_fp;
    EvaluatePurchaseRating* control;

public:
    EvaluatePurchaseRatingUI(FILE* in_fp, FILE* out_fp, EvaluatePurchaseRating* evaluatePurchaseRating) {
        this->in_fp = in_fp;
        this->out_fp = out_fp;
        this->control = evaluatePurchaseRating;
    }

    void enterRating();

};


// 의류 등록 UI
class RegisterProductUI
{
private:
    FILE* in_fp; // 등록하기 위해 받을 정보들때문에 필요함
    FILE* out_fp; // 출력을 위해 필요
    RegisterProduct* control; // RegisterProduct에 대한 레퍼런스
public:

    // 등록상품에 대한 정볼 입력 받는 함수
    void typeProductInformation(FILE* in_fp,
        FILE* out_fp,
        RegisterProduct* registerProduct);
};

// 등록 상품 조회 UI
class ListProductOnSaleUI
{
private:
    FILE* out_fp; // 출력을 위해 필요
    ListProductOnSale* control; // ListProductOnSale에 대한 레퍼런스
public:
    // 생성자
    ListProductOnSaleUI() { }
    ListProductOnSaleUI(FILE* out_fp,
        ListProductOnSale* listProductOnSale) {
        this->out_fp = out_fp;
        this->control = listProductOnSale;
    }

    void startInterface(string result); // control에서 호출할 출력을 위한 함수
    void getProductOnSale(); // 등록 상품 조회를 위해 필요한 함수
};

// 판매 완료 상품 조회 UI
class ListSoldProductUI {
private:
    FILE* out_fp; // 출력을 위해 필요
    ListSoldProduct* control; // ListSoldProduct에 대한 레퍼런스
public:
    ListSoldProductUI(FILE* out_fp,
        ListSoldProduct* listSoldProduct) {
        this->out_fp = out_fp;
        this->control = listSoldProduct;
    }

    void getProductOnSale(); // 판매 완료 상품을 구하기 위한 함수
};

// 판매 상품 통계 UI
class PrintSalesHistoryUI {
private:
    FILE* out_fp; // 출력을 위해 필요
    PrintSalesHistory* control; // PrintSalesHistory에 대한 레퍼런스
public:
    // 생성자
    PrintSalesHistoryUI(FILE* out_fp,
        PrintSalesHistory* printSalesHistory) {
        this->out_fp = out_fp;
        this->control = printSalesHistory;
    }

    void getHistory(); // 통계 호출을 위한 함수

};
