#include "FileCompressor.h"
#include <fstream>
#include <iostream>

bool FileCompressor::compress(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile, ios::in | ios::binary);
    if (!inFile) {
        cerr << "Error opening input file: " << inputFile << endl;
        return false;
    }

    ofstream outFile(outputFile, ios::out | ios::binary);
    if (!outFile) {
        cerr << "Error opening output file: " << outputFile << endl;
        inFile.close();
        return false;
    }

    string data((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    string compressedData = runLengthEncode(data);

    outFile << compressedData;

    inFile.close();
    outFile.close();
    return true;
}

bool FileCompressor::decompress(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile, ios::in | ios::binary);
    if (!inFile) {
        cerr << "Error opening input file: " << inputFile << endl;
        return false;
    }

    ofstream outFile(outputFile, ios::out | ios::binary);
    if (!outFile) {
        cerr << "Error opening output file: " << outputFile << endl;
        inFile.close();
        return false;
    }

    string data((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    string decompressedData = runLengthDecode(data);

    outFile << decompressedData;

    inFile.close();
    outFile.close();
    return true;
}

string FileCompressor::runLengthEncode(const string& data) {
    string encoded;
    int n = data.length();
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && data[i] == data[i + 1]) {
            count++;
            i++;
        }
        encoded += data[i] + to_string(count);
    }
    return encoded;
}

string FileCompressor::runLengthDecode(const string& data) {
    string decoded;
    int n = data.length();
    for (int i = 0; i < n; i++) {
        char c = data[i];
        i++;
        int count = 0;
        while (i < n && isdigit(data[i])) {
            count = count * 10 + (data[i] - '0');
            i++;
        }
        i--;
        decoded.append(count, c);
    }
    return decoded;
}
