//Nama		: Muhammad Farhan
//Tanggal	: 1 Februari 2018

#include <iostream>
#include "Time.h"
using namespace std;

//ctor tanpa parameter
Time::Time() {
	setHour(0);
	setMinute(0);
	setSecond(0);
}


//ctor dengan parameter
Time::Time(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
}


//cctor
Time::Time(const Time& T) {
	setHour(T.hour);
	setMinute(T.minute);
	setSecond(T.second);
}


//dtor
Time::~Time() {

}


//Setter & Getter
void Time::setHour(int h) {
	hour = h;
}

void Time::setMinute(int m) {
	minute = m;
}

void Time::setSecond(int s) {
	second = s;
}

int Time::getHour() const {
	return hour;
}

int Time::getMinute() const {
	return minute;
}

int Time::getSecond() const {
	return second;
}


//Konversi ke detik
int Time::convertToSecond() {
	return ((hour*3600) + (minute*60) + second);
}


//Menuliskan waktu ke layar (format: hh:mm:ss)
void Time::printTime() {
	if (hour < 10) {
		cout << 0 << hour << ':';
	} else {
		cout << hour << ':';
	}
	if (minute < 10) {
		cout << 0 << minute << ':';
	} else {
		cout << minute << ':';
	}
	if (second < 10) {
		cout << 0 << second << endl;
	} else {
		cout << second << endl;
	}
}


//Operator Overloading
Time Time::operator+(const Time& T) {
	Time newT = T;
	int totalsec = convertToSecond() + newT.convertToSecond();

	newT.setHour((totalsec/3600)%24);
	newT.setMinute((totalsec%3600)/60);
	newT.setSecond(totalsec%60);

	return newT;
}

Time Time::operator-(const Time& T) {
	Time newT = T;
    int totalsec = convertToSecond() - newT.convertToSecond();

	if (totalsec < 0) {
        newT = *this;
	} else {
		newT.setHour(totalsec/3600);
		newT.setMinute((totalsec%3600)/60);
		newT.setSecond(totalsec%60);
	}

	return newT;
}

Time& Time::operator=(const Time& T) {
	setHour(T.hour);
	setMinute(T.minute);
	setSecond(T.second);

	return *this;
}

bool Time::operator<(const Time& T) {
	Time newT = T;
    int totalsec = convertToSecond() - newT.convertToSecond();

	return (totalsec < 0);
}

bool Time::operator>(const Time& T) {
	return !(*this < T);
}
