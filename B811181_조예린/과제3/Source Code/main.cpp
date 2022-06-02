//소프트웨어공학
// 과제 3 :  Detailed Design & Implementation – 의류 쇼핑 사이트>
//
//
//** 입력 파일의 메뉴 파싱 코드 예시
//

// 헤더 선언
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

#include "ControlClass.h"
#include "BoundaryClass.h"
#include "ProductCollection.h"
#include "User.h"
#include "Product.h"

// 상수 선언
#define MAX_STRING_SIZE 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

// 함수 선언
void doTask();              // 프로그램 실행
void sign_up();             // 회원가입
void sign_out();            // 회원탈퇴
void login();               // 로그인
void logout();              // 로그아웃
void program_exit();        // 프로그램 종료

void getProductOnSale();
void registerNewProduct();
void listSoldProduct();
void printSalesHistory();

void doSearchProduct();         // 4.1 상품 정보 검색
void doPurchaseProduct();           // 4.2 상품 구매
void doListPurchaseHistory();       // 4.3 상품 구매 내역 조회
void doEvaluatePurchaseRating();    // 4.4 상품 구매 만족도 평가


//전역 변수 선언
char get_recent_ID[MAX_STRING_SIZE];         // 현재 유저의 ID
ProductCollection prodCollection;       // 사이트에 등록된 모든 Product를 관리하는 Collection
User users;             

// 4.1과 4.2 에서 사용하는 변수
Product* foundProd = NULL;      // 검색한 Product의 포인터 변수

// 파일 입출력을 위한 초기화
FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

int main() {

    doTask();
    return 0;
}

void doTask() {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1) {
        case 1:
            switch (menu_level_2) {
            case 1: // 회원가입
                sign_up();
                break;
            case 2: // 회원탈퇴
                sign_out();
                break;
            }
            break;
        case 2:
            switch (menu_level_2) {
            case 1: // 로그인
                login();
                break;
            case 2: // 로그아웃
                logout();
                break;
            }
            break;
        case 3:
            switch (menu_level_2) {
            case 1: // 판매 의류 등록
                registerNewProduct();

                break;
            case 2: // 판매 상품 조회
                getProductOnSale();

                break;
            case 3: // 판매 완료 상품 조회
                listSoldProduct();
                break;
            }
            break;
        case 4:
            switch (menu_level_2) {
            case 1:                 // 4.1 상품 정보 검색
                doSearchProduct();
                break;
            case 2:                 // 4.2 상품 구매
                doPurchaseProduct();
                break;
            case 3:                 // 4.3 상품 구매 내역 조회
                doListPurchaseHistory();
                break;
            case 4:                 // 4.4 상품 구매만족도 평가
                doEvaluatePurchaseRating();
                break;
            }
            break;
        case 5:
            switch (menu_level_2) {
            case 1: // 판매 상품 통계
                printSalesHistory();
                break;
            }
            break;
        case 6:
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
                //    ..
                program_exit();
                is_program_exit = 1;
                break;;
            }
            break;
        }
    }
}

void sign_up()
{
    printf("sign_up");
    char  name[MAX_STRING_SIZE], SSN[MAX_STRING_SIZE],
        ID[MAX_STRING_SIZE], password[MAX_STRING_SIZE];
    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);


    // 해당 기능 수행
    users.input_user(name, SSN, ID, password);

    // 출력 형식
    fprintf(out_fp, "1.1. 회원가입\n");
    fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}

void sign_out()
{
    printf("sign_out");
    // 회원탈퇴할 ID를 USER class에서 found
    char ID[MAX_STRING_SIZE];
    strcpy(ID, get_recent_ID);

    // 해당 기능 수행
    users.delete_user();

    // 출력 형식
    fprintf(out_fp, "1.2. 회원탈퇴\n");
    fprintf(out_fp, "%s \n", ID);
}

void login()
{
    printf("login");
    //입력 형식 : ID, password 를 파일로부터 읽음
    char ID[MAX_STRING_SIZE], password[MAX_STRING_SIZE];
    // 해당 기능 수행
    fscanf(in_fp, "%s %s", ID, password);

    //로그인 함수 구현
    strcpy(get_recent_ID, ID);
    users.login_user(ID, password);
    // 출력 형식
    fprintf(out_fp, "2.1. 로그인\n");
    fprintf(out_fp, "%s \n", ID, password);
}

void logout()
{
    printf("logout");
    //입력 형식 : ID를 USER class로부터 읽음
    char ID[MAX_STRING_SIZE];

    //로그아웃 구현
    strcpy(ID, get_recent_ID);
    users.logout_user();
    // 출력 형식
    fprintf(out_fp, "2.2. 로그아웃\n");
    fprintf(out_fp, "%s \n", ID);
}



// 아래 함수는 사용자가 UI에 들어갔을 때 UI의 함수를 호출하는 상황이다.
void getProductOnSale() {
    ListProductOnSale listProductOnSale(&users);
    ListProductOnSaleUI listProductOnSaleUI(out_fp, &listProductOnSale);

    listProductOnSaleUI.getProductOnSale();
}

// 아래 함수는 사용자가 UI에 들어가서 등록할 상품에 대한 정보들을 입력한 상황이다.
void registerNewProduct() {
    RegisterProduct registerProduct(&prodCollection, &users);
    RegisterProductUI registerProductUI;

    registerProductUI.typeProductInformation(in_fp, out_fp, &registerProduct);
}

// 아래 함수는 사용자가 UI에 들어갔을 때 UI의 함수를 호출하는 상황이다.
void listSoldProduct() {
    ListSoldProduct listSoldProduct(&users);
    ListSoldProductUI listSoldProductUI(out_fp, &listSoldProduct);

    listSoldProductUI.getProductOnSale();

}

// 아래 함수는 사용자가 UI에 들어갔을 때 UI의 함수를 호출하는 상황이다.
void printSalesHistory() {
    PrintSalesHistory printSalesHistory(&users);
    PrintSalesHistoryUI printSalesHistoryUI(out_fp, &printSalesHistory);

    printSalesHistoryUI.getHistory();
}



// 4.1 상품 정보 검색
void doSearchProduct()
{
    SearchProduct searchProduct(&prodCollection);                       // control 클래스 생성
    SearchProductUI searchProductUI(in_fp, out_fp, &searchProduct);     // boundary 클래스 생성

    foundProd = searchProductUI.enterProductName();                     // 검색 기능 수행 후 검색했던 상품의 포인트 저장
}

// 4.2 상품 구매
void doPurchaseProduct()
{
    PurchaseProductUI purchaseProductUI(in_fp, out_fp);
    PurchaseProduct purchaseProduct(foundProd, &user, &purchaseProductUI);
}

// 4.3 상품 구매 내역 조회
void doListPurchaseHistory()
{
    ListPurchaseHistoryUI listPurchaseHistoryUI(in_fp, out_fp);
    ListPurchaseHistory listPurchaseHistory(&user, &prodCollection, &listPurchaseHistoryUI);
}


// 4.4 상품 구매 만족도 평가
void doEvaluatePurchaseRating()
{
    EvaluatePurchaseRating evaluatePurchaseRating(&prodCollection);
    EvaluatePurchaseRatingUI evaluatePurchaseRatingUI(in_fp, out_fp, &evaluatePurchaseRating);

    evaluatePurchaseRatingUI.enterRating();
}





void program_exit()
{
    //출력 형식
    fprintf(out_fp, "6.1. 종료\n");
}