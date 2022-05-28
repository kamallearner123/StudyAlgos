// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class router {
    public:
    int id;
    mutable string name;
    
    router (int i_id, string i_name) {
        id = i_id;
        name = i_name;
    }
    
    void change_name (string i_name) const {
        name = i_name;
    }
    bool isitme(router &obj);
};

bool router::isitme(router &obj) {
    if (this == &obj) return true;
    else return false;
}

int main() {
    router r1 = {101, "srx"};
    router r2 = {101, "srx"};
    cout << r1.isitme(r1) << endl;
    cout << r1.isitme(r2) << endl;
}
