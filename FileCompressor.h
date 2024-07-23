#pragma once
#include <string>

using namespace std;

class FileCompressor {
public:
    bool compress(const string& inputFile, const string& outputFile);
    bool decompress(const string& inputFile, const string& outputFile);

private:
    string runLengthEncode(const string& data);
    string runLengthDecode(const string& data);
};
