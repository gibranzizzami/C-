#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>

int main() {
    // made folder
    mkdir("FolderBaru", 0777);
    std::cout << "Folder berhasil dibuat!" << std::endl;
}

    // made file
     std::ofstream file("contoh.txt");
     cout << "file berhasil dibuat";
     return 0;
}