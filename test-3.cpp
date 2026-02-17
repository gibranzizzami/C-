#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string pathFolder;

    std::cout << "Masukkan path folder yang ingin dihapus: ";
    std::getline(std::cin, pathFolder);

    if (fs::exists(pathFolder) && fs::is_directory(pathFolder)) {
        std::uintmax_t jumlah = fs::remove_all(pathFolder);
        std::cout << "Berhasil menghapus " << jumlah << " file/folder\n";
    } else {
        std::cout << "Folder tidak ditemukan!\n";
    }

    return 0;
}

