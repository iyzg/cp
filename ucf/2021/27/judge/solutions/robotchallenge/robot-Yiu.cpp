/*
ACM ICPC Southeast Regional Contest 2009

Robot Challenge

Author: Yiu Yu Ho
*/

#include <ctime>
#include <cstdio>
#include <cmath>

using namespace std;

const double T50 = 1e50;
const double tol = 1e-12;

const int N = 10000 + 100;
int p[N], psum[N], x[N], y[N];
double cost[N];

//distance between target points (x[i], y[i]) and (x[j], y[j])
double dist(int i, int j)
{
	double dx, dy;
	dx = x[i] - x[j];
	dy = y[i] - y[j];
	return sqrt(dx*dx + dy*dy);
}

int main()
{
	clock_t startClock = clock();

	int i, j, k;
	int n;
	double T;

	while(scanf("%d", &n)==1 && n>0)
	{
		x[0] = y[0] = p[0] = 0;
		psum[0] = 0;
		
		//(x[i], y[i], p[i]) are the input location and penalty
		//psum[i] = sum(p[k], k = 0 .. i)
		for(i=1;i<=n;++i)
		{
			scanf("%d %d %d", x+i, y+i, p+i);
			psum[i] = psum[i-1] + p[i];
		}
		x[n+1] = y[n+1] = 100;
		p[n+1] = 0;
		psum[n+1] = psum[n];

		//cost[i]: optimal cost of starting at point (0, 0), visiting/skipping targets points {1, 2, ..., i-1} and 
		//arriving, and stopping for a second at point(x[i], y[i]).
		cost[0] = 0;
		for(i=1;i<=n+1;++i)
		{
			cost[i] = T50;
			//j is the previous point of visit before visiting point i
			for(j=i-1;j>=0;--j)
			{
				//incur penality p[j+1] + ... + p[i-1]
				T = cost[j] + dist(j, i) + 1.0 + psum[i-1] - psum[j];
				if(T < cost[i]) cost[i] = T;
				
				//Note that penality can only increase as we step back, so if it is greater than cost[i] at this stage, 
				//it will always be greater, and will never contribute to giving smaller answers
				if(psum[i-1] - psum[j] > cost[i]) break;
			}
		}

		printf("%.3lf\n", cost[n+1] + tol);
	}

	clock_t endClock = clock();
	fprintf(stderr, "Time = %lf(ms)\n", (double)(1000.0)*(endClock - startClock)/(CLOCKS_PER_SEC));
	return 0;
}

