#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File {
private:
    string fileName;
    int fileSize;
public:
    void split();
    void join();
};