#ifndef shippable_h
#define shippable_h
#include "product.h"
#include <vector>

class Shippable : public Product{
public:
	std::vector<float> checkOut(){
		std::vector<float> some = {price, weight};
		return some;
	}
	Shippable(std::string name_, float price_, int quantity_, float weight_):Product(name_, price_, quantity_), weight(weight_){}
	float getWeight(){
		return weight;
	}

private:
	float weight;
};

#endif
