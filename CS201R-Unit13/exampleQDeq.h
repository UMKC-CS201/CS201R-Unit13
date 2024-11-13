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

    // NOTE: you can not 'loop' through a queue - no iteration
    //       so NO for loop
    //       ONLY access from the top 
    //       here - a while loop is needed

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
    
    deque<string> line2;

    line2.push_back("Lion");
    line2.push_back("Tiger");
    line2.push_back("Bear");
    line2.push_back("Duck");
    line2.push_back("Duck");
    line2.push_back("Goose");

    //deques are iterable
    cout << "\n\nDEQUE EXAMPLE A: PRINT WITH ITERATOR" << endl;
    for (auto id = line2.begin(); id != line2.end(); ++id) {
        cout << *id << " ";
    }
    cout << endl;

    //deques are iterable
    cout << "\n\nDEQUE EXAMPLE B: PRINT WITH RANGE BASED FOR LOOP" << endl;
    for (auto i : line2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "\nTHERE ARE " << line2.size() << " ANIMALS IN THE DEQUE" << endl;


    // a while loop will work too...but now deque is empty
    cout << "\n\nDEQUE EXAMPLE C: PRINT WITH WHILE LOOP" << endl;
    j = 1;
    while (line2.size() > 0) {
        animal = line2.front();
        cout << j << " : " << animal << " is now at the front of the line" << endl;
        line2.pop_front();
        j++;
    }

    cout << "\n\nDEQUE EXAMPLE D: MIN, MAX, FIND" << endl << endl;
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

    cout << "\n\nDEQUE EXAMPLE E: PRINT WITH ITERATOR\n\n";
    //NEED TO IMPLEMENT
    //decLare a new iterator & print the deque using a standard for loop



    cout << "\n\nDEQUE EXAMPLE F: SORT & PRINT WITH RANGE BASED FOR LOOP\n\n";
    //NEED TO IMPLEMENT
    //use sort command to sort list


    //print deque using range based for loop



    cout << "\n\nDEQUE EXAMPLE G:  DEQUE - STANDARD FOR LOOP" << endl << endl;
    //NEED TO IMPLEMENT
    //print elements using iterator & remove from the deque



    cout << "Exiting line 2" << endl;

}