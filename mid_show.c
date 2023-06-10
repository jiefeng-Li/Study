#define _CRT_SECURE_NO_WARNINGS 1
#include "Show.h"

void print_adding()
{
	system("cls");
	printf("请按例子输入(按enter键跳过的信息将设为\"未知\")\n");
	printf("================================================\n");
	Sleep(500);
	printf("电话：12345678910【*11位电话号码*】\n");
	printf("================================================\n");
	Sleep(500);
	printf("备注：张三\n");
	printf("================================================\n");
	Sleep(500);
	printf("年龄：24\n");
	printf("================================================\n");
	Sleep(500);
	printf("性别：男\n");
	printf("================================================\n");
	Sleep(500);
	printf("家庭住址：四川成都\n");
	printf("================================================\n");
	Sleep(500);
	printf("群组：\n");
	printf("================================================\n");
	system("pause");
}

void print_finding()
{
	system("cls");
	printf("************************************\n");
	printf("*         请选择查询方式           *\n");
	printf("*                                  *\n");
	printf("*         1.按姓名查询             *\n");
	printf("*                                  *\n");
	printf("*         2.按电话查询             *\n");
	printf("*                                  *\n");
	printf("*         3.按年龄查询             *\n");
	printf("*                                  *\n");
	printf("*         4.按家庭地址查询         *\n");
	printf("*                                  *\n");
	printf("*         0.结束查询               *\n");
	printf("*                                  *\n");
	printf("************************************\n");
}

void print_Uni()
{
	system("cls");
	printf("************************************\n");
	printf("*         群组信息管理             *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("*         0.返回菜单               *\n");
	printf("*                                  *\n");
	printf("*         1.添加群组               *\n");
	printf("*         2.删除群组               *\n");
	printf("*         3.修改群组               *\n");
	printf("*         4.查看群组               *\n");
	printf("*         5.导出群组               *\n");
	printf("*                                  *\n");
	printf("*                                  *\n");
	printf("************************************\n");
}