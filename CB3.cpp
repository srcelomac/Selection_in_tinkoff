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
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;

#define eol '\n'
#define FastIO(){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define INF 1e9 + 7
#define YES cout << "YES" << eol;
#define NO cout << "NO" << eol;

//template <class T> void print(T & g){for (auto el: g){cout << el << " ";} cout << "\n";}

//int gcd (long long a, int b) {return b ? gcd (b, a % b) : a;} // наибольший общий делитель
//int lcm (long long a, int b) {return a / gcd (a, b) * b;} // наименьшее общее кратное

//unsigned long long gcd(ull a, ull b) { return b?gcd(b,a%b):a;}
//unsigned long long lcm(ull a, ull b) { return a/gcd(a,b) * b;}

using namespace std;

void print(vector <ll> gcout) {for (ll zout = 0; zout < gcout.size(); zout++) cout << gcout[gcout.size()-1-zout];}

//int TrunsferNumbers(int x, int k) {int c = 0;while (x > 0) {if (x % k == 0) c++;x /= k;}return c; }

int main() {
    FastIO();

    ll n; cin >> n;

    vector <string> v(6);
    v[0] = "RGB";
    v[1] = "GRB";
    v[2] = "GBR";
    v[3] = "BGR";
    v[4] = "BRG";
    v[5] = "RBG";

    cout << v[(n % 6)];

    return 0;
}
