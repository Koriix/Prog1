#include "std_lib_facilities.h"


struct Person
{
	Person(string vnev, string knev, int kor);

	string veznev() const { return first; }
	string kernev() const { return last; }
	int age() const { return a; }

private:
	string first;
	string last;
	int a;
};

Person::Person(string vnev, string knev, int kor)
	: first{vnev}, last{knev}, a{kor}
{
	if(kor < 0 || 150 < kor) error("A személy kora kisebb mint 0 vagy nagyobb mint 150!");

	string telnev = vnev + knev;
	for(char c : telnev)
	{
		switch(c)
		{
			case ';': case ':': case '"': case '[': case ']': case '*':
			case '&': case '^': case '%': case '$': case '#': case '@':
			case '!':
				error("A személy nevében nem használható karakter van!");
				break;
			default:
				break;
		}
	}
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.veznev() << ' ' << p.kernev() << ' ' << p.age() << endl;
}

istream& operator>>(istream& is, Person& p)
{
	string v;
	string k;
	int a;

	is >> v >> k >> a;
	p = Person(v,k,a);

	return is;
}

int main()
try{

	Person p (" ", "Goofy", 63);
	cout << p;
	cin >> p;
	cout << p;

	cout << "Írj egy teljes nevet és egy kort!" << endl;
	vector<Person> vepo;
	for(int i = 0; i < 3; i++)
	{	cin >> p;
		vepo.push_back(p);
	}

	for(Person p : vepo)
	{
		cout << p;
	}


}
catch (exception& e)
{
	cerr << "Exception: " << e.what() << endl;
	return 1;
}
catch (...)
{
	cerr << "Error!" << endl;
	return 2;
}
