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
};

int main() {
    router r1 = {101, "srx"};
    cout << "Name:" << r1.name << " id:" <<  r1.id << endl;
    r1.change_name("srx5000");
    cout << "Name:" << r1.name << " id:" <<  r1.id << endl;
}
