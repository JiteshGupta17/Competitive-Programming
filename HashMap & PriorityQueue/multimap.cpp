#include <iostream>
#include<map>
#include<cstring>
using namespace std;

// Input
// 7
// b batman
// a apple
// b boat
// a angry
// c cat
// d dog
// e elephant


int main() {
    multimap<char, string> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch;
        string s;
        cin >> ch >> s;
        m.insert(make_pair(ch, s));
    }

    //Try to print the entire map
    for (auto p : m) {
        cout << p.first << " -> " << p.second << endl;
    }

    auto it = m.begin();
    m.erase(it);

    // Lower and Upper Bound
    auto it2 = m.lower_bound('b'); //batman
    auto it3 = m.upper_bound('d'); //elephant

    for (auto it4 = it2; it4 != it3; it4++) {
        cout << it4->second << " ," << endl;
    }

    //search for cat and delete it
    auto f = m.find('c');
    if (f->second == "cat") {
        m.erase(f);
    }

    //Try to print the entire map
    for (auto p : m) {
        cout << p.first << " -> " << p.second << endl;
    }

}

