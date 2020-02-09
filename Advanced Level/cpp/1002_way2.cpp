//This time, you are supposed to find A+B where A and B are two polynomials.
//
//Input
//
//Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10£¬0 <= NK < ... < N2 < N1 <=1000.
//
//Output
//
//For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
//
//Sample Input
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
//Sample Output
//3 2 1.5 1 2.9 0 3.2
//



#include<iostream>
#include<iomanip>
#include<list>

using namespace std;
class Poly{
public:
	double a;
	int n;
	Poly(int n, double a):n(n),a(a){};
	friend bool operator >(const Poly & p1, const Poly &p2)
	{
		if(p1.n > p2.n ) return true;
		else return false;
	}
	friend bool operator <(const Poly & p1, const Poly &p2)
	{
		if(p1.n < p2.n ) return true;
		else return false;
	}
	friend bool operator ==(const Poly & p1, const Poly &p2)
	{
		if(p1.n == p2.n && p1.a == p2.a) return true;
		else return false;
	}
};

int main()
{

	//Poly aa(2,1.2),bb(3,3.2);

	//cout << (aa>bb);
	//list<Poly> pp;
	//pp.push_back(*(new Poly(1,1.1)));
	//pp.push_back(*(new Poly(3,1.1)));
	//pp.push_back(*(new Poly(2,1.1)));
	//pp.sort( greater<Poly>());
	//pp.sort();
	//for(auto iter = pp.begin(); iter != pp.end(); )
	//{
	//	auto temp = iter;
	//	++iter;
	//	cout << temp->n;
	//	pp.erase(temp);
	//}


	int k,n,num;
	double a;
	list<Poly> p1,p2,p3;
	cin >> num;
	for(k = 0; k < num; ++k)
	{
		cin >> n >> a;
		p1.push_back(*(new Poly(n,a)));
	}
	cin >> num;
	for(k = 0; k < num; ++k)
	{
		cin >> n >> a;
		p2.push_back(*(new Poly(n,a)));
	}

	for(auto ii = p1.begin(); ii != p1.end(); )
	{
		auto i = ii++;
		for(auto jj = p2.begin(); jj != p2.end(); )
		{
			auto j = jj++;
			if(i->n == j->n)
			{
				i->a += j->a;
				if(i->a == 0)
					p1.erase(i);
				p2.erase(j);
			}
		}
	}
	if(p2.size() > 0)
		p1.merge(p2,greater<Poly>());

	cout << p1.size();
	for(auto it = p1.begin(); it != p1.end(); ++it)
		cout << " " << it->n << " " << fixed << setprecision(1) << it->a;

	//fixed << setprecision(1)

	//system("pause");


	return 0;

}