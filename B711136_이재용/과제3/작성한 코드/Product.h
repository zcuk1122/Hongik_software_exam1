#pragma once

#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
	string name;				// ��ǰ��
	string sellerID;			// �Ǹ����� ID
	string prodCompany;			// ����ȸ���
	int price;					// ��ǰ ����
	int quantity;				// ���� ����
    int sold;
	double avgRating = 0;		// ��� ���� ������

public:
	// ������
	Product(){}
    
	Product(string name, string sellerID, string prodCompany, int price, int quantity){
		this->name = name;
		this->sellerID = sellerID;
		this->prodCompany = prodCompany;
		this->price = price;
		this->quantity = quantity;
	}

	// Getter
	string getName();

	// ��ǰ�� �������� ���� ��� ���Ŀ� ���� string���� ��ȯ ([�Ǹ���ID] [��ǰ��] [����ȸ���] [����] [��������] [��� ���Ÿ�����])
	string getProductDetails();
    
    
    string getProductOnSaleDetails();
    
    string getProductStatistics();
    
    int getQuantity();
};

