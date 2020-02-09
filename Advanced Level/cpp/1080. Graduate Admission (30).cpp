#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Student{
public:
	int id;
	int Ge,Gi,sum;
	int rank;
	vector<int> prefer;
	friend bool operator < (const Student &a, const Student &b)
	{
		if(a.sum != b.sum)
			return a.sum > b.sum;
		return a.Ge > b.Ge;
	}
};

class School{
public:
	int quota;
	vector<const Student*> student;
	vector<int> student_id;
	//student's applying ,success return true, else return false
	bool Apply(const Student &a)
	{
		// quota is not exceeded, accept
		if(student.size() < quota)
		{
			student.push_back(&a);
			student_id.push_back(a.id);
			return true;
		}
		if(student.size() == 0)
			return false;
		const Student *p = *student.rbegin();
		//ranks are the same, accept
		if(p->rank == a.rank)
		{
			student.push_back(&a);
			student_id.push_back(a.id);
			return true;
		}
		return false;
	}
};



int main()
{
	int N,M,K;
	cin >> N >> M >> K;
	vector<School> schools(M);
	for(int k = 0; k < M; ++k)
		scanf("%d",&schools[k].quota);
	vector<Student> students(N);
	//get student's information
	for(int k = 0; k < N; ++k)
	{
		auto &s = students[k];
		scanf("%d %d ",&s.Ge,&s.Gi);
		s.id = k;
		s.sum = s.Ge + s.Gi;
		s.prefer.resize(K);
		for(int j = 0; j < K; ++j)
			scanf("%d",&s.prefer[j]);
	}

	//set rank
	sort(students.begin(),students.end());
	auto i = students.begin();
	i->rank = 1;
	auto pre = i;
	for(; i != students.end(); pre = i, ++i)
		if(i->sum == pre->sum && i->Ge == pre->Ge)
			i->rank = pre->rank;
		else
			i->rank = i - students.begin() + 1;
	
	//applying
	for(i = students.begin(); i != students.end(); ++i)
	{
		for(auto j = i->prefer.begin(); j != i->prefer.end(); ++j)
			if(schools[*j].Apply(*i) == true)
				break;
	}

	//print
	for(auto it = schools.begin(); it != schools.end(); ++it)
	{
		auto &id = it->student_id;
		sort(id.begin(),id.end());
		for(auto j = id.begin(); j != id.end();++j)
		{
			if(j != id.begin())
				printf(" ");
			printf("%d",*j);
		}
		printf("\n");
	}

	return 0;
}