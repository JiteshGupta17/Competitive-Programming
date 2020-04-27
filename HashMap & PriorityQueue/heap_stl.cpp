// K-th Largest --> use max-heap.
// K-th Smallest --> use min-heap.

// 1. for integers
// priority_queue<int> gives by default max-heap.
// priority_queue<int, vector<int>, greater<int>> gives min-heap.

// 2. for pair of int,int
// priority_queue <pair<int, int>> pq;
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

// 3. for a class , let class name be Person  -
// struct CompareHeight {
//     bool operator()(Person const& p1, Person const& p2)
//     {
//         // return "true" if "p1" is ordered
//         // before "p2", for example:
//         return p1.height < p2.height;
//     }
// };
// priority_queue<Person, vector<Person>, CompareHeight> Q;

#include<bits/stdc++.h>
using namespace std;

//Using MaxHeap
int findKthLargest(vector<int>& nums, int k)
{
	priority_queue <int> pq(nums.begin(), nums.end());

	for (int i = 0; i < k - 1; i++)
	{
		pq.pop();
	}

	return pq.top();
}

//Using MinHeap
int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < k; i++)
	{
		pq.push(nums[i]);
	}

	for (int i = k; i < nums.size(); i++ )
	{
		if (pq.top() < nums[i])
		{
			pq.pop();
			pq.push(nums[i]);
		}
	}

	return pq.top();
}

int main()
{
	vector<int> nums = {3, 2, 1, 5, 6, 4};

	cout << findKthLargest(nums, 2);
}

// =============================================================================================
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

// If class instead of struct then operator<(const student& x, student y)
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
	priority_queue<student, vector<student>, comp> batch;

	batch.push(student("jitesh", 8.10));
	batch.push(student("zeeshan", 8.2));
	batch.push(student("rohit", 8.3));
	batch.push(student("vishesh", 8.5));
	batch.push(student("shanky" , 8.7));

	while (!batch.empty())
	{
		auto ele = batch.top();
		cout << ele.name << " " << ele.cgpa << endl;
		batch.pop();
	}
}