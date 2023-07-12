#include "File.h"

int main() {
    File f;
    int slt = -1;

    while(slt != 0) {
        cout << "Enter 0 to quit the program" << endl;
        cout << "Enter 1 to split file" << endl;
        cout << "Enter 2 to join file" << endl;
        cout << "Enter your selection: ";
        cin >> slt;

        switch (slt)
        {
        case 1:
            f.split();
            break;
        case 2:
            f.join();
            break;
        default:
            break;
        }

    }

    return 0;
}