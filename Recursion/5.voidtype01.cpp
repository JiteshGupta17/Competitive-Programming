#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void Subsequence(string ques,string ans)
{
    if(ques.length()==0)
    {
        cout<<ans<<endl;
        return;
    }

    char ch = ques[0];

    Subsequence(ques.substr(1),ans + ch);
    Subsequence(ques.substr(1),ans);
}

void RemoveHi(string ques,string ans)
{
    if(ques.length()==0)
    {
        cout<<ans<<endl;
        return;
    }

    if(ques.length() > 1 && ques[0] == 'H' && ques[1] == 'i')
    {
        RemoveHi(ques.substr(2),ans);
    }
    else RemoveHi(ques.substr(1),ans + ques[0]);
}

void RemoveDupli(string ques,string ans)
{
    if(ques.length()==0)
    {
        cout<<ans<<endl;
        return;
    }

    if(ques.length() > 1 && ques[0]==ques[1])
    {
        RemoveDupli(ques.substr(1),ans);
    }
    else RemoveDupli(ques.substr(1),ans + ques[0]);
}

void Compression(string ques,int count,string ans)
{
    if(ques.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    
    if(ques.length() > 1 && ques[0]==ques[1])
    {
        Compression(ques.substr(1),count +1,ans);
    }
    else{ 
        if(count > 1)
            Compression(ques.substr(1),1,ans + ques[0] + to_string(count));
        else Compression(ques.substr(1),1,ans + ques[0]);
    }
}

int permutation(string ques,string ans)
{
    if(ques.length() == 0)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    for(int start = 0;start < ques.length();start++)
    {
        char ch = ques[start];
        string roq = ques.substr(0,start) + ques.substr(start + 1);

        count += permutation(roq,ans + ch);
    }

    return count;
}


int permutWithoutDupl(string ques,string ans)
{
    if(ques.length() == 0)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    // vector<bool> mapping(26,0);
    int mapping = 0;

    for(int start = 0;start < ques.length();start++)
    {
        char ch = ques[start];
        if((mapping & (1<<(ch - 'a'))) == 0)
        {
            // mapping[ch-'a']=1;
            mapping |= (1<<(ch - 'a'));
            string roq = ques.substr(0,start) + ques.substr(start + 1);

            count += permutWithoutDupl(roq,ans + ch);
        }
    }

    return count;
}

// ======================================================================================================================================

void mazePathSimple(int sr,int sc,int er,int ec,string ans)
{
    if(sr==er && sc == ec){
        cout<<ans<<endl;
        return;
    }

    if(sr+1<=er){
        mazePathSimple(sr+1,sc,er,ec,ans+"V"); //add V while calling not individually outside call because then it must be removed
    }                                          //i.e not like ans +="v";and then passing whole ans ,and if done like this then V is 
    //                                           removed then after this call temp = ans;ans += v; call();ans = temp;
 

    if(sc+1<=ec){
        mazePathSimple(sr,sc+1,er,ec,ans+"H");
    }
}

int mazePathMulti(int sr,int sc,int er,int ec,string ans)
{
    if(sr==er && sc == ec){
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    for(int i = 1;sr + i <= er;i++){
        count += mazePathMulti(sr+i,sc,er,ec,ans+"V" + to_string(i));
    }

    for(int i = 1;sc + i <= ec;i++){
        count += mazePathMulti(sr,sc +i,er,ec,ans+"H" + to_string(i));
    }

    for(int i = 1;sr + i <= er && sc + i <= ec;i++){
        count += mazePathMulti(sr+i,sc + i,er,ec,ans+"D" + to_string(i));
    }

    return count;
}

int boardPath(int end,string ans)
{
    if(end == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for(int i = 1;i<=6;i++)
    {
        if(end - i >=0)
        {
            count += boardPath(end - i,ans + to_string(i) + " ");
        }
    }

    return count;
}

// =====================================================================================================================================

int coinChange_permu01(vector<int> arr,int target,string ans)
{
    if(target==0)
    {
        cout<< ans <<endl;
        return 1;
    }

    int count = 0;
    for(int ele : arr)
    {
        if(target - ele >= 0)
        {
            count += coinChange_permu01(arr,target - ele,ans + to_string(ele) + " ");
        }
    }

    return count;
}

int coinChange_combi01(vector<int> arr,int vidx,int target,string ans)
{
    if(target==0)
    {
        cout<< ans <<endl;
        return 1;
    }

    int count = 0;
    for(int i = vidx; i < arr.size();i++)
    {
        if(target - arr[i] >= 0)
        {
            count += coinChange_combi01(arr,i,target - arr[i],ans + to_string(arr[i]) + " ");
        }
    }

    return count; 
}

int coinChange_permu02(vector<int> arr,vector<bool> isDone,int target,string ans)
{
    if(target==0)
    {
        cout<< ans <<endl;
        return 1;
    }

    int count = 0;
    for(int i = 0;i<arr.size();i++)
    {
        if(!isDone[i] && target - arr[i] >= 0)
        {
            isDone[i] = true;
            count += coinChange_permu02(arr,isDone,target - arr[i],ans + to_string(arr[i]) + " ");
            isDone[i] = false;
        }
    }

    return count;
}

int coinChange_combi02(vector<int> arr,int vidx,int target,string ans)
{
    if(target==0)
    {
        cout<< ans <<endl;
        return 1;
    }

    int count = 0;
    for(int i = vidx; i < arr.size();i++)
    {
        if(target - arr[i] >= 0)
        {
            count += coinChange_combi02(arr,i + 1,target - arr[i],ans + to_string(arr[i]) + " ");//only change is i + 1 from combi01
        }
    }

    return count;
}

// ======================================================================================================================================

void basic()
{
    // Subsequence("abc","");

    // RemoveHi("HiiiHiHHiH","");

    // RemoveDupli("aaabccdd","");

    // Compression("aabcccdd",1,""); 

    // cout<<permutation("abc","")<<endl;

    // cout<<permutWithoutDupl("aba","")<<endl;

}

void pathType()
{
    // mazePathSimple(0,0,2,2,"");

    // cout<<mazePathMulti(0,0,2,2,"")<<endl;

    // cout<<boardPath(6,""); //Dice moves of 1-6
}

void combiPermu()
{
    vector<int> arr = {2, 3, 5, 7};
    // cout<<coinChange_permu01(arr,10,"")<<endl;

    // cout<<coinChange_combi01(arr,0,10,"")<<endl;

    /*Each coin use only once*/
    // vector<bool> isDone(arr.size(), false);
    // cout << coinChange_permu02(arr, isDone, 10, "") << endl;

    // cout<<coinChange_combi02(arr,0,10,"")<<endl;

    
}

int main()
{
    // basic();
    // pathType();
    combiPermu();
}