#define _CRT_SECURE_NO_WARNINGS 1
#include "Function.h"
//�˳�
void goto_exit()
{
	print_exit();
	int tmp = -1;
	printf("������������ѡ���ܣ�\n");
	while (1)
	{
		scanf("%d", &tmp);
		if (tmp == 1)
		{
			printf("�����˳�ϵͳ����");
			Sleep(750);
			system("cls");
			printf("���˳���\n");
			exit(0);
		}
		else if (tmp == 0)
		{
			return_manu();
			break;
		}
		else
			printf("����������������룺\n");
	}
}
//ȷ��ȡ����ѡ����
int YesOrNo(int num)//����1��0---ʹ�û�ʹ��return_manu()���
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
			printf("����������������룺\n");
	}
}
//�õ���ϵ�˵���Ϣ
int get_inf_contact(Peo* cont[])
{
	int i = 0;//��ϵ����
	FILE* fp = fopen("E:\\����ͨѶ¼�������\\Project1\\��ϵ��Ŀ¼\\Ĭ����ϵ��Ŀ¼.txt", "r");
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
	return i;//�Ѿ���ӵ���ϵ������//
}
//�õ�Ⱥ����Ϣ
int get_inf_Uni(char *Unis[])
{
	int i = 0;//�Ѿ���ӵ�Ⱥ�����
	FILE* fp = fopen("E:\\����ͨѶ¼�������\\Project1\\��ϵ��Ŀ¼\\Ⱥ������.txt", "r");
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
	return i;//�Ѿ���ӵ�Ⱥ�����
}
//���ز˵�
void return_manu()
{
	printf("���ڷ��ز˵�����");
	Sleep(750);
	print_manu();
	printf("������������ѡ���ܣ�");
}//���ú����return���ʹ��

void easy_list(Peo* cont[], int conts)//�򵥵��г���ǰ�����е�ȫ����Ա
{
	printf("================================================\n");
	for (int j = 0; j < conts; j++)
	{
		printf("[%2d] %s %s %s %s %s ", j + 1,
			cont[j]->telenumber, cont[j]->name, cont[j]->age, cont[j]->sex, cont[j]->home);
		if (strcmp(cont[j]->Uni, "��") != 0)
			puts(cont[j]->Uni);
		else
			puts("");
	}
	printf("================================================\n");
}

void easy_del(Peo* cont[], int conts, int sub)//��ϵ��+��ϵ����+��Ҫɾ������ϵ���±�
{
	if (sub < 0 || sub > conts)
	{
		printf("ɾ��ʱ�����ݴ���\n");
		return;
	}
	if (sub == conts - 1)
	{
		free(cont[sub]);
	}
	for (int i = sub; i + 1 < conts; i++)
	{
		cont[i] = cont[i + 1];//���������ϵ��������ǰ����
	}
}//�򵥵�ɾ�����ܣ���������һЩ�޸ģ����ң��鿴����Ҫ���м�ɾ������

void easy_reset(Peo* cont[], int conts, int sub)//��ϵ��+��ϵ����+��Ҫ�޸ĵ���ϵ���±�
{
	if (sub < 0 || sub + 1 > conts)
	{
		printf("����ĸ���Ŵ���\n");
		Sleep(750);
		return;
	}
	memset(cont[sub], 0, sizeof(Peo));
	system("cls");
	while (1)
	{
		printf("================================================\n");
		printf("�绰��");
		memset(cont[sub]->telenumber, 0, sizeof(cont[sub]->telenumber));
		gets(cont[sub]->telenumber);
		if (strlen(cont[sub]->telenumber) != 11)
		{
			printf("�绰�������ô������������롭��");
			Sleep(1000);
			system("cls");
		}
		else if (strlen(cont[sub]->telenumber) == 11)
			break;
	}
	printf("================================================\n");
	printf("��ע��");
	gets(cont[sub]->name);
	if (cont[sub]->name[0] == '\0')
		strcpy(cont[sub]->name, "δ֪");
	printf("================================================\n");
	printf("���䣺");
	while (1)
	{
		gets(cont[sub]->age);
		if (cont[sub]->age[0] == '\0')
		{
			strcpy(cont[sub]->age, "δ֪");
			break;
		}
		int i = 0;
		for (i = 0; i < strlen(cont[sub]->age); i++)
		{
			if (cont[sub]->age[i] > '9' || cont[sub]->age[i] < '0')
			{
				printf("�������ô����������룺");
				memset(cont[sub]->age, 0, sizeof(cont[sub]->age));
				i = -1;//�������ô���--�����
				break;
			}
		}
		if (i == -1)
			continue;
		else
			break;
	}
	printf("================================================\n");
	printf("�Ա�");
	gets(cont[sub]->sex);
	if (cont[sub]->sex[0] == '\0')
		strcpy(cont[sub]->sex, "δ֪");
	printf("================================================\n");
	printf("��ͥסַ��");
	gets(cont[sub]->home);
	if (cont[sub]->home[0] == '\0')
		strcpy(cont[sub]->home, "δ֪");
	printf("================================================\n");
	printf("Ⱥ�飺");
	gets(cont[sub]->Uni);
	while (1)
	{
		if (strlen(cont[sub]->Uni) == 0)
		{
			strcpy(cont[sub]->Uni, "��");
			break;
		}
		else if (strcmp(cont[sub]->Uni, "��") == 0)
		{
			printf("Ⱥ�����Ʋ���Ϊ\"��\"��");
			gets(cont[sub]->Uni);
		}
		else if (!isUniExist(cont[sub]->Uni))
		{
			printf("��Ⱥ�鲻���ڣ����������룺");
			gets(cont[sub]->Uni);
		}
		else
			break;
	}
	printf("================================================\n");
	printf("�޸ĳɹ�\n");
	Sleep(250);
}//�򵥵��޸Ĺ��ܣ���������һЩ���ң��鿴����Ҫ���м��޸Ĳ���---���ִ�����Դ��goto_adding();

void easy_Uni(Peo* cont[], int sub)
{
	system("cls");
	printf("���и���ϵ�˵�Ⱥ�������\n1.�޸�\t2.�˳�\t\n");
	int key = 0;
	while (1)
	{
		scanf("%d", &key);
		getchar();
		switch (key)
		{
		case 1:
		{
			printf("��ǰȺ�飺%s\n", cont[sub]->Uni);
			printf("�޸�Ϊ��");
			gets(cont[sub]->Uni);
			while (1)//����޸ĵ������Ƿ���ȷ
			{
				if (strlen(cont[sub]->Uni) == 0)
				{
					strcpy(cont[sub]->Uni, "��");
					return;
				}
				else if (strcmp(cont[sub]->Uni, "��") == 0)
				{
					printf("Ⱥ�����Ʋ���Ϊ\"��\"��");
					gets(cont[sub]->Uni);
				}
				else if (!isUniExist(cont[sub]->Uni))
				{
					printf("��Ⱥ�鲻���ڣ����������룺");
					gets(cont[sub]->Uni);
				}
				else
					return;
			}
		}
		case 2:
			strcpy(cont[sub]->Uni, "��");
			return;
		default:
			printf("����������������룺");
			break;
		}
	}
}

void save_file(Peo* cont[], int conts)
{
	FILE* fp = fopen("E:\\����ͨѶ¼�������\\Project1\\��ϵ��Ŀ¼\\Ĭ����ϵ��Ŀ¼.txt", "w");
	for (int i = 0; i < conts; i++)
	{
		fprintf(fp, "%s %s %s %s %s %s\n", cont[i]->telenumber, cont[i]->name, cont[i]->age,
			cont[i]->sex, cont[i]->home, cont[i]->Uni);
	}
	fclose(fp);
}

void save_Uni(char* Unis[], int nums_Uni)
{
	FILE* fp = fopen("E:\\����ͨѶ¼�������\\Project1\\��ϵ��Ŀ¼\\Ⱥ������.txt", "w");
	for (int i = 0; i < nums_Uni; i++)
		fprintf(fp, "%s\n", Unis[i]);
	fclose(fp);//�����ļ�
}

void easy_func(Peo* cont[], int* conts, int sub)//��ϵ��+��ϵ������+��Ҫ�������±�
{
	system("cls");
	printf("================================================\n");
	printf("�绰\t����\t����\t�Ա�\tȺ��\n");
	printf("%s\t%s\t%s\t%s\t%s\t%s\n", cont[sub]->telenumber, cont[sub]->name, cont[sub]->age, 
		cont[sub]->sex, cont[sub]->home, cont[sub]->Uni);
	printf("================================================\n");
	printf("ѡ��Ҫ�Ը���ϵ�˵Ĳ�����\n1.�޸�\t2.ɾ��\t3.Ⱥ��\n");
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
			printf("�����ɹ���\n");
			system("pause");
			return;
		}
		case 3:
		{
			easy_Uni(cont, sub);
			printf("�����ɹ���\n");
			system("pause");
			return;
		}
		default:
			printf("��������������룺");
			break;
		}
	}
}

int output_Uni(Peo* cont[], int conts, char Uni_name[])
{
	int tmp = 0;//��¼����Uni_nameȺ�������
	char filename[100] = "E:\\����ͨѶ¼�������\\Project1\\��ϵ��Ŀ¼\\�����ļ�\\";
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
		fprintf(fp, "��Ⱥ��������ϵ��!\n");
	else
		fprintf(fp, "���С�%d��λ��ϵ��\n", tmp);
	printf("�����ɹ���\n");
	fclose(fp);
	return tmp;
}

int isUniExist(char Uniname[])//��鴫���Ⱥ�������Ƿ����
{
	char* Unis[MAX_NUM_CONTACT];
	int nums_Uni/*Ⱥ�����*/ = get_inf_Uni(Unis);//��ȡȺ������
	for (int i = nums_Uni - 1; i >= 0; i--)
	{
		if (strcmp(Uniname, Unis[i]) == 0)
			return TRUE;
	}
	return FALSE;
}