#include<bits/stdc++.h>
using namespace std;

std::vector<string> maze(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        std::vector<string> ans;
        ans.push_back("");
        return ans;
    }

    std::vector<string> ans;
    if (sc + 1 <= ec)
    {
        std::vector<string> h = maze(sr, sc + 1, er, ec);
        for (auto i : h)
        {
            ans.push_back("H" + i);
        }
    }

    if (sr + 1 <= er)
    {


        std::vector<string> v = maze(sr + 1, sc, er, ec);
        for (auto i : v)
        {
            ans.push_back("V" + i);
        }
    }


    return ans;

}

std::vector<string> maze_2(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        std::vector<string> ans;
        ans.push_back("");
        return ans;
    }

    std::vector<string> ans;
    if (sc + 1 <= ec)
    {
        std::vector<string> h = maze_2(sr, sc + 1, er, ec);
        for (auto i : h)
        {
            ans.push_back("H" + i);
        }
    }

    if (sr + 1 <= er)
    {
        std::vector<string> v = maze_2(sr + 1, sc, er, ec);
        for (auto i : v)
        {
            ans.push_back("V" + i);
        }
    }

    if ((sr + 1 <= er) && (sc + 1 <= ec))
    {
        std::vector<string> d = maze_2(sr + 1, sc + 1, er, ec);
        for (auto i : d)
        {
            ans.push_back("D" + i);
        }
    }

    return ans;

}

vector <string> maze_Multimove(int sr, int sc, int er, int ec) {
	if (sr == er && sc == ec) {
		vector <string> base ;
		base.push_back("");
		return base;
	}


	std::vector<string> ans;
	for (int i = 1; sc + i <= ec; i++) {
		std::vector<string> h = maze_Multimove(sr, sc + i, er, ec);
        for (auto s : h)
        {
            ans.push_back("H" + to_string(i) + s);
        }
	}

	for (int i = 1; sr + i <= er; i++) {
		std::vector<string> v = maze_Multimove(sr + i, sc, er, ec);
        for (auto s : v)
        {
            ans.push_back("V" + to_string(i) + s);
        }
	}

	for (int i = 1; sr + i <= er && sc + i <= ec; i++) {
		std::vector<string> d = maze_Multimove(sr + i, sc + i, er, ec);
        for (auto s : d)
        {
            ans.push_back("D" + to_string(i) + s);
        }
	}

	return ans;
}

string maze_MaxString(int sr, int sc, int er, int ec)
{

    if (sr == er && sc == ec)
    {
        return "";
    }

    string ans = "";
    if (sc + 1 <= ec)
    {
        string h = maze_MaxString(sr, sc + 1, er, ec);
        h = h + "H";


        ans = ans.length() > h.length() ? ans : h;

    }

    if (sr + 1 <= er)
    {
        string v = maze_MaxString(sr + 1, sc , er, ec);
        v = v + "V";

        ans = ans.length() > v.length() ? ans : v;
    }

    if ((sr + 1 <= er) && (sc + 1 <= ec))
    {
        string d = maze_MaxString(sr + 1, sc + 1, er, ec);
        d = d + "D";

        ans = ans.length() > d.length() ? ans : d;
    }

    return ans;

}

int maze_MaxHeight(int sr, int sc, int er, int ec)
{

    if (sr == er && sc == ec)
    {
        return 0;
    }

    int h1 = 0,h2 = 0,h3 = 0;
    if (sc + 1 <= ec)
    {
        h1 = maze_MaxHeight(sr, sc + 1, er, ec);
    }

    if (sr + 1 <= er)
    {
        h2 = maze_MaxHeight(sr + 1, sc , er, ec);
    
    }

    if ((sr + 1 <= er) && (sc + 1 <= ec))
    {
        h3 = maze_MaxHeight(sr + 1, sc + 1, er, ec);
    }

    return max(h1,max(h2,h3)) + 1;

}

std::vector<string> floodFill(int sr, int sc, int er, int ec, bool isVisited[][3])
{
    if (sr == er && sc == ec)
    {
        std::vector<string> ans;
        ans.push_back("");
        return ans;
    }

    // Can be done by using dir array of size 4 for D,U,R,L
    std::vector<string> ans;
    isVisited[sr][sc] = true;

    if (sc + 1 <= ec && !isVisited[sr][sc + 1])
    {
        std::vector<string> right = floodFill(sr, sc + 1, er, ec, isVisited);
        for (auto i : right)
        {
            ans.push_back("R" + i);
        }
    }

    if (sr + 1 <= er && !isVisited[sr + 1][sc])
    {
        std::vector<string> down = floodFill(sr + 1, sc, er, ec, isVisited);
        for (auto i : down)
        {
            ans.push_back("D" + i);
        }
    }

    if (sr - 1 >= 0 && !isVisited[sr - 1][sc])
    {
        std::vector<string> up = floodFill(sr - 1, sc, er, ec, isVisited);
        for (auto i : up)
        {
            ans.push_back("U" + i);
        }
    }

    if (sc - 1 >= 0 && !isVisited[sr][sc - 1] )
    {
        std::vector<string> left = floodFill(sr, sc - 1, er, ec, isVisited);
        for (auto i : left)
        {
            ans.push_back("L" + i);
        }
    }

    isVisited[sr][sc] = false;
    return ans;
}
// ==============================================================================================================

// vector<vector<int>> dir ={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
// vector<string> dirName={"D","R","U","L","1","3","4","2"};

// bool isValid(int x,int y,bool isVisited[][4],vector<vector<bool>> obstacle)
// {
//     if(x>=0 && y >=0 && x<obstacle.size() && y<obstacle[0].size() && !isVisited[x][y] && !obstacle[x][y])
//     {
//         return true;
//     }

//     return false;
// }

// vector<string> floodFillObstacles(int sr,int sc,int er,int ec,bool isVisited[][4],vector<vector<bool>>obstacle)
// {
//     if(sr==er && sc==ec)
//     {
//         vector<string> base;
//         base.push_back("");
//         return base;
//     }

//     vector<string> ans;
//     isVisited[sr][sc] = 1;

//     for(int d = 0;d < dir.size();d++)
//     {
//         int x = sr + dir[d][0];
//         int y = sc + dir[d][1];

//         if(isValid(x,y,isVisited,obstacle))
//         {
//             // cout<<x<<" "<<y<<endl;
//             vector<string> recAns = floodFillObstacles(x,y,er,ec,isVisited,obstacle);
//             for(auto s : recAns)
//             {
//                 ans.push_back(dirName[d] + s );
//             }
//         }
//     }

//     isVisited[sr][sc] = 0;
//     return ans;
// }

// ============================================================================================

vector<vector<int>> dir ={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

bool isValid(int x,int y,vector<vector<bool>> isVisited)
{
    if(x>=0 && y >=0 && x<isVisited.size() && y<isVisited[0].size() && !isVisited[x][y])
    {
        return true;
    }

    return false;
}

int knightPath(int sr,int sc,int er,int ec,string ans,vector<vector<bool>> isVisited)
{
    if(sr==er && sc==ec)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    isVisited[sr][sc] = 1;

    for(int d = 0; d < dir.size();d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];

        if(isValid(x,y,isVisited))
        {
            count+=knightPath(x,y,er,ec,ans + to_string(x) +"-"+ to_string(y)+" ",isVisited);
        }
    }

    isVisited[sr][sc] = 0;
    return count;

}

bool knightPath_Fill(int sr,int sc,int count,int Boxes,vector<vector<bool>> isVisited,vector<vector<int>> ans)
{
    isVisited[sr][sc] = 1;
    ans[sr][sc] = count;

    if(count==Boxes-1)
    {
        for(auto arr : ans)
        {
            for(int ele : arr) cout<<ele<<" ";
            cout<<endl; 
        }
        return true;
    }

    bool res = false;

    for(int d = 0; d < dir.size() && !res;d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];

        if(isValid(x,y,isVisited))
        {
            res = res || knightPath_Fill(x,y,count + 1,Boxes,isVisited,ans);
        }
    }

    isVisited[sr][sc] = 0;
    ans[sr][sc] = 0;

    return res;
}


int main() {

    // std::vector<string> v = maze(0, 0, 2, 2);
    // for (auto i : v) cout << i << endl;


    // std::vector<string> v = maze_2(0, 0, 2, 2); //Diagnol
    // for (auto i : v) cout << i << endl;

    // vector <string> v = maze_Multimove(0,0,2,2);
    // for (auto i : v) cout << i << endl;

    // string v = maze_MaxString(0, 0, 2, 2);
    // cout<<v<<endl;

    // int maxPath = maze_MaxHeight(0,0,2,2);
    // cout<<maxPath<<endl;

    // bool isVisited[3][3] = {0}; //False not visited and true visited
    // vector<string> v = floodFill(0, 0, 2, 2,isVisited);
    // for(auto i : v)cout<<i<<endl;

    // bool isVisited[4][4] = {0};
    // vector<vector<bool>> obstacle = {{0,0,0,1},
    //                     {0,1,0,0},
    //                     {0,0,1,0},
    //                     {1,0,0,0} }; // 1 means obstacle 

    // vector<string> v = floodFillObstacles(0, 0, 3, 3,isVisited,obstacle);
    // for(auto i : v)cout<<i<<endl;

    // vector<vector<bool>> isVisited = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    // cout<<knightPath(0,0,3,3,"",isVisited);

    // vector<vector<bool>> isVisited (4,vector<bool> (4,false));
    // vector<vector<int>> ans = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    // cout<<knightPath_Fill(0,0,0,25,isVisited,ans);

    


    return 0;

}
