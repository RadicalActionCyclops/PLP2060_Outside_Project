/**
 * Antonio Vega
 * Fungus Among Us: Outside Project
 * 20 April 2026
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Fungus {
    string commonName, genus, species;
    int score;
};

bool loadFile(vector<Fungus>& fungi);

int main() {
    vector<Fungus> fungi;
    bool fileFound = loadFile(fungi);
    if (!fileFound)
        return 1; // terminate program if fungi.txt not found in root directory

    return 0;
}

/**
 * Opens fungi.txt and reads its contents to load into program memory.
 * @param fungi
 * @return true if file loaded and read, false if not loaded
 */
bool loadFile(vector<Fungus>& fungi) {
    ifstream ifile("fungi.txt");
    if (ifile.fail()) {
        cout << "ERROR: File \"fungi.txt\" not found."
                " Please place file in the same directory as this executable." << endl;
        return false;
    }
    return true;
}