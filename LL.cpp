#include <iostream>
#include <ctime>
#include "Monster.h"
#include "LL.h"

using namespace std;

LL::LL()
{
    hol = NULL;
    size = 0;
}

LL::~LL()
{
    monster *t=hol, *next=NULL;
    int i;
    for(i=0; i<size; i++)
    {
        next = t->move_next();
        delete t;
        t = next;
    }
    cout<<" **destructor"<<endl;
}

void LL::add_node(monster *&A)
{
    hol->insert(A);// new_node->next=hol;
    hol = A;

    size++;
}

void LL::show_all()
{
    monster* t=hol;
    int i;
    for(i=0; i<size; i++)
    {
        t->show_node();
        t = t->move_next();
    }
}

void attack(monster*& t, monster *&boss) {
    string melee[3] = {"Broadsword", "Battle Axe", "Dagger"};
    string spell[3] = {"Lighting bolt", "Fire ball", "Icy Blizzard"};
    int damage[10] = {1,1,10,10,10,10,10,100,100,10000};
    int a,b,dmg;
    if (t->getpotion() > 1)
        a = rand() % 3;
    else
        a = rand() % 2;
    b = rand() % 3;
    dmg = (int)((float)(rand() % 10000)*damage[rand() % 10]/100);
    switch (a) {
    case 0:
        cout<<t->getname()<<" stroke "<<boss->getname()<<" using "<<melee[b]<<"!"<<endl;
        cout<<"  dealt "<<dmg<<" damage"<<endl;
        boss->addhp(-dmg);
        break;
    case 1:
        cout<<t->getname()<<" casted "<<spell[b]<<" at "<<boss->getname()<<"!"<<endl;
        cout<<"  dealt "<<dmg<<" damage"<<endl;
        boss->addhp(-dmg);
        break;
    case 2:
        cout<<t->getname()<<" used potion!"<<endl;
        cout<<"  Recovered 50 hp"<<endl;
        t->addhp(50);
        t->addpotion(-1);
        break;
    }
}

void LL::atk_All(monster *&boss) {
    srand((unsigned) time(NULL));

    monster* t=hol;
    for(int i=0; i<size; i++)
    {
        if (t->gethp() > 0)
            attack(t, boss);
        if (boss->gethp() <= 0) {
            cout<<"Congratulations"<<endl;
            cout<<boss->getname()<<" had been defeated!"<<endl;
            break;
        }
        t = t->move_next();
    }

    t=hol;
    for(int i=0; i<size; i++)
    {
        if (boss->gethp() > 0)
            attack(boss, t);
        if (t->gethp() <= 0) {
            cout<<t->getname()<<" is died!"<<endl;
        }
        t = t->move_next();
    }
    cout<<"Summary:"<<endl;
    boss->show_node();
    show_all();
}



