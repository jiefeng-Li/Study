#define _CRT_SECURE_NO_WARNINGS 1
#include "Function.h"

void goto_adding()
{
	int nums_cont = 0;//��ϵ������
	Peo* cont[MAX_NUM_CONTACT];//��ϵ����Ϣ
	nums_cont = get_inf_contact(cont);

	print_adding();//�����ʾ������
	while (1)
	{
		Peo newpeo;
		memset(&newpeo, 0, sizeof(Peo));
		system("cls");
		while (1)
		{
			printf("================================================\n");
			printf("�绰��");
			memset(newpeo.telenumber, 0, sizeof(newpeo.telenumber));
			gets(newpeo.telenumber);
			if (strlen(newpeo.telenumber) != 11)
			{
				printf("�绰�������ô������������롭��");
				Sleep(1000);
				system("cls");
			}
			else if (strlen(newpeo.telenumber) == 11)//������õ绰�����Ƿ��Ѵ��ڵĹ���
				break;
		}
		printf("================================================\n");
		printf("��ע��");
		gets(newpeo.name);
		if (newpeo.name[0] == '\0')
			strcpy(newpeo.name, "δ֪");
		printf("================================================\n");
		printf("���䣺");
		while (1)
		{
			gets(newpeo.age);
			if (newpeo.age[0] == '\0')
			{
				strcpy(newpeo.age, "δ֪");
				break;

			}
			int i = 0;
			for (i = 0; i < strlen(newpeo.age); i++)//���������ַ������Ƿ���0~9֮����ַ�
			{
				if (newpeo.age[i] > '9' || newpeo.age[i] < '0')
				{
					printf("�������ô����������룺");
					memset(newpeo.age, 0, sizeof(newpeo.age));
					i = -1;//����оͰ�i��ֵΪ-1
					break;
				}
			}
			if (i == -1)//�зǷ��ַ�
				continue;
			else
				break;
		}
		printf("================================================\n");
		printf("�Ա�");
		gets(newpeo.sex);
		if (newpeo.sex[0] == '\0')
			strcpy(newpeo.sex, "δ֪");
		printf("================================================\n");
		printf("��ͥסַ��");
		gets(newpeo.home);
		if (newpeo.home[0] == '\0')
			strcpy(newpeo.home, "δ֪");
		printf("================================================\n");
		printf("Ⱥ�飺");
		gets(newpeo.Uni);
		while (1)
		{
			if (strlen(newpeo.Uni) == 0)
			{
				strcpy(newpeo.Uni, "��");
				break;
			}
			else if (strcmp(newpeo.Uni, "��") == 0)
			{
				printf("Ⱥ�����Ʋ���Ϊ\"��\"��");
				gets(newpeo.Uni);
			}
			else if (!isUniExist(newpeo.Uni))
			{
				printf("��Ⱥ�鲻���ڣ����������룺");
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
		printf("��ӳɹ���\n");
		system("pause");
		print_YesOrNo(" ���������ϵ��?  ");
		if (!(YesOrNo(1)))
			return;
	}
}

void goto_deling()//��ʱ��ɣ�
{
	system("cls");
	int nums_cont = 0;//��ϵ������
	Peo* cont[MAX_NUM_CONTACT];//��ϵ����Ϣ
	nums_cont = get_inf_contact(cont);

	easy_list(cont, nums_cont);
	printf("��������Ҫɾ������ϵ��������绰���룺");
	char t_inf[20];
	gets(t_inf);
	system("cls");
	printf("��������Ҫɾ������ϵ��������绰���룺%s\n", t_inf);
	while (1)
	{
		int hash[MAX_NUM_CONTACT] = {0};//��¼��ѯ������ϵ��---�Է�ɾ��ʱ��������
		int tmp = FALSE;//�Ƿ���ҳɹ�
		if (t_inf[0] == '\0')
		{
			printf("��Ϣ���벻��Ϊ�գ����������룺");
			continue;
		}
		printf("================================================\n");
		for (int i = 0; i < nums_cont; i++)
		{
			//int len = strlen(t_inf);
			char* p;
			p = strstr(cont[i]->telenumber, t_inf);
			if (p)//ƥ�䵽��ͬ��Ϣ
			{
				tmp = TRUE;//��Ϣƥ��ɹ�----���ΪTRUE
				hash[i]++;
				printf("[%2d] ", i + 1);
				for (int j = 0; j < 11; j++)
				{
					if (cont[i]->telenumber + j == p)
					{
						printf("\033[47;30m%s\033[0m", t_inf);//��ѯ������Ϣ��ɫ��ӡ
						j += strlen(t_inf);
					}
					printf("%c", cont[i]->telenumber[j]);
				}
				printf(" %s %s %s %s ", cont[i]->name, cont[i]->age, cont[i]->sex, cont[i]->home);//��ӡʣ����Ϣ
				if (strcmp(cont[i]->Uni, "��") != 0)
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
					tmp = TRUE;//��Ϣƥ��ɹ�----���ΪTRUE
					printf("[%2d] %s ", i + 1, cont[i]->telenumber);
					for (int j = 0; cont[i]->name[j] != '\0'; j++)
					{
						if (cont[i]->name + j == p)
						{
							printf("\033[47;30m%s\033[0m", t_inf);//��ѯ������Ϣ��ɫ��ӡ
							j += strlen(t_inf);
						}
						if (j < strlen(cont[i]->name))
							printf("%c", cont[i]->name[j]);
					}
					printf(" %s %s %s ", cont[i]->age, cont[i]->sex, cont[i]->home);//��ӡʣ����Ϣ
					if (strcmp(cont[i]->Uni, "��") != 0)
						puts(cont[i]->Uni);
					else
						puts("");
				}
			}
		}
		if (tmp == FALSE)
		{
			memset(t_inf, 0, 20);//����t_inf�е���Ϣ
			printf("δ���ҵ�\n");
		}
		printf("================================================\n");
		printf("׷����Ϣ(y/n):");
		char ch = getchar();
		getchar();
		while (1)
		{
			if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
				break;
			else
			{
				printf("�����������������(y/n):");
				ch = getchar();
				getchar();
			}
		}
		if (ch == 'y' || ch == 'Y')//ȷ��׷����Ϣ
		{
			char t[20] = {'\0'};
			printf("������Ҫ׷�ӵ���Ϣ��");
			gets(t);
			strcat(t_inf, t);
			system("cls");
			printf("��������Ҫɾ������ϵ��������绰���룺%s\n", t_inf);
		}
		else//ȡ��׷����Ϣ������ɾ������
		{
			int sub;
			printf("��������Ҫɾ������ϵ��ǰ�����(����0ȡ��):");
			scanf("%d", &sub);//��ţ�sub-1��Ϊ�±꣩
			while (1)
			{
				if (sub == 0)//ȡ��ɾ�������ز˵�
				{
					return_manu();
					return 0;
				}
				if (hash[sub - 1])//���Ϊsub����ϵ���ǲ�ѯ���ģ���ֹ����ɾ����
				{
					easy_del(cont, nums_cont--, sub - 1);
					printf("ɾ���ɹ���\n");
					save_file(cont, nums_cont);
					break;
				}
				else
				{
					printf("δ��ѯ������ŵ���ϵ�ˣ����������룺");
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
	printf("��ѡ���ѯ��ʽ��");
	int key;
	int nums_cont = 0;//��ϵ������
	Peo* cont[MAX_NUM_CONTACT];
	nums_cont = get_inf_contact(cont);
	while (1)
	{
		scanf("%d", &key);
		getchar();
		switch (key)
		{
		case 0://�˳�-----ok
			return_manu();
			return;
		case 1://����-----
		{
			while (1)
			{
				int nums = 0;//��¼���ѯ��Ϣ��ƥ�������
				short hash[MAX_NUM_CONTACT] = { 0 };//ȷ���������������Ǳ�����������ϵ�ˣ���ֹ�������
				char name[MAX_NAME];
				system("cls");
				printf("������:");
				gets(name);
				system("cls");
				printf("================================================\n");
				for (int i = 0; i < nums_cont; i++)
				{
					char* p = strstr(cont[i]->name, name);
					if (p)
					{
						hash[i]++;
						nums++;//��¼���ѯ��Ϣ��ƥ�������
						printf("[%2d] %s ", i + 1, cont[i]->telenumber);
						for (int j = 0; cont[i]->name[j] != '\0'; j++)
						{
							if (cont[i]->name + j == p)
							{
								printf("\033[47;30m%s\033[0m", name);//��ѯ������Ϣ��ɫ��ӡ
								j += strlen(name);
							}
							if (j < strlen(cont[i]->name))
								printf("%c", cont[i]->name[j]);
						}
						printf(" %s %s %s ", cont[i]->age, cont[i]->sex, cont[i]->home);//��ӡʣ����Ϣ
						if (strcmp(cont[i]->Uni, "��") != 0)
							puts(cont[i]->Uni);
						else
							puts("");
					}
				}
				printf("================================================\n");
				printf("[[[���ҵ�%d����\"%s\"��ص���ϵ��]]]\n", nums, name);
				if (nums == 0)
				{
					printf("�Ƿ��������룿(1/0)");
					if (YesOrNo(1))//��������
						continue;
					else//���ز˵�
						return;
				}
				int key = 0;
				printf("������ϵ��ǰ����Ų�����");
				while (1)
				{
					scanf("%d", &key);
					if (key == 0)
						break;
					if (key >= 1 && key <= nums_cont && hash[key-1])
					{
						easy_func(cont, &nums_cont, key - 1);//�򵥵Ĳ�����ɾ��+�޸�+Ⱥ�飨�޸�+�˳�����
						save_file(cont, nums_cont);//�����ļ�
						break;
					}
					else
						printf("��������������룺");
				}
				break;
			}
			print_finding();
			printf("��ѡ���ѯ��ʽ��");
			break;
		}
		case 2://�绰------ok
		{
			while (1)
			{
				system("cls");
				char tele[20];
				printf("������绰���룺");
				int nums = 0;//��¼���ѯ��Ϣ��ƥ�������
				short hash[MAX_NUM_CONTACT] = { 0 };//ȷ���������������Ǳ�����������ϵ�ˣ���ֹ�������
				gets(tele);
				printf("================================================\n");
				for (int i = 0; i < nums_cont; i++)
				{
					char* p = strstr(cont[i]->telenumber, tele);
					if (p)
					{
						hash[i]++;
						nums++;//��¼���ѯ��Ϣ��ƥ�������
						printf("[%2d] ", i + 1);
						for (int j = 0; cont[i]->telenumber[j] != '\0'; j++)
						{
							if (cont[i]->telenumber + j == p)
							{
								printf("\033[47;30m%s\033[0m", tele);//��ѯ������Ϣ��ɫ��ӡ
								j += strlen(tele);
							}
							if (j < strlen(cont[i]->telenumber))
								printf("%c", cont[i]->telenumber[j]);
						}
						printf(" %s %s %s %s", cont[i]->name, cont[i]->age, cont[i]->sex, cont[i]->home);//��ӡʣ����Ϣ
						if (strcmp(cont[i]->Uni, "��") != 0)
							puts(cont[i]->Uni);
						else
							puts("");
					}
				}
				printf("================================================\n");
				printf("[[[���ҵ�%d����\"%s\"��ص���ϵ��]]]\n", nums, tele);
				if (nums == 0)//��¼���ѯ��Ϣ��ƥ�������
				{
					printf("�Ƿ��������룿(1/0)");
					if (YesOrNo(1))//��������
						continue;
					else//���ز˵�
						return;
				}
				int key = 0;
				printf("������ϵ��ǰ����Ų�����");
				while (1)
				{
					scanf("%d", &key);
					if (key == 0)
						break;
					if (key >= 1 && key <= nums_cont && hash[key-1])
					{
						easy_func(cont, &nums_cont, key - 1);//�򵥵Ĳ�����ɾ��+�޸�+Ⱥ�飨�޸�+�˳�����
						save_file(cont, nums_cont);//�����ļ�
						break;
					}
					else
						printf("��������������룺");
				}
				break;
			}
			print_finding();
			printf("��ѡ���ѯ��ʽ��");
			break;
		}
		case 3://����
		{
			while (1)
			{
				short hash[MAX_NUM_CONTACT] = {0};//ȷ���������������Ǳ�����������ϵ�ˣ���ֹ�������
				system("cls");
				char t_age[5];
				printf("��������ҵ����䣺");
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
						printf("�������ô����������룺");
						continue;
					}
					else
						break;
				}
				int nums = 0;//��¼���ѯ��Ϣ��ƥ�������
				system("cls");
				printf("================================================\n");
				for (int sub = 0; sub < nums_cont; sub++)
				{
					if (strcmp(cont[sub]->age, t_age) == 0)
					{
						hash[sub]++;//���������������
						nums++;//��¼���ѯ��Ϣ��ƥ�������
						printf("[%2d] %s %s %s %s %s\n", sub + 1,
							cont[sub]->telenumber, cont[sub]->name, cont[sub]->age, cont[sub]->sex, cont[sub]->home);
					}
				}
				printf("================================================\n");
				printf("[[[���ҵ�%d����\"%s\"�����ϵ��]]]\n", nums, t_age);
				if (nums == 0)
				{
					printf("�Ƿ��������룿(1/0)");
					if (YesOrNo(1))//��������
						continue;
					else//���ز˵�
						return;
				}
				int key = 0;
				printf("������ϵ��ǰ����Ų�����");
				while (1)
				{
					scanf("%d", &key);
					getchar();
					if (key == 0)
						break;
					if (key >= 1 && key <= nums_cont && hash[key-1])
					{
						easy_func(cont, &nums_cont, key - 1);//�򵥵Ĳ�����ɾ��+�޸�+Ⱥ�飨�޸�+�˳�����
						save_file(cont, nums_cont);
						break;
					}
					else
						printf("��������������룺");
				}
			}
			print_finding();
			printf("��ѡ���ѯ��ʽ��");
			break;
		}
		case 4://��ͥ��ַ------ok
		{
			while (1)
			{
				short hash[MAX_NUM_CONTACT] = {0};//ȷ���������������Ǳ�����������ϵ�ˣ���ֹ�������
				int nums = 0;//��¼���ѯ��Ϣ��ƥ�������
				char t_home[MAX_HOME];
				printf("������:");
				gets(t_home);
				system("cls");
				printf("================================================\n");
				for (int i = 0; i < nums_cont; i++)
				{
					char* p = strstr(cont[i]->home, t_home);
					if (p)//��ѯ�ɹ�
					{
						hash[i]++;//���������������
						nums++;
						printf("[%2d] %s %s %s %s ", i + 1, cont[i]->telenumber, 
							cont[i]->name, cont[i]->age, cont[i]->sex);
						for (int j = 0; cont[i]->home[j] != '\0'; j++)
						{
							if (cont[i]->home + j == p)
							{
								printf("\033[47;30m%s\033[0m", t_home);//��ѯ������Ϣ��ɫ��ӡ
								j += strlen(t_home);
							}
							if (j < strlen(cont[i]->home))
								printf("%c", cont[i]->home[j]);
						}
						if (strcmp(cont[i]->Uni, "��") != 0)
							puts(cont[i]->Uni);
						else
							puts("");
					}
				}
				printf("================================================\n");
				printf("[[[���ҵ�%d����\"%s\"��ص���ϵ��]]]\n", nums, t_home);
				if (nums == 0)
				{
					printf("�Ƿ��������룿(1/0)");
					if (YesOrNo(1))//��������
						continue;
					else//���ز˵�
						return;
				}
				int key = 0;
				printf("������ϵ��ǰ����Ų�����");
				while (1)
				{
					scanf("%d", &key);
					if (key == 0)
						break;
					if (key >= 1 && key <= nums_cont && hash[key-1])
					{
						easy_func(cont, &nums_cont, key - 1);//�򵥵Ĳ�����ɾ��+�޸�+Ⱥ�飨�޸�+�˳�����
						save_file(cont, nums_cont);
						break;
					}
					else
						printf("��������������룺");
				}
				break;
			}
			print_finding();
			printf("��ѡ���ѯ��ʽ��");
			break;
		}
		default:
			printf("�Ƿ����룡 ���������룺");
			break;
		}
	}
	save_file(cont, nums_cont);//�����ļ�
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
		if (strcmp(cont[j]->Uni, "��") != 0)
			puts(cont[j]->Uni);
		else
			puts("");
	}
	printf("================================================\n");
	printf("�����%dλ��ϵ��\n", nums_cont);
	system("pause");
	return_manu();
	return 0;
}

void goto_reseting()//��ʱ���
{
	system("cls");
	int nums_cont = 0;
	Peo* cont[MAX_NUM_CONTACT];
	nums_cont = get_inf_contact(cont);
	easy_list(cont, nums_cont);
	printf("������Ҫ�޸ĵ���ϵ����ţ�����������ַ��˳�����");
	while (1)
	{
		int th = 0;
		if ((scanf("%d", &th)) != 1)
		{
			getchar();
			break;
		}
		else//ִ�����Ϊ th ����ϵ���޸�
		{
			getchar();
			easy_reset(cont, nums_cont, th - 1);//�޸�
			save_file(cont, nums_cont);//����
			system("cls");
			easy_list(cont, nums_cont);//�г�
			printf("������Ҫ�޸ĵ���ϵ����ţ�����������ַ��˳�����");//������ʾ
		}
	}
	return_manu();
	return 0;
}

void goto_Uni()
{
	char* Unis[MAX_NUM_CONTACT];
	int nums_Uni/*Ⱥ�����*/ = get_inf_Uni(Unis);//��ȡȺ������
	Peo* cont[MAX_NUM_CONTACT];
	int nums_cont/*��ϵ�˸���*/ = get_inf_contact(cont);//��ȡ��ϵ����Ϣ
	char* t_Uname = (char*)malloc(sizeof(char) * MAX_Uni);//��������������������Ⱥ������

	print_Uni();
	while (1)
	{
		int key;
		scanf("%d", &key);
		getchar();
		system("cls");
		if (key >= 1 && key <= 5)//��ӡ���е�Ⱥ��
		{
			printf("================================================\n");
			for (int i = 0; i < nums_Uni; i++)
				printf("[%d]\t%s\n", i + 1, Unis[i]);
			printf("================================================\n");
		}
		switch (key)
		{
		case 1://���Ⱥ��
		{
			printf("������Ҫ��ӵ�Ⱥ�����ƣ�");
			while (1)
			{
				gets(t_Uname);
				if (strlen(t_Uname) == 0)//��Ϣ��Ϊ��
					printf("������Ҫ��ӵ�Ⱥ�����ƣ�");
				else if (strcmp(t_Uname, "��") == 0)//��������λ���ޡ�
					printf("Ⱥ�����Ʋ�������Ϊ���ޡ���");
				else if (isUniExist(t_Uname))//��Ϊ�Ѿ����ڵ�Ⱥ��
					printf("��Ⱥ���Ѵ��ڣ����������룺");
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
			printf("��ӳɹ���\n");
			save_Uni(Unis, nums_Uni);
			system("pause");
			print_Uni();
			break;
		}
		case 2://ɾ��Ⱥ��		//���
		{
			printf("������Ҫ��ӵ�Ⱥ����ţ�");
			int number;
			while (1)//������������Ƿ�Ϸ�
			{
				scanf("%d", &number);
				if (number >= 1 && number <= nums_Uni)
					break;
				else
					printf("����������������룺");
			}
			char tstr[50] = " ��ɾ��Ⱥ��-> ";
			strcat(tstr, Unis[number - 1]);
			print_YesOrNo(tstr);//ɾ����ʾ
			if (YesOrNo(0))
			{
				for (int i = 0; i < nums_cont; i++)
					if (strcmp(Unis[number - 1], cont[i]->Uni) == 0)
						strcpy(cont[i]->Uni, "��");//�޸����ڸ�Ⱥ�����ϵ��
				for (int i = number - 1; i < nums_cont; i++)
					Unis[i] = Unis[i + 1];//ɾ��Ⱥ��
				nums_Uni--;
				printf("ɾ���ɹ���\n");
				save_file(cont, nums_cont);
				save_Uni(Unis, nums_Uni);
				system("pause");
			}
			print_Uni();
			break;
		}
		case 3://�޸�Ⱥ��
		{
			printf("������Ҫ�޸ĵ�Ⱥ����ţ�");
			int number;
			while (1)
			{
				scanf("%d", &number);
				getchar();
				if (number >= 1 && number <= nums_Uni)
					break;
				else
					printf("����������������룺");
			}
			printf("�޸�Ϊ��");
			while (1)
			{
				gets(t_Uname);
				if (strlen(t_Uname) == 0)
					printf("Ⱥ�����Ʋ��ܿգ���");
				else if (strcmp(t_Uname, "��") == 0)
					printf("Ⱥ�����Ʋ�������Ϊ���ޡ���");
				else if (isUniExist(t_Uname))
					printf("��Ⱥ���Ѵ��ڣ����������룺");
				else break;
			}
			for (int i = 0; i < nums_cont; i++)
				if (strcmp(Unis[number - 1], cont[i]->Uni) == 0)
					strcpy(cont[i]->Uni, t_Uname);//�޸����ڸ�Ⱥ�����ϵ��
			strcpy(Unis[number-1], t_Uname);
			printf("�޸ĳɹ���\n");
			save_file(cont, nums_cont);
			save_Uni(Unis, nums_Uni);
			system("pause");
			print_Uni();
			break;
		}
		case 4:
		{
			int tmp;
			printf("��������Ҫ�鿴Ⱥ��ǰ����ţ�");
			while (1)
			{
				scanf("%d", &tmp);
				if (tmp <= 0 || tmp > nums_Uni)
					printf("�������");
				else
					break;
			}
			int cnt = 0;
			for (int i = 0; i < nums_cont; i++)
			{
				if (strcmp(cont[i]->Uni, Unis[tmp - 1]) == 0)//����Ⱥ��
				{
					cnt++;
					printf("%s %s %s %s %s\n", cont[i]->telenumber,
						cont[i]->name, cont[i]->age, cont[i]->sex, cont[i]->home);
				}
			}
			printf("��%dλ��ϵ�����ڸ�Ⱥ��\n", cnt);
			system("pause");
			print_Uni();
			break;
		}
		case 5://����Ⱥ��		//���
		{
			int tmp;
			printf("��������Ҫ����Ⱥ��ǰ����ţ�");
			while (1)
			{
				scanf("%d", &tmp);
				if (tmp <= 0 || tmp > nums_Uni)
					printf("�������");
				else
					break;
			}
			output_Uni(cont, nums_cont, Unis[tmp-1]);//�����ļ�
			system("pause");
			print_Uni();
			break;
		}
		case 0:
			return_manu();
			return;
		default:
			printf("�Ƿ����룡 ���������룺");
			break;
		}
	}
}