#define _CRT_SECURE_NO_WARNINGS
#include "BoundaryClass.h"
#include <iostream>
#include <string>

using namespace std;

// 4.1 
// �̸��� ���� ��ǰ �˻�
Product* SearchProductUI::enterProductName()
{
    string prodName;
    fscanf(this->in_fp, "%s", &prodName);

    // control���� ��ǰ �˻� �� ����� ������ result�� ����
    string result = (this->control)->searchProductName(prodName);

    fprintf(this->out_fp, "%s", result);

    // ���� ��ǰ ���Ÿ� ���� �˻��� ��ǰ�� �����͸� ��ȯ
    return (this->control)->getFoundProd();
}

// 4.2 
// ���� ��� ��� �Լ�
void PurchaseProductUI::writeToFile(string result)
{
    fprintf(this->out_fp, "%s", result);
}

// 4.3 
// ���� ��ǰ ����Ʈ ��� �Լ� 
void ListPurchaseHistoryUI::writeToFile(string result)
{
    fprintf(this->out_fp, "%s", result);
}

// 4.4 
// ���� ������ �򰡸� ���� �Լ�
void EvaluatePurchaseRatingUI::enterRating()
{
    string prodName;
    double rating;
    fscanf(this->in_fp, "%s %f", &prodName, &rating);

    string result = control->evaluateRating(prodName, rating);

    fprintf(this->out_fp, "%s", result);
}



void ListProductOnSaleUI::getProductOnSale()
{
    // ��� ��ǰ ��ȸ
    (this->control)->getProductOnSale();
}

void ListProductOnSaleUI::startInterface(string result)
{
    // ��� ��ǰ ��ȸ ���
    fprintf(this->out_fp, "3.2 ��� ��ǰ ��ȸ");
    fprintf(this->out_fp, "%s", result.c_str());
}

void RegisterProductUI::typeProductInformation(FILE* in_fp, FILE* out_fp, RegisterProduct* registerProduct) {
    // �ʱ�ȭ
    this->in_fp = in_fp;
    this->out_fp = out_fp;
    this->control = registerProduct;

    // ��ǰ ��Ͽ� �ʿ��� ���� �Է�
    string productName = "";
    string sellerName = "";
    int price = 0;
    int quantity = 0;
    fscanf(in_fp, "%s %s %d %d ", &productName, &sellerName, &price, &quantity);

    // ��ǰ��� �Ϸῡ ���� ���
    fprintf(this->out_fp, "3.1 �Ǹ� �Ƿ� ���");

    // ��ǰ����ϱ�
    (this->control)->addProduct(productName, sellerName, price, quantity);

    string result = "> " + productName + " " + sellerName + to_string(price) + to_string(quantity);
    fprintf(this->out_fp, "%s", result.c_str());
};

void ListSoldProductUI::getProductOnSale() {
    // �Ǹ� �Ϸ��� ��ǰ ���
    fprintf(this->out_fp, "3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ");

    string result = (this->control)->getProductOnSale();
    fprintf(this->out_fp, "%s", result.c_str());
}

void PrintSalesHistoryUI::getHistory() {
    // ��ǰ ��迡 ���� ���
    fprintf(this->out_fp, "5.1 �Ǹ� ��ǰ ���");

    string result = (this->control)->getHistory();
    fprintf(this->out_fp, "%s", result.c_str());
}
