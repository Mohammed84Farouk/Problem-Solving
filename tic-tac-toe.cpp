//نفعكم الله ووفقكم -ادع لي-
//اللهم حرر فلسطين من كيد الصهاينة واجعل كيدهم في نحورهم
//اللهم انصر الأقصى والقدس وأهالي غزة وفلسطين اللهم اطمس على أعداء الدين والمدنسين -الصهاينة اللصوص-
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define multi_ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template<class T>
bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+9, M = 2e5 + 6, MOD = 1e9+7, OO = 0x3f3f3f3f, SQR = 320;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-7;
int dx[8]={0, 0, 1, -1, 1, -1, -1, 1};
int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
bool valid(int x, int y, int nnn, int mmm){return x>=0&&x<nnn&&y>=0&&y<mmm;}
int Log2(int x) {return 31-__builtin_clz(x);}
int player(char c){
    return (c=='X'? 1:2);
}
int checkWin(vector<vector<char>>&grid){
    if(grid[0][0] !='.' && (grid[0][0]==grid[0][1] && grid[0][1]==grid[0][2] || grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]
    || grid[0][0]==grid[1][0] && grid[1][0]==grid[2][0])) return player(grid[0][0]);
    if(grid[2][2] !='.' && (grid[2][2]==grid[2][1] && grid[2][1]==grid[2][0] || grid[0][2]==grid[1][2] && grid[1][2]==grid[2][2])) return player(grid[2][2]);
    if(grid[1][1] !='.' && (grid[1][0]==grid[1][1] && grid[1][1]==grid[1][2] || grid[0][1]==grid[1][1] && grid[1][1]==grid[2][1]
    || grid[2][0]==grid[1][1] && grid[1][1]==grid[0][2])) return player(grid[1][1]);
    return 0;
}
int checkManyWins(vector<vector<char>>&grid){
    int p[3]={0};
    if(grid[0][0]!='.') {
        if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) p[player(grid[0][0])]++;
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) p[player(grid[0][0])]++;
        if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) p[player(grid[0][0])]++;;
    }
    if(grid[2][2]!='.') {
        if (grid[2][2] == grid[2][1] && grid[2][1] == grid[2][0]) p[player(grid[2][2])]++;
        if (grid[2][2] == grid[1][2] && grid[1][2] == grid[0][2]) p[player(grid[2][2])]++;
    }
    if(grid[1][1]!='.') {
        if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) p[player(grid[1][1])]++;
        if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) p[player(grid[1][1])]++;
        if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]) p[player(grid[1][1])]++;
    }
    if(p[1] && p[2]) return OO;
    return 0;
}

void TT(){
    vector<vector<char>>grid(3, vector<char>(3, '.'));
    int X=0, O=0, temp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='0') O++;
            else if(grid[i][j]=='X') X++;
        }
    }
    if(X-O>1 || X-O<0 || checkManyWins(grid)) cout<<"illegal\n";
    else if((temp=checkWin(grid))){
        if(temp==1){
            if(X-O==1) cout<<"the first player won\n";
            else cout<<"illegal\n";
        }
        else{
            if(X==O) cout<<"the second player won\n";
            else cout<<"illegal\n";
        }
    }
    else if(abs(X-O)==1 && (X==5 || O==5)) cout<<"draw\n";
    else{
        if(X>O) cout<<"second\n";
        else cout<<"first\n";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    FAST
    int testCases = 1;
//    cin >> testCases;
    while (testCases--) TT();
    return 0;
}
// You Got this! Bear those in mind:
//      * Read the problem Carefully
//      * BrainStorm & Think Twice, code once.
//      * Overcome Corner Cases.
//      * Have a quick revision of the code before submitting
