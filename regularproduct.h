#ifndef RegularProduct_h
#define RegularProduct_h
#include "product.h"
#include <vector>

class RegularProduct : virtual public Product{
public:
	RegularProduct(std::string name, float price, int quantity): Product(name, price, quantity){};
	std::vector<float> checkout(){
		return std::vector<float>{price};
	}

};

#endif
