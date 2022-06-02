#pragma once

#include <string>
#include "ControlClass.h"

// 4.1 ��ǰ �˻��� ���� boundary class
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

// 4.2 ��ǰ ���Ÿ� ���� boundary class
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

// 4.3 ���� ��ǰ ��ȸ�� ���� boundary class
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

// 4.4 ���� ������ �򰡸� ���� boundary class
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


// �Ƿ� ��� UI
class RegisterProductUI
{
private:
    FILE* in_fp; // ����ϱ� ���� ���� �����鶧���� �ʿ���
    FILE* out_fp; // ����� ���� �ʿ�
    RegisterProduct* control; // RegisterProduct�� ���� ���۷���
public:

    // ��ϻ�ǰ�� ���� ���� �Է� �޴� �Լ�
    void typeProductInformation(FILE* in_fp,
        FILE* out_fp,
        RegisterProduct* registerProduct);
};

// ��� ��ǰ ��ȸ UI
class ListProductOnSaleUI
{
private:
    FILE* out_fp; // ����� ���� �ʿ�
    ListProductOnSale* control; // ListProductOnSale�� ���� ���۷���
public:
    // ������
    ListProductOnSaleUI() { }
    ListProductOnSaleUI(FILE* out_fp,
        ListProductOnSale* listProductOnSale) {
        this->out_fp = out_fp;
        this->control = listProductOnSale;
    }

    void startInterface(string result); // control���� ȣ���� ����� ���� �Լ�
    void getProductOnSale(); // ��� ��ǰ ��ȸ�� ���� �ʿ��� �Լ�
};

// �Ǹ� �Ϸ� ��ǰ ��ȸ UI
class ListSoldProductUI {
private:
    FILE* out_fp; // ����� ���� �ʿ�
    ListSoldProduct* control; // ListSoldProduct�� ���� ���۷���
public:
    ListSoldProductUI(FILE* out_fp,
        ListSoldProduct* listSoldProduct) {
        this->out_fp = out_fp;
        this->control = listSoldProduct;
    }

    void getProductOnSale(); // �Ǹ� �Ϸ� ��ǰ�� ���ϱ� ���� �Լ�
};

// �Ǹ� ��ǰ ��� UI
class PrintSalesHistoryUI {
private:
    FILE* out_fp; // ����� ���� �ʿ�
    PrintSalesHistory* control; // PrintSalesHistory�� ���� ���۷���
public:
    // ������
    PrintSalesHistoryUI(FILE* out_fp,
        PrintSalesHistory* printSalesHistory) {
        this->out_fp = out_fp;
        this->control = printSalesHistory;
    }

    void getHistory(); // ��� ȣ���� ���� �Լ�

};
