#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstring>

using namespace std;
namespace fs = filesystem;

bool filesAreEqual(const string& f1, const string& f2) {
    ifstream a(f1, ios::binary | ios::ate);
    ifstream b(f2, ios::binary | ios::ate);

    if (!a || !b) return false;
    if (a.tellg() != b.tellg()) return false;

    a.seekg(0);
    b.seekg(0);

    const size_t BUFSIZE = 4096;
    char buf1[BUFSIZE], buf2[BUFSIZE];

    while (a && b) {
        a.read(buf1, BUFSIZE);
        b.read(buf2, BUFSIZE);

        if (a.gcount() != b.gcount()) return false;
        if (memcmp(buf1, buf2, a.gcount()) != 0)
            return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage:\n";
        cerr << argv[0] << " <program> <input_folder> <output_folder>\n";
        return 1;
    }

    string program = argv[1];
    string inputDir = argv[2];
    string outputDir = argv[3];

    int passed = 0, total = 0;

    for (const auto& entry : fs::directory_iterator(inputDir)) {
        string inputFile = entry.path().filename().string();

        // trasforma: inputX.txt → outputX.txt
        string outputFile = inputFile;
        outputFile.replace(0, 5, "output");

        string inputPath = inputDir + "/" + inputFile;
        string expectedOutputPath = outputDir + "/" + outputFile;
        string producedOutputPath = "output.txt";

        // comando: ./program input.txt output.txt
        string command = "./" + program + "  " + inputPath + " " + producedOutputPath;
        system(command.c_str());

        total++;

        if (filesAreEqual(producedOutputPath, expectedOutputPath)) {
            cout << "✅ " << inputFile << " -> OK\n";
            passed++;
        } else {
            cout << "❌ " << inputFile << " -> WRONG\n";
        }
    }

    cout << "\n========================\n";
    cout << "Passed: " << passed << " / " << total << endl;

    return 0;
}
