#ifndef SHIPPABLE_H
#define SHIPPABLE_H

#include "product.h"
#include <vector>

class Shippable : virtual public Product{
public:
	Shippable(std::string name_, float price_, int quantity_, float weight_):Product(name_, price_, quantity_), weight(weight_){}
	float getWeight(){
		return weight;
	}
protected:
	std::vector<float> checkout(){
		return std::vector<float>{price, weight};
	}
private:
	float weight;
};

#endif
