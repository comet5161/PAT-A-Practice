#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

bool valid[256];
int main()
{
	int n,k;
	char c;
	map<string,int> word_count;
	string s;
	for(k =0; k < 256;++k)
		valid[k] = false;
	for(k = '0'; k <= '9'; ++k)
		valid[k] = true;
	for(k = 'a'; k <= 'z'; ++k)
		valid[k] = true;
	for(k = 'A'; k <= 'Z'; ++k)
		valid[k] = true;

	do
	{
		scanf("%c",&c);
		if(valid[c])
			s.push_back(c);
		else if(s.size()>0)
		{
			transform(s.begin(),s.end(),s.begin(),::tolower);//×ª»»³ÉÐ¡Ð´
			word_count[s]++;
			s.clear();
		}
	}while(c != '\n');

	int max = 0;
	string most_use;

	for(auto i = word_count.begin(); i != word_count.end(); ++i)
		if(i->second > max)
		{
			max = i->second;
			most_use = i->first;
		}
	
	cout << most_use << " " << max << endl;

	return 0;
}