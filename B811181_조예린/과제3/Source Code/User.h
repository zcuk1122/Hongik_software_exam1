#pragma once

#include <string>
#include "Product.h"
#include "ProductCollection.h"

#define MAX_STRING_SIZE 32

// 사용자를 관리하는 클래스
class User
{
private:
    char name[MAX_STRING_SIZE];              // User의 이름
    char SSN[MAX_STRING_SIZE];               // User의 주민번호
    char ID[MAX_STRING_SIZE];                // User의 ID
    char password[MAX_STRING_SIZE];          // User의 비밀번호
    string recent_ID, recent_password;  // 현재 ID와 현재 password

    Product productOnSale[1000];        // 해당 사용자가 판매중인 상품의 배열
    int productOnSaleCount = 0;         // 판매중인 상품의 개수 (productOnSale 배열에 대한 인덱스)

    Product productBought[1000];        // 해당 사용자가 구매한 상품의 배열
    int productBoughtCount = 0;         // 구매한 상품의 개수 (productBought 배열에 대한 인덱스)

    Product soldProductOnSale[1000];    // 판매 완료한 상품 배열
    int soldProductOnSaleCount = 0;     // 판매 완료한 상품의 개수 (soldProductOnSale 배열에 대한 포인터)

public:

    void input_user(char* _name, char* _SSN, char* _ID, char* _password); //user 정보를 입력(회원생성)
    void delete_user(); //user 정보 삭제 함수(회원탈퇴)
    void login_user(char* _name, char* _password); //user 로그인 함수
    void logout_user(); //user 로그아웃 함수

    string getUsersID() { //현재 User ID 리턴 함수
        return ID;
    }

    Product* getProductOnSale();        // 판매중인 상품 배열 반환 함수
    int getProdcutOnSaleCount();        // 판매중인 상품 개수 반환 함수

    Product* getSoldProductOnSale();    // 판매 완료한 상품 배열 반환 함수
    int getSoldProductOnSaleCount();    // 판매 완료한 상품 개수 반환 함수

    void addProduct(Product newProduct); // productOnSale에 상품 추가하는 함수


    // 4.2 
    // 사용자의 구매 상품 리스트에 구매한 상품의 정보를 추가하는 함수
    void addToPurchaseList(Product newProduct);     

    // 4.3 
    // 사용자가 구매한 상품에 대한 배열을 반환하는 함수
    string getPurchaseList(ProductCollection* prodCollection);

};
