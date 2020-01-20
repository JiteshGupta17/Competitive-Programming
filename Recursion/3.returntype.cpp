#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> Subseq(string s)
{
    if (s.size() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    char ch = s[0];
    vector <string> recAns = Subseq(s.substr(1));

    vector<string> myAns = recAns;

    for (auto s : recAns )
    {
        myAns.push_back(ch + s);
    }

    return myAns;

}

string removeHi(string ques)
{
    if (ques.length() == 0 || ques.length() == 1 )
    {
        return ques;
    }

    if (ques.substr(0, 2) == "Hi") //(ques[0]=='H' && ques[1]=='i')
    {
        return removeHi(ques.substr(2));
    }
    else return ques[0] + removeHi(ques.substr(1));
}

string removeHiNotHit(string ques)
{
    if (ques.length() == 0 || ques.length() == 1 )
    {
        return ques;
    }

    if (ques.length() == 2)
    {
        if (ques[0] == 'H' && ques[1] == 'i') return "";
        return ques;

    }

    if (ques[0] == 'H' && ques[1] == 'i' && ques[2] != 't')
    {
        return removeHiNotHit(ques.substr(2));
    }
    else return ques[0] + removeHiNotHit(ques.substr(1));
}

string Compressed(string s)
{
    if(s.length() <= 1) return s;

    char front = s[0];
    
    string recAns = Compressed(s.substr(1));

    if(front == recAns[0])
    {
        if(recAns.length() > 1 && isdigit(recAns[1]))
        {
            recAns[1]++;
            return recAns;
        }
        else 
        {
            recAns[0] = '2';
            return front + recAns;
        }
    }
    
    return front + recAns;
}

vector<string> Permutation(string str)
{
    // Only for the case of empty string
    if(str.length()==0)
    {
        vector<string> base(1,"");
        return base;
    }

    if(str.length()==1)
    {
        vector<string> base(1,str);
        return base;
    }

    char ch = str[0];
    vector<string> ans;
    vector<string> recAns = Permutation(str.substr(1));

    for(string s : recAns)
    {
        for(int i = 0;i<=s.length();i++)
        {
            ans.push_back(s.substr(0,i) + ch + s.substr(i));
        }
    }

    return ans;
}

vector<string> encoding(string ques)
{
    if(ques.length()==0)
    {
        vector<string>base(1,"");
        return base;
    }

    vector<string> ans;
    char ch = ques[0];
    if(ch=='0')
    {
        return encoding(ques.substr(1));
    }
    ch = ch  + 'a'-'1' ;
    vector<string> recAns = encoding(ques.substr(1));

    for(string s : recAns)
    {
        ans.push_back(ch + s);
    }

    if(ques.length()>1)
    {
        int num = stoi(ques.substr(0,2)); // Inbuilt func to convert string to int
        if(num < 27)
        {
            char ch2 = num - 1 + 'a';
            vector<string> recAns02 = encoding(ques.substr(2));
            for(string s : recAns02)
            {
            ans.push_back(ch2 + s);
            }
        }

    }

    return ans;
}

// ======================================================================================================

bool isValidSudoku(vector<vector<int>> board,int i,int j,int num)
{
    // Check within column
    for(int r = 0;r<9;r++)
    {
        if(board[r][j]==num)return false;
    }

    // Check within row
    for(int c = 0;c<9;c++)
    {
        if(board[i][c]==num)return false;
    }

    // Check within box
    i = (i/3)*3;
    j = (j/3)*3;

    for(int r = 0;r < 3;r++)
    {
        for(int c = 0;c<3;c++)
        {
            if(board[i+r][j+c]==num) return false;
        }
    }

    return true;
}

bool sudoku(vector<vector<int>> board,int vidx)
{
    if(vidx==board.size()*board[0].size())
    {
        for (auto ar : board) {
            for (int ele : ar) {
                cout << ele << " ";
            }
            cout << endl;
        }
        return true;
    }

    int r = vidx / 9;
    int c = vidx % 9;

    bool res = false;
    if(board[r][c]!=0)
    {
        res = res || sudoku(board,vidx+1);
    }
    else{
        for(int num = 1;num<=9;num++)
        {
            if(isValidSudoku(board,r,c,num))
            {
                board[r][c] = num;

                res = res || sudoku(board,vidx+1);

                board[r][c] = 0;
            }
        }
    }

    return res;
}

int main()
{

    // vector <string> ans = Subseq("abc");
    // for(auto i : ans)cout<<i<<endl;

    // string ques = "HiiHHiHiiiH";
    // ques = removeHi(ques);
    // cout << ques << endl;

    // string ques_2 = "HiHitHiit";
    // ques_2 = removeHiNotHit(ques_2);
    // cout << ques_2;

    // string ques_3 = "aaabcc";
    // cout<<Compressed(ques_3);

    // vector<string> ans = Permutation("abc");
    // for(string s : ans) cout<<s<<endl;

    // vector<string> ans = encoding("123");
    // for(string s : ans) cout<<s<<" ";

    vector<vector<int>>board = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout<<sudoku(board, 0);
}