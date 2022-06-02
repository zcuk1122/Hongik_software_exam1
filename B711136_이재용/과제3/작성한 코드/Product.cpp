#include "Product.h"

string Product::getName() { return this->name; }


// ��ǰ�� �������� ���� ��� ���Ŀ� ���� string���� ��ȯ ([�Ǹ���ID] [��ǰ��] [����ȸ���] [����] [��������] [��� ���Ÿ�����])
string Product::getProductDetails()
{
	string details = this->sellerID + " " + this->name + " " + this->prodCompany + " " + to_string(this->price) + " " + to_string(this->quantity) + " " + to_string(this->avgRating) + "\n";
	return details;
}

// print (productName, productComany, price, quantity)
string Product::getProductOnSaleDetails() {
    string details = this->name + " " + this->prodCompany + " " + to_string(this->price) + " " + to_string(this->quantity);
    return details;
}

int Product::getQuantity() {
    return this->quantity;
}

// print (productName, whole price, avgRating)
string Product::getProductStatistics() {
    int price = sold * this->price;
    string statistics = this->name + " " + to_string(price) + " " + to_string(avgRating);
    return statistics;
}
