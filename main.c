#define _CRT_SECURE_NO_WARNINGS 1
#include "Function.h"

int main()
{//����ʼ����ϵ����Ϣ��Ⱥ���������
	sort_Peo_Uni();
	sort_Peo_name();
	print_manu();
	int key = 1;
	printf("������������ѡ���ܣ�");
	while (1)
	{
		scanf("%d", &key);
		switch (key)
		{
		case 1:
		{
			print_YesOrNo("�����ϵ��        ");
			if (YesOrNo(1))//�����ϵ��
				goto_adding();
			break;
		}
		case 2:
		{
			print_YesOrNo("ɾ����ϵ��        ");
			if (YesOrNo(1))//ɾ����ϵ��
				goto_deling();
			break;
		}
		case 3:
		{
			print_YesOrNo("������ϵ��        ");
			if (YesOrNo(1))//������ϵ��
				goto_finding();
			break;
		}
		case 4:
		{
			print_YesOrNo("�鿴������ϵ��    ");
			if (YesOrNo(1))//�鿴��ϵ��
				goto_listing();
			break;
		}
		case 5:
		{
			print_YesOrNo("�޸���ϵ��        ");
			if (YesOrNo(1))//�޸���ϵ��
				goto_reseting();
			break;
		}
		case 6:
		{
			print_YesOrNo(" Ⱥ����Ϣ����     ");
			if (YesOrNo(1))
				goto_Uni();
			break;
		}
		case 0:
			goto_exit();//�˳�ϵͳ
			break;
		default:
			printf("����������������룺");
			break;
		}
	}
	return 0;
}