#define _CRT_SECURE_NO_WARNINGS
#include "BoundaryClass.h"
#include <iostream>
#include <string>

using namespace std;

string SearchProductUI::enterProductName()
{
	string prodName;
	fscanf(this->in_fp, "%s", &prodName);

	string result = (this->control)->searchProductName(prodName);

    fprintf(this->out_fp, "%s", result.c_str());
	
	return prodName;
}

void ListProductOnSaleUI::getProductOnSale()
{
    // 등록 상품 조회
    (this->control)->getProductOnSale();
}

void ListProductOnSaleUI::startInterface(string result)
{
    // 등록 상품 조회 출력
    fprintf(this->out_fp, "3.2 등록 상품 조회");
    fprintf(this->out_fp, "%s", result.c_str());
}

void RegisterProductUI::typeProductInformation(FILE *in_fp, FILE *out_fp, RegisterProduct* registerProduct) {
    // 초기화
    this->in_fp = in_fp;
    this->out_fp = out_fp;
    this->control = registerProduct;
    
    // 상품 등록에 필요한 정보 입력
    string productName = "";
    string sellerName = "";
    int price = 0;
    int quantity = 0;
    fscanf(in_fp, "%s %s %d %d ", &productName, &sellerName, &price, &quantity);
    
    // 상품등록 완료에 대한 출력
    fprintf(this->out_fp, "3.1 판매 의류 등록");
    
    // 상품등록하기
    (this->control)->addProduct(productName, sellerName, price, quantity);
    
    string result = "> " + productName + " " + sellerName + to_string(price) + to_string(quantity);
    fprintf(this->out_fp, "%s", result.c_str());
};

void ListSoldProductUI::getProductOnSale() {
    // 판매 완료한 상품 출력
    fprintf(this->out_fp, "3.3 판매 완료 상품 조회");
    
    string result = (this->control)->getProductOnSale();
    fprintf(this->out_fp, "%s", result.c_str());
}

void PrintSalesHistoryUI::getHistory() {
    // 상품 통계에 대한 출력
    fprintf(this->out_fp, "5.1 판매 상품 통계");
    
    string result = (this->control)->getHistory();
    fprintf(this->out_fp, "%s", result.c_str());
}
