#include <iostream>
#include <cstdio>
using namespace std;

struct Man
{
	int num;
	int mark;
	int power;
	bool operator<(const Man &a) const
	{
		if (mark != a.mark)
			return mark > a.mark;
		return num < a.num;
	}
	Man() { }
	Man(int a, int b, int c) {num = a; mark = b; power = c; }
	friend ostream &operator<<(ostream &os, const Man &a)
	{
		os << a.num;
	}
};

int N, R, Q;
Man men[200010];

void Merge_sort(int start, int end)
{	
	if(start < end)
	{
		int mid = start + (end - start) / 2;
		Merge_sort(start, mid);
		Merge_sort(mid + 1, end);
		int i = start;
		int j = mid + 1;
		Man temp[200010];
		int top = 0;
		while(i <= mid && j <= end)
		{
			if(men[i] < men[j])
				temp[top++] = men[i++];
			else
				temp[top++] = men[j++];
		}
		while(i <= mid)
			temp[top++] = men[i++];
		while(j <= end)
			temp[top++] = men[j++];
		for(int k = 0, i = start; k < top; k++)
			men[i++] = temp[k];
	}
}

void read()
{
	scanf("%d%d%d", &N, &R, &Q);
	for(int i = 1; i <= 2 * N; men[i].num = i, i++)
		scanf("%d", &men[i].mark);
	for(int i = 1; i <= 2 * N; i++)
		scanf("%d", &men[i].power);
}

void match()
{
	for(int i = 1; i <= 2*N; i += 2)
	{
		if(men[i].power > men[i + 1].power)
			men[i].mark++;
		else
			men[i + 1].mark++;
	}
}

int main()
{
	read();

	for(int i = 0; i < R; i++)
	{
		match();
		Merge_sort(1, 2 * N);
	}

	cout << men[Q];
}
