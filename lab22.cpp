#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
		ComplexNumber operator+(double);
        ComplexNumber operator-(double);
        ComplexNumber operator*(double);
        ComplexNumber operator/(double);

        bool operator==(double);

        friend ComplexNumber operator+(double, const ComplexNumber &);
        friend ComplexNumber operator-(double, const ComplexNumber &);
        friend ComplexNumber operator*(double, const ComplexNumber &);
        friend ComplexNumber operator/(double, const ComplexNumber &);

        friend bool operator==(double, const ComplexNumber &);

        friend ostream& operator<<(ostream&, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here.

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real - imag*c.imag,
	                     real*c.imag + imag*c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double denom = c.real*c.real + c.imag*c.imag;
	return ComplexNumber((real*c.real + imag*c.imag)/denom,
	                     (imag*c.real - real*c.imag)/denom);
}

ComplexNumber ComplexNumber::operator+(double d){
	return ComplexNumber(real+d, imag);
}

ComplexNumber ComplexNumber::operator-(double d){
	return ComplexNumber(real-d, imag);
}

ComplexNumber ComplexNumber::operator*(double d){
	return ComplexNumber(real*d, imag*d);
}

ComplexNumber ComplexNumber::operator/(double d){
	return ComplexNumber(real/d, imag/d);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	return real==c.real && imag==c.imag;
}

bool ComplexNumber::operator==(double d){
	return real==d && imag==0;
}

ComplexNumber operator+(double d, const ComplexNumber &c){
	return ComplexNumber(d+c.real, c.imag);
}

ComplexNumber operator-(double d, const ComplexNumber &c){
	return ComplexNumber(d-c.real, -c.imag);
}

ComplexNumber operator*(double d, const ComplexNumber &c){
	return ComplexNumber(d*c.real, d*c.imag);
}

ComplexNumber operator/(double d, const ComplexNumber &c){
	double denom = c.real*c.real + c.imag*c.imag;
	return ComplexNumber((d*c.real)/denom,
	                     (-d*c.imag)/denom);
}

bool operator==(double d, const ComplexNumber &c){
	return c.real==d && c.imag==0;
}

double ComplexNumber::abs(){
	return sqrt(real*real + imag*imag);
}

double ComplexNumber::angle(){
	return atan2(imag, real) * 180.0 / M_PI;
}

ostream& operator<<(ostream& os, const ComplexNumber &c){
	if(c.real==0 && c.imag==0){
		os << 0;
	}
	else if(c.imag==0){
		os << c.real;
	}
	else if(c.real==0){
		if(c.imag==1) os << "i";
		else if(c.imag==-1) os << "-i";
		else os << c.imag << "i";
	}
	else{
		os << c.real;
		if(c.imag > 0) os << "+" << c.imag << "i";
		else os << c.imag << "i";
	}
	return os;
}
