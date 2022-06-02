#include "User.h"

void User::input_user(char* _name, char* _SSN, char* _ID, char* _password) {//ȸ������ �Լ�
    //�Է¹��� ������ ����
    ////== this->name = _name
    strncpy(name, _name, MAX_STRING_SIZE - 1);
    strncpy(SSN, _SSN, MAX_STRING_SIZE - 1);
    strncpy(ID, _ID, MAX_STRING_SIZE - 1);
    strncpy(password, _password, MAX_STRING_SIZE - 1);
}

void User::delete_user() {//ȸ��Ż�� �Լ�
    delete[] name;
}

void User::login_user(char* _name, char* _password) { //�α��� �Լ� ����
    recent_ID = _name;
    recent_password = _password;
}

void User::logout_user() { //�α׾ƿ� ����
    recent_ID = "";
    recent_password = "";
}

Product* User::getProductOnSale() {
    return productOnSale;
};

int User::getProdcutOnSaleCount() {
    return productOnSaleCount;
};

Product* User::getSoldProductOnSale() {
    // product ��ƼƼ�� ���� ���� ������ Ȯ�����ְ� 0�� ��� �ǸſϷ�Ǿ��ٰ� �Ǵ��Ѵ�.
    int j = 0;
    for (int i = 0; i < productOnSaleCount; i++) {
        if (productOnSale[i].getQuantity() == 0) {
            soldProductOnSale[j] = productOnSale[i];
            soldProductOnSaleCount += 1;
            j++;
        }
    }

    return soldProductOnSale;
};

int User::getSoldProductOnSaleCount() {
    return soldProductOnSaleCount;
};

void User::addProduct(Product newProduct) {
    productOnSale[productOnSaleCount] = newProduct;
    productOnSaleCount += 1;
};

// 4.2 
// user�� ���� ��ǰ ����Ʈ�� ������ ��ǰ�� ������ �߰��ϴ� �Լ�
void User::addToPurchaseList(Product newProduct) {
    productBought[productBoughtCount] = newProduct;
    productBoughtCount++;
}

// 4.3 
// ����ڰ� ������ ��ǰ�� ���� �迭�� ��ȯ�ϴ� �Լ�
string User::getPurchaseList(ProductCollection* prodCollection) {

    string result;

    for (int i = 0; i < productBoughtCount; i++) {
        Product* product = prodCollection->findProduct(productBought[i].getName());
        result += product->getProductDetails();
    }

    return result;
}
