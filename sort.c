#define _CRT_SECURE_NO_WARNINGS 1
#include "Function.h"

void sort_Peo_name()//���
{
	int nums_cont = 0;//��ϵ������
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
	}//ð������
	save_file(cont, nums_cont);//�����ļ�
}

void sort_Peo_Uni()//���
{
	FILE* fp = fopen("E:\\����ͨѶ¼�������\\Project1\\��ϵ��Ŀ¼\\Ⱥ������.txt", "r");
	char Uni_name[MAX_NUM_CONTACT][MAX_Uni];//����Ⱥ������
	int num = 0;//�Ѿ�����˵�Ⱥ�����
	for (int i = 0; ; i++)
	{
		if (fscanf(fp, "%s\n", Uni_name[i]) != 1)
		{
			num = i;//�Ѿ�����˵�Ⱥ�����
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
	}//ѡ������
	fclose(fp);
	fp = fopen("E:\\����ͨѶ¼�������\\Project1\\��ϵ��Ŀ¼\\Ⱥ������.txt", "w");
	for (int i = 0; i < num; i++)
		fprintf(fp, "%s\n", Uni_name[i]);
	fclose(fp);
}