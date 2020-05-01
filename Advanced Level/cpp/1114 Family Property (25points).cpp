// 1114 Family Property (25point(s))
// 考点：建立邻接表、遍历图
#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <set>
#include <map>

using namespace std;

class Person{
public:
    int id;
    set<int> family; //直系亲属
    int estate, area;
    bool visited;
    Person():id(-1), visited(false){}
};

class Family{
public:
    int min_id;
    double avgSets, avgArea;
    int familySize;
    Family(){
        avgSets = 0.0;
        avgArea = 0.0;
        familySize = 0;
    }
    friend bool operator < (const Family& p1, const Family& p2){
        if(p1.avgArea != p2.avgArea)
            return p1.avgArea < p2.avgArea;
        return p1.min_id > p2.min_id;
    }
};

map<int, Person> mPersons;

void Visit(Person& person, Family& family){
    person.visited = true;
    family.min_id = min(family.min_id, person.id);
    family.familySize++;
    family.avgSets += person.estate;
    family.avgArea += person.area;
    for(auto iter : person.family){
        if( mPersons[iter].visited == false)
            Visit(mPersons[iter], family);
    }
}

int main()
{
    int n;
    int id, father, mother, k, estate, area;
    cin >> n;
    
    //建立邻接表
    for(int i = 0; i < n; i++){
        cin >> id;
        Person& person = mPersons[id];
        person.id = id;
        cin >> father >> mother >> k;
        if(father >= 0){
            mPersons[father].id = father;
            mPersons[father].family.insert(id);
            person.family.insert(father);
        }
        if(mother >= 0){
            mPersons[mother].id = mother;
            mPersons[mother].family.insert(id);
            person.family.insert(mother);
        }
        for(int j = 0; j < k; j++){
            cin >> id;
            person.family.insert(id);
            mPersons[id].id = id;
            mPersons[id].family.insert(person.id);
        }
        cin >> person.estate >> person.area;
    }
    vector<Family> res;
    for(auto& iter:mPersons){
        auto& person = iter.second;
        if(person.id >= 0 && person.visited == false){
            Family family;
            family.min_id = person.id;
            Visit(person, family);
            family.avgSets /= family.familySize;
            family.avgArea /= family.familySize;
            res.push_back(family);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(int i = res.size()-1; i >= 0; i--){
        Family& person = res[i];
        printf("%04d %d %.3f %.3f\n", person.min_id, person.familySize, person.avgSets, person.avgArea);
    }
    return 0;
}