// 1114 Family Property (25point(s))
// 考点：遍历图森林
#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <set>

#define MAX_SIZE 10000

using namespace std;

class Person{
public:
    int id;
    set<int> family; //直系亲属
    int estate, area;
    int familySize;
    double avgSets, avgArea;
    bool visited;
    Person(){
        id = -1;
        familySize = 0;
        visited = false;
        avgSets = 0.0;
        avgArea = 0.0;
    }
    friend bool operator < (const Person& p1, const Person& p2){
        if(p1.avgArea != p2.avgArea)
            return p1.avgArea < p2.avgArea;
        return p1.id > p2.id;
    }
};

vector<Person> vFamilies(MAX_SIZE);

void Visit(Person& p, Person& root){
    p.visited = true;
    root.id = min(root.id, p.id);
    root.familySize++;
    root.avgSets += p.estate;
    root.avgArea += p.area;
    for(auto iter : p.family){
        if( vFamilies[iter].visited == false)
            Visit(vFamilies[iter], root);
    }
}

int main()
{
    int n;
    int id, father, mother, k, estate, area;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> id;
        Person& p = vFamilies[id];
        p.id = id;
        cin >> father >> mother >> k;
        if(father >= 0){
            vFamilies[father].id = father;
            vFamilies[father].family.insert(id);
            p.family.insert(father);
        }
        if(mother >= 0){
            vFamilies[mother].id = mother;
            vFamilies[mother].family.insert(id);
            p.family.insert(mother);
        }
        for(int j = 0; j < k; j++){
            cin >> id;
            p.family.insert(id);
            vFamilies[id].id = id;
            vFamilies[id].family.insert(p.id);
        }
        cin >> p.estate >> p.area;
    }
    vector<Person> res;
    for(auto& iter:vFamilies){
        if(iter.id >= 0 && iter.visited == false){
            Person p;
            p.id = iter.id;
            Visit(iter, p);
            p.avgSets /= p.familySize;
            p.avgArea /= p.familySize;
            res.push_back(p);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(int i = res.size()-1; i >= 0; i--){
        Person& p = res[i];
        printf("%04d %d %.3f %.3f\n", p.id, p.familySize, p.avgSets, p.avgArea);
    }


    return 0;
}