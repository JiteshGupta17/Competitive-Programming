Ques -> https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313/
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

    - FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
    - int showFirstUnique() returns the value of the first unique integer of the queue, and returns - 1 if there is no such integer.
    - void add(int value) insert value to the queue.

        Input:
        ["FirstUnique", "showFirstUnique", "add", "showFirstUnique", "add", "showFirstUnique", "add", "showFirstUnique"]
        [[[2, 3, 5]], [], [5], [], [2], [], [3], []]
        Output:
        [null, 2, null, 2, null, 3, null, -1]

        Explanation:
        FirstUnique firstUnique = new FirstUnique([2, 3, 5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1

// ============================================================================================
// Method - 1
class FirstUnique {
public:
    queue<int> q;
    unordered_map<int, int> mp;
    FirstUnique(vector<int>& nums) {

        for (int ele : nums)
        {
            if (mp.find(ele) == mp.end())
            {
                q.push(ele);
            }
            mp[ele]++;
        }
    }

    int showFirstUnique() {
        while (!q.empty())
        {
            int cur = q.front();
            if (mp[cur] == 1) return cur;
            q.pop();
        }

        return -1;
    }

    void add(int value) {
        if (mp.find(value) == mp.end())
        {
            q.push(value);
        }
        mp[value]++;
    }
};


// Method - 2
class FirstUnique {
public:
    list<int> l;
    // int for ele, iterator for position in list and bool if we have already deleted it
    unordered_map<int, pair<list<int> :: iterator, bool>> mp;
    int pos = 0;

    FirstUnique(vector<int>& nums) {

        for (int ele : nums)
        {
            if (mp.find(ele) == mp.end())
            {
                l.push_back(ele);
                auto it = l.end(); it--;
                mp[ele] = {it, false};
            }
            else {
                if (!mp[ele].second)
                {
                    l.erase(mp[ele].first);
                    mp[ele].second = true;
                }
            }
        }
    }

    int showFirstUnique() {

        if (l.empty()) return -1;
        return l.front();
    }

    void add(int value) {
        if (mp.find(value) == mp.end())
        {
            l.push_back(value);
            auto it = l.end(); it--;
            mp[value] = {it, false};
        }
        else {
            if (!mp[value].second)
            {
                l.erase(mp[value].first);
                mp[value].second = true;
            }
        }
    }
};

// Method - 3
class Node {
public:
    int data;
    Node* prev ;
    Node* next ;

    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class FirstUnique {
public:

    Node* prehead = new Node(-1);
    Node* tail = prehead;
    unordered_map<int, pair<Node*, bool>>  present;


    FirstUnique(vector<int>& nums) {

        for (int ele : nums)
        {
            if (present.find(ele) == present.end())
            {
                Node* n = new Node(ele);
                tail->next = n;
                n->prev = tail;
                tail = n;

                present[ele] = {n, false};
            }
            else { // false not deleted and true means deleted
                if (!present[ele].second)
                {
                    present[ele].second = true;
                    Node* cur = present[ele].first;

                    if (cur == tail) {
                        tail = tail->prev;
                        tail->next = NULL;
                        continue;
                    }

                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;

                }
            }
        }
    }

    int showFirstUnique() {

        if (prehead->next) return prehead->next->data;
        return -1;

    }

    void add(int ele) {
        if (present.find(ele) == present.end())
        {
            Node* n = new Node(ele);
            tail->next = n;
            n->prev = tail;
            tail = n;

            present[ele] = {n, false};
        }
        else {
            if (!present[ele].second)
            {
                present[ele].second = true;
                Node* cur = present[ele].first;

                if (cur == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                    return;
                }

                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;

            }
        }
    }
};


// Method - 4
class FirstUnique {
public:

    set<pair<int, int>> st1; // first will be like index and second will be ele
    unordered_map<int, int>  present;

    int front = 0;

    FirstUnique(vector<int>& nums) {

        for (int ele : nums)
        {
            if (present.find(ele) == present.end())
            {
                st1.insert({front, ele});
                present[ele] = front;
                front++;
            }
            else {
                st1.erase({present[ele], ele});
            }
        }
    }

    int showFirstUnique() {

        if (st1.empty()) return -1;
        return st1.begin()->second;
    }

    void add(int ele) {
        if (present.find(ele) == present.end())
        {
            st1.insert({front, ele});
            present[ele] = front;
            front++;
        }
        else {
            st1.erase({present[ele], ele});
        }
    }
};

