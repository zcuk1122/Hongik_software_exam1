#include "User.h"

void User::input_user(char* _name, char* _SSN, char* _ID, char* _password) {//회원가입 함수
    //입력받은 데이터 저장
    ////== this->name = _name
    strncpy(name, _name, MAX_STRING_SIZE - 1);
    strncpy(SSN, _SSN, MAX_STRING_SIZE - 1);
    strncpy(ID, _ID, MAX_STRING_SIZE - 1);
    strncpy(password, _password, MAX_STRING_SIZE - 1);
}

void User::delete_user() {//회원탈퇴 함수
    delete[] name;
}

void User::login_user(char* _name, char* _password) { //로그인 함수 실행
    recent_ID = _name;
    recent_password = _password;
}

void User::logout_user() { //로그아웃 실행
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
    // product 엔티티로 가서 남은 수량을 확인해주고 0일 경우 판매완료되었다고 판단한다.
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
// user의 구매 상품 리스트에 구매한 상품의 정보를 추가하는 함수
void User::addToPurchaseList(Product newProduct) {
    productBought[productBoughtCount] = newProduct;
    productBoughtCount++;
}

// 4.3 
// 사용자가 구매한 상품에 대한 배열을 반환하는 함수
string User::getPurchaseList(ProductCollection* prodCollection) {

    string result;

    for (int i = 0; i < productBoughtCount; i++) {
        Product* product = prodCollection->findProduct(productBought[i].getName());
        result += product->getProductDetails();
    }

    return result;
}
