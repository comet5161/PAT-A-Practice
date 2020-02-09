#include<iostream>
#include<string>
#include<set>
using namespace std;

class Inf{
public:
	string name,id;
	int grade;
	Inf(string name,string id, int grade):name(name),id(id),grade(grade){}
	Inf(){}
	friend bool operator < (const Inf& a, const Inf& b)
	{ 
		return a.grade < b.grade;
	}
};

int main() 
{
	set<Inf> male,female;
	string name,gender,id;
	int grade;
	int n;
	cin >> n;
	for(int k = 0; k < n; ++k)
	{

		cin >> name >> gender >> id >> grade;
		Inf inf(name,id,grade);
		if(gender == "M")
			male.insert(inf);
		else
			female.insert(inf);
	}
	//female
	if(female.size() > 0)
	{
		auto &i = *female.rbegin();
		cout << i.name << " " << i.id << endl;
	}
	else
		cout << "Absent\n";
	//male
	if(male.size() > 0)
	{
		auto &i = *male.begin();
		cout << i.name << " " << i.id << endl;
	}
	else
		cout << "Absent\n";
	//distinct
	if(male.size() > 0 && female.size() > 0)
		cout << female.rbegin()->grade - male.begin()->grade << endl;
	else
		cout << "NA\n";
	return 0;
}