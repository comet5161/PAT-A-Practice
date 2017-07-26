#include<iostream>


using namespace std;

class BinTree{
public:
	int id;
	BinTree():left(NULL),right(NULL){}
	BinTree* left;
	BinTree* right;
	// +=
	BinTree& operator += (const BinTree& t)
	{
		id += t.id;
		return *this;
	}
	//++i
	BinTree& operator ++()
	{
		++id;
		return *this;
	}
	//i++
	BinTree operator ++(int)//��Ҫ��BinTree& operator ++(int)
	{
		BinTree t(*this);
		++id;
		return t;
	}
	// *
	int operator * ()
	{
		return id;
	}
	// =
	int operator = (const int &a)
	{
		id = a;
		return id ;
	}
	// int
	operator int()//��Ҫ��int operator int()
	{
		return id;
	}
	// <<
	friend ostream& operator << (ostream& os,const BinTree& t)
	{
		os << t.id;
		return os;
	}
	// []
	int operator [](int k)
	{
		return k*2;
	}
};


int main()
{
	BinTree t;
	t.id = 6;
	int a = *t;
	cout << a << endl;

	int b;
	t = 8;
	b = t;
	cout << b << endl;

	double d;
	++t;
	d = t++;
	cout << d << endl;

	cout << t << endl;

	cout << t[8] << endl;

	BinTree t2 = t;
	cout << t2 << endl;
	t2 += t;
	cout << t2 << endl;

	//����ת��
	//static_cast
	int *pint;
	char *pchar;
	a = 42;
	pint = &a;
	cout << *pint << endl;
	//pchar =(char*) pint;
	pint = new int(99);
	//pchar = static_cast<char*>(pint);//����static_castҪ�����߱����С���ϵ����"�̳�"����������֮һ
	pchar = reinterpret_cast<char*>(pint);
	cout << *pchar << endl;

	return 0;
}