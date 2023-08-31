#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <map>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;

#define eol '\n'
#define FastIO(){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define INF 1e9 + 7
#define YES cout << "YES" << eol;
#define NO cout << "NO" << eol;
//template <class T> void print(T & g){for (auto el: g){cout << el << " ";}cout << "\n";}

//int gcd (long long a, int b) {return b ? gcd (b, a % b) : a;} // наибольший общий делитель
//int lcm (long long a, int b) {return a / gcd (a, b) * b;} // наименьшее общее кратное

//unsigned long long gcd(ull a, ull b) { return b?gcd(b,a%b):a;}
//unsigned long long lcm(ull a, ull b) { return a/gcd(a,b) * b;}

using namespace std;

//void print(vector <ll> gcout) {for (ll zout = 0; zout < gcout.size(); zout++) cout << gcout[zout] << " ";}

int main() {
    FastIO();

    char c; cin >> c;
    if (c == '0') {
        cout << 0; 
        return 0;
    }
    string s; cin >> s;
    
    if (c == '-') cout << s;
    else cout << '-' << c << s;
    
    return 0;
}
