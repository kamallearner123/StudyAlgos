#include <iostream>

using namespace std;

struct student {
    char *name;
    int id;
};

void fun(struct student &arg) {
    arg.id += 1;
}

int main()
{
    struct student s1 = {"Kamal", 100};
    fun(s1);
    cout << s1.id << endl;
}
