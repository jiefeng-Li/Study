#pragma once
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_NAME 10//���ֳ���
#define MAX_SEX 5//�Ա����Ƴ���A
#define MAX_HOME 40//��ͥ���Ƴ���
#define MAX_Uni 15//Ⱥ�����Ƴ���
#define MAX_NUM_CONTACT 500//��ϵ�������
#define TRUE 1
#define FALSE 0

typedef struct Peo//��ϵ��
{
	char telenumber[20];//�绰����
	char name[MAX_NAME];//����
	char age[5];//����
	char sex[MAX_SEX];//�Ա�
	char home[MAX_HOME];//��ͥ��ַ
	char Uni[MAX_Uni];//Ⱥ������
}Peo;

void print_YesOrNo(char str[]);//ȷ�Ͻ���
void print_manu();//��ӡ�˵�
void print_exit();//��ӡ�˳�����
void print_adding();//ȷ�������ϵ��
void print_finding();//���ҽ���
void print_Uni();//Ⱥ����Ϣ������ѡ��