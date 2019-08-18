#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Num {
    bool mi;
    bool x;
    int num;
};

int c_n(vector<char> num);
void sp_a_save(vector<Num>& tar, string& str, unsigned& key, bool& first);
void save(vector<Num>& tar, Num& val, string& str, unsigned& key);
void tidy(vector<Num>& lefts, vector<Num>& rights);
void get_unknown(string& str, char& ch);
bool equal(const double num, const double tar);
double solve(vector<Num>& lefts, vector<Num>& rights);

int main()
{
    vector<Num> lefts, rights;
    bool first = true;
    unsigned key = 0;
    string str;
    char ch;

    cin >> str;

    get_unknown(str, ch);

    while (str[key] != '=')
	sp_a_save(lefts, str, key, first);

    key++;
    first = true;

    while (key < str.size())
	sp_a_save(rights, str, key, first);

    tidy(lefts, rights);

    cout.flags(ios::fixed);
    cout.precision(3);

    cout << ch << '=' << solve(lefts, rights);

    return 0;
}

void save(vector<Num>& tar, Num& val, string& str, unsigned& key)
{
    vector<char> num;
    if (str[key] >= 'a' && str[key] <= 'z') {
	val.num = 1;
	val.x = true;
	key++;
    } else {
	while (str[key] <= '9' && str[key] >= '0')
	    num.push_back(str[key++]);
	val.num = c_n(num);
	if (str[key] >= 'a' && str[key] <= 'z') {
	    val.x = true;
	    key++;
	}
    }
    tar.push_back(val);
}

void tidy(vector<Num>& lefts, vector<Num>& rights)
{
    for (unsigned i = 0; i < lefts.size(); i++)
	if (!lefts[i].x) {
	    lefts[i].mi = !lefts[i].mi;
	    rights.push_back(lefts[i]);
	    lefts.erase(lefts.begin() + i);
	    i--;
	}

    for (unsigned i = 0; i < rights.size(); i++)
	if (rights[i].x) {
	    rights[i].mi = !rights[i].mi;
	    lefts.push_back(rights[i]);
	    rights.erase(rights.begin() + i);
	    i--;
	}
}

double solve(vector<Num>& lefts, vector<Num>& rights)
{
    double le = 0.0;
    double ri = 0.0;
    for (unsigned i = 0; i < lefts.size(); i++) {
	if (lefts[i].mi)
	    le -= lefts[i].num;
	else
	    le += lefts[i].num;
    }
    for (unsigned i = 0; i < rights.size(); i++) {
	if (rights[i].mi)
	    ri -= rights[i].num;
	else
	    ri += rights[i].num;
    }
    if (equal(ri / le, 0.000))
	return 0.000;
    else
	return ri / le;
}

void sp_a_save(vector<Num>& tar, string& str, unsigned& key, bool& first)
{
    Num val;
    val.x = false;
    if (first) {
	if (str[key] != '-') {
	    val.mi = false;
	    save(tar, val, str, key);
	} else {
	    val.mi = true;
	    key++;
	    save(tar, val, str, key);
	}
	first = false;
    } else if (str[key] == '+') {
	val.mi = false;
	key++;
	save(tar, val, str, key);
    } else if (str[key] == '-') {
	val.mi = true;
	key++;
	save(tar, val, str, key);
    }
}

void get_unknown(string& str, char& ch)
{
    for (unsigned i = 0; i < str.length(); i++)
	if (str[i] >= 'a' && str[i] <= 'z') {
	    ch = str[i];
	    break;
	}
}

int c_n(vector<char> num)
{
    int p = 1;
    int ans = 0;
    for (int i = num.size() - 1; i >= 0; i--, p *= 10) {
	ans += (num[i] - '0') * p;
    }
    return ans;
}

bool equal(const double num, const double tar)
{
    if (fabs(tar - num) <= 0.0001)
	return true;
    return false;
}
