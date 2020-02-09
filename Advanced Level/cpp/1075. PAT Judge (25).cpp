#include<iostream>

#include<algorithm>
#include<vector>

using namespace std;

class User{
public:
	int id;
	int total_score;
	int perfectNum;
	bool show;
	int rank;
	vector<int> score_list;
	static vector<int> full_score;
	User(int id,int problem_num):id(id)
	{
		for(int k = 0; k < problem_num; ++k)
			score_list.push_back(-2);
	}
	//update total score and perfect num
	void Update()
	{
		show = false;
		total_score = perfectNum = 0;
		for(int k = 0; k < score_list.size(); ++k)
		{
			if(score_list[k] >= 0)
			{
				show = true;
				total_score += score_list[k];
			}
			if(score_list[k] == full_score[k])
				++perfectNum;
		}
	}
	// operator <
	friend bool operator < (const User &a, const User &b)
	{
		if(a.total_score != b.total_score)
			return a.total_score > b.total_score;
		if(a.perfectNum != b.perfectNum)
			return a.perfectNum > b.perfectNum;
		return a.id < b.id;
	}
};

vector<int> User::full_score;

int main()
{
	int user_num,prob_num,submit_num;
	int id,pr,score;
	cin >> user_num >> prob_num >> submit_num;
	User utemp(0,prob_num);
	vector<User> user(user_num+1,utemp);
	vector<int> full_score(prob_num);
	//set user id
	for(int k = 1; k <= user_num; ++k)
		user[k].id = k;
	//get full score
	for(int k = 0;k < prob_num; ++k)
	{
		scanf("%d",&score);
		User::full_score.push_back(score);
	}
	//get users' submit score
	for(int k = 0; k < submit_num;++k)
	{
		scanf("%d %d %d",&id,&pr,&score);
		auto &s = user[id].score_list[pr-1];
		if(s < score)
			s = score;
	}
	//count total score and perfect num
	for(int k = 1; k <= user_num; ++k)
		user[k].Update();

	sort(user.begin()+1,user.end());
	//print result
	auto i = user.begin()+1;
	auto pre = i;
	i->rank = 1;
	for(; i != user.end(); ++i)
	{

		if(pre->total_score == i->total_score)
			i->rank = pre->rank;
		else
			i->rank = i - user.begin();
		if(i->show == false)
			break;
		printf("%d %05d %d",i->rank,i->id,i->total_score);
		for(auto j = i->score_list.begin(); j != i->score_list.end(); ++j)
			if(*j >= 0)
				printf(" %d",*j);
			else if(*j == -1)
				printf(" 0");
			else
				printf(" -");
		printf("\n");
		pre = i;
	}

	return 0;
}