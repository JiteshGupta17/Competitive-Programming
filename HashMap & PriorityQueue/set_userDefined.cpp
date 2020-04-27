#include<bits/stdc++.h>
using namespace std;

class student {
public:
    string name;
    double cgpa;
    student(string name, double cgpa) {
        this -> name = name;
        this -> cgpa = cgpa;
    }
};

// bool operator () (student x, student y)
// bool operator () (const student & x, const student & y)
// bool operator () (student & x, const student & y) // Wrong , All other right
struct comp {
    bool operator () (const student& x, student y) {
        return x.name < y.name;
    }
};

int main()
{
    set < student, comp > batch;
    batch.insert(student("jitesh", 8.10));
    batch.insert(student("zeeshan", 8.2));
    batch.insert(student("rohit", 8.3));
    batch.insert(student("vishesh", 8.5));
    batch.insert(student("shanky" , 8.7));

    for (auto ele : batch)
    {
        cout << ele.name << " " << ele.cgpa << "\n";
    }

}