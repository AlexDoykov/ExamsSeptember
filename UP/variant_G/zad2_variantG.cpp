#include <iostream>
using namespace std;
char* stripduplicates (const char* s){
	int i = 0, size = 0;
	bool found = 0;
	char* seen = new char[200];
	while(s[i] != '\0'){
		int j = 0;
		while(seen[j] != '\0'){
			if(s[i] == seen[j]){
				found = 1;
			}
			j++;
		}
		if(found == 0){
			cout<<s[i]<<endl;
			seen[size] = s[i];
			size++;
		}else{
			found = 0;
		}
		i++;
	}
	char* result = new char[size];
	i = 0;
	while(i < size){
		result[i] = seen[i];
		i++;
	}
	delete seen;
	return result;
}
int main(){
	char* input = new char[200];
	cin.getline(input, 200);
	char* show = stripduplicates(input);
	int i = 0;
	cout<<show<<endl;
	return 0;
}