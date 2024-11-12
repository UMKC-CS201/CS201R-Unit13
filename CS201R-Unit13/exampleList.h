#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

using namespace std;

struct TV {
	int duration;
	string show;
};

void exampleList();
int loadListData(list<TV>& TVShows, list<string>& TVNames);
void removeList(list<TV>& TVShows, int key);
void removeList(list<string>& TVNames, string key);
void printList(list<TV> TVShows);
void printList(list<string> TVNames);

void exampleList() {
    cout << "\n\nLIST EXAMPLES\n";


    cout << "\n\nLIST EXAMPLE A: LOADING DATA INTO LISTS\n";
	list<TV> TVShows;
	list<string>TVNames;
	loadListData(TVShows, TVNames);

    cout << "\n\nLIST EXAMPLE B: REMOVING DATA FROM LIST\n";
    cout << "Your turn\n";
	//NEED TO IMPLEMENT : remove
	removeList(TVShows, 20);
    removeList(TVNames, "Bonanza");
    removeList(TVNames, "Blue Bloods");

    cout << "\n\nLIST EXAMPLE C: SORTING LIST DATA\n";
    cout << "Your turn\n";
    //NEED TO IMPLEMENT : sort


    cout << "\n\nLIST EXAMPLE D: PRINTING LIST DATA\n";
    cout << "Your turn\n";
	printList(TVShows);
	printList(TVNames);
}

int loadListData(list<TV>& TVShows, list<string>& TVNames) {

    // open input file
    ifstream inFile;
    int duration;
    inFile.open("shows.csv");
    if (!inFile.is_open())
        return 0;

    // setup variables and vectors
    string type, inLine, sstream, word, show;
    vector<string> row;
    TV temp;

    // read file into inLine string & loop to end of file

    getline(inFile, inLine);
    while (inFile.good()) {
        // push data onto the row vector as individual strings (separated by comma)
        row.clear();
        stringstream inSS(inLine);
        while (getline(inSS, word, ',')) {
            row.push_back(word);
        }

        try {
            temp.show = row[1];
            temp.duration = stoi(row[0]);
            TVNames.push_back(temp.show);

            // adding to the end of the lists
            TVShows.push_back(temp);

            //NEED TO IMPLEMENT : update to add in order by duration
            //create iterator & set to beginning of the list

            //loop through list until iterator is where we need to insert

            //insert in the list

        }
        catch (invalid_argument& e) {
            cout << e.what() << " can not be converted to int" << endl;
            return -1;
        }
        getline(inFile, inLine);
    }
    return 0;
}

void removeList(list<TV>& TVShows, int key) {
    //NEED TO IMPLEMENT
    //create an iterator

    //loop through list to find key to erase
    //if found erase the key and decrement the iterator

}

void removeList(list<string>& TVNames, string key) {
    //NEED TO IMPLEMENT
    //use list.remove();

}

// print using range-based for-loop
void printList(list<TV> TVShows) {
    //NEED TO IMPLEMENT
    cout << "\n\nPrint TV Shows Using Range Based For Loop\n";


}

void printList(list<string> TVNames) {
    //NEED TO IMPLEMENT
    cout << "\n\nPrint Shows Using Iterator\n";
    TVNames.sort();
    for (auto i : TVNames)
        cout << i << endl;

}