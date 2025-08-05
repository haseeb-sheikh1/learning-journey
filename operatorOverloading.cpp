	#include<iostream>
	using namespace std;
	class Distance{
		private:
			double feet;
			double inches;

		public:
			Distance(double feet, double inches): feet(feet), inches(inches){}
		bool operator== (const Distance &other){
		if ((this->feet == other.feet) && (this->inches == other.inches)){
		 return true;
		}
		else {
			return false;
		}
	   }	 
	};
	 int main ()
	 {
	 	Distance d1(10,20);
	 	Distance d2(30,33);
	 	bool isEqual;
		isEqual = d1==d2;
	         return 0;
	 }
