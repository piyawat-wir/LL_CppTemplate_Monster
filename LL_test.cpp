#include <iostream>
#include <cstdlib>
//#include "Monster.h"
#include "LL.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    LL A; //Linked List =>constructor L.hol=NUL L.size=0
    int i;
    monster *t;
    monster *boss = new monster("Boss", 999999, 999999);

    for (i=1; i<argc; i+=3)
    {
        t = new monster(argv[i], atoi(argv[i+1]), atoi(argv[i+2])); //constructor
        A.add_node(t);
        //add front of linked List + size++
    }

    cout<<"--------------------------------------"<<endl;
    A.show_all();
    A.atk_All(boss);
    //system("PAUSE");
    return 0;
}
