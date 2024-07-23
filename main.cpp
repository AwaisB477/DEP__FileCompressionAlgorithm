#include <iostream>
#include "FileCompressor.h"

using namespace std;

int main() {
    FileCompressor compressor;
    string inputFile, outputFile;
    int choice;

    cout << "File Compression Tool\n";
    cout << "1. Compress\n";
    cout << "2. Decompress\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    if (choice == 1) {
        if (compressor.compress(inputFile, outputFile)) {
            cout << "File compressed successfully.\n";
        }
        else {
            cout << "Compression failed.\n";
        }
    }
    else if (choice == 2) {
        if (compressor.decompress(inputFile, outputFile)) {
            cout << "File decompressed successfully.\n";
        }
        else {
            cout << "Decompression failed.\n";
        }
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
