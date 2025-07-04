#include <iostream>
#include <vector>
#include "product.h"
#include "shippable.h"

using namespace std;

int main(int argc, char** argv){
	//Product prod("ewis", 10, 10);
	Shippable shipment("mohab", 10, 10, 55);
	//cout << prod.getName() << endl;
	cout << shipment.getName() << endl;
	return 0;
}
