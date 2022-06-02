#include "Product.h"

// Getter
string Product::getName() { return this->name; }
string Product::getSellerID() { return this->sellerID; }
int Product::getQuantity() { return this->quantity; }


// 4.1
// 4.3 
// ��ǰ�� �˻��Ͽ� �������� ����ϴ� �Լ� ([�Ǹ���ID] [��ǰ��] [����ȸ���] [����] [��������] [��� ���Ÿ�����])
string Product::getProductDetails()
{
    string details = this->sellerID + " " + this->name + " " + this->prodCompany + " " + to_string(this->price) + " " + to_string(this->quantity) + " " + to_string(this->avgRating) + "\n";
    return details;
}

// 4.2 
// ��ǰ ���� �� �ش� ��ǰ�� ���� ���� ��Ű�� �Լ� 
void Product::reduceQuantity()
{
    if ((this->quantity) != 0)
    {
        (this->quantity)--;
        (this->sold)++;
    }
}

// 4.4
// ��� �������� ����Ͽ� ��ǰ ������ �ݿ��ϴ� �Լ�
void Product::putRating(double rating)
{
    double sum = ratingCount * avgRating + rating;      // sum = (���ڼ�) * (��� ������) + (rating)
    avgRating = sum / (++ratingCount);                  // ���� �� ����
                                                        // (��� ������) = sum / (���ڼ�)
    // ��� ���
}



// �ڽ��� �Ǹ� ��ǰ ��ȸ�� ����ϴ� �Լ� (productName, productComany, price, quantity)
string Product::getProductOnSaleDetails() {
    string details = this->name + " " + this->prodCompany + " " + to_string(this->price) + " " + to_string(this->quantity);
    return details;
}

// ��� ���� ��� �Լ� (productName, whole price, avgRating)
string Product::getProductStatistics() {
    int price = sold * this->price;
    string statistics = this->name + " " + to_string(price) + " " + to_string(avgRating);
    return statistics;
}
