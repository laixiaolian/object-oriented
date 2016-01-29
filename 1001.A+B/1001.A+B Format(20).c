#include <stdio.h>
#include <string.h>
#include<math.h>
char str[1000005];
int main(void)
{
	int a, b, sum, n,m;
	int i, j, t = 0, k, l,g=0,h;
	scanf("%d %d", &a, &b);
	sum = a + b;
	if(sum==0)
	{
		printf("0");}
	else
	{
	k = sum;
	sum = abs(sum);
	while (sum>0)
	{
		n = sum % 10;
		sum = sum / 10;
		str[t] = n + 48;
		t++;
		g++;
	}
	m=g-1;

	for(t=0;t<=m/2;t++)
	{
			h=str[t];str[t]=str[m-t];str[m-t]=h;
	}
	if (k<0)
	{
		printf("-");
	}
	if (strlen(str) % 3 != 0)
	{
		for (i = 0; i<strlen(str) % 3; i++)
		{
			putchar(str[i]);
		}
		if(strlen(str)>3) putchar(',');
		for (j = 0; i<strlen(str); i++)
		{
			putchar(str[i]);
			if (++j % 3 == 0 && i != strlen(str) - 1)
			{
				putchar(',');
			}
		}
	}
	else
	{
		l = 0;
		for (i = 0; i<strlen(str) / 3; i++)
		{
			for (j = l; j<l + 3; j++)
			{
				putchar(str[j]);
			}
			l = j;
			if (i != strlen(str) / 3 - 1)
			{
				putchar(',');
			}
		}
	}
	}
	return 0;
}
