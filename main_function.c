#define _CRT_SECURE_NO_WARNINGS 1
#include "Function.h"

void goto_adding()
{
	int nums_cont = 0;//联系人人数
	Peo* cont[MAX_NUM_CONTACT];//联系人信息
	nums_cont = get_inf_contact(cont);

	print_adding();//输入的示范样例
	while (1)
	{
		Peo newpeo;
		memset(&newpeo, 0, sizeof(Peo));
		system("cls");
		while (1)
		{
			printf("================================================\n");
			printf("电话：");
			memset(newpeo.telenumber, 0, sizeof(newpeo.telenumber));
			gets(newpeo.telenumber);
			if (strlen(newpeo.telenumber) != 11)
			{
				printf("电话号码设置错误！请重新输入……");
				Sleep(1000);
				system("cls");
			}
			else if (strlen(newpeo.telenumber) == 11)//还差检查该电话号码是否已存在的功能
				break;
		}
		printf("================================================\n");
		printf("备注：");
		gets(newpeo.name);
		if (newpeo.name[0] == '\0')
			strcpy(newpeo.name, "未知");
		printf("================================================\n");
		printf("年龄：");
		while (1)
		{
			gets(newpeo.age);
			if (newpeo.age[0] == '\0')
			{
				strcpy(newpeo.age, "未知");
				break;

			}
			int i = 0;
			for (i = 0; i < strlen(newpeo.age); i++)//检查年龄的字符串中是否有0~9之外的字符
			{
				if (newpeo.age[i] > '9' || newpeo.age[i] < '0')
				{
					printf("年龄设置错误，重新输入：");
					memset(newpeo.age, 0, sizeof(newpeo.age));
					i = -1;//如果有就把i赋值为-1
					break;
				}
			}
			if (i == -1)//有非法字符
				continue;
			else
				break;
		}
		printf("================================================\n");
		printf("性别：");
		gets(newpeo.sex);
		if (newpeo.sex[0] == '\0')
			strcpy(newpeo.sex, "未知");
		printf("================================================\n");
		printf("家庭住址：");
		gets(newpeo.home);
		if (newpeo.home[0] == '\0')
			strcpy(newpeo.home, "未知");
		printf("================================================\n");
		printf("群组：");
		gets(newpeo.Uni);
		while (1)
		{
			if (strlen(newpeo.Uni) == 0)
			{
				strcpy(newpeo.Uni, "无");
				break;
			}
			else if (strcmp(newpeo.Uni, "无") == 0)
			{
				printf("群组名称不能为\"无\"！");
				gets(newpeo.Uni);
			}
			else if (!isUniExist(newpeo.Uni))
			{
				printf("该群组不存在，请重新输入：");
				gets(newpeo.Uni);
			}
			else
				break;
		}
		printf("================================================\n");
		cont[nums_cont] = (Peo*)malloc(sizeof(Peo));
		*cont[nums_cont] = newpeo;
		for (int i = 0; i < nums_cont; i++)
		{
			if (strcmp(cont[i]->name, newpeo.name) > 0)
			{
				for (int j = nums_cont; j > i; j--)
					*cont[j] = *cont[j - 1];
				*cont[i] = newpeo;
				break;
			}
		}
		nums_cont++;
		save_file(cont, nums_cont);
		printf("添加成功！\n");
		system("pause");
		print_YesOrNo(" 继续添加联系人?  ");
		if (!(YesOrNo(1)))
			return;
	}
}

void goto_deling()//暂时完成？
{
	system("cls");
	int nums_cont = 0;//联系人人数
	Peo* cont[MAX_NUM_CONTACT];//联系人信息
	nums_cont = get_inf_contact(cont);

	easy_list(cont, nums_cont);
	printf("请输入需要删除的联系人姓名或电话号码：");
	char t_inf[20];
	gets(t_inf);
	system("cls");
	printf("请输入需要删除的联系人姓名或电话号码：%s\n", t_inf);
	while (1)
	{
		int hash[MAX_NUM_CONTACT] = {0};//记录查询到的联系人---以防删除时操作错误
		int tmp = FALSE;//是否查找成功
		if (t_inf[0] == '\0')
		{
			printf("信息输入不能为空！请重新输入：");
			continue;
		}
		printf("================================================\n");
		for (int i = 0; i < nums_cont; i++)
		{
			//int len = strlen(t_inf);
			char* p;
			p = strstr(cont[i]->telenumber, t_inf);
			if (p)//匹配到相同信息
			{
				tmp = TRUE;//信息匹配成功----标记为TRUE
				hash[i]++;
				printf("[%2d] ", i + 1);
				for (int j = 0; j < 11; j++)
				{
					if (cont[i]->telenumber + j == p)
					{
						printf("\033[47;30m%s\033[0m", t_inf);//查询到的信息变色打印
						j += strlen(t_inf);
					}
					printf("%c", cont[i]->telenumber[j]);
				}
				printf(" %s %s %s %s ", cont[i]->name, cont[i]->age, cont[i]->sex, cont[i]->home);//打印剩余信息
				if (strcmp(cont[i]->Uni, "无") != 0)
					puts(cont[i]->Uni);
				else
					puts("");

			}
			else
			{
				p = strstr(cont[i]->name, t_inf);
				if (p)
				{
					hash[i]++;
					tmp = TRUE;//信息匹配成功----标记为TRUE
					printf("[%2d] %s ", i + 1, cont[i]->telenumber);
					for (int j = 0; cont[i]->name[j] != '\0'; j++)
					{
						if (cont[i]->name + j == p)
						{
							printf("\033[47;30m%s\033[0m", t_inf);//查询到的信息变色打印
							j += strlen(t_inf);
						}
						if (j < strlen(cont[i]->name))
							printf("%c", cont[i]->name[j]);
					}
					printf(" %s %s %s ", cont[i]->age, cont[i]->sex, cont[i]->home);//打印剩余信息
					if (strcmp(cont[i]->Uni, "无") != 0)
						puts(cont[i]->Uni);
					else
						puts("");
				}
			}
		}
		if (tmp == FALSE)
		{
			memset(t_inf, 0, 20);//重置t_inf中的信息
			printf("未查找到\n");
		}
		printf("================================================\n");
		printf("追加信息(y/n):");
		char ch = getchar();
		getchar();
		while (1)
		{
			if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
				break;
			else
			{
				printf("输入错误！请重新输入(y/n):");
				ch = getchar();
				getchar();
			}
		}
		if (ch == 'y' || ch == 'Y')//确认追加信息
		{
			char t[20] = {'\0'};
			printf("输入需要追加的信息：");
			gets(t);
			strcat(t_inf, t);
			system("cls");
			printf("请输入需要删除的联系人姓名或电话号码：%s\n", t_inf);
		}
		else//取消追加信息并进行删除操作
		{
			int sub;
			printf("请输入需要删除的联系人前的序号(输入0取消):");
			scanf("%d", &sub);//序号（sub-1才为下标）
			while (1)
			{
				if (sub == 0)//取消删除并返回菜单
				{
					return_manu();
					return 0;
				}
				if (hash[sub - 1])//序号为sub的联系人是查询到的（防止错误删除）
				{
					easy_del(cont, nums_cont--, sub - 1);
					printf("删除成功！\n");
					save_file(cont, nums_cont);
					break;
				}
				else
				{
					printf("未查询到此序号的联系人，请重新输入：");
					scanf("%d", &sub);
				}
			}
			break;
		}
	}
	return_manu();
	return 0;
}

void goto_finding()
{
	print_finding();
	printf("请选择查询方式：");
	int key;
	int nums_cont = 0;//联系人人数
	Peo* cont[MAX_NUM_CONTACT];
	nums_cont = get_inf_contact(cont);
	while (1)
	{
		scanf("%d", &key);
		getchar();
		switch (key)
		{
		case 0://退出-----ok
			return_manu();
			return;
		case 1://姓名-----
		{
			while (1)
			{
				int nums = 0;//记录与查询信息相匹配的人数
				short hash[MAX_NUM_CONTACT] = { 0 };//确定后面输入的序号是被检索到的联系人，防止错误操作
				char name[MAX_NAME];
				system("cls");
				printf("请输入:");
				gets(name);
				system("cls");
				printf("================================================\n");
				for (int i = 0; i < nums_cont; i++)
				{
					char* p = strstr(cont[i]->name, name);
					if (p)
					{
						hash[i]++;
						nums++;//记录与查询信息相匹配的人数
						printf("[%2d] %s ", i + 1, cont[i]->telenumber);
						for (int j = 0; cont[i]->name[j] != '\0'; j++)
						{
							if (cont[i]->name + j == p)
							{
								printf("\033[47;30m%s\033[0m", name);//查询到的信息变色打印
								j += strlen(name);
							}
							if (j < strlen(cont[i]->name))
								printf("%c", cont[i]->name[j]);
						}
						printf(" %s %s %s ", cont[i]->age, cont[i]->sex, cont[i]->home);//打印剩余信息
						if (strcmp(cont[i]->Uni, "无") != 0)
							puts(cont[i]->Uni);
						else
							puts("");
					}
				}
				printf("================================================\n");
				printf("[[[查找到%d名与\"%s\"相关的联系人]]]\n", nums, name);
				if (nums == 0)
				{
					printf("是否重新输入？(1/0)");
					if (YesOrNo(1))//重新输入
						continue;
					else//返回菜单
						return;
				}
				int key = 0;
				printf("输入联系人前的序号操作：");
				while (1)
				{
					scanf("%d", &key);
					if (key == 0)
						break;
					if (key >= 1 && key <= nums_cont && hash[key-1])
					{
						easy_func(cont, &nums_cont, key - 1);//简单的操作（删除+修改+群组（修改+退出））
						save_file(cont, nums_cont);//保存文件
						break;
					}
					else
						printf("输入错误，重新输入：");
				}
				break;
			}
			print_finding();
			printf("请选择查询方式：");
			break;
		}
		case 2://电话------ok
		{
			while (1)
			{
				system("cls");
				char tele[20];
				printf("请输入电话号码：");
				int nums = 0;//记录与查询信息相匹配的人数
				short hash[MAX_NUM_CONTACT] = { 0 };//确定后面输入的序号是被检索到的联系人，防止错误操作
				gets(tele);
				printf("================================================\n");
				for (int i = 0; i < nums_cont; i++)
				{
					char* p = strstr(cont[i]->telenumber, tele);
					if (p)
					{
						hash[i]++;
						nums++;//记录与查询信息相匹配的人数
						printf("[%2d] ", i + 1);
						for (int j = 0; cont[i]->telenumber[j] != '\0'; j++)
						{
							if (cont[i]->telenumber + j == p)
							{
								printf("\033[47;30m%s\033[0m", tele);//查询到的信息变色打印
								j += strlen(tele);
							}
							if (j < strlen(cont[i]->telenumber))
								printf("%c", cont[i]->telenumber[j]);
						}
						printf(" %s %s %s %s", cont[i]->name, cont[i]->age, cont[i]->sex, cont[i]->home);//打印剩余信息
						if (strcmp(cont[i]->Uni, "无") != 0)
							puts(cont[i]->Uni);
						else
							puts("");
					}
				}
				printf("================================================\n");
				printf("[[[查找到%d名与\"%s\"相关的联系人]]]\n", nums, tele);
				if (nums == 0)//记录与查询信息相匹配的人数
				{
					printf("是否重新输入？(1/0)");
					if (YesOrNo(1))//重新输入
						continue;
					else//返回菜单
						return;
				}
				int key = 0;
				printf("输入联系人前的序号操作：");
				while (1)
				{
					scanf("%d", &key);
					if (key == 0)
						break;
					if (key >= 1 && key <= nums_cont && hash[key-1])
					{
						easy_func(cont, &nums_cont, key - 1);//简单的操作（删除+修改+群组（修改+退出））
						save_file(cont, nums_cont);//保存文件
						break;
					}
					else
						printf("输入错误，重新输入：");
				}
				break;
			}
			print_finding();
			printf("请选择查询方式：");
			break;
		}
		case 3://年龄
		{
			while (1)
			{
				short hash[MAX_NUM_CONTACT] = {0};//确定后面输入的序号是被检索到的联系人，防止错误操作
				system("cls");
				char t_age[5];
				printf("请输入查找的年龄：");
				while (1)
				{
					gets(t_age);
					int i = 0;
					for (i = 0; i < strlen(t_age); i++)
					{
						if (t_age[i] > '9' || t_age[i] < '0')
						{
							i = -1;
							break;
						}
					}
					if (i == 0 || i == -1)
					{
						printf("年龄设置错误，重新输入：");
						continue;
					}
					else
						break;
				}
				int nums = 0;//记录与查询信息相匹配的人数
				system("cls");
				printf("================================================\n");
				for (int sub = 0; sub < nums_cont; sub++)
				{
					if (strcmp(cont[sub]->age, t_age) == 0)
					{
						hash[sub]++;//符合条件，做标记
						nums++;//记录与查询信息相匹配的人数
						printf("[%2d] %s %s %s %s %s\n", sub + 1,
							cont[sub]->telenumber, cont[sub]->name, cont[sub]->age, cont[sub]->sex, cont[sub]->home);
					}
				}
				printf("================================================\n");
				printf("[[[查找到%d名与\"%s\"岁的联系人]]]\n", nums, t_age);
				if (nums == 0)
				{
					printf("是否重新输入？(1/0)");
					if (YesOrNo(1))//重新输入
						continue;
					else//返回菜单
						return;
				}
				int key = 0;
				printf("输入联系人前的序号操作：");
				while (1)
				{
					scanf("%d", &key);
					getchar();
					if (key == 0)
						break;
					if (key >= 1 && key <= nums_cont && hash[key-1])
					{
						easy_func(cont, &nums_cont, key - 1);//简单的操作（删除+修改+群组（修改+退出））
						save_file(cont, nums_cont);
						break;
					}
					else
						printf("输入错误，重新输入：");
				}
			}
			print_finding();
			printf("请选择查询方式：");
			break;
		}
		case 4://家庭地址------ok
		{
			while (1)
			{
				short hash[MAX_NUM_CONTACT] = {0};//确定后面输入的序号是被检索到的联系人，防止错误操作
				int nums = 0;//记录与查询信息相匹配的人数
				char t_home[MAX_HOME];
				printf("请输入:");
				gets(t_home);
				system("cls");
				printf("================================================\n");
				for (int i = 0; i < nums_cont; i++)
				{
					char* p = strstr(cont[i]->home, t_home);
					if (p)//查询成功
					{
						hash[i]++;//符合条件，做标记
						nums++;
						printf("[%2d] %s %s %s %s ", i + 1, cont[i]->telenumber, 
							cont[i]->name, cont[i]->age, cont[i]->sex);
						for (int j = 0; cont[i]->home[j] != '\0'; j++)
						{
							if (cont[i]->home + j == p)
							{
								printf("\033[47;30m%s\033[0m", t_home);//查询到的信息变色打印
								j += strlen(t_home);
							}
							if (j < strlen(cont[i]->home))
								printf("%c", cont[i]->home[j]);
						}
						if (strcmp(cont[i]->Uni, "无") != 0)
							puts(cont[i]->Uni);
						else
							puts("");
					}
				}
				printf("================================================\n");
				printf("[[[查找到%d名与\"%s\"相关的联系人]]]\n", nums, t_home);
				if (nums == 0)
				{
					printf("是否重新输入？(1/0)");
					if (YesOrNo(1))//重新输入
						continue;
					else//返回菜单
						return;
				}
				int key = 0;
				printf("输入联系人前的序号操作：");
				while (1)
				{
					scanf("%d", &key);
					if (key == 0)
						break;
					if (key >= 1 && key <= nums_cont && hash[key-1])
					{
						easy_func(cont, &nums_cont, key - 1);//简单的操作（删除+修改+群组（修改+退出））
						save_file(cont, nums_cont);
						break;
					}
					else
						printf("输入错误，重新输入：");
				}
				break;
			}
			print_finding();
			printf("请选择查询方式：");
			break;
		}
		default:
			printf("非法输入！ 请重新输入：");
			break;
		}
	}
	save_file(cont, nums_cont);//保存文件
	return_manu();
	return 0;
}

void goto_listing()
{
	system("cls");
	int nums_cont = 0;
	Peo* cont[MAX_NUM_CONTACT];
	nums_cont = get_inf_contact(cont);
	printf("================================================\n");
	for (int j = 0; j < nums_cont; j++)
	{
		printf("[%2d] %s %s %s %s %s ", j + 1,
			cont[j]->telenumber, cont[j]->name, cont[j]->age, cont[j]->sex, cont[j]->home);
		if (strcmp(cont[j]->Uni, "无") != 0)
			puts(cont[j]->Uni);
		else
			puts("");
	}
	printf("================================================\n");
	printf("已添加%d位联系人\n", nums_cont);
	system("pause");
	return_manu();
	return 0;
}

void goto_reseting()//暂时完成
{
	system("cls");
	int nums_cont = 0;
	Peo* cont[MAX_NUM_CONTACT];
	nums_cont = get_inf_contact(cont);
	easy_list(cont, nums_cont);
	printf("输入需要修改的联系人序号（输入非数字字符退出）：");
	while (1)
	{
		int th = 0;
		if ((scanf("%d", &th)) != 1)
		{
			getchar();
			break;
		}
		else//执行序号为 th 的联系人修改
		{
			getchar();
			easy_reset(cont, nums_cont, th - 1);//修改
			save_file(cont, nums_cont);//保存
			system("cls");
			easy_list(cont, nums_cont);//列出
			printf("输入需要修改的联系人序号（输入非数字字符退出）：");//输入提示
		}
	}
	return_manu();
	return 0;
}

void goto_Uni()
{
	char* Unis[MAX_NUM_CONTACT];
	int nums_Uni/*群组个数*/ = get_inf_Uni(Unis);//获取群组名称
	Peo* cont[MAX_NUM_CONTACT];
	int nums_cont/*联系人个数*/ = get_inf_contact(cont);//获取联系人信息
	char* t_Uname = (char*)malloc(sizeof(char) * MAX_Uni);//用来保存后续操作输入的群组名称

	print_Uni();
	while (1)
	{
		int key;
		scanf("%d", &key);
		getchar();
		system("cls");
		if (key >= 1 && key <= 5)//打印所有的群组
		{
			printf("================================================\n");
			for (int i = 0; i < nums_Uni; i++)
				printf("[%d]\t%s\n", i + 1, Unis[i]);
			printf("================================================\n");
		}
		switch (key)
		{
		case 1://添加群组
		{
			printf("请输入要添加的群组名称：");
			while (1)
			{
				gets(t_Uname);
				if (strlen(t_Uname) == 0)//信息不为空
					printf("请输入要添加的群组名称：");
				else if (strcmp(t_Uname, "无") == 0)//不能设置位“无”
					printf("群组名称不能设置为“无”：");
				else if (isUniExist(t_Uname))//不为已经存在的群组
					printf("该群组已存在，请重新输入：");
				else break;
			}
			for (int i = 0; i < nums_Uni; i++)
			{
				if (strcmp(t_Uname, Unis[i]) < 0)
				{
					for (int j = nums_Uni; j > i; j--)
						Unis[j] = Unis[j - 1];
					Unis[i] = (char*)malloc(sizeof(char) * MAX_Uni);
					strcpy(Unis[i], t_Uname);
					nums_Uni++;
					break;
				}
				if (i == nums_Uni - 1)
				{
					Unis[nums_Uni] = (char*)malloc(sizeof(char) * MAX_Uni);
					strcpy(Unis[nums_Uni], t_Uname);
					nums_Uni++;
					break;
				}
			}
			printf("添加成功！\n");
			save_Uni(Unis, nums_Uni);
			system("pause");
			print_Uni();
			break;
		}
		case 2://删除群组		//完成
		{
			printf("请输入要添加的群组序号：");
			int number;
			while (1)//检查输入的序号是否合法
			{
				scanf("%d", &number);
				if (number >= 1 && number <= nums_Uni)
					break;
				else
					printf("输入错误！请重新输入：");
			}
			char tstr[50] = " 将删除群组-> ";
			strcat(tstr, Unis[number - 1]);
			print_YesOrNo(tstr);//删除提示
			if (YesOrNo(0))
			{
				for (int i = 0; i < nums_cont; i++)
					if (strcmp(Unis[number - 1], cont[i]->Uni) == 0)
						strcpy(cont[i]->Uni, "无");//修改属于该群组的联系人
				for (int i = number - 1; i < nums_cont; i++)
					Unis[i] = Unis[i + 1];//删除群组
				nums_Uni--;
				printf("删除成功！\n");
				save_file(cont, nums_cont);
				save_Uni(Unis, nums_Uni);
				system("pause");
			}
			print_Uni();
			break;
		}
		case 3://修改群组
		{
			printf("请输入要修改的群组序号：");
			int number;
			while (1)
			{
				scanf("%d", &number);
				getchar();
				if (number >= 1 && number <= nums_Uni)
					break;
				else
					printf("输入错误！请重新输入：");
			}
			printf("修改为：");
			while (1)
			{
				gets(t_Uname);
				if (strlen(t_Uname) == 0)
					printf("群组名称不能空！：");
				else if (strcmp(t_Uname, "无") == 0)
					printf("群组名称不能设置为“无”：");
				else if (isUniExist(t_Uname))
					printf("该群组已存在，请重新输入：");
				else break;
			}
			for (int i = 0; i < nums_cont; i++)
				if (strcmp(Unis[number - 1], cont[i]->Uni) == 0)
					strcpy(cont[i]->Uni, t_Uname);//修改属于该群组的联系人
			strcpy(Unis[number-1], t_Uname);
			printf("修改成功！\n");
			save_file(cont, nums_cont);
			save_Uni(Unis, nums_Uni);
			system("pause");
			print_Uni();
			break;
		}
		case 4:
		{
			int tmp;
			printf("请输入需要查看群组前的序号：");
			while (1)
			{
				scanf("%d", &tmp);
				if (tmp <= 0 || tmp > nums_Uni)
					printf("输入错误：");
				else
					break;
			}
			int cnt = 0;
			for (int i = 0; i < nums_cont; i++)
			{
				if (strcmp(cont[i]->Uni, Unis[tmp - 1]) == 0)//属于群组
				{
					cnt++;
					printf("%s %s %s %s %s\n", cont[i]->telenumber,
						cont[i]->name, cont[i]->age, cont[i]->sex, cont[i]->home);
				}
			}
			printf("共%d位联系人属于该群组\n", cnt);
			system("pause");
			print_Uni();
			break;
		}
		case 5://导出群组		//完成
		{
			int tmp;
			printf("请输入需要导出群组前的序号：");
			while (1)
			{
				scanf("%d", &tmp);
				if (tmp <= 0 || tmp > nums_Uni)
					printf("输入错误：");
				else
					break;
			}
			output_Uni(cont, nums_cont, Unis[tmp-1]);//导出文件
			system("pause");
			print_Uni();
			break;
		}
		case 0:
			return_manu();
			return;
		default:
			printf("非法输入！ 请重新输入：");
			break;
		}
	}
}