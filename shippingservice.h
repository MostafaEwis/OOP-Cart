#ifndef shippingservice_h
#define shippingservice_h
#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include "shippable.h"

class ShippingService{
public:
	static void service(std::vector<std::pair<Shippable*, int>>& items){
		std::cout << "** shipment notice **" << std::endl;
		for(auto item : items){
			std::cout << std::left
				<<item.second << "x " <<
				std::setw(20) <<
				item.first -> getName() <<
				item.first -> getWeight()<<
				"g"
				<<std::endl;
		}
	}
};
#endif
