#pragma once

#include "Product.h"
#include <string>
using namespace std;

#define MAX_PRODUCT 1000

class ProductCollection
{
private:
	Product* productCollection[MAX_PRODUCT];
	int numProd = 0;

public:
	ProductCollection()
		:numProd(0) {}

	Product* findFirst();
	void addProduct(Product* newProd);
	Product* findProduct(string prodName);
};
