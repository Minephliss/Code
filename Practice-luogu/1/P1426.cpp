#include <iostream>
using namespace std;

int main()
{
    double s, d;
    cin >> s >> d;
    double alarm = s - d;
    double x = 0.0, v = 7.0;
    while (x + v < alarm) {
	x += v;
	v *= 0.98;
    }
    double time = (alarm - x) / v;
    double last_time = 1.0 - time;
    if (last_time * v + time * v * 0.98 > 2 * d)
	cout << 'n';
    else
	cout << 'y';
}
