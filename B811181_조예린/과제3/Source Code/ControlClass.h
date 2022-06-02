#pragma once

#include <string>
#include "ProductCollection.h"
#include "Product.h"
#include "User.h"

using namespace std;

// 4.1 ��ǰ �˻��� ���� control class
class SearchProduct
{
private:
    ProductCollection* prodCollection;
    Product* foundProd;

public:

    // ������
    SearchProduct(ProductCollection* prodCollection)
    {
        this->prodCollection = prodCollection;

    }

    string searchProductName(string prodName);
    Product* getFoundProd() { return foundProd; }
};

// 4.2 ��ǰ ���Ÿ� ���� control class
class PurchaseProduct 
{
private:
    Product* foundProd;
    PurchaseProductUI* boundary;
    User* user;

public:

    //������
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

// 4.3 ���� ��ǰ ��ȸ�� ���� control class
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

// 4.4 ���� ������ �򰡸� ���� control class
class EvaluatePurchaseRating
{
private:
    ProductCollection* prodCollection;

public:

    // ������
    EvaluatePurchaseRating(ProductCollection* prodCollection)
    {
        this->prodCollection = prodCollection;
    }

    string evaluateRating(string prodName, double rating);
};


// �Ǹ� �Ƿ� ��� control
class RegisterProduct
{
private:
    ProductCollection* prodCollection; // prodCollection�� ���� ���۷���
    User* user; // user�� ���� ���۷���
public:
    // ������
    RegisterProduct(ProductCollection* prodCollection, User* user)
    {
        this->prodCollection = prodCollection;
        this->user = user;
    }

    // UI���� �θ� ��ǰ ��� �Լ�
    void addProduct(string productName,
        string sellerName,
        int price,
        int quantity);
};

// ��� ��ǰ ��ȸ control
class ListProductOnSale
{
private:
    User* user; // user�� ���� ���۷���
public:
    // ������
    ListProductOnSale(User* user) {
        this->user = user;
    }
    // UI���� �Ҹ� ��� ��ǰ ��ȸ �Լ�
    void getProductOnSale();
};

// �Ǹ� �Ϸ� ��ǰ ��ȸ control
class ListSoldProduct {
private:
    User* user; // user�� ���� ���۷���
public:
    // ������
    ListSoldProduct(User* user) {
        this->user = user;
    };

    // UI���� �θ� �Ǹ� �Ϸ� ��ǰ ��ȸ �Լ�
    string getProductOnSale();
};

// �Ǹ� ��ǰ ��� control
class PrintSalesHistory {
private:
    User* user; // user�� ���� ���۷���
public:
    // ������
    PrintSalesHistory(User* user) {
        this->user = user;
    };

    // UI���� �θ� ��� �Լ�
    string getHistory();
};

