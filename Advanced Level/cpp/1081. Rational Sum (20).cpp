//���ֺ������long long��
//���Ե�1ע����Ϊ���������
//������Ϊ�����������ֺ�С�����ֶ�Ҫ�и���
//ע�������Լ���㷨

#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

//���Լ�� greatest common divisor
long long GCD(long long x, long long y)
{
	if(y == 0)
		return x;
	return GCD(y,x%y);
};

//��С������  lowest common multiple
long long LCM(long long x, long long y)
{
	return x / GCD(x,y) *y; 
};

//numerator/denominator
class RationalNum{
public:
	long long numer,denomina;
	//Reset denomina
	void ResetDenomina(long long x)
	{
		numer = numer*(x/denomina);
		denomina = x;
	}
	//Add
	void Add(RationalNum &x)
	{
		auto &y = *this;
		long long d ;
		d = LCM(y.denomina,x.denomina);
		y.ResetDenomina(d);
		y.numer += x.numer * (d/x.denomina);
	}
	//simplify ����
	void Simplify()
	{
		if(numer == 0)
			return;
		long long d;
		d = GCD(numer,denomina);
		while(d != 1 && d != -1)
		{
			numer /= d;
			denomina /= d;
			d = GCD(numer,denomina);
		}
	}
};


int main()
{
	int n,a,b;
	cin >> n;
	vector<RationalNum> numbers(n);
	for(int k = 0; k < n; ++k)
		scanf("%lld/%lld",&numbers[k].numer,&numbers[k].denomina);

	for(auto i = numbers.begin()+1; i != numbers.end(); ++i)
		numbers[0].Add(*i);

	auto &num = numbers[0];
	num.Simplify();
	long long inter =  num.numer / num.denomina;
	long long numer = num.numer % num.denomina;
	if(inter == 0 && numer == 0)
		printf("0\n");
	else if(numer == 0)
		printf("%lld\n",inter);
	else if(inter == 0)
		printf("%lld/%lld\n",numer,num.denomina);
	else
		printf("%lld %lld/%lld\n",inter,numer,num.denomina);

	return 0;
}