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

void exampleMap();
int loadMapData(map<int, vector <string>>& TVShows);


int loadMapData(map<int, vector <string>>& TVShows) {

    // open input file
    ifstream inFile;
    int duration;
    inFile.open("shows.csv");

    // setup iterator. variables and vectors
    map<int, vector<string>> ::iterator iter;
    string type, inLine, sstream, word, show;
    vector <string> temp;
    vector <string> row;

    // read file into inLine string & loop to end of file

    getline(inFile, inLine);
    while (inFile.good()) {
        // push data onto the row vector as individual strings (separated by comma)
        row.clear();
        stringstream inSS(inLine);
        while (getline(inSS, word, ',')) {
            row.push_back(word);
        }
        show = row[1];
        try {
            duration = stoi(row[0]);
        }
        catch (invalid_argument& e) {
            cout << e.what() << " can not be converted to int" << endl;
            return -1;
        }

        //if the duration is not in the list
        //clear the temporary vector that will hold the list of shows; 
        //add the show to the vector 
        //and insert the pair<duration, show list> into the map
        if (TVShows.find(duration) == TVShows.end()) {
            temp.clear();
            temp.push_back(show);
            TVShows.insert(pair<int, vector<string>>(duration, temp));
        }
        //if the duration has already been added
        //add the new show to the duration    
        else {
            TVShows[duration].push_back(show);
        }
        getline(inFile, inLine);
    }
    return 0;
}

void exampleMap() {
    cout << "\n\nMAP EXAMPLES\n";


    cout << "\n\nMAP EXAMPLE A: MAP WITH INTEGER KEY AND ASSOCIATED STRING DATA\n";
    //MAP1:  a simple map (key is an integer, with an associated name)

    map<int, string> name_map;
    map<int, string>::iterator it1;

    //NOTE: value in [] must be assignable
    //add keys & values to map:
    name_map[0] = "Yosemite Sam";
    name_map[1] = "Bugs Bunny";
    name_map[2] = "Bob the Builder";
    name_map[1] = "Dora";                //will replace Bugs
    name_map.emplace(3, "BooBooBear");   //will add BooBoo
    name_map.emplace(1, "BooBooBear");   //will not replace Dora
    name_map.insert({ 4, "Yogi Bear" }); //will add Yogi
    name_map.insert({ 28, "Gasp" });     //will add Gasp 
    name_map[3] = "Say What Now?";       //will replace BooBoo


    // this one is odd b/c we are iterating through key values
    // NOTE:  changes to the map
    for (int i = 0; i < name_map.size(); i++)
        cout << i << " : " << name_map[i] << endl;

    // initialize container 
    map<int, int> map2;
    map<int, int>::iterator it;

    // insert elements in random order 
    map2[4] = 15;            //added
    map2.emplace(2, 25);     //added
    map2.insert({ 1, 10 });  //added
    map2.insert({ 3, 20 });  //added

    map2.insert({ 2, 20 });  //key 2 not replaced
    map2.insert({ 5, 50 });  //added
    map2.emplace(4, 40);     //key 4 (value 15) not replaced

    // prints the elements 
    cout << "\n\nKEY\tELEMENT\n";
    for (it = map2.begin(); it != map2.end(); ++it) {
        cout << it->first << '\t' << it->second << '\n';
    }

    cout << "\n\nMAP EXAMPLE B: MAP WITH CHAR KEY AND ASSOCIATED STRING DATA \n";
    map<char, string> grades_map;      //this also works: map<pair<char,string>>

    // add keys & values to map:
    grades_map['a'] = "Alvin";
    grades_map['b'] = "Boo Boo Bear";
    grades_map['c'] = "Charlie Brown";
    grades_map['D'] = "Daffy Duck";
    grades_map['a'] = "Alfred";       //replaces Alvin

    // What is happening???

    cout << "\n\nMAP EXAMPLE C(1): WHAT THE HECK - PART 1\n";
    for (int i = 0; i < grades_map.size(); i++)
        cout << i << ":" << grades_map[i] << endl;

    cout << "\n\nMAP EXAMPLE C(2): WHAT THE HECK - PART 2\n";
    for (auto j : grades_map)
        cout << j.first << " : " << j.second << endl;

    // try an iterator??
    cout << "\n\nMAP EXAMPLE C(3): WHAT THE HECK - PART 3\n";
    map<char, string>::iterator it2 = grades_map.begin();
    while (it2 != grades_map.end()) {
        cout << it2->first << ":" << it2->second << endl;
        it2++;
    }

    cout << "\n\nMAP EXAMPLE C(4): A FIX - PART 4\n";
    cout << "NEW MAPS!\n";



    cout << "\n\nMAP EXAMPLE D(1): MAP WITH CHAR KEY AND ASSOCIATED STRING DATA \n";
    map<char, string> grades_map2;   //this also works: map<pair<char,string>>


    // add keys & values to map:
    grades_map2.insert(pair<char, string>('a', "Alvin"));
    grades_map2.insert(pair<char, string>('b', "Boo Boo Bear"));
    grades_map2.insert(pair<char, string>('c', "Charlie Brown"));
    grades_map2.insert(pair<char, string>('D', "Daffy Duck"));
    grades_map2.emplace(pair<char, string>('B', "Bubba Wubba"));
    grades_map2.emplace(pair<char, string>('c', "Corella DeVille"));

    //this will not compile:
    // grades_map2.insert('e',"Elle");
    //this will also work
    grades_map2.insert(make_pair('e', "Elle"));

    for (auto j : grades_map2)
        cout << j.first << " : " << j.second << endl;
    cout << endl;


    cout << "\n\nMAP EXAMPLE D(2): A FIX - PART 4 (REVERSED)\n";
    map<char, string>::reverse_iterator revIt;
    for (revIt = grades_map2.rbegin(); revIt != grades_map2.rend(); ++revIt)
        cout << revIt->first << " : " << revIt->second << endl;



    cout << "\n\nEXAMPLE 3C: MAP WITH INTEGER KEY AND ASSOCIATED VECTOR OF DATA\n";
    //EXAMPLE3: here the key is an integer (the number of years a show has been on the air)
    //    the associated data is a list of the shows that have been on the air matching
    //    that number of years   

    // set up map & iterator & load data
    map<int, vector<string>> TVShows;
    map<int, vector<string>> ::iterator it3;
    loadMapData(TVShows);

    // using standard for loop & iterator
    cout << "          TV SHOWS" << endl;
    for (it3 = TVShows.begin(); it3 != TVShows.end(); it3++) {
        cout << "************** " << it3->first << " **************" << endl;
        for (auto it4 = it3->second.cbegin(); it4 != it3->second.cend(); ++it4)
            cout << "  " << *it4 << endl;
        cout << endl;
    }

    // print shows with specific duration 
    cout << "******* TV SHOWS - 14 YEARS  ******* " << endl;

    it3 = TVShows.find(14);
    for (auto i = it3->second.begin(); i != it3->second.end(); ++i)
        cout << *i << endl;


    // insert a value with a new key into the map
    int tempDuration = 25;
    string tempShow = "NCIS";
    TVShows[tempDuration].push_back(tempShow);
    TVShows[54].push_back("As The World Turns");

    // insert a valie with an existing key into the map 
    TVShows[57].push_back("Days of our Lives");


    // using range based for loop
    cout << "\n\n\tTV SHOWS - Range Based" << endl;
    for (auto& tv : TVShows) {
        cout << "************** " << tv.first << " **************" << endl;
        for (auto tv2 : tv.second)
            cout << " " << tv2 << endl;
        cout << endl;
    }


}
