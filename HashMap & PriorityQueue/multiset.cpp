#include <bits/stdc++.h>
using namespace std;

#define It multiset<int> :: iterator

int main() {
    vector<int> arr = {10, 10, 20, 20, 20, 30, 30, 30, 40, 70, 80};
    multiset<int> m(arr.begin(), arr.end());

    for (int ele : m) cout << ele << ", ";
    cout << endl;

    // Erase
    m.erase(m.find(20)); // Delete the first encountered 20
    m.erase(20); // Deletes all 20 present
    for (int ele : m) cout << ele << ", ";
    cout << endl;

    // count
    cout << m.count(30) << endl;

    // Equal range
    pair<It, It> range = m.equal_range(30);
    for (auto start = range.first; start != range.second; start++)
    {
        cout << *start << ", ";
    }
    cout << endl;

    // Lower bound >= and Upper bound >
    for (auto it = m.lower_bound(10); it != m.upper_bound(70); it++) // end will be greater than 70 i.e 80
    {
        cout << *it << ", ";
    }
    cout << endl;

}
