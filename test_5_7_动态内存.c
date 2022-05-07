#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int main()
{
	//向内存申请40个空间	
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		//打印错误的方法
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d\n", *(p + i));
		}
	}
	//使用玩后返回内存
	free(p);
	//p还可以指向空间地址
	//把p设置为空指针防止被乱用
	p = NULL;
	return 0;
}