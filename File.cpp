#include "File.h"

void File::split() {
    cout << "Enter file name to split: ";
    cin >> fileName;
    cout << "Enter part size: ";
    int partSize = 0;
    cin >> partSize;
    char *reader = new char[partSize];
    
    ifstream in(fileName, ios::binary);
    in.seekg(0, in.end);
    fileSize = in.tellg();
    in.seekg(0, in.beg);

    int remainByte = fileSize % partSize;

    int i = 1;
    while(!in.eof()) {
        in.read(reader, partSize);

        ofstream out(fileName + "." + to_string(i), ios::binary);
        out.write(reader, partSize);
        out.close();

        i++;
    }
    in.close();

    i--;
    if(remainByte != 0) {
        ofstream out(fileName + "." + to_string(i), ios::binary);
        out.write(reader, remainByte);
        out.close();
    }

    delete []reader;
}

void File::join() {
    cout << "Enter name of the first file to join: ";
    string fname;
    cin >> fname;
    ifstream in(fname, ios::binary);
    in.seekg(0, in.end);
    int size = in.tellg();
    in.seekg(0, in.beg);
    in.close();

    char* reader = new char[size];
    fname = fname.substr(0, fname.length() - 2);

    ofstream out("merged" + fname, ios::binary);
    int i = 1;
    while(true) {
        ifstream readFile(fname + "." + to_string(i), ios::binary);
        if(!readFile.is_open()) break;

        readFile.seekg(0, readFile.end);
        int partSize = readFile.tellg();
        readFile.seekg(0, readFile.beg);

        readFile.read(reader, partSize);
        out.write(reader, partSize);


        readFile.close();
        i++;
    }
    out.close();

    delete []reader;
}