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

void print(vector <ll> gcout) { for (ll zout = 0; zout < gcout.size(); zout++) cout << gcout[gcout.size() - 1 - zout]; }

//int TrunsferNumbers(int x, int k) {int c = 0;while (x > 0) {if (x % k == 0) c++;x /= k;}return c; }

int year;
int w;
int n;
int o;

vector <int> daytype;
int brickscanind = 0, clusterscanleft = 0, clusterscanright = 0;
bool flag = true;

int FindLastIndex(int b, int e) {
    int c = 0;
    for (int j = b; c < e; j--) {
        c++;
        if (daytype[j] > 0) return j;
    }
    return -1;
}

int FindIndex(int b, int e) {
    int c = 0;
    for (int j = b; c < e; j++) {
        c++;
        if (daytype[j] > 0) return j;
    }
    return -1;
}

int finalcountdown() {

    int previ = FindLastIndex(clusterscanleft - 1, clusterscanleft <= 5 ? clusterscanleft : 6);
    int nexti = FindIndex(clusterscanright+1, daytype.size()-clusterscanright <=5 ? daytype.size() - clusterscanright-1 : 6);
    if (previ==-1) previ = clusterscanleft-7;
    if (previ<-1) previ=-1;
    if (nexti==-1) nexti=clusterscanright+7;
    if (nexti>daytype.size()) nexti = daytype.size();

    int divprev = clusterscanleft - previ-1;
    int divnext = nexti - clusterscanright-1;

    int tindl = 0;
    while (daytype[tindl] != 1 && daytype[tindl] != 2) {
        tindl++;
    }

    int tindr = 0;
    while (daytype[365+o-tindr] != 1 && daytype[365+o-tindr] != 2) {
        tindr++;
    }

    int cnttrans = 0;
    if (tindl < divprev) cnttrans++;
    if (tindr < divnext) cnttrans++;

    int plus = 0;
    if (cnttrans == 1) {
        if (((clusterscanleft-2 > 0) && (daytype[clusterscanleft-2] == 2))  || ((clusterscanright+2 < 365+o-1) && (daytype[clusterscanright+2] == 2))) plus += 2;
        else plus++;
    }
    else if (cnttrans == 2) {
        if ((clusterscanleft-2 > 0) && (clusterscanright+2 < 365+o-1)) {
            if ((daytype[clusterscanleft-2] == 2) && (daytype[clusterscanright+2] == 2)) plus += 4;
        }
        else if ((daytype[clusterscanleft-3] == 2) || (daytype[clusterscanright+3] == 2)) plus += 3;
        else plus += 2;
    }



    int maxq = 0, curq = 0;
    for (auto d : daytype) {
        if (d > 0) {
            curq++;
            if (maxq < curq) maxq = curq;
        }
        else curq = 0;
    }
    maxq += plus;
    cout << maxq;
    return maxq;
}

int scan4nextbrick() {

    do {
        int workinterval = 0;
        if (brickscanind >= clusterscanleft && brickscanind < clusterscanright)brickscanind = clusterscanright;
        if (brickscanind >= daytype.size() - 1) {
            flag = false;
            return 777;
        }

        workinterval++;
        brickscanind++;

        if (daytype[brickscanind] == 2) {
            workinterval = 0;
            brickscanind++;
        }
    }
    while (daytype[brickscanind] == 0);

    if (daytype[brickscanind] == 1)
    {
        int previ = FindLastIndex(brickscanind - 1, brickscanind <= 5 ? brickscanind : 6);
        int nexti = FindIndex(brickscanind+1, daytype.size()-brickscanind<=5 ? daytype.size() - brickscanind-1 : 6);
        if (previ==-1) previ=brickscanind-7;
        if (previ<-1) previ=-1;
        if (nexti==-1) nexti=brickscanind+7;
        if (nexti>daytype.size()) nexti=daytype.size();
        if (nexti-previ>7) return 3;
    }

    return daytype[brickscanind];
}

int scan4nexthole() {
    if (clusterscanleft<0) clusterscanleft=0;
    if (clusterscanright>daytype.size()-1) clusterscanright=daytype.size()-1;
    while (daytype[clusterscanleft] > 0 && daytype[clusterscanright] > 0)
    {
        if (clusterscanleft <= 0 && clusterscanright >= daytype.size() - 1) {flag = false; return 777;}
        else {
            if (clusterscanleft <= 0) {
                clusterscanleft = 1;

            }
            if (clusterscanright >= daytype.size() - 1) clusterscanright = daytype.size() - 2;
        }
        clusterscanleft--;
        clusterscanright++;
    }

    if (daytype[clusterscanleft] == 0 && daytype[clusterscanright] == 0) return 2;
    else {
        if (daytype[clusterscanleft] == 0) return -1;
        if (daytype[clusterscanright] == 0) return 1;
    }
    return 0;
}

int main() {
    int resbrick = 0, reshole = 0;
    bool flag = true;
    FastIO();
    cin >> year;

    if (year % 4 == 0) o = 1;
    else o = 0;
    daytype.resize(365+o);

    cin >> w;
    cin >> n;


    int td, tm, day, sumday = 0, mean = 0;
    char c;


    vector <int> holydays;
    vector <int> tvd(365 + o);

    vector <int> cd(12);



    for (int j = 0; j < 7; j++) cd[j] = 30 + ((j + 1) % 2);
    cd[1] = 28 + o;
    for (int j = 0; j < 5; j++) cd[j+7] = 30 + ((j + 1) % 2);

    vector <int> pcd(13);
    pcd[0] = 0;
    for (int j = 1; j <= 12; j++) pcd[j] = pcd[j - 1] + cd[j-1];

    if (n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> td >> c >> tm;

            day = pcd[tm-1] + td;
            day--;
            sumday += day;
            holydays.push_back(day);
            tvd[day] = 1;
        }
    }

    if (n != 0) mean = round(double(sumday) / double(n));


    int curW = w, curM = 1, curD = 1;

    int weekendForTrans = 0;
    for (int i = 0; i < 365+o; i++) {
        if (curW == 6 || curW == 7) {
            if (tvd[i] == 1) {daytype[i] = 2; weekendForTrans++;}
            else daytype[i] = 1;
        }
        else {
            if (tvd[i] == 1) daytype[i] = 2;
            else {
                if (weekendForTrans > 0) {daytype[i] = 1; weekendForTrans--;}
                else daytype[i] = 0;
            }
        }
        curW++;
        if (curW > 7) curW = 1;
    }

    if (n == 0) {
        vector <int> weekend(365 + o);
        int sumweek = 0, countweek = 0;

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
        for (int i = 0; i < 365 + o; i++) {
            if (weekend[i] == 1) {
                sumweek += i;
                countweek++;
            }
        }

        mean = round(double(sumweek) / double(countweek));
    }

    int clustercentr = mean;
    int centrscanleft = clustercentr;
    int centrscanright = clustercentr;
    if (daytype[clustercentr] == 0) {
        do {centrscanleft--; centrscanright++;}
        while (daytype[centrscanleft] == 0 && daytype[centrscanright] == 0);
        if (daytype[centrscanleft] > 0) clustercentr = centrscanleft;
        if (daytype[centrscanright] > 0) clustercentr = centrscanright;
    }

    clusterscanleft = clustercentr-1;
    clusterscanright = clustercentr+1;

    do {
        do {
            resbrick = scan4nextbrick();
            if (resbrick == 777)
            {int q = finalcountdown(); return 0;}
        }
        while (resbrick == 2 || resbrick==3);

        reshole = scan4nexthole();
        if (reshole == 777)
        { int q = finalcountdown(); return 0;}
        if (reshole == -1)
        {
            daytype[brickscanind] = 0;
            daytype[clusterscanleft] = 1;
        }
        if (reshole == 1)
        {
            daytype[brickscanind] = 0;
            daytype[clusterscanright] = 1;
        }
        if (reshole == 2) {
            daytype[brickscanind] = 0; daytype[clusterscanleft] = 1;
            do resbrick = scan4nextbrick();
            while (resbrick == 2);

            daytype[brickscanind] = 0; daytype[clusterscanright] = 1;
        }
    }
    while (flag);
}
