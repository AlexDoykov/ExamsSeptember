#include <iostream>
#include <cstring>
using namespace std;

char* getduplicates(const char* s){
	int i = 0;
	char* buffer = new char[strlen(s)+1];
	int bufferSize = 0;
	buffer[bufferSize] = '\0';
	while(s[i] != '\0'){
		int j = 0;
		bool found = 0;
		while(s[j] != '\0'){
			if(s[j] == s[i] && i != j){
				found = 1;
				break;
			}
			j++;
		}
		if(found == 1){
			found = 0;
			buffer[bufferSize++] = s[i];			
			buffer[bufferSize] = '\0';
		}
		i++;
	}
	char* result = new char[bufferSize+1];
	strcpy(result, buffer);
	delete[] buffer;
	return result;
}

int main(){
	char input[500];
	cin.getline(input, 500);
	char* answer = getduplicates(input);
	cout<<answer<<endl;
	return 0;
}