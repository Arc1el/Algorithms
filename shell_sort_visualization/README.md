# 쉘정렬 프로그램 및 시각화 프로그램

![Image Of Result](https://github.com/Arc1el/Algorithms/blob/master/shell_sort_visualization/result.png)

셸정렬을 C로 구현한 두 함수 inc_insertion_sort() 와 shell_sort()를 이용하여

셸정렬기법으로 정렬되어 가는 과정을 보이도록 프로그램을 작성해보자.




삽입정렬(부분리스트)
```c
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
```
쉘정렬
```c
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
			printf("\n                      "
             "==========================================\n부분리스트 정리 후\n");
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
			printf("                      "
             "==========================================\n");
		printf("간격 %d 정렬후 배열\n                      ", gap);
		for(k=0; k<LIST_SIZE; k++)
		{
			printf("%2d  ", list[k]);
		}
		printf("\n                      "
           "==========================================\n");
	}  
	for(k=0; k<BUFSIZ; k++)
	{
		list2[k]=0;
	}
}
```
