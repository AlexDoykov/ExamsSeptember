#include <iostream>
#include <fstream>
#include "Product.h"
#define MAX 100

bool is_empty_char(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

int main(){
	int size;
	Product product(size);
	Product product1(size),product2(size);
	product.setName("xxxxx");
	product.setPrice(14.44);
	product.setNumber(334);
	product1.setName("xyyyyy");
	product1.setPrice(55.43);
	product1.setNumber(8876);
	std::ofstream outf ("products1.txt");
	outf << product1;
	outf << product;
	outf << product1;
	outf.close();
	int i = 0;
	while (!inf.eof() && !is_empty_char(inf.peek())) {
		std::ifstream inf ("products1.txt");
		inf >> product1;
		inf.close();
		std::ofstream outfile ("products2.txt");
		for(int i = 0; i < size; i++){
			Product p;
			for(int j = i+1; j < size; j++){
				if(products[i].getNumber() == products[j].getNumber()){
					if(products[i].getPrice() > p.getPrice())
						p = products[i];
				}
			}
			outfile << products[i];
		}
		outfile.close();
		i++;
	}
	size = i;
	return 0;
}