/**
 * Antonio Vega
 * Fungus Among Us: Outside Project
 * 20 April 2026
 *
 * This is a program that quizzes the user on six different edible Floridian fungi.
 * The user is asked various aesthetic questions about their fungus,
 * with each answer adding a different value to the score.
 * The highest-scoring fungus is deemed the result and is described in detail.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure for each fungus
struct Fungus
{
    string commonName, scientificName, habitat, notes;
    int score;
};

void resetScores(Fungus fungi[], int size);
int findBestMatch(Fungus fungi[], int size);
void runQuiz(Fungus fungi[]);

int main()
{
    Fungus fungi[6] =
    {
        {
            "Chanterelle",
            "Cantharellus cibarius",
            "Forest soil near hardwood trees",
            "Basidiomycete. Produces false gills rather than true gills.\n"
            "Mycorrhizal species forming symbiosis with tree roots.",
            0
        },

        {
            "Oyster Mushroom",
            "Pleurotus ostreatus",
            "Dead or decaying hardwood logs",
            "Basidiomycete. Saprotrophic decomposer of lignin-rich wood.\n"
            "Decurrent true gills and fan-shaped cap.",
            0
        },

        {
            "Morel",
            "Morchella esculenta",
            "Forest floor during spring",
            "Ascomycete. Produces spores in asci rather than basidia.\n"
            "Honeycomb fertile cap with hollow stem.",
            0
        },

        {
            "Indigo Milk Cap",
            "Lactarius indigo",
            "Near pine trees and sandy soil",
            "Basidiomycete. Exudes blue latex when damaged.\n"
            "Ectomycorrhizal species associated with conifers.",
            0
        },

        {
            "Ringless Honey Mushroom",
            "Desarmillaria tabescens",
            "Roots, buried wood, tree bases",
            "Basidiomycete. Forms dense clusters.\n"
            "Parasitic and saprotrophic species capable of colonizing weakened trees.",
            0
        },

        {
            "Bolete",
            "Boletus edulis",
            "Woodlands and grassy soil",
            "Basidiomycete. Possesses pore surface instead of gills.\n"
            "Many species are ectomycorrhizal with trees.",
            0
        }
    };

    int choice, border = 34;
    const int QUIZ = 1, LIST = 2, QUIT = 3;
    string errorMsg = "\nERROR: Invalid selection. "
        "Please type one of the following integers corresponding to an option:";

    cout << "============ FUNGAL GUESSING GAME ============" << endl
        << "This program contains data on six edible fungi found throughout Florida.\n"
           "Before starting the quiz, select a fungus mentally.\n"
           "Then, answer each question with the option that best matches your selection.\n"
           "(Consult the readme for more information.)" << endl;

    do {
        resetScores(fungi, 6);
        cout << "\n=========== MAIN MENU ===========" << endl
            << "\t1. Take Quiz\n"
            << "\t2. List Fungi\n"
            << "\t3. Quit Program\n"
            << "Choose an option: ";
        cin >> choice;
        cout << endl << setw(border) << setfill('=') << '\n' << endl;

        switch (choice) {
            case QUIZ:
                // Take the quiz
                runQuiz(fungi);
                break;
            case LIST: {
                // List all fungi in the program
                bool invalid = false;
                const int NAMES = 1, DETAILS = 2;
                do {
                    invalid = false;
                    cout << "\nWhich would you like to display?" << endl
                        << "\t1. Names only (useful for starting)" << endl
                        << "\t2. Detailed descriptions (answer key)" << endl
                        << "Option: ";
                    int answer;
                    cin >> answer;
                    cout << endl;

                    switch (answer) {
                        case NAMES:
                            for (int i=0; i<6; i++) {
                                cout << i+1 << ". " << fungi[i].commonName << " ("
                                    << fungi[i].scientificName << ')' << endl;
                            }
                            break;
                        case DETAILS:
                            border = 77;
                            for (auto & f : fungi) {
                                cout << endl << setw(border) << setfill('=') << '\n';
                                cout << "Common Name: " << f.commonName << endl;
                                cout << "Scientific Name: " << f.scientificName << endl;
                                cout << "Habitat: " << f.habitat << endl;
                                cout << "Description: " << f.notes << endl;
                                cout << setw(border) << setfill('=') << '\n' << endl;
                            }
                            break;
                        default:
                            invalid = true;
                            cout << errorMsg << endl << endl;
                    }
                } while (invalid);
                break;
            }
            case QUIT:
                // Close the program
                cout << "Goodbye." << endl;
                system("pause");
                break;
            default:
                // Error handler for invalid inputs
                cout << errorMsg << endl;
        }

    } while (choice != QUIT);

    return 0;
}

/**
 * Resets quiz scores to zero if the user wishes to repeat.
 * @param fungi
 * @param size
 */
void resetScores(Fungus fungi[], int size) {
    for (int i = 0; i < size; i++)
        fungi[i].score = 0;
}

/**
 * Finds which fungus best matches the scores yielded by the user's answers.
 * @param fungi
 * @param size
 * @return array index corresponding to the fungus closest to the user's score.
 */
int findBestMatch(Fungus fungi[], int size) {
    int best = 0;

    for (int i = 1; i < size; i++) {
        if (fungi[i].score > fungi[best].score)
            best = i;
    }

    return best;
}

/**
 * Function to administer the quiz.
 * @param fungi
 */
void runQuiz(Fungus fungi[])
{
    const int BORDER = 37;
    char answer;
    bool invalid = false;
    string errorMsg = "\nERROR: Invalid selection. "
        "Please enter one of the listed letters.\n";
    
    cout << '\n' << setw(BORDER) << setfill('=') << "" << endl
        << setw(30) << setfill(' ') << "Florida Edible Fungi Quiz" << endl
        << setw(BORDER) << setfill('=') << "" << endl;

    do {
        invalid = false;
        cout << "1. Main cap color?\n";
        cout << "a) Yellow/Orange\n"
            "b) White/Grey\n"
            "c) Blue\n"
            "d) Brown/Tan\n";
        cin >> answer;
        
        switch (tolower(answer)) {
            case 'a':
                fungi[0].score += 4;
                break;
            case 'b':
                fungi[1].score += 4;
                break;
            case 'c':
                fungi[3].score += 6;
                break;
            case 'd':
                fungi[2].score += 2;
                fungi[4].score += 2;
                fungi[5].score += 3;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    do {
        invalid = false;
        cout << "\n2. Where is it growing?\n";
        cout << "a) On dead wood\n"
                "b) On soil near trees\n"
                "c) In clusters near roots/stumps\n";
        cin >> answer;
    
        switch (tolower(answer)) {
            case 'a':
                fungi[1].score += 5;
                break;
            case 'b':
                fungi[0].score += 3;
                fungi[2].score += 3;
                fungi[3].score += 3;
                fungi[5].score += 3;
                break;
            case 'c':
                fungi[4].score += 5;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);
    
    do {
        invalid = false;
        cout << "\n3. Underside structure?\n";
        cout << "a) True gills\n"
                "b) Ridges / false gills\n"
                "c) Pores / sponge-like\n";
        cin >> answer;
    
        switch (tolower(answer)) {
            case 'a':
                fungi[1].score += 3;
                fungi[3].score += 3;
                fungi[4].score += 3;
                break;
            case 'b':
                fungi[0].score += 6;
                break;
            case 'c':
                fungi[5].score += 7;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    do {
        invalid = false;
        cout << "\n4. Cap shape?\n";
        cout << "a) Funnel / vase\n"
                "b) Shelf / fan\n"
                "c) Honeycomb\n"
                "d) Rounded cap\n";
        cin >> answer;
    
        switch (tolower(answer)) {
            case 'a':
                fungi[0].score += 5;
                break;
            case 'b':
                fungi[1].score += 6;
                break;
            case 'c':
                fungi[2].score += 8;
                break;
            case 'd':
                fungi[3].score += 2;
                fungi[4].score += 2;
                fungi[5].score += 2;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    do {
        invalid = false;
        cout << "\n5. Growing pattern?\n";
        cout << "a) Single\n"
                "b) Small scattered group\n"
                "c) Dense cluster\n";
        cin >> answer;

        switch (tolower(answer)) {
            case 'a':
                fungi[2].score += 3;
                fungi[5].score += 2;
                break;
            case 'b':
                fungi[0].score += 2;
                fungi[3].score += 2;
                break;
            case 'c':
                fungi[1].score += 3;
                fungi[4].score += 5;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    do {
        invalid = false;
        cout << "\n6. Stem present?\n";
        cout << "a) Yes\n"
                "b) Very short / none\n";
        cin >> answer;

        switch (tolower(answer)) {
            case 'a':
                fungi[0].score++;
                fungi[2].score++;
                fungi[3].score++;
                fungi[4].score++;
                fungi[5].score++;
                break;
            case 'b':
                fungi[1].score += 4;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    do {
        invalid = false;
        cout << "\n7. Texture?\n";
        cout << "a) Smooth\n"
                "b) Wavy\n"
                "c) Thick / fleshy\n";
        cin >> answer;

        switch (tolower(answer)) {
            case 'a':
                fungi[2].score += 2;
                fungi[3].score += 2;
                break;
            case 'b':
                fungi[0].score += 4;
                break;
            case 'c':
                fungi[1].score += 2;
                fungi[5].score += 2;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    do {
        invalid = false;
        cout << "\n8. Season found?\n";
        cout << "a) Spring\n"
                "b) Summer\n"
                "c) Fall\n";
        cin >> answer;

        switch (tolower(answer)) {
            case 'a':
                fungi[2].score += 4;
                break;
            case 'b':
                fungi[0].score += 2;
                fungi[3].score += 2;
                fungi[5].score += 2;
                break;
            case 'c':
                fungi[4].score += 3;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    do {
        invalid = false;
        cout << "\n9. Does it bruise blue when touched?\n";
        cout << "a) Yes\n"
                "b) No\n";
        cin >> answer;
    
        switch (tolower(answer)) {
            case 'a':
                fungi[5].score += 5;
                break;
            case 'b':
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    do {
        invalid = false;
        cout << "\n10. Most distinctive feature?\n";
        cout << "a) Bright blue color\n"
                "b) Golden color\n"
                "c) Shelf-like layers\n"
                "d) Honeycomb cap\n";
        cin >> answer;

        switch (tolower(answer)) {
            case 'a':
                fungi[3].score += 8;
                break;
            case 'b':
                fungi[0].score += 6;
                break;
            case 'c':
                fungi[1].score += 6;
                break;
            case 'd':
                fungi[2].score += 8;
                break;
            default:
                invalid = true;
                cout << errorMsg << endl;
        }
    } while (invalid);

    int best = findBestMatch(fungi, 6);

    cout << endl << setw(BORDER) << setfill('=') << '\n';
    cout << " Closest Match Identified" << endl;
    cout << setw(BORDER) << setfill('=') << '\n';
    cout << "Common Name: " << fungi[best].commonName << endl;
    cout << "Scientific Name: " << fungi[best].scientificName << endl;
    cout << "Habitat: " << fungi[best].habitat << endl;
    cout << "Description: " << fungi[best].notes << endl;
    cout << setw(BORDER) << setfill('=') << '\n';
}