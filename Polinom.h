#pragma once
#include <vector>
#include "monom.h"
#include <algorithm>
class Polinom
{
private:
	vector <monom> monoms;
public:
	
	Polinom(const vector <monom>& monoms)
	{
		vector <monom> vec(monoms);
		sort(vec.begin(), vec.end(), cmp);//сортировка
		this->monoms = vec; //вектор мономов есть указатель на него
	}
	static bool cmp(const monom &left, const monom &right)
	{
		return left.getDegree() > right.getDegree(); //сравнение мономов
	}
	const vector<monom>& getMonoms() const
	{
		return monoms;
	}
	friend Polinom operator+(const Polinom& left, const Polinom& right)
	{
		vector<monom> res(left.monoms);
		for (int i = 0; i < right.monoms.size(); i++)
		{
			bool gerb = true;
			int deg = right.monoms[i].getDegree();
			int cf = right.monoms[i].getCoef();
			for (int j = 0; j < left.monoms.size(); j++)
			{
				if (deg == res[j].getDegree())
				{
					res[j] = monom(cf + res[j].getCoef(), deg);
					gerb = false; //если нашелся такой
				}

			}
			if (gerb) //если такого не нашлось
			{
				res.push_back(right.monoms[i]);
			}

		}

		return clear(Polinom(res));
	}
	friend Polinom derivation(const Polinom& poly)
	{
		vector<monom> res(poly.monoms);
		for (int i = 0; i < poly.monoms.size(); i++)
		{
			res[i] = monom_derivation(poly.monoms[i]);
		}
		return (Polinom(res));
	}
	friend double point(const Polinom& poly, double point)
	{
		double res = 0;
		for (int i = 0; i < poly.monoms.size(); i++)
		{
			res = res + monom_point(poly.monoms[i],point);
		}
		return res;
	}
	friend Polinom clear(const Polinom& pol)
	{
		auto vec = pol.monoms;
		sort(vec.begin(), vec.end(), cmp);
		auto it = vec.begin();
		int cf = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			if (pol.monoms[i].getCoef() == 0)
			{
				vec.erase(it + cf);
				it = vec.begin();
				cf--;
			}
			cf++;
		}
		if (vec.size() == 0)
		{
			vec.push_back(monom(0, 0));
		}
		return Polinom(vec);
	}
	//умножение на моном
	friend Polinom operator*(const Polinom& pol, const monom& mon)
	{
		vector <monom> res(pol.monoms);
		for (auto& re: res)
		{
			re = re * mon; //каждый моном умножаем на наш моном
		}
		return clear(Polinom(res)); //{res}
	}
	//умножение на число
	friend Polinom operator*(const Polinom& pol, const int number)
	{
		vector <monom> res(pol.monoms);
		for (auto& re : res)
		{
			re = number * re; //умножаем
		}
		return clear(Polinom(res)); //вдруг умножили на ноль
	}
	//умножение полиномов
	friend  Polinom operator*(const Polinom& left, const Polinom& right)
	{
		vector <monom> vec(left.monoms);
		Polinom res({});
		for (auto& m : vec)
		{
			res = res + right * m;
		}
		return res;
	}
	friend bool operator==(const Polinom& left, const Polinom& right)
	{
		return left.monoms == right.monoms;
	}
	friend string str(Polinom pol)
	{
		string res = " ";
		for (int i = 0; i < pol.monoms.size(); i++)
		{
			res += str(pol.monoms[i]);
			if (i != pol.monoms.size() - 1)
			{
				res += " + ";
			}
		}
		return res;
	}
	friend ostream& operator <<(std::ostream& os, const Polinom& pol)
	{
		return os << str(pol);
	}
};

