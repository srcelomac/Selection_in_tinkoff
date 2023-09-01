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

//void print(vector <ll> gcout) { for (ll zout = 0; zout < gcout.size(); zout++) cout << gcout[gcout.size() - 1 - zout]; }

//int TrunsferNumbers(int x, int k) {int c = 0;while (x > 0) {if (x % k == 0) c++;x /= k;}return c; }

int main() {
    FastIO();

    int year; cin >> year;
    int w; cin >> w;
    int n; cin >> n;
    
    int td, tm, day, sumday = 0, mean;
    char c;

    vector <int> holydays;

    vector <int> cd(12);

    int o;
    if (year % 4) o = 1;
    else o = 0;

    for (int j = 0; j < 7; j++) cd[j] = 30 + ((j + 1) % 2);
    cd[1] = 28 + o;
    for (int j = 0; j < 5; j++) cd[j+7] = 30 + ((j + 1) % 2);

    vector <int> pcd(13);
    pcd[0] = 0;
    for (int j = 1; j <= 12; j++) pcd[j] = pcd[j - 1] + cd[j-1];

    for (int i = 0; i < n; i++) {
        cin >> td >> c >> tm;

        day = pcd[tm-1] + td;
        sumday += day;
        holydays.push_back(day);
        //cout << day << eol;
    }

    mean = round(double(sumday) / double(n));

    vector <int> weekend(365 + o);
    
    if (w == 7) {
        weekend[0] = 1;
        for (int i = 6; i < 365 + o; i += 7) {
            weekend[i] = 1;
            if (i < 365 + o - 1) weekend[i + 1] = 1;
        }

    }
    else {
        weekend[6 - w] = 1;
        weekend[7 - w] = 1;
        for (int i = (6 - w); i < 365 + o; i += 7) {
            weekend[i] = 1;
            if (i < 365 + o - 1) weekend[i + 1] = 1;
        }
    }



    cout << mean;

    return 0;
}
