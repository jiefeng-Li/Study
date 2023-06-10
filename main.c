#define _CRT_SECURE_NO_WARNINGS 1
#include "Function.h"

int main()
{//程序开始对联系人信息和群组进行排序
	sort_Peo_Uni();
	sort_Peo_name();
	print_manu();
	int key = 1;
	printf("请输入数字来选择功能：");
	while (1)
	{
		scanf("%d", &key);
		switch (key)
		{
		case 1:
		{
			print_YesOrNo("添加联系人        ");
			if (YesOrNo(1))//添加联系人
				goto_adding();
			break;
		}
		case 2:
		{
			print_YesOrNo("删除联系人        ");
			if (YesOrNo(1))//删除联系人
				goto_deling();
			break;
		}
		case 3:
		{
			print_YesOrNo("查找联系人        ");
			if (YesOrNo(1))//查找联系人
				goto_finding();
			break;
		}
		case 4:
		{
			print_YesOrNo("查看所有联系人    ");
			if (YesOrNo(1))//查看联系人
				goto_listing();
			break;
		}
		case 5:
		{
			print_YesOrNo("修改联系人        ");
			if (YesOrNo(1))//修改联系人
				goto_reseting();
			break;
		}
		case 6:
		{
			print_YesOrNo(" 群组信息管理     ");
			if (YesOrNo(1))
				goto_Uni();
			break;
		}
		case 0:
			goto_exit();//退出系统
			break;
		default:
			printf("输入错误请重新输入：");
			break;
		}
	}
	return 0;
}