#include <iostream>
#include <cstring>
using namespace std;
void Sort(char** input, int n){
	int k;
	for(int j = 0; j < n-1; j++){
		for(int i = 0; i < n-j-1; i++){
			if(strcmp(input[i], input[i+1]) > 0){
				//cout<<j<<" "<<i<<endl;
				cout<<input[i]<<" "<<input[i+1]<<endl;
				char* temp = input[i];
				input[i] = input[i+1];
				input[i+1] = temp;
				cout<<input[i]<<" "<<input[i+1]<<endl;
			}
		}
	}
	int j;
	for(int i = 0; i < n; i++){
		j = 0;
		while(input[i][j] != '\0'){
			cout<<input[i][j];
			j++;
		}cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	char** input = new char*[n];
	cin.ignore();
	for(int i = 0; i < n; i++){
		input[i] = new char[101];
		cin.getline(input[i], 100);
	}
	Sort(input, n);
	return 0;
}