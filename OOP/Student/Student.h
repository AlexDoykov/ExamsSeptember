#include <iostream>
#include <cstring>
class Student
{
private:
	char* name;
	int facultyNumber;
	double mark;
public:
	char const* getName() const;
	void setName(const char* _name);

	int getFacultyNumber() const;
	void setFacultyNumber(int _facultyNumber);
	
	double getMark() const;
	void setMark(double _mark);

	Student();
	Student(const Student&);
	Student& operator = (const Student&);
	~Student();

	friend std::ostream& operator << (std::ostream&, const Student&);
	friend std::istream& operator >> (std::ifstream& in, Student&);

};