#pragma once
#include "Show.h"

int YesOrNo(int num);											//�Ƿ��ѡ����
int isUniExist(char Uniname[]);									//���Ⱥ���Ƿ����
int get_inf_contact(Peo* cont[]);								//�����ϵ����Ϣ
int get_inf_Uni(char* Unis[]);									//���Ⱥ����Ϣ
int output_Uni(Peo* cont[], int conts, char Uni_name[]);		//����Ⱥ���е���ϵ��
void goto_exit();												//�˳�����
void return_manu();												//���ز˵�
void sort_Peo_Uni();											//�Դ���Ⱥ�����Ƶ��ļ�����
void sort_Peo_name();											//�Դ�����ϵ�����Ƶ��ļ�����
void save_file(Peo* cont[], int conts);							//�����ļ�
void save_Uni(char* Unis[], int nums_Uni);						//����Ⱥ��
void easy_list(Peo* cont[], int conts);							//�򵥵Ĵ�ӡ����ǰ���е���ϵ��
void easy_del(Peo* cont[], int conts, int sub);					//�򵥵���ϵ��ɾ������
void easy_reset(Peo* cont[], int conts, int sub);				//�򵥵���ϵ����Ϣ�޸�
void easy_func(Peo* cont[], int* conts, int sub);				//�����������ֹ���

//-----main_function.c��---------//			��ת����Ҫ�Ĺ�����ȥ
void goto_Uni();
void goto_adding();
void goto_deling();
void goto_finding();
void goto_listing();
void goto_reseting();
//-------------------------------//