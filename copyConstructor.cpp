#include<iostream>
using namespace std;
class Student{
	public:
		int rollNumber;
		string name;
		int* agePtr;
	     
	    Student(string name, int age, int rollNumber){
	    	this-> name = name;
	    	agePtr = new int;
	    	*agePtr = age;
	    	this-> rollNumber = rollNumber;
		}
		
		Student (Student &obj){ // shallow copy
			this->name = obj.name;
			this->agePtr = obj.agePtr;
			this->rollNumber = obj.rollNumber;	
		}
		
		Student (Student &obj){ // deep copy
			this->name = obj.name;
			this->agePtr=new int;
		    *agePtr=*(obj.agePtr);
			this->rollNumber = obj.rollNumber;	
		}

		void getInfo(){
			cout << "Name: " << this->name << endl;
			cout << "Age: " << *agePtr << endl;
			cout << "Roll Number: " << this->rollNumber << endl;
		} 
};

int main(){
	Student s1("Ali", 21, 43);
	s1.getInfo();
	Student s2(s1);
	*(s2.agePtr)= 31;
	s1.getInfo();
	s2.getInfo();	
	return 0;
}