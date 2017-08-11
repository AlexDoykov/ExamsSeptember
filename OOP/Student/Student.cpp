#include "Student.h"
#include <iostream>
#include <cstring>
#include <fstream>

void Student::setName(const char* _name){
	if(strlen(_name) > strlen(name)){
		delete[] name;
		name = new char[strlen(_name)+1];
	}
	strcpy(name,_name);
}
const char* Student::getName() const{
	return name;
}

int Student::getFacultyNumber() const{
	return facultyNumber;
}
void Student::setFacultyNumber(int _facultyNumber){
	facultyNumber = _facultyNumber;
}

double Student::getMark() const{
	return mark;
}
void Student::setMark(double _mark){
	mark = _mark;
}

Student::Student(){
	name = new char[strlen("")+1];
	name[0] = '\0';
	mark = 0.0;
	facultyNumber = 0;
}

Student::Student(const Student& other){
	name = new char[strlen(other.name)+1];
	strcpy(name,other.name);
	facultyNumber = other.facultyNumber;
	mark = other.mark;
}

Student& Student::operator = (const Student& other){
	setName(other.name);
	facultyNumber = other.facultyNumber;
	mark = other.mark;
}

Student::~Student(){
	delete[] name;
}

std::ostream& operator << (std::ostream& out, const Student& student){
	out<<student.name<<" ,"<<student.facultyNumber<<","<<student.mark<<"\n";
}

std::istream& operator >> (std::ifstream& in, Student& student){
	char name[500];
	in>>name;
	student.setName(name);
	in.get();
	in.get();
	in>>student.facultyNumber;
	in.get();
	in>>student.mark;
	in.get();
}