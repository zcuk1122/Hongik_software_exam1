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
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

// 클래스 선언

// 함수 선언
void doTask();
void join();
void program_exit();

void getProductOnSale();
void registerNewProduct();
void listSoldProduct();
void printSalesHistory();

// 변수 선언

ProductCollection prodCollection;
User user;

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
    
    while(!is_program_exit) {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        
        // 메뉴 구분 및 해당 연산 수행
        switch(menu_level_1) {
            case 1:
                switch(menu_level_2) {
                    case 1: // 회원가입
                        join();
                        break;
                    case 2: // 회원탈퇴
                        break;
                }
                break;
            case 2:
                switch(menu_level_2) {
                    case 1: // 로그인
                        break;
                    case 2: // 로그아웃
                        break;
                }
                break;
            case 3:
                switch(menu_level_2) {
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
                switch(menu_level_2) {
                    case 1: // 상품 정보 검색
                        break;
                    case 2: // 상품 구매
                        break;
                    case 3: // 상품 구매 내역 조회
                        break;
                    case 4: // 상품 구매만족도 평가
                        break;
                        
                }
                break;
            case 5:
                switch(menu_level_2) {
                    case 1: // 판매 상품 통계
                        printSalesHistory();
                        break;
                }
                break;
            case 6:
                switch(menu_level_2)
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



void join() {
    char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING],
    address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
    
    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);
    
    // 해당 기능 수행
    //   ...
    
    // 출력 형식
    fprintf(out_fp, "1.1. 회원가입\n");
    fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}


void program_exit() {
    
}

// 아래 함수는 사용자가 UI에 들어갔을 때 UI의 함수를 호출하는 상황이다.
void getProductOnSale() {
    ListProductOnSale listProductOnSale(&user);
    ListProductOnSaleUI listProductOnSaleUI(out_fp, &listProductOnSale);

    listProductOnSaleUI.getProductOnSale();
}

// 아래 함수는 사용자가 UI에 들어가서 등록할 상품에 대한 정보들을 입력한 상황이다.
void registerNewProduct() {
    RegisterProduct registerProduct(&prodCollection, &user);
    RegisterProductUI registerProductUI;
    
    registerProductUI.typeProductInformation(in_fp, out_fp, &registerProduct);
}

// 아래 함수는 사용자가 UI에 들어갔을 때 UI의 함수를 호출하는 상황이다.
void listSoldProduct() {
    ListSoldProduct listSoldProduct(&user);
    ListSoldProductUI listSoldProductUI(out_fp, &listSoldProduct);
    
    listSoldProductUI.getProductOnSale();
    
}

// 아래 함수는 사용자가 UI에 들어갔을 때 UI의 함수를 호출하는 상황이다.
void printSalesHistory() {
    PrintSalesHistory printSalesHistory(&user);
    PrintSalesHistoryUI printSalesHistoryUI(out_fp, &printSalesHistory);
    
    printSalesHistoryUI.getHistory();
}
