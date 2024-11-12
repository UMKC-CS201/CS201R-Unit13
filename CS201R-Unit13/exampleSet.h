#pragma once
#include <iostream>
#include <set>
#include <string>

using namespace std;

void exampleSet();

void exampleSet() {

    cout << "\n\nSET EXAMPLES\n";
    set<string> newSet1;
    set<string>::iterator setIt;

    newSet1.insert("Yosemite Sam");
    newSet1.insert("Spongebob Squarepants");
    newSet1.insert("Boo Boo Bear");
    newSet1.insert("Dora the Explorer");
    newSet1.insert("Boo Boo Bear");

    cout << "\n\nSET EXAMPLE A: Print Set1 Using Standard For Loop & Iterator\n";
    // print using standard for loop 
    for (setIt = newSet1.begin(); setIt != newSet1.end(); ++setIt)
        cout << *setIt << endl;

    cout << "\n\nSET EXAMPLE B: Print Set1 Using Range Based For Loop\n";
    // print using range based for loop
    for (auto name : newSet1)
        cout << name << endl;


    // print newSet2 in reverse (code from GeeksforGeeks)
    set<string> newSet2 = { "Mr. Crabs", "Han Solo", "Obiwan Kenobi", "Yogi", "Albert", "Yosemite Sam" };

    set<string> newSet3 = newSet1;
    cout << "\n\nSET EXAMPLE C:  Output Set Equality\n";
    cout << (newSet1 == newSet2) << endl;
    cout << (newSet1 == newSet3) << endl;

    cout << "\n\nSET EXAMPLE D: Merge 2 Sets & Output Result In Reverse\n";
    // merge newSet2 with newSet3
    newSet2.insert(newSet3.begin(), newSet3.end());

    set<string>::reverse_iterator revIt;

    for (revIt = newSet2.rbegin(); revIt != newSet2.rend(); ++revIt)
        cout << *revIt << endl;

}