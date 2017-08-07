#include <iostream>
#include <fstream>
#include "Product.h"
#define MAX 100

bool is_empty_char(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

int main(){
	int size;
	bool flag = 0;
	int numbers[MAX];
	Product product;
	Product product1,product2;
	product.setName("xxxxx");
	product.setPrice(14.44);
	product.setNumber(334);
	product1.setName("xyyyyy");
	product1.setPrice(55.43);
	product1.setNumber(8876);
	product2.setName("zzzzz");
	product2.setPrice(1000.43);
	product2.setNumber(8876);
	std::ofstream outf ("products1.txt");
	outf << product1;
	outf << product;
	outf << product1;
	outf << product2;
	outf.close();
	int i = 0;
	std::ifstream inf ("products1.txt");
	Product products[MAX];
	while (!inf.eof() && !is_empty_char(inf.peek())) {
		inf >> products[i];
		i++;
	}
	size = i-1;
	inf.close();
	int k = 0;
	for(int i = 0; i < size; i++){
		numbers[i] = 0;
	}
	std::ofstream outfile ("products2.txt");
	for(int i = 0; i < size; i++){
		Product p;
		for(int j = 0; j < size; j++){
			if(products[i].getNumber() == products[j].getNumber()){
				if(products[i].getPrice() >= products[j].getPrice()){
					p = products[i];
				}else{
					p = products[j];
				}
				if(products[i].getNumber() == numbers[j]){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0){
			outfile << p;
			numbers[k] = p.getNumber();
			k++;
		}else{
			flag = 0;
		}
	}

	outfile.close();

	size = i;
	return 0;
}