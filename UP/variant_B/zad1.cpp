#include <iostream>
using namespace std;
int main(){
	//в общия случай как трябва да постъпвам когато не ми е даден размер на входа?
	char input[200];
	cin.getline(input, 200);
	int countLetters = 0,answer = 0, i = 0;
	while(input[i] != '\0'){
		if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){
			countLetters++;
		}else{
			if(countLetters > 0){
				answer++;
				countLetters = 0;
			}
		}
		i++;
	}
	if(countLetters > 0){
		answer++;
		countLetters = 0;
	}
	cout<<answer<<endl;
	return 0;
}