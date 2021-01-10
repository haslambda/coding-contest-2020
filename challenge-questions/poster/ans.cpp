#include <stdio.h>
#include <algorithm>
using namespace std;
#define size 300002

typedef struct {
	int height;
	int cost;
}Pic;

int ByH(Pic A, Pic B)
{
	if (A.height < B.height)
		return 1;
	if (A.height == B.height && A.cost < B.cost)
		return 1;
	return 0;
}

int main(void)
{
	Pic pic[size];
	pic[0].height = 0;
	pic[0].cost = 0;
	int N, S;
    int index[size] = { 0, };
    int maxforthis[size] = { 0, };
	int result[size] = { 0, };
	scanf("%d%d", &N, &S);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &pic[i].height, &pic[i].cost);
	sort(pic, pic + N+1, ByH);
	for (int i = 1; i < N+1; i++)
	{
		for (int j = index[i - 1]; j <= i; j++)
		{
            if (maxforthis[i] == 0 && pic[i].height>=S)
				maxforthis[i] = pic[i].cost;
            
			if (pic[i].height - pic[j].height >= S)
            {
				maxforthis[i] = max(maxforthis[i], result[j] + pic[i].cost);
			}	
            
			if(pic[i].height - pic[j].height < S) 
            {
				if (j == 0)
                    index[i] = 0;
				else {
                    index[i] = j - 1;
				break;}
			}
			
		}
        result[i] = max(maxforthis[i], result[i - 1]);
	}
    
	printf("%d", result[N]);
	return 0;
}
