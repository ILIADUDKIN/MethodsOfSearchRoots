#pragma once
#include <string>
#include <iostream>
using namespace std;
class monom
{
public:
	monom(int coeff, int degree) :coeff(coeff), degree(degree) {};
	int getCoef() const
	{
		return coeff;
	}
	int getDegree() const
	{
		return degree;
	}
	friend monom operator*(const monom& left, const monom& right) //умножение одночлена на одночлен
	{
		if (left.coeff == 0 || right.coeff == 0) return { 0, 0 };
		return { left.coeff * right.coeff, left.degree + right.degree };
	}
	friend monom operator*(const int number, const monom& mon)
	{
		if (number == 0) return { 0, 0 };
		return { number * mon.coeff, mon.degree };
	}
	friend bool operator==(const monom& left, const monom& right)
	{
		return left.degree == right.degree && right.coeff == left.coeff;
	}
	 monom& operator=(const monom& mon)
	{
		if (&mon == this)
		{
			return *this;
		}
		degree = mon.degree;
		coeff = mon.coeff;
		return *this;
	}
	friend string str(const monom mon)
	{
		if (mon.coeff == 0) return "0";
		string cf; //строка под коэффициент
		cf = to_string(mon.coeff); //делаем из него строку
		if (mon.degree == 0) return cf;
		//иначе не ноль
		string res = "x";
		if (mon.coeff != 1) res = cf + res; //если коэф не единичный, то приписываем
		if (mon.degree != 1) res = res + "^" + to_string(mon.degree);
		return res;
	}
	friend ostream& operator <<(std::ostream& os, const monom& mon)
	{
		return os << str(mon);

	} 
	//взятие производной
	friend monom monom_derivation(const monom &mon)
	{
		if (mon.degree != 0)
			return { mon.coeff * mon.degree, mon.degree - 1 };
		else return { 0 , 0 };
	}
	friend double monom_point(const monom& mon, double point)
	{
		 return mon.coeff * pow(point, mon.degree);
	}

private:
	int degree; //степень многочлена
	int coeff; //коэффициент монома
};

