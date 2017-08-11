#include <iostream>
using namespace std;
int main(){
	int br = 0,cnt = 0;
	char input[200];
	cin.getline(input, 200);
	int i = 0;
	while(input[i] != '\0'){
		if(((int)input[i]) <= '9' && (int)input[i] >= '0'){
			br++;
		}else{
			if(br > 0){
				cnt++;
				br = 0;
			}
		}
		i++;
	}
	if(br > 0){
		cnt++;
		br = 0;
	}
	cout<<cnt<<endl;
	return 0;
}	