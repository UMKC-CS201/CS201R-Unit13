#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//Functions Used for examplePair
int loadPairData(list<pair<int, string>>& grades);
 
void examplePair() {

    cout << "\n\nPAIR EXAMPLES\n";
     
    //create 3 pairs and print them
    //create a pair & then load values in using make_pair
    pair<int, string> newPair1;
    newPair1 = make_pair(85, "Mr. Crabs");

    //create & load values in pair
    pair<int, string> newPair2(99, "Han Solo");
    pair<int, string> newPair3(newPair1);

    //change value in the pair
    newPair3.first = 79;

    //print the pairs
    cout << "\n\nPAIR EXAMPLE A: Print Three Pairs\n";
    cout << newPair1.first << " : " << newPair1.second << endl;
    cout << newPair2.first << " : " << newPair2.second << endl;
    cout << newPair3.first << " : " << newPair3.second << endl;

    //add pair elements to grades list:
    list<pair<int, string>> grades1;

    grades1.push_back(newPair1);
    grades1.push_back(newPair2);
    grades1.push_back(newPair3);

    //print the list using range based for loop
    cout << "\n\nPAIR EXAMPLE B: Print List Made Up Of Pairs\n";
    for (auto i : grades1) {
        cout << i.first << " : " << i.second << endl;
    }
    cout << endl << endl;

    cout << "\n\nPAIR EXAMPLE C:  Print List of Pairs Using Standard For Loop\n";
    cout << "Your turn\n";
    //print the list using standard for loop & iterator
    //declare the iterator

    //write the for loop for the list





    // this example is creating a list of pairs 
    // by reading in data from grade.txt
    // then printing a list of pair types
    list<pair<int, string>> grades2;
    loadPairData(grades2);

    // print using standard for loop & iterator
    cout << "\n\nPAIR EXAMPLE D:   Print Grades Using Standard For Loop\n";
    cout << "Your Turn\n";
    //declare the iterator for the list

    //write the standard for loop that iterates through the list


    //sort the grades list of pairs
    grades2.sort();

    // print using range based for loop
    cout << "\n\nPAIR EXAMPLE E:   Print Grades > 80 Using Range Based For Loop\n";
    cout << "Your Turn\n";

    //write the range based for loop to print the grades over 80


}


int loadPairData(list<pair<int, string>>& grades) {
    ifstream inFile;
    int duration;
    inFile.open("grade.txt");

    int score;
    string type, inLine, sstream, word, name;
    pair <int, string> temp;
    vector <string> row;

    getline(inFile, inLine);
    while (inFile.good()) {
        row.clear();
        stringstream inSS(inLine);
        while (getline(inSS, word, ',')) {
            row.push_back(word);
        }
        name = row[1];
        try {
            score = stoi(row[0]);
            temp = make_pair(score, name);
            grades.push_back(temp);
            /*
            //add to list in order or use .sort()
            list<pair<int,string>>::iterator listIt2;
            bool inserted = false;
            for (listIt2 = grades.begin();
                 listIt2 != grades.end(); listIt2++){
                 if (listIt2->first > score){
                    grades.insert(listIt2, temp);
                    inserted  = true;
                    break;
                 }
            }
            if (!inserted)
              grades.push_back(temp);
            */
        }
        catch (invalid_argument& e) {
            cout << e.what() << " can not be converted to int" << endl;
            return -1;
        }

        getline(inFile, inLine);
    }

    return 0;
}
