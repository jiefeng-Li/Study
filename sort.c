#define _CRT_SECURE_NO_WARNINGS 1
#include "Function.h"

void sort_Peo_name()//完成
{
	int nums_cont = 0;//联系人人数
	Peo* cont[MAX_NUM_CONTACT];
	nums_cont = get_inf_contact(cont); 
	for (int i = nums_cont - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (strcmp(cont[j]->name, cont[j + 1]->name) > 0)
			{
				Peo* tmp = cont[j + 1];
				cont[j + 1] = cont[j];
				cont[j] = tmp;
			}
			else if (strcmp(cont[j]->name, cont[j + 1]->name) == 0)
			{
				if (strcmp(cont[j]->telenumber, cont[j + 1]->telenumber) > 0)
				{
					Peo* tmp = cont[j + 1];
					cont[j + 1] = cont[j];
					cont[j] = tmp;
				}
			}
		}
	}//冒泡排序
	save_file(cont, nums_cont);//保存文件
}

void sort_Peo_Uni()//完成
{
	FILE* fp = fopen("E:\\个人通讯录管理程序\\Project1\\联系人目录\\群组名称.txt", "r");
	char Uni_name[MAX_NUM_CONTACT][MAX_Uni];//保存群组名称
	int num = 0;//已经添加了的群组个数
	for (int i = 0; ; i++)
	{
		if (fscanf(fp, "%s\n", Uni_name[i]) != 1)
		{
			num = i;//已经添加了的群组个数
			break;
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			if (strcmp(Uni_name[i], Uni_name[j]) > 0)
			{
				char tmp[MAX_Uni];
				strcpy(tmp, Uni_name[i]);
				strcpy(Uni_name[i], Uni_name[j]);
				strcpy(Uni_name[j], tmp);
			}
		}
	}//选择排序
	fclose(fp);
	fp = fopen("E:\\个人通讯录管理程序\\Project1\\联系人目录\\群组名称.txt", "w");
	for (int i = 0; i < num; i++)
		fprintf(fp, "%s\n", Uni_name[i]);
	fclose(fp);
}