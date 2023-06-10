#define _CRT_SECURE_NO_WARNINGS 1
#include "Show.h"
//打印功能界面的函数
void print_manu()
{
	system("cls");
	printf("************************************\n");
	printf("*        个人通讯录管理程序        *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*        0.退出系统                *\n");
	printf("*        1.添加联系人              *\n");
	printf("*        2.删除联系人              *\n");
	printf("*        3.查找联系人              *\n");
	printf("*        4.查看全部联系人          *\n");
	printf("*        5.修改信息                *\n");
	printf("*        6.群组信息管理            *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("************************************\n");
}

void print_exit()
{
	system("cls");
	printf("************************************\n");
	printf("*           退出系统               *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*         1.确定                   *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*         0.取消                   *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("************************************\n");
}

void print_YesOrNo(char str[])
{
	system("cls");
	printf("************************************\n");
	printf("*        %s        *\n", str);
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*         1.确定                   *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*         0.取消                   *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("************************************\n");
}