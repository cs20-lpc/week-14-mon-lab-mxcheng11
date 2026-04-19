#include "ArrayListDictionary.hpp"
#include <string>

int main() {
    // variables
    ArrayListDictionary<string, string> dict;
    string userWord, s;
    int userChoice = 0;
    bool flag = false;

    // add data to the dictionary
    dict.insert("quack", "said Mr. Duck");
    dict.insert("haskell", "fantastic programming language, go learn it");
    dict.insert("banana", "a fruit that many like, or a phone");
    dict.insert("dog", "a domesticated fluff ball");
    dict.insert("cactus", "a pointy plant");
    dict.insert("phoenix", "a bird on fire");
    dict.insert("igloo", "a cool house");
    dict.insert("graph", "an awesome data structure!");

    // display menu
    cout << "Welcome to my dictionary program!\n";
    cout << "Here are your options:\n";
    cout << "\t1. Find\n";
    cout << "\t2. Insert\n";
    cout << "\t3. Remove\n";
    cout << "\t4. Sort\n";
    cout << "\t5. Size\n";
    cout << "\t6. Clear\n";
    cout << "\t7. Print\n";
    cout << "\t8. Quit\n";

    // loop until the user quits
    do {
        cout << "Enter your option: ";
        cin  >> userChoice;

        switch (userChoice) {
            // find
            case 1:
                try {
                    cout << "Enter a key to search my dictionary: ";
                    cin.ignore();
                    getline(cin, userWord);
                    s = dict.find(userWord);
                    cout << s << endl;
                }
                catch (const string& e) {
                    cout << e << endl;
                }
                break;

            // insert
            case 2:
                cout << "Enter the key of the new record: ";
                cin.ignore();
                getline(cin, userWord);
                cout << "Enter the value of the new record: ";
                getline(cin, s);
                dict.insert(userWord, s);
                break;

            // remove
            case 3:
                try {
                    cout << "Enter the key of the record to be "
                         << "removed from my dictionary: ";
                    cin.ignore();
                    getline(cin, userWord);
                    dict.remove(userWord);
                }
                catch (const string& e) {
                    cout << e << endl;
                }
                break;

            // sort
            case 4:
                do {
                    cout << "What kind of sort algorithm should be used?\n"
                         << "\t1. Bubble sort\n"
                         << "\t2. Selection sort\n"
                         << "\t3. Insertion sort\n";
                    cin  >> userChoice;
                } while (userChoice < 1 || userChoice > 3);
                try {
                    dict.sort(userChoice);
                    cout << "Number of key comparisons: "
                         << dict.getNumComps() << endl
                         << "Number of swaps: "
                         << dict.getNumSwaps() << endl;
                }
                catch (const string& e) {
                    cout << e << endl;
                }
                break;

            // size
            case 5:
                cout << "Dictionary size is " << dict.size() << endl;
                break;

            // clear
            case 6:
                cout << "Clearing out my dictionary . . . ";
                dict.clear();
                cout << "cleared!\n";
                break;

            // print
            case 7:
                cout << dict;
                break;

            // quit
            case 8:
                flag = true;
                break;
        }
    } while (!flag);

    // terminate
    return 0;
}
