#include "Money.h"

Money operator+(Money m1, Money m2)
{
	Money res(m1.rub + m2.rub, m1.kop + m2.kop);
	res.Reduction();
	return res;
}

Money operator+(Money m, int amount)
{
	return m + Money(amount);
}

Money operator+(int amount, Money m)
{
	return m + Money(amount);
}

Money operator-(Money m1, Money m2)
{
	return m1 + -m2;
}

bool operator>(Money m1, Money m2)
{
	return (m1.rub * 100 + m1.kop) > (m2.rub * 100 + m2.kop);
}

bool operator>(Money m1, int amount)
{
	return m1 > Money(amount);
}

bool operator<=(Money m1, Money m2)
{
	return !(m1 > m2);
}

bool operator<(Money m1, Money m2)
{
	return (m1.rub * 100 + m1.kop) < (m2.rub * 100 + m2.kop);
}

bool operator==(Money m1, Money m2)
{
	return (m1.rub * 100 + m1.kop) == (m2.rub * 100 + m2.kop);
}

std::ostream& operator<<(std::ostream& out, Money m)
{
	out << m.rub << " rub, " << m.kop << " kop.";
	return out;
}

Money Money::operator-()
{
	return Money(-this->rub, this->kop);
}

Money Money::operator++()
{
	return Money(++this->rub, this->kop);
}

Money Money::operator++(int)
{
	Money copy = *this;
	++(*this);
	return copy;
}
