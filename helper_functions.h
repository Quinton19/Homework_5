#include<iostream>

#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }

class Str_conversion
{
private:
public:
	static string to_string(int n);
	static string to_string(double d);
};
