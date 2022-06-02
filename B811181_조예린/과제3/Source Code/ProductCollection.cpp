#include "ProductCollection.h"


Product* ProductCollection::findFirst() { return this->productCollection[0]; }

//Product* ProductCollection::getNext(){}

void ProductCollection::addProduct(Product* newProd)
{
	this->productCollection[this->numProd++] = newProd;
}

Product* ProductCollection::findProduct(string prodName)
{
	for (int i = 0; i < this->numProd; i++)
	{
		if ((this->productCollection[i])->getName() == prodName) { return this->productCollection[i]; }
	}

	return NULL;
}
