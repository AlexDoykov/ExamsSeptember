#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	char** input = new char* [n];
	cin.ignore();
	for(int i = 0; i < n; i++){
		input[i] = new char[101];
		cin.getline(input[i],100);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1-i; j++){
			if(strlen(input[j]) > strlen(input[j+1])){
				char* swap = input[j];
				input[j] = input[j+1];
				input[j+1] = swap;
			}
		}
	}

	for(int i = 0 ; i < n; i++){
		int j = 0;
		cout<<input[i]<<endl;
	}

	return 0;
}