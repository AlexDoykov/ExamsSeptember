#include <iostream>
#include <fstream>
#include "Student.h"

bool isEmptyChar(char ch){
	return ch == ' ' || ch == '\n' || ch == '\t';
}


bool isChecked(const Student& student, const int* seen, int n){
	for(int j = 0; j < n; j++){
		if(seen[j] == student.getFacultyNumber()){
			return 1;
		}
	}
	return 0;
}

double calculateAverageMark(const Student& student, const Student* students, int currentStudent, int n){
	double marks = student.getMark();
	int countDuplicates = 1;
	for(int j = currentStudent+1; j < n; j++){
		if(student.getFacultyNumber() == students[j].getFacultyNumber()){
			marks += students[j].getMark();
			countDuplicates++;
		}
	}
	return marks/countDuplicates;
}

int main(){
	Student students[100];
	std::ifstream readFile("students1.txt");
	int i = 0;
	while(!readFile.eof() && !isEmptyChar(readFile.peek())){
		readFile>>students[i];
		i++;
	}
	readFile.close();
	int n = i;
	int seen[100];
	for(i = 0; i < n; i++){
		seen[i] = 0;
	}
	std::ofstream outFile("studens2.txt");
	int k = 0;
	for(i = 0; i < n; i++){
		double averageMark = calculateAverageMark(students[i], students, i, n);
		bool found = isChecked(students[i], seen, n);
		if(found == 0){
			seen[k] = students[i].getFacultyNumber();
			k++;
			students[i].setMark(averageMark);
			outFile << students[i];
		}else{
			found = 0;
		}
	}
	return 0;
}