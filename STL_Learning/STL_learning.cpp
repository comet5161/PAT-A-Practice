#include<iostream>
#include<iomanip>
#include<map>
#include<tuple>
#include<queue>
#include<vector>
#include<list>
#include<set>
#include<queue>

#define INIFINITY 99999999

using namespace std;

class Vertex{
public:
    int v;
    int min_dist;
	list<int> rode;
	list<int> path;
    //Vertex(int s,int d ,int dist):s_city(s),d_city(d),distance(dist){}
    //Vertex(int s, int d):s_city(s),d_city(d),distance(INIFINITY){}
    friend bool operator < ( const Vertex& r1, const Vertex& r2)
    {
		if(r1.v < r2.v)
			return true;
		if(r1.v > r2.v)
			return false;
		if(r1.min_dist<r2.min_dist)
			return true;
		return false;
    }
    friend bool operator > ( const Vertex& r1, const Vertex& r2)
    {
		if(r1.v > r2.v)
			return true;
		if(r1.v < r2.v)
			return false;
		if(r1.min_dist>r2.min_dist)
			return true;
		return false;
    }

};


// 表达式必须具有pointer to 函数类型??????????????????????
template<class T>
class mySet: public set<T>{
public:
	friend ostream & operator << (ostream& os,const mySet& m)
	{
		if( m.size() == 0)
			return os;
		auto iter = m.begin();
			os << *iter;
		++iter;
		for(; iter != m.end(); ++iter)
			os << " " << *iter;
		return os;
	};
	
};

class intSet: public set<int>{
public:
	friend ostream & operator << (ostream& os, const intSet& m)
	{
		if( m.size() == 0)
			return os;
		auto iter = m.begin();
			os << *iter;
		++iter;
		for(; iter != m.end(); ++iter)
			os << " " << *iter;
		return os;
	};
	
};



template<class T>
struct MyCompare{
	bool operator () (const T& a,const T& b)
	{
		return  a < b;
	}
};



int main()
{
    multiset<Vertex> s;

	map<int,double,MyCompare<int>> m;

	m.insert( make_pair(1,2.2) );
	m.insert( make_pair(4,2.2) );
	m.insert( make_pair(3,1.2) );
	m.insert( make_pair(3,1.3) );
	for(auto i = m.begin(); i != m.end(); ++i)
		cout << i->first << "," << i->second << endl;
	cout << endl;

	// <<
	mySet<int> myset;
	for(int k = 0; k < 8; k++)
		myset.insert(k);
	cout << myset;
	
	// set
	set<Vertex> VSet;
	Vertex v;
	v.v = 1;
	v.min_dist = 3;
	VSet.insert(v);
	v.v = 2;
	v.min_dist = 4;
	VSet.insert(v);
	v.v = 1;
	v.min_dist = 4;
	VSet.insert(v);
	cout << endl << endl;
	for(auto iter = VSet.begin(); iter != VSet.end(); ++iter)
		cout << "V: " << iter->v << " dist: " << iter->min_dist << endl;
	

	// sort
	vector<Vertex> vect;
	
	vect.insert(vect.end(),VSet.begin(),VSet.end());
	vect.push_back(v);
	sort(vect.begin(),vect.end(),greater<Vertex>());//greater<Vertex>()注意括号！
	cout << endl;
	for(int k = 0; k < vect.size(); ++k)
		cout << "V: " << vect[k].v << " dist: " << vect[k].min_dist << endl;

    return 0;
}
