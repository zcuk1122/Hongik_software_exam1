#include "ControlClass.h"
#include "BoundaryClass.h"
#include <iostream>

using namespace std;

// 4.1 ��ǰ �˻��� ���� �Լ�
string SearchProduct::searchProductName(string prodName)
{
    this->foundProd = prodCollection->findProduct(prodName);
    return foundProd->getProductDetails();

};

// 4.4 ���Ÿ����� �򰡸� ���� ����� �Լ�
string EvaluatePurchaseRating::evaluateRating(string prodName, double rating)
{
    Product* targetProd = prodCollection->findProduct(prodName);
    targetProd->putRating(rating);

    //[�Ǹ���ID] [��ǰ��] [���Ÿ�����]
    string result = targetProd->getSellerID() + " " + targetProd->getName() + " " + to_string(rating) + "\n";
    return result;
}



void ListProductOnSale::getProductOnSale() {
    // ����ڰ� ��� ��ǰ�� ���� ��ȸ
    // �������� �Բ� ȣ���Ѵ�.
    Product* products = user->getProductOnSale();
    int count = user->getProdcutOnSaleCount();

    // UI�� startInterface�� �θ��� ���� �����Ѵ�.
    // ������Ŀ� �°� �����Ѵ�.
    ListProductOnSaleUI listProductOnSaleUI;
    string result = "< ";
    for (int i = 0; i < count; i++) {
        result += ("{ " + products->getProductOnSaleDetails() + " } ");
    }
    listProductOnSaleUI.startInterface(result);
};

void RegisterProduct::addProduct(string productName, string sellerName, int price, int quantity) {
    // ���ο� ��ǰ�� �����Ѵ�.
    Product newProduct = Product(productName, sellerName, "", price, quantity);
    // prodCollection�� productCollection �迭�� user�� productOnSale �迭�� �߰��Ѵ�.
    prodCollection->addProduct(&newProduct);
    user->addProduct(newProduct);

}

string ListSoldProduct::getProductOnSale() {
    // ����ڰ� ����ϰ� �ǸſϷ��� ��ǰ�� ���� ��ȸ�Ѵ�.
    // �������� �Բ� ȣ���Ѵ�.
    Product* products = user->getSoldProductOnSale();
    int count = user->getSoldProductOnSaleCount();

    // UI �ʿ� ����� ��ȯ�Ѵ�.
    // ����� ��ǰ��, ����ȸ���, ����, ���� ����, ��� ���� ������ �̴�.
    string result = "> ";
    for (int i = 0; i < count; i++) {
        result += products[i].getProductDetails();
    }
    return result;

}

string PrintSalesHistory::getHistory() {
    // ������ ����ϰ� �ǸſϷ��� ��ǰ�� ���� ��ȸ�Ѵ�.
    Product* products = user->getSoldProductOnSale();
    int count = user->getSoldProductOnSaleCount();

    // UI �ʿ� ����� ��ȯ�Ѵ�.
    // ����� ��ǰ�� ��ǰ�Ǹ��Ѿ�, ��ձ��Ÿ����� �̴�.
    string result = "> ";
    for (int i = 0; i < count; i++) {
        result += ("{ " + products[i].getProductStatistics() + "} ");
    }
    return result;
}
