#pragma once

#include <string>
#include "Product.h"
#include "ProductCollection.h"

#define MAX_STRING_SIZE 32

// ����ڸ� �����ϴ� Ŭ����
class User
{
private:
    char name[MAX_STRING_SIZE];              // User�� �̸�
    char SSN[MAX_STRING_SIZE];               // User�� �ֹι�ȣ
    char ID[MAX_STRING_SIZE];                // User�� ID
    char password[MAX_STRING_SIZE];          // User�� ��й�ȣ
    string recent_ID, recent_password;  // ���� ID�� ���� password

    Product productOnSale[1000];        // �ش� ����ڰ� �Ǹ����� ��ǰ�� �迭
    int productOnSaleCount = 0;         // �Ǹ����� ��ǰ�� ���� (productOnSale �迭�� ���� �ε���)

    Product productBought[1000];        // �ش� ����ڰ� ������ ��ǰ�� �迭
    int productBoughtCount = 0;         // ������ ��ǰ�� ���� (productBought �迭�� ���� �ε���)

    Product soldProductOnSale[1000];    // �Ǹ� �Ϸ��� ��ǰ �迭
    int soldProductOnSaleCount = 0;     // �Ǹ� �Ϸ��� ��ǰ�� ���� (soldProductOnSale �迭�� ���� ������)

public:

    void input_user(char* _name, char* _SSN, char* _ID, char* _password); //user ������ �Է�(ȸ������)
    void delete_user(); //user ���� ���� �Լ�(ȸ��Ż��)
    void login_user(char* _name, char* _password); //user �α��� �Լ�
    void logout_user(); //user �α׾ƿ� �Լ�

    string getUsersID() { //���� User ID ���� �Լ�
        return ID;
    }

    Product* getProductOnSale();        // �Ǹ����� ��ǰ �迭 ��ȯ �Լ�
    int getProdcutOnSaleCount();        // �Ǹ����� ��ǰ ���� ��ȯ �Լ�

    Product* getSoldProductOnSale();    // �Ǹ� �Ϸ��� ��ǰ �迭 ��ȯ �Լ�
    int getSoldProductOnSaleCount();    // �Ǹ� �Ϸ��� ��ǰ ���� ��ȯ �Լ�

    void addProduct(Product newProduct); // productOnSale�� ��ǰ �߰��ϴ� �Լ�


    // 4.2 
    // ������� ���� ��ǰ ����Ʈ�� ������ ��ǰ�� ������ �߰��ϴ� �Լ�
    void addToPurchaseList(Product newProduct);     

    // 4.3 
    // ����ڰ� ������ ��ǰ�� ���� �迭�� ��ȯ�ϴ� �Լ�
    string getPurchaseList(ProductCollection* prodCollection);

};
