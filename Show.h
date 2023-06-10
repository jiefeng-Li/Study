#pragma once
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_NAME 10//名字长度
#define MAX_SEX 5//性别名称长度A
#define MAX_HOME 40//家庭名称长度
#define MAX_Uni 15//群组名称长度
#define MAX_NUM_CONTACT 500//联系人最大数
#define TRUE 1
#define FALSE 0

typedef struct Peo//联系人
{
	char telenumber[20];//电话号码
	char name[MAX_NAME];//名字
	char age[5];//年龄
	char sex[MAX_SEX];//性别
	char home[MAX_HOME];//家庭地址
	char Uni[MAX_Uni];//群组名称
}Peo;

void print_YesOrNo(char str[]);//确认界面
void print_manu();//打印菜单
void print_exit();//打印退出界面
void print_adding();//确认添加联系人
void print_finding();//查找界面
void print_Uni();//群组信息管理功能选择