#ifndef COMPLEX_H
#define COMPLEX_H
#include <fstream>
using namespace std;
class Complex
{
  public:
    Complex();
    Complex(double real, double imaginary);

    void setReal(double real){this->real=real;}
    void setImaginary(double imaginary){this->imaginary=imaginary;}
    
    double getReal() const{return real;}
    double getImaginary() const{return imaginary;}
    // overloaded operators
    friend ostream& operator <<(ostream& out, const Complex& c);
    friend Complex operator +(const Complex& cleft, const Complex& cright);
    friend Complex operator -(const Complex& cleft, const Complex& cright);
    friend bool operator ==(Complex& cleft, const Complex& cright);
    friend bool operator !=(Complex& cleft, const Complex& cright);
  private:
    double real, imaginary;
};
#endif // COMPLEX_H