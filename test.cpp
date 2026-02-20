#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <exception>

using namespace std;
namespace fs = std::filesystem;

int main() {

    // Buat File 
    {
        std::ofstream file("test.md");
        std::cout << "file berhasil dibuat";
    }

    // Hapus Folder 
    {
        std::string pathFolder;

        std::cout << "Masukkan path folder yang ingin dihapus: ";
        std::getline(std::cin, pathFolder);

        if (fs::exists(pathFolder) && fs::is_directory(pathFolder)) {
            std::uintmax_t jumlah = fs::remove_all(pathFolder);
            std::cout << "Berhasil menghapus " << jumlah << " file/folder\n";
        } else {
            std::cout << "Folder tidak ditemukan!\n";
        }
    }

    // Tulis File 
    {
        std::ofstream file("output.txt");

        if (file.is_open()) {
            file << "hello" << std::endl;
            file << "world" << std::endl;
            file.close();
            std::cout << "file berhasil dibuat" << std::endl;
        } else {
            std::cout << "gagal membuat file." << std::endl;
        }
    }

    // Edit File 
    {
        string namaFile;
        cout << "Masukkan nama file yang ingin diedit: ";
        getline(cin, namaFile);

        ifstream file(namaFile);
        if (!file) {
            cout << "File tidak ditemukan!\n";
        } else {
            string isi;
            getline(file, isi);
            file.close();

            if (isi == "hello world") {
                isi += "!";

                ofstream out(namaFile);
                out << isi;
                out.close();

                cout << "Tanda seru berhasil ditambahkan!\n";
            } else {
                cout << "Isi file bukan 'hello world', tidak ada perubahan.\n";
            }
        }
    }

    // Buat String 
    {
        string greeting = "hello world!";
        cout << greeting;
    }

    // Copy File
    {
        std::string source_path_str, destination_path_str;

        std::cout << "Masukkan file sumber: ";
        std::cin >> source_path_str;
        std::cout << "Masukkan file tujuan: ";
        std::cin >> destination_path_str;

        try {
            fs::path source_path(source_path_str);
            fs::path destination_path(destination_path_str);

            if (!fs::exists(source_path) || !fs::is_regular_file(source_path)) {
                std::cerr << "Error: Source file does not exist or is not a regular file." << std::endl;
            } else {
                fs::copy(source_path, destination_path, fs::copy_options::overwrite_existing);
                std::cout << "File copied successfully!" << std::endl;
            }

        } catch (const fs::filesystem_error& e) {
            std::cerr << "Filesystem error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        }
    }

    // Move File 
{
    std::string sumber_move, tujuan_move;

    std::cout << "Masukkan path file yang ingin dipindahkan: ";
    std::getline(std::cin >> std::ws, sumber_move);

    std::cout << "Masukkan path tujuan baru: ";
    std::getline(std::cin, tujuan_move);

    try {
        if (!fs::exists(sumber_move) || !fs::is_regular_file(sumber_move)) {
            std::cout << "File sumber tidak ditemukan!\n";
        } else {
            fs::rename(sumber_move, tujuan_move);
            std::cout << "File berhasil dipindahkan!\n";
        }
    }
    catch (fs::filesystem_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

    // Copy Folder
    {
        std::string sumber, tujuan;

        std::cout << "Masukkan path folder sumber: ";
        std::getline(std::cin >> std::ws, sumber);

        std::cout << "Masukkan path folder tujuan: ";
        std::getline(std::cin, tujuan);

        try {
            fs::copy(
                sumber,
                tujuan,
                fs::copy_options::recursive |
                fs::copy_options::overwrite_existing
            );

            std::cout << "Folder berhasil dicopy!\n";
        }
        catch (fs::filesystem_error& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}