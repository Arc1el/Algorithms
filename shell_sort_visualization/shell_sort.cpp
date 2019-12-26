#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_SIZE 11

int list[LIST_SIZE];
int n;

void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i=0, j=0, k=0, key;
	
	for(i=first+gap; i<=last; i=i+gap)
	{
		key=list[i];
		for(j=i-gap; j>=first && key<list[j]; j=j-gap)
		{
		list[j+gap]=list[j]; 
		}
		list[j+gap]=key;
	}
}

void shell_sort(int list[], int n)
{
	int i, gap;
	int j=0,k=0, l=0;
	int list2[BUFSIZ]={0};


	for(gap=n/2; gap>0; gap=gap/2)
	{
		if((gap%2)==0)
		{
			gap++;
		}
		if(gap!=1)
			printf("간격 %d일때 부분리스트\n",gap);
		for(i=0; i<gap; i++)
		{
			printf("                      ");
			for(j=0; j<n; j++)
			{
				for(l=0; l<=n/gap; l++)
				{
					list2[i+gap*l]=list[i+gap*l];
				}
				if(gap!=1)
					printf("%2d  ",list2[j]);
			}
			for(k=0; k<BUFSIZ; k++)
			{
				list2[k]=0;
			}
			if(gap!=1)
				printf("\n");
			inc_insertion_sort(list,i,n-1,gap);
		}
		if(gap!=1)
			printf("\n                      ==========================================\n부분리스트 정리 후\n");
		for(i=0; i<gap; i++)
		{
			printf("                      ");
			for(j=0; j<n; j++)
			{
				for(l=0; l<=n/gap; l++)
				{
					list2[i+gap*l]=list[i+gap*l];
				}
				if(gap!=1)
					printf("%2d  ",list2[j]);
				for(k=0; k<BUFSIZ; k++)
				{
					list2[k]=0;
				}
			}
				printf("\n");
		}
		if(gap!=1)
			printf("                      ==========================================\n");
		printf("간격 %d 정렬후 배열\n                      ", gap);
		for(k=0; k<LIST_SIZE; k++)
		{
			printf("%2d  ", list[k]);
		}
		printf("\n                      ==========================================\n");
	}  
	for(k=0; k<BUFSIZ; k++)
	{
		list2[k]=0;
	}
}

int main(void)
{
	int i;
	n=LIST_SIZE;
	srand(time(NULL));

	for(i=0; i<n; i++)
	{
		list[i]=rand()%100;
	}
	printf("     입력배열\n                      ");
	for(i=0; i<n; i++)
	{
		printf("%2d  ",list[i]);
	}
	printf("\n                      ==========================================\n");
	shell_sort(list,n);
	printf("\n");
	return 0;
}
