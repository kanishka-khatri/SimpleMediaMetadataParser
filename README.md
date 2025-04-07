# SimpleMediaMetadataParser

A lightweight C++ application that recursively scans a `media/` directory for supported media files and generates mock metadata in a JSON format.

---

## 📁 Directory Structure

SIMPLEMEDIAMETADATAPARSER/
├── .vscode/
│ ├── launch.json
│ └── settings.json
├── build/
│ ├── CMakeFiles/
│ ├── media/
│ │ ├── sample-1.mkv
│ │ ├── sample-3s.mp3
│ │ ├── sample-5s.mp4
│ │ ├── sample-12s.wav
│ └── output/
│ └── metadata.json
├── cmake_install.cmake
├── CMakeCache.txt
├── Makefile
├── SimpleMediaMetadataParser.exe
├── .gitignore
├── CMakeLists.txt
├── main.cpp
└── README.md


---

## 🛠️ Features

- ✅ Scans supported media file types: `.mp3`, `.wav`, `.mp4`, `.mkv`
- ✅ Collects basic metadata:
  - File name
  - File path (normalized)
  - File extension/format
  - File size in kilobytes
  - Mocked duration in seconds
- ✅ Outputs JSON to `build/output/metadata.json`
- ❌ No real metadata extraction (e.g., bitrate, resolution) — this is a mockup prototype.

---

## 📦 Requirements

- ✅ C++17 compatible compiler
- ✅ [CMake ≥ 3.10](https://cmake.org/)
- ❌ No external libraries required

---

## 🚀 Build & Run

1. **Navigate to the `build/` directory**:

   ```bash
   cd build
2. **Configure and build the project using CMake**:

cmake ..
cmake --build .
3. **Run the executable**:

./SimpleMediaMetadataParser.exe
4.**Check your metadata at**:

build/output/metadata.json

## 📂 Example Output
[
  {
    "name": "sample-1.mkv",
    "path": "./media/sample-1.mkv",
    "format": ".mkv",
    "size_kb": 83609,
    "duration_seconds": 107
  },
  {
    "name": "sample-12s.wav",
    "path": "./media/sample-12s.wav",
    "format": ".wav",
    "size_kb": 2202,
    "duration_seconds": 150
  },
  {
    "name": "sample-3s.mp3",
    "path": "./media/sample-3s.mp3",
    "format": ".mp3",
    "size_kb": 50,
    "duration_seconds": 121
  },
  {
    "name": "sample-5s.mp4",
    "path": "./media/sample-5s.mp4",
    "format": ".mp4",
    "size_kb": 2781,
    "duration_seconds": 211
  }
]

## 💡 Future Improvements
🔍 Use FFmpeg or MediaInfo to extract real metadata

🧪 Add unit tests

🌐 Add GUI frontend or web-based viewer

📊 Visualize metadata stats

---

## ✍️ Author

This project was created by *Kanishka Khatri* as part of the **Google Summer of Code 2025** proposal:  
**Library Content Manager – Metadata Component**