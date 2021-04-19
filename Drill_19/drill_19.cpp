#include <iostream>
#include "std_lib_facilities.h"


template<typename T>
struct S
{
	explicit S(T vv = 0) : val{vv} { }
	S& operator=(const T&);
	T& get();
	const T& get() const;
	void set(T new_t) {val = new_t; } 

private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
	val = s;
	return *this;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	os << "{ ";
	for(int i=0; i<v.size(); ++i)
	{
		os << v[i] << (i < v.size()-1 ? ", " : " " );
	}
	os << "}" << endl;

	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
	char ch = 0;
	is >> ch;
	if(ch != '{')
	{
		is.unget();
		return is;
	}

	for(T val; is >> val; )
	{
		v.push_back(val);
		is >> ch;
		if(ch != ',') break;
	}

	return is;
}

template<typename T> void read_val(T& v)
{
	cin >> v;
}

int main()
{
	S<int> si {42};
	S<char> sc {'c'};
	S<double> sd {19.19};
	S<string> s {"STRING"};
	S<vector<int>> svi {vector<int>{1, 2, 3, 4, 5, 6}};

	cout << "S<int>: " << si.get() << endl;
	cout << "S<char>: " << sc.get() << endl;
	cout << "S<double>: " << sd.get() << endl;
	cout << "S<string>: " << s.get() << endl;
	cout << "S<vector<int>>: " << svi.get() << endl;

	
	cout << "S<vector<int>> : ";
	for(auto& a : svi.get()) cout << a << ' ';
	cout << endl;
	

	
	sc.set('s');
	cout << "S<char> : " << sc.get() << endl;
	

	sd = 3.14159;
	cout << "S<double> : " << sd.get() << endl;

	cout << "Reads: " << endl;

	
	cout << "Integer: ";
	int ii;
	read_val(ii);
	S<int> si2 {ii};

	cout << "Char: ";
	char cc;
	read_val(cc);
	S<char> sc2 {cc};

	cout << "Double: ";
	double dd;
	read_val(dd);
	S<double> sd2 {dd};

	cout << "String: ";
	string ss;
	read_val(ss);
	S<string> s2 {ss};

	cout << "S<int> read: " << si2.get() << endl;
	cout << "S<char> read: " << sc2.get() << endl;
	cout << "S<double> read: " << sd2.get() << endl;
	cout << "S<string> read: " << s2.get() << endl;
	

	cout << "Vector<int>: (Write like this: {val1, val2, val3 }) ";
	vector<int> vi2;
	read_val(vi2);
	S<vector<int>> svi2 {vi2};
	cout << "S<vector<int>> read: " << svi2.get() << endl;
}
