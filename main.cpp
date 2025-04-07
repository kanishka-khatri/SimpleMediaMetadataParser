#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

namespace fs = std::filesystem;

struct MediaFile {
    std::string path;
    std::string name;
    std::string format;
    long size_kb;
    int duration_seconds; // Mocked
};

// Function to simulate metadata
MediaFile mockMetadata(const fs::directory_entry& file) {
    MediaFile m;

    // Normalize path slashes
    std::string rawPath = file.path().string();
    std::replace(rawPath.begin(), rawPath.end(), '\\', '/');
    m.path = rawPath;

    m.name = file.path().filename().string();
    m.format = file.path().extension().string();

    try {
        m.size_kb = fs::file_size(file) / 1024;
    } catch (const std::exception& e) {
        m.size_kb = 0; // In case of access issues
    }

    m.duration_seconds = 30 + (std::rand() % 270); // Random duration (30–300)
    return m;
}

int main() {
    std::srand(std::time(nullptr)); // Seed randomness
    std::string folder = "./media"; // Path relative to the build folder

    // Create output directory if it doesn't exist
    fs::create_directories("output");

    std::vector<MediaFile> mediaList;

    for (const auto& entry : fs::recursive_directory_iterator(folder)) {
        if (entry.is_regular_file()) {
            auto ext = entry.path().extension().string();
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower); // normalize extension

            if (ext == ".mp3" || ext == ".wav" || ext == ".mp4" || ext == ".mkv") {
                std::cout << "Found: " << entry.path().string() << std::endl;
                mediaList.push_back(mockMetadata(entry));
            }
        }
    }

    std::ofstream out("output/metadata.json");
    out << "[\n";
    for (size_t i = 0; i < mediaList.size(); ++i) {
        const auto& m = mediaList[i];
        out << "  {\n";
        out << "    \"name\": \"" << m.name << "\",\n";
        out << "    \"path\": \"" << m.path << "\",\n";
        out << "    \"format\": \"" << m.format << "\",\n";
        out << "    \"size_kb\": " << m.size_kb << ",\n";
        out << "    \"duration_seconds\": " << m.duration_seconds << "\n";
        out << "  }";
        if (i < mediaList.size() - 1) out << ",";
        out << "\n";
    }
    out << "]\n";

    std::cout << "Scan complete. Metadata saved to output/metadata.json\n";
    return 0;
}
