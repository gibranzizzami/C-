#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string folderName = "folder-saya";

    // Membuat folder
    if (fs::create_directory(folderName)) {
        std::cout << "folder berhasil dibuat: " << folderName << std::endl;
    } else {
        std::cout << "folder gagal dibuat atau sudah ada." << std::endl;
    }

    return 0;
}
