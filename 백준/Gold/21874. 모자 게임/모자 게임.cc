#include "hat.h"
#include <vector>
using namespace std;

void init(int N)
{
	// Do Something...
}

int call(vector<int> F, vector<int> B, int num)
{
	int t = 0;
	for (auto f:F) t ^= f;
	for (auto b:B) t ^= b;
	return t;
}