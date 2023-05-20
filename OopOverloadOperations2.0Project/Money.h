#pragma once
#include <iostream>

class Money
{
	int rub;
	int kop;

	void Reduction()
	{
		rub += kop / 100;
		kop %= 100;
	}
public:
	Money(int rub, int kop) 
		: rub{ rub }, kop{ kop } { Reduction(); }
	
	Money(int amount) : Money(0, amount) {}
	Money() : Money(0, 0) {}

	int& Rub() { return this->rub; }
	int& Kop() { return this->kop; }

	Money operator-();

	friend Money operator+(Money m1, Money m2);
	friend Money operator+(Money m, int amount);
	friend Money operator+(int amount, Money m);

	friend Money operator-(Money m1, Money m2);

	Money operator++();
	Money operator++(int);

	friend bool operator>(Money m1, Money m2);
	friend bool operator>(Money m1, int amount);

	friend bool operator<=(Money m1, Money m2);
	friend bool operator<(Money m1, Money m2);
	friend bool operator==(Money m1, Money m2);

	friend std::ostream& operator<<(std::ostream& out, Money m);
	
};

