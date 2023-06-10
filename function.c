#define _CRT_SECURE_NO_WARNINGS 1
#include "Function.h"
//退出
void goto_exit()
{
	print_exit();
	int tmp = -1;
	printf("请输入数字来选择功能：\n");
	while (1)
	{
		scanf("%d", &tmp);
		if (tmp == 1)
		{
			printf("即将退出系统……");
			Sleep(750);
			system("cls");
			printf("已退出！\n");
			exit(0);
		}
		else if (tmp == 0)
		{
			return_manu();
			break;
		}
		else
			printf("输入错误请重新输入：\n");
	}
}
//确认取消的选择功能
int YesOrNo(int num)//传入1或0---使用或不使用return_manu()语句
{
	int tmp = -1;
	while (1)
	{
		scanf("%d", &tmp);
		getchar();
		if (tmp == 1)
		{
			return 1;
		}
		else if (tmp == 0)
		{
			if (num == 1)
				return_manu();
			return 0;
		}
		else
			printf("输入错误请重新输入：\n");
	}
}
//得到联系人的信息
int get_inf_contact(Peo* cont[])
{
	int i = 0;//联系人数
	FILE* fp = fopen("E:\\个人通讯录管理程序\\Project1\\联系人目录\\默认联系人目录.txt", "r");
	for (i = 0;; i++)
	{
		Peo* tmp = (Peo*)malloc(sizeof(Peo));
		if (fscanf(fp, "%s %s %s %s %s %s\n", tmp->telenumber, tmp->name, 
			tmp->age, tmp->sex, tmp->home, tmp->Uni) != 6)
		{
			free(tmp);
			break;
		}
		else
		{
			cont[i] = tmp;
			tmp = NULL;
		} 
	}
	fclose(fp);
	return i;//已经添加的联系人人数//
}
//得到群组信息
int get_inf_Uni(char *Unis[])
{
	int i = 0;//已经添加的群组个数
	FILE* fp = fopen("E:\\个人通讯录管理程序\\Project1\\联系人目录\\群组名称.txt", "r");
	for (i = 0;; i++)
	{
		char* tmp = (char*)malloc(sizeof(MAX_Uni));
		if (fscanf(fp, "%s\n", tmp) != 1)
		{
			free(tmp);
			break;
		}
		else
		{
			Unis[i] = tmp;
			tmp = NULL;
		}
	}
	fclose(fp);
	return i;//已经添加的群组个数
}
//返回菜单
void return_manu()
{
	printf("正在返回菜单……");
	Sleep(750);
	print_manu();
	printf("请输入数字来选择功能：");
}//调用后配合return语句使用

void easy_list(Peo* cont[], int conts)//简单的列出当前数组中的全部成员
{
	printf("================================================\n");
	for (int j = 0; j < conts; j++)
	{
		printf("[%2d] %s %s %s %s %s ", j + 1,
			cont[j]->telenumber, cont[j]->name, cont[j]->age, cont[j]->sex, cont[j]->home);
		if (strcmp(cont[j]->Uni, "无") != 0)
			puts(cont[j]->Uni);
		else
			puts("");
	}
	printf("================================================\n");
}

void easy_del(Peo* cont[], int conts, int sub)//联系人+联系人数+需要删除的联系人下标
{
	if (sub < 0 || sub > conts)
	{
		printf("删除时，数据错误\n");
		return;
	}
	if (sub == conts - 1)
	{
		free(cont[sub]);
	}
	for (int i = sub; i + 1 < conts; i++)
	{
		cont[i] = cont[i + 1];//将后面的联系人数据向前覆盖
	}
}//简单的删除功能，用于其他一些修改，查找，查看后需要进行简单删除操作

void easy_reset(Peo* cont[], int conts, int sub)//联系人+联系人数+需要修改的联系人下标
{
	if (sub < 0 || sub + 1 > conts)
	{
		printf("输入的该序号错误！\n");
		Sleep(750);
		return;
	}
	memset(cont[sub], 0, sizeof(Peo));
	system("cls");
	while (1)
	{
		printf("================================================\n");
		printf("电话：");
		memset(cont[sub]->telenumber, 0, sizeof(cont[sub]->telenumber));
		gets(cont[sub]->telenumber);
		if (strlen(cont[sub]->telenumber) != 11)
		{
			printf("电话号码设置错误！请重新输入……");
			Sleep(1000);
			system("cls");
		}
		else if (strlen(cont[sub]->telenumber) == 11)
			break;
	}
	printf("================================================\n");
	printf("备注：");
	gets(cont[sub]->name);
	if (cont[sub]->name[0] == '\0')
		strcpy(cont[sub]->name, "未知");
	printf("================================================\n");
	printf("年龄：");
	while (1)
	{
		gets(cont[sub]->age);
		if (cont[sub]->age[0] == '\0')
		{
			strcpy(cont[sub]->age, "未知");
			break;
		}
		int i = 0;
		for (i = 0; i < strlen(cont[sub]->age); i++)
		{
			if (cont[sub]->age[i] > '9' || cont[sub]->age[i] < '0')
			{
				printf("年龄设置错误，重新输入：");
				memset(cont[sub]->age, 0, sizeof(cont[sub]->age));
				i = -1;//年龄设置错误--做标记
				break;
			}
		}
		if (i == -1)
			continue;
		else
			break;
	}
	printf("================================================\n");
	printf("性别：");
	gets(cont[sub]->sex);
	if (cont[sub]->sex[0] == '\0')
		strcpy(cont[sub]->sex, "未知");
	printf("================================================\n");
	printf("家庭住址：");
	gets(cont[sub]->home);
	if (cont[sub]->home[0] == '\0')
		strcpy(cont[sub]->home, "未知");
	printf("================================================\n");
	printf("群组：");
	gets(cont[sub]->Uni);
	while (1)
	{
		if (strlen(cont[sub]->Uni) == 0)
		{
			strcpy(cont[sub]->Uni, "无");
			break;
		}
		else if (strcmp(cont[sub]->Uni, "无") == 0)
		{
			printf("群组名称不能为\"无\"！");
			gets(cont[sub]->Uni);
		}
		else if (!isUniExist(cont[sub]->Uni))
		{
			printf("该群组不存在，请重新输入：");
			gets(cont[sub]->Uni);
		}
		else
			break;
	}
	printf("================================================\n");
	printf("修改成功\n");
	Sleep(250);
}//简单的修改功能，用于其他一些查找，查看后需要进行简单修改操作---部分代码来源于goto_adding();

void easy_Uni(Peo* cont[], int sub)
{
	system("cls");
	printf("进行该联系人的群组操作：\n1.修改\t2.退出\t\n");
	int key = 0;
	while (1)
	{
		scanf("%d", &key);
		getchar();
		switch (key)
		{
		case 1:
		{
			printf("当前群组：%s\n", cont[sub]->Uni);
			printf("修改为：");
			gets(cont[sub]->Uni);
			while (1)//检测修改的名称是否正确
			{
				if (strlen(cont[sub]->Uni) == 0)
				{
					strcpy(cont[sub]->Uni, "无");
					return;
				}
				else if (strcmp(cont[sub]->Uni, "无") == 0)
				{
					printf("群组名称不能为\"无\"！");
					gets(cont[sub]->Uni);
				}
				else if (!isUniExist(cont[sub]->Uni))
				{
					printf("该群组不存在，请重新输入：");
					gets(cont[sub]->Uni);
				}
				else
					return;
			}
		}
		case 2:
			strcpy(cont[sub]->Uni, "无");
			return;
		default:
			printf("输入错误请重新输入：");
			break;
		}
	}
}

void save_file(Peo* cont[], int conts)
{
	FILE* fp = fopen("E:\\个人通讯录管理程序\\Project1\\联系人目录\\默认联系人目录.txt", "w");
	for (int i = 0; i < conts; i++)
	{
		fprintf(fp, "%s %s %s %s %s %s\n", cont[i]->telenumber, cont[i]->name, cont[i]->age,
			cont[i]->sex, cont[i]->home, cont[i]->Uni);
	}
	fclose(fp);
}

void save_Uni(char* Unis[], int nums_Uni)
{
	FILE* fp = fopen("E:\\个人通讯录管理程序\\Project1\\联系人目录\\群组名称.txt", "w");
	for (int i = 0; i < nums_Uni; i++)
		fprintf(fp, "%s\n", Unis[i]);
	fclose(fp);//保存文件
}

void easy_func(Peo* cont[], int* conts, int sub)//联系人+联系人人数+需要操作的下标
{
	system("cls");
	printf("================================================\n");
	printf("电话\t姓名\t年龄\t性别\t群组\n");
	printf("%s\t%s\t%s\t%s\t%s\t%s\n", cont[sub]->telenumber, cont[sub]->name, cont[sub]->age, 
		cont[sub]->sex, cont[sub]->home, cont[sub]->Uni);
	printf("================================================\n");
	printf("选择要对该联系人的操作：\n1.修改\t2.删除\t3.群组\n");
	while (1)
	{
		int key = 0;
		scanf("%d", &key);
		getchar();
		switch (key)
		{
		case 1:
		{
			easy_reset(cont, *conts, sub);
			return;
		}
		case 2:
		{
			easy_del(cont, *conts--, sub);
			printf("操作成功！\n");
			system("pause");
			return;
		}
		case 3:
		{
			easy_Uni(cont, sub);
			printf("操作成功！\n");
			system("pause");
			return;
		}
		default:
			printf("输入错误！重新输入：");
			break;
		}
	}
}

int output_Uni(Peo* cont[], int conts, char Uni_name[])
{
	int tmp = 0;//记录属于Uni_name群组的人数
	char filename[100] = "E:\\个人通讯录管理程序\\Project1\\联系人目录\\导出文件\\";
	strcat(filename, Uni_name);
	strcat(filename, ".txt");
	FILE* fp = fopen(filename, "w");
	for (int i = 0; i < conts; i++)
	{
		if (strcmp(cont[i]->Uni, Uni_name) == 0)
		{
			tmp++;
			fprintf(fp, "%s %s %s %s %s\n", cont[i]->telenumber, cont[i]->name,
				cont[i]->age, cont[i]->sex, cont[i]->home);
		}
	}
	if (tmp == 0)
		fprintf(fp, "该群组暂无联系人!\n");
	else
		fprintf(fp, "共有【%d】位联系人\n", tmp);
	printf("导出成功！\n");
	fclose(fp);
	return tmp;
}

int isUniExist(char Uniname[])//检查传入的群组名称是否存在
{
	char* Unis[MAX_NUM_CONTACT];
	int nums_Uni/*群组个数*/ = get_inf_Uni(Unis);//获取群组名称
	for (int i = nums_Uni - 1; i >= 0; i--)
	{
		if (strcmp(Uniname, Unis[i]) == 0)
			return TRUE;
	}
	return FALSE;
}