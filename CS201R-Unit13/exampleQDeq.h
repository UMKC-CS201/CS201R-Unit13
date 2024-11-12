#pragma once
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


void exampleQDeq() {

    cout << "\n\nQUEUE EXAMPLE A" << endl << endl;
    queue<string> line1;
    line1.push("Lion");
    line1.push("Tiger");
    line1.push("Bear");
    line1.push("Duck");
    line1.push("Duck");
    line1.push("Goose");

    string animal;
    int j = 1;
    cout << "\nTHERE ARE " << line1.size() << " ANIMALS IN THE QUEUE" << endl;

    // NOTE: you can not 'loop' through a queue
    //       you may only access from the top
    //       therefore - a for loop does not work properly here - a while loop is needed

    while (line1.size() > 0) {
        animal = line1.front();
        cout << j << " : " << animal << " is now at the front of the line" << endl;
        line1.pop();
        j++;
    }
    /*
    // NOTE:    if you don't want to 'empty' the queue - you could use a 'for' loop to size
    //          and push the elements back onto the queue
    int lineSize = line1.size();
    for (int i = 0; i < lineSize; i++){
        animal = line1.front();
        cout << i+1 << " : " << animal << " is now at the front of the line" << endl;
        line1.pop();
        line1.push(animal);
    }
    */
    
    cout << "\n\n\nDEQUE EXAMPLE A:" << endl << endl;
    deque<string> line2;

    line2.push_back("Lion");
    line2.push_back("Tiger");
    line2.push_back("Bear");
    line2.push_back("Duck");
    line2.push_back("Duck");
    line2.push_back("Goose");

    cout << "\nTHERE ARE " << line2.size() << " ANIMALS IN THE DEQUE" << endl;

    // a while loop will work here
    j = 1;
    while (line2.size() > 0) {
        animal = line2.front();
        cout << j << " : " << animal << " is now at the front of the line" << endl;
        line2.pop_front();
        j++;
    }

    cout << "\n\nDEQUE EXAMPLE B: MIN, MAX, FIND" << endl << endl;
    line2.push_front("Lion");
    line2.push_front("Tiger");
    line2.push_front("Bear");
    line2.push_front("Duck");
    line2.push_front("Duck");
    line2.push_front("Goose");

    // use iterator to use the functions: find, min, max
    // delcare iterator
    deque<string>::iterator it4;

    //use min_element to find the location of the minimum element
    it4 = min_element(line2.begin(), line2.end());
    cout << *it4 << " is the minimum element\n";

    //use max_element to find the location of the maximum element
    it4 = max_element(line2.begin(), line2.end());
    cout << *it4 << " is the maximum element\n";

    //use find to find "Bear"
    it4 = find(line2.begin(), line2.end(), "Bear2");
    if (it4 != line2.end())
        cout << *it4 << " is equal to Bear\n";
    else
        cout << "Bear 2 not found\n";

    cout << "\n\nDEQUE EXAMPLE C: PRINT WITH ITERATOR\n\n";
    //NEED TO IMPLEMENT
    //decLare a new iterator & print the deque using a standard for loop
    deque<string> ::iterator it5;
    for (it5 = line2.begin(); it5 != line2.end(); it5++)
        cout << *it5 << endl;


    cout << "\n\nDEQUE EXAMPLE D: SORT & PRINT WITH RANGE BASED FOR LOOP\n\n";
    //NEED TO IMPLEMENT
    //use sort command to sort list
    sort(line2.begin(), line2.end());

    //print deque using range based for loop
    for (auto its : line2)
        cout << its << endl;


    //print elements using iterator & remove from the deque
    cout << "\n\nDEQUE EXAMPLE E:  DEQUE - STANDARD FOR LOOP" << endl << endl;
    j = 1;

    cout << "Exiting line 2" << endl;

}