#include <string>

using namespace std;

class monster
{
    int hp, potion;
    string name;
    monster* next;
public:
    monster(string,int,int);
    void show_node();
    void insert(monster*&);
    monster* move_next();
    ~monster();
    void addhp(int);
    void addpotion(int);
    int gethp();
    int getpotion();
    string getname();
};


monster:: monster(string NAME, int HP, int POTION) {
    name = NAME;
    hp = HP;
    potion = POTION;
    next = NULL;
    cout<<" **adding "<<name<<" hp:"<<hp<<" pot:"<<potion<<endl;
}

monster:: ~monster() {
    cout<<" **removed "<<name<<endl;
}

void monster::show_node() {
    cout<<" Name   : "<<name<<endl;
    cout<<" Hp     : "<<hp<<endl;
    cout<<" Potion : "<<potion<<endl;
    cout<<"--------------------------------------"<<endl;
}

void monster::insert(monster *&mon) {
    mon->next = this;
}

monster* monster::move_next() {
    return next;
}

string monster::getname() {
    return name;
}

void monster::addhp(int v) {
    hp += v;
    if (hp < 0) hp = 0;
}

void monster::addpotion(int v) {
    potion += v;
    if (potion < 0) potion = 0;
}

int monster::gethp() {
    return hp;
}

int monster::getpotion() {
    return potion;
}
