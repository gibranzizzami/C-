#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> greetings ={"hello", "world"}; 

    for (string greeting : greetings) {
        cout << greeting << "/n";
    }
    return 0;
}