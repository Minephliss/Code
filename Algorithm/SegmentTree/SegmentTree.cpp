#include <iostream>
using namespace std;

#define lef rt << 1
#define rig rt << 1 | 1
#define lefs l, mid, rt << 1
#define rigs mid + 1, r, rt << 1 | 1

const int maxn = 100010;

struct operate
{
	int num;
	int x;
	int y;
	long long k;
}O[maxn];

long long tree[maxn * 4 + 1];
long long lazy1[maxn * 4 + 1];
long long lazy2[maxn * 4 + 1];
int N, M, P, x, y;
long long sum;

void update(int rt)	{ tree[rt] = tree[lef] + tree[rig];	}

void build(int l, int r, int rt)
{
	if(l == r)
		cin >> tree[rt];
	else
	{
		int mid = (l + r) >> 1;
		build(lefs); build(rigs);
		update(rt);
	}
}

void put_lazy1(int l, int r, int rt, int la)
{
	lazy1[rt] = (lazy1[rt] % P + la % P) % P;
	tree[rt] = (tree[rt] % P + (r - l + 1) * la % P) % P;
}

void put_lazy2(int rt, int la)
{
	lazy2[rt] = (la % P) * (lazy2[rt] % P) % P;
	lazy1[rt] = (la % P) * (lazy1[rt] % P) % P;
	tree[rt] = ((tree[rt] % P) * (la % P)) % P;
}

void push_lazy(int l, int r, int rt)
{
	if(l < r)
	{
		int mid = (l + r) >> 1;
		put_lazy2(lef, lazy2[rt]);	put_lazy2(rig, lazy2[rt]);
		put_lazy1(lefs, lazy1[rt]);	put_lazy1(rigs, lazy1[rt]);
	}
	lazy1[rt] = 0;
	lazy2[rt] = 1;
}

void multi(int l, int r, int rt, int p)
{
	if(l >= x && y >= r)
		put_lazy2(rt, p);
	else
	{
		int mid = (l + r) >> 1;
		if(lazy1[rt] != 0 || lazy2[rt] != 1)	push_lazy(l, r, rt);
		if(mid >= x)	multi(lefs, p);
		if(y > mid)		multi(rigs, p);
		update(rt);
	}
}

void addi(int l, int r, int rt, int p)
{
	if(l >= x && y >= r)
		put_lazy1(l, r, rt, p);
	else
	{
		int mid = (l + r) >> 1;
		if(lazy1[rt] != 0 || lazy2[rt] != 1)	push_lazy(l, r, rt);
		if(mid >= x)	addi(lefs, p);
		if(y > mid)		addi(rigs, p);
		update(rt);
	}
}

void show(int l, int r, int rt)
{
	if(l >= x && y >= r)
		sum += tree[rt];
	else
	{
		int mid = (l + r) >> 1;
		if(lazy1[rt] != 0 || lazy2[rt] != 1)	push_lazy(l, r, rt);
		if(mid >= x)	show(lefs);
		if(y > mid)		show(rigs);
	}
}

void solve()
{
	cin >> N >> M >> P;
	build(1, N, 1);
	for(int i = 0; i <= maxn * 4; i++)
		lazy2[i] = 1;
	for(int i = 0; i < M; i++)
	{
		int num, a, b, c = 0;
		cin >> num;
		if(num == 3)
			cin >> a >> b;
		else
			cin >> a >> b >> c;
		O[i].num = num;
		O[i].x = a;
		O[i].y = b;
		O[i].k = c % P;
	}
	for(int i = 0; i < M; i++)
	{
		x = O[i].x; y = O[i].y;
		switch(O[i].num)
		{
			case 1:
			{
				multi(1, N, 1, O[i].k);
				break;
			}
			case 2:
			{
				addi(1, N, 1, O[i].k);
				break;
			}
			case 3:
			{
				sum = 0;
				show(1, N, 1);
				cout << sum % P << endl;
				break;
			}
		}
	}
}

int main()
{
	solve();
	return 0;
}
