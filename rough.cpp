#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void password(string s,vector<string> words,int ind)
{
    if(ind >= s.size()) return;

    int temp;
    int i=0;
    for(i;i<words.size();i++)
    {
        temp = ind;
        for (int j = 0; j < words[i].size(); j++)
        {
            if(s[temp]==words[i][j])
            {
                temp++;
            }
            else break;
        }
        if((temp-ind)==words[i].size())
        {
            ans.push_back(words[i]);
            break;
        }
    }
    if((temp-ind)!=words[i-1].size() && i==words.size())
    {
        ans.clear();
        return;
    }
    else
    {
        ind = temp;
        password(s,words,ind);
    }
}

int main()
{
    int t;
    cin>>t;

    int n;
    while(t--)
    {
        cin>>n;
        std::vector<string> words(n);

        for(int i=0;i<words.size();i++)
        {
            cin>>words[i];
        }

        string s;
        cin>>s;

        password(s,words,0);
        if(ans.size()==0) cout<<"WRONG PASSWORD";
        else for(auto word : ans) cout<<word<<" ";
        cout<<endl;
        ans.clear();
    }

    return 0;
}