#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE	10	 
#define TABLE_SIZE	13	

typedef struct
{
	char key[KEY_SIZE];
} element;

element hash_table[TABLE_SIZE];

void init_table(element ht[])
{
	int i;
	for (i = 0; i<TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}

int transform1(char *key)
{
	int number = 0;
	while (*key)
		number = number + *key++;
	return number;
}

int hash_function(char *key)
{
	return transform1(key) % TABLE_SIZE;
}

#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key,item2.key))

void hash_lp_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다\n");
			exit(1);
		}
	}
	ht[i] = item;
}

void hash_lp_search_store(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i]))
	{
		if (equal(item, ht[i])) {
			fprintf(stderr, "인덱스 %d번에 저장되었음\n\n", i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 테이블에 없음\n\n");
}

void hash_lp_search_srch(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i]))
	{
		if (equal(item, ht[i])) {
			fprintf(stderr, "%s는 해쉬테이블 %d 인덱스에 있음!\n\n",item.key, i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 테이블에 없음\n\n");
}

void hash_lp_delete(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i]))
	{
		if (equal(item, ht[i])) {
			fprintf(stderr, "%s를 테이블에서 삭제합니다.\n\n",item.key);
			ht[i].key[0] = NULL;
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 테이블에 없음\n\n");
}

void hash_lp_print(element ht[])
{
	int i;
	printf("\n===============================\n");
	for (i = 0; i<TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
	printf("===============================\n\n");
}

int main(void)
{
	char ch=0;
	char animal= 0;
	int i;
	element search;

	while(1)
	{
		printf("삽입(i), 탐색(s), 삭제(d), 종료(x) : ");
		scanf("%s", &ch);
		
		if(ch == 'x')
		{
			exit(0);
		}

		printf("동물의 이름 : ");
		scanf("%s", search.key);

		switch(ch)
		{
			case 'i' :
				hash_lp_add(search, hash_table);
				hash_lp_search_store(search,hash_table);
				break;
			case 's' :
				hash_lp_search_srch(search, hash_table);
				break;
			case 'd' :
				hash_lp_delete(search, hash_table);
				break;
		}
		hash_lp_print(hash_table);
	}
	return 0;
}
