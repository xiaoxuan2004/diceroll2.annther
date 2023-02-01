#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int rollem(int sides);
int rollcount = 0;
int main()
{
	int n=0;
	int status=0;
	int doc=0;
	printf("Please enter an interger as the number of sides per die, \n0 or char string to quit:");
	while ((status=scanf("%d", &n) == 1) && n > 0)
	{
		while (getchar() != '\n')
			continue;//处理错误输入
		if (n < 2)
		{
			printf("The number of sides is at least 2 .\n");
			printf("Please enter another positive figure like 6 or 12:");
			continue;
		}
		else
		{
			int die = 0;
			int total = 0;
			printf("Enter the number of dies:");
			while ((doc=scanf("%d", &die)) == 1 && die >= 1)
			{

				int every=0;
				while (getchar() != '\n')
					continue;//处理错误输入
				for (int i = 0;i < die;i++)
				{
					every = rollem(n);
					total += every;
				}
				printf("The total is %d.\n", total);
				++rollcount;
				printf("You have rolled %d times.\n", rollcount);
				printf("Enter the number of sides per die, 0 to quit:");
				break;
			}
			if (die < 1||doc!=1)
			{
				while (getchar() != '\n')
					continue;//处理错误输入
				printf("The number of dies is at least 1 .\n");
				printf("Let's start again!\n");
				printf("Enter the number of sides per die, 0 to quit:");
				continue;
			}
		}

	}
	printf("Good Fortune For You!");
	return 0;
}
int rollem(int sides)
{
	int roll;
	srand((unsigned int)time(NULL));
	roll = rand() % sides + 1;
	return roll;
}