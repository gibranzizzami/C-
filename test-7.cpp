#include <iostream>
#include <string>
#include <filesystem>
#include <exception>

namespace fs = std::filesystem;

int main() {
    std::string source_path_str, destination_path_str;

    std::cout << "Enter the source file path: ";
    std::cin >> source_path_str;
    std::cout << "Enter the destination file path: ";
    std::cin >> destination_path_str;

    try {
        fs::path source_path(source_path_str);
        fs::path destination_path(destination_path_str);

        // Check if the source file exists
        if (!fs::exists(source_path) || !fs::is_regular_file(source_path)) {
            std::cerr << "Error: Source file does not exist or is not a regular file." << std::endl;
            return 1;
        }

        // Copy the file
        fs::copy(source_path, destination_path, fs::copy_options::overwrite_existing);
        std::cout << "File copied successfully!" << std::endl;

    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
