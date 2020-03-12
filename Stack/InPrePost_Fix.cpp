#include<bits/stdc++.h>
using namespace std;

int operatorResolve(char op, int val, int val2)
{
    if (op == '+') return val2 + val;
    if (op == '-') return val2 - val;
    if (op == '*') return val2 * val;
    if (op == '/') return val2 / val;
    if (op == '%') return val2 % val;
    if (op == '^') return pow(val2, val);

}

int inFixEval(string s,unordered_map<char, int> mp)
{
    stack<int> s1;
    stack<char> s2;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '(')
        {
            s2.push(s[i]);
            continue;
        }

        if (isdigit(s[i]))
        {
            int val = 0; 
            //For more than 1 digit
            while(i < s.length() &&  isdigit(s[i])) 
            { 
                val = (val*10) + (s[i]-'0'); 
                i++; 
            } 
            i--;
            s1.push(val);
            cout<<s1.top();
            continue;
        }

        char cur_operator = s[i];

        if (cur_operator == ')')
        {
            while (s2.top() != '(')
            {
                int x = s1.top();
                s1.pop();
                int y = s1.top();
                s1.pop();

                char op = s2.top();
                s2.pop();
                int value = operatorResolve(op, x, y);

                s1.push(value);
            }

            s2.pop();
            continue;

        }

        cout<<cur_operator;
        while (!s2.empty() && mp[s2.top()] > mp[cur_operator])
        {
            int x = s1.top();
            s1.pop();
            int y = s1.top();
            s1.pop();

            char op = s2.top();
            s2.pop();
            int value = operatorResolve(op, x, y);

            s1.push(value);
        }

        s2.push(cur_operator);
    }
    cout<<endl;
    while (!s2.empty())
    {
        int x = s1.top();
        s1.pop();
        int y = s1.top();
        s1.pop();

        char op = s2.top();
        s2.pop();
        int value = operatorResolve(op, x, y);

        s1.push(value);
    }

    return s1.top();
}

int main()
{
    unordered_map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;

    mp['*'] = 2;
    mp['/'] = 2;
    mp['%'] = 2;

    mp['^'] = 3;

    string s = "10+4*3-9/3^(2-1)";
    cout << inFixEval(s,mp)<<endl;



}