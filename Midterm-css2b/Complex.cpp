#include "Complex.hpp"
Complex::Complex()
{
  real = 0;
  imaginary = 0;
}
Complex::Complex(double real, double imaginary)
{
  setReal(real);
  setImaginary(imaginary);
}
ostream& operator <<(ostream& out, const Complex& c)
{
  // This function displays the complex object as "real + imaginary i"
  out << c.real << " + " << c.imaginary << " i" << endl;
  return out;
}
Complex operator +(const Complex& cleft, const Complex& cright)
{
  Complex result;
  // This function adds the cleft's real to cright's real and stores it in the
  // resulting real variable of the complex object.
  result.real = (cleft.real + cright.real);
  // Then it adds cleft's imaginary with cright's imaginary and stores it in the
  // resulting imaginary variable of the complex object.
  result.imaginary = (cleft.imaginary + cright.imaginary);
  // It returns a new complex object with these two updated values
  return result;
}
Complex operator -(const Complex& cleft, const Complex& cright)
{
  Complex result;
  // This function subtracts the cleft's real from the cright's real and stores it in the
  // resulting real variable of the complex object.
  result.real = (cleft.real - cright.real);
  // Then it subtracts cleft's imaginary with cright's imaginary and stores the result in the
  // resulting imaginary variable of the complex object.
  result.imaginary = (cleft.imaginary - cright.imaginary);
  // It returns a new complex object with these two updated values
  return result;
}
bool operator ==(Complex& cleft, const Complex& cright)
{
  // Two complex objects are the same if their real and imaginary variables
  // have the same value.
  return (cleft.real == cright.real) && (cleft.imaginary == cright.imaginary);
}
bool operator !=(Complex& cleft, const Complex& cright)
{
  // Two complex objects are not equal if their real or imaginary variables have
  // mismatching values
  return (cleft.real != cright.real) || (cleft.imaginary != cright.imaginary);
}