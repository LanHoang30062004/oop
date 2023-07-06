#include<iostream>
#include<string>
using namespace std; 
class Person
{
protected:
	string name; 
	int yearOfBirth; 
public:
	Person()
	{

	}
	int getYear()
	{
		return this->yearOfBirth; 
	}
	void setYear(int year)
	{
		this->yearOfBirth = year; 
	}
	virtual void input()
	{
		cin.ignore(); 
		cout << "Nhap name :"; 
		getline(cin, this->name); 
		cout << "Nhap year of birth :"; 
		cin >> this->yearOfBirth; 
	}
	virtual void display()
	{
		cout << "Name :" << this->name; 
		cout << "\n"; 
		cout << "Year of birth :" << this->yearOfBirth; 
		cout << "\n"; 
	}
	virtual double calculateSalary() = 0; 
	

};
class Employee:public Person
{
private:
	float salaryCoffient; 
public:
	float getSalaryCoffient()
	{
		return this->salaryCoffient; 
	}
	void setSalaryCoffient(float salary)
	{
		this->salaryCoffient = salary; 
	}
	void input()
	{
		Person::input(); 
		cout << "Nhap salary coffient :"; 
		cin >> this->salaryCoffient; 
	}
	double calculateSalary()
	{
		return (double)this->salaryCoffient * 1500000;
	}
	void display()
	{
		Person::display();
		cout << "Salary Coffient:" << this->salaryCoffient; 
		cout << "\n"; 
		cout << "Salary :" << (size_t) this->calculateSalary();
	}
	
};
class FootballPlayer:public Person
{
private:
	int goals;
public:
	void input()
	{
		Person::input(); 
		cout << "Nhap Goals :"; 
		cin >> goals; 
	}
	double  calculateSalary()
	{
		return (double)10000000 + (goals * 350000);
	}
	void display()
	{
		Person::display(); 
		cout << "Goals :" << this->goals; 
		cout << "\n"; 
		cout << "Salary :" << (size_t) this->calculateSalary();
	}
	


};
class Group
{
private:
	int n; 
	Person** a;
public:
	void input()
	{
		cout << "Nhap so luong :"; 
		cin >> this->n; 
		this->a = new Person * [n]; 
		for (int i = 0; i < n; i++)
		{
			int job; 
			cout << "1. Employee" << "\n"; 
			cout << "2. Football Player" << "\n"; 
			cout << "Nhap Job :"; 
			cin >> job;
			if (job == 1)
			{
				this->a[i] = new Employee;
			}
			else
			{
				this->a[i] = new FootballPlayer; 
			}
			this->a[i]->input(); 
		}
	}
	void display()
	{
		for (int i = 0; i < this->n; i++)
		{
			cout << "Thong tin nhan vien thu " << i + 1 << "\n"; 
			this->a[i]->display(); 
			cout << "\n\n"; 
		}
	}
	void sort()
	{
		for (int i = 0; i < this->n; i++)
		{
			for (int k = i +1; k < this->n; k++)
			{
				if (this->a[i]->calculateSalary()>this->a[k]->calculateSalary()) 
				{
					swap(this->a[i], this->a[k]); 
				}
			}
		}
	}
	void increase()
	{
		for (int i = 0; i < this->n; i++)
		{
			Employee* ee = dynamic_cast<Employee*>(this->a[i]); 
			if (ee != nullptr && ee->getYear() < 1970)
			{
				ee->setSalaryCoffient(ee->getSalaryCoffient() + 0.33); 
			}
		}
	}
	void xoa(int viTriXoa, int& n)
	{
		Person** tam; 
		tam = new Person * [n]; 
		for (int i = 0; i < n; i++)
		{
			tam[i] = this->a[i]; 
		}
		delete[]a; 
		for (int i = viTriXoa; i < n; i++)
		{
			tam[i] = tam[i + 1]; 
		}
		n--; 
		this->a = new Person * [n]; 
		for (int i = 0; i < n; i++)
		{
			this->a[i] = tam[i]; 
		}
	}
	void remove()
	{
		int year; 
		cout << "Nhap nam tuoi ban muon xoa :"; 
		cin >> year; 
		for (int i = 0; i < n; i++)
		{
			if (this->a[i]->getYear() == year)
			{
				xoa(i, this->n); 
			}
		}
	}
	
};
int main()
{
	Group gr; 
	gr.input(); 
	gr.increase(); 
	gr.display(); 
	cout << "\n"; 
	gr.sort(); 
	cout << "Sort" << "\n";
	gr.display(); 
	cout << "\n"; 
	gr.remove(); 
	cout << "Remove" << "\n"; 
	gr.display(); 
	return 0; 
}