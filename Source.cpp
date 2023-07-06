#include<iostream>
#include<fstream>
#include<cmath>
using namespace std; 
class Fraction
{
private :
	int numerator; 
	int denominator; 
public:
	Fraction()
	{
		this->numerator = 0; 
		this->denominator = 1; 
	}
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator; 
		this->denominator = denominator; 
	}
	Fraction(const Fraction& fr)
	{
		this->numerator = fr.numerator; 
		this->denominator = fr.denominator; 
	}
	int UCLN(int a, int b)
	{
		a = abs(a); 
		b = abs(b); 
		if (a != b)
		{
			while (a!=b)
			{
				if (a > b)
				{
					a -= b; 
				}
				else
				{
					b -= a; 
				}
			}
			return a; 
		}
		else
		{
			return 1; 
		}
	}
	void rutGon()
	{
		int ucln = this->UCLN(this->numerator, this->denominator); 
		this->numerator = this->numerator / ucln; 
		this->denominator = this->denominator / ucln; 

	}
	friend istream& operator>>(istream& is, Fraction& fr)
	{
		is >> fr.numerator; 
		is >> fr.denominator; 
		fr.rutGon(); 
		return is; 
		
	}
	friend Fraction operator + (const Fraction f1, const Fraction f2)
	{
		Fraction tamp; 
		tamp.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator); 
		tamp.denominator = f1.denominator * f2.denominator; 
		tamp.rutGon(); 
		return tamp; 
 	}
	friend Fraction operator / (const Fraction f1, const Fraction f2)
	{
		Fraction tamp; 
		tamp.numerator = f1.numerator * f2.denominator; 
		tamp.denominator = f1.denominator * f2.numerator; 
		tamp.rutGon();
		return tamp;  
 	}
	friend bool operator == (const Fraction f1, const Fraction f2)
	{
		double tu1 = double(f1.numerator); 
		double mau1 = double(f1.denominator);
		double tu2 = double(f2.numerator);
		double mau2 = double(f2.denominator);
		if ((tu1 / mau1) == (tu2 / mau2))
		{
			return true; 
		}
		else
		{
			return false; 
		}

	}
	friend ostream& operator<<(ostream& os, const Fraction& fr)
	{
		if (fr.numerator == 0)
		{
			os << "0"; 
	    }
		else if (fr.numerator == fr.denominator)
		{
			os << "1"; 
		}
		else if (fr.denominator == 1)
		{
			if (fr.numerator > 0)
			{
				os << abs(fr.numerator); 
			}
			else
			{
				os << "-" << abs(fr.numerator); 
			}
		}
		else if (fr.denominator == -1)
		{
			if (fr.numerator > 0)
			{
				os << "-"<<abs(fr.numerator);
			}
			else
			{
				os<< abs(fr.numerator);
			}
		}
		else if (fr.numerator * fr.denominator < 0)
		{
			os << "-" << abs(fr.numerator) << "/" << abs(fr.denominator); 
		}
		else
		{
			os << abs(fr.numerator) << "/" << abs(fr.denominator); 
		}
		return os; 
	}
	
	
};
int main()
{
	Fraction f1, f2; 
	cout << "Nhap F1 :"; 
	cout << "\n"; 
	cin >> f1; 
	cout << "Nhap F2 :";
	cout << "\n"; 
	cin >> f2; 
	cout << "F1:" << f1; 
	cout << "\n"; 
	cout << "F2:" << f2;
	cout << "\n"; 
	cout << "F1+F2 :" << f1 + f2; 
	cout << "\n"; 
	cout << "F1/F2:" << f1 / f2; 
	cout << "\n"; 
	if (f1 == f2)
	{
		cout << "Hai phan so bang nhau"; 
	}
	else
	{
		cout << "Hai phan so khac nhau "; 
	}
	return 0; 
}