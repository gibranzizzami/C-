// buat folder
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>

int main() {
    mkdir("FolderBaru", 0777);
    std::cout << "Folder berhasil dibuat!" << std::endl;
    return 0;
}
