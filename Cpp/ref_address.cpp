// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void update(int &counter) {
    counter +=1;
    cout << &counter << endl;
}
int main() {
    // Write C++ code here
    int counter = 100;
    std::cout << "Hello world!";
    update(counter);
    cout << &counter << endl;
    return 0;
}
