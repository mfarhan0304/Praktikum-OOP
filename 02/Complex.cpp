//Nama		: Muhammad Farhan
//Tanggal	: 1 Februari 2018

#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex() {
	setReal(0);
	setImaginer(0);
}

Complex::Complex(int re, int im) {
	setReal(re);
	setImaginer(im);
}

Complex::Complex(const Complex &comp) {
	setReal(comp.real);
	setImaginer(comp.imaginer);
}

Complex::~Complex() {

}

int Complex::getReal() {
	return real;
}

int Complex::getImaginer() {
	return imaginer;
}

void Complex::setReal(int re) {
	real = re;
}

void Complex::setImaginer(int im) {
	imaginer = im;
}

Complex Complex::operator + (Complex const &comp) {
	Complex C;
	C.setReal(real + comp.real);
	C.setImaginer(imaginer + comp.imaginer);
	return C;
}

Complex Complex::operator - (Complex const &comp) {
	Complex C;
	C.setReal(real - comp.real);
	C.setImaginer(imaginer - comp.imaginer);
	return C;
}

Complex Complex::operator * (Complex const &comp) {
	Complex C;
	C.setReal((real * comp.real) - (imaginer * comp.imaginer));
	C.setImaginer((real * comp.imaginer) + (imaginer * comp.real));
	return C;
}
