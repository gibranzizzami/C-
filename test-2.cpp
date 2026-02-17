#include <iostream>
#include <fstream>
using namespace std;

int main () {
    std::offstream file("test.md");
    cout << "file berhasil dibuat";
    return 0;
}