#pragma once
#include "Show.h"

int YesOrNo(int num);											//是否的选择功能
int isUniExist(char Uniname[]);									//检查群组是否存在
int get_inf_contact(Peo* cont[]);								//获得联系人信息
int get_inf_Uni(char* Unis[]);									//获得群组信息
int output_Uni(Peo* cont[], int conts, char Uni_name[]);		//导出群组中的联系人
void goto_exit();												//退出程序
void return_manu();												//返回菜单
void sort_Peo_Uni();											//对储存群组名称的文件排序
void sort_Peo_name();											//对储存联系人名称的文件排序
void save_file(Peo* cont[], int conts);							//保存文件
void save_Uni(char* Unis[], int nums_Uni);						//保存群组
void easy_list(Peo* cont[], int conts);							//简单的打印出当前已有的联系人
void easy_del(Peo* cont[], int conts, int sub);					//简单的联系人删除程序
void easy_reset(Peo* cont[], int conts, int sub);				//简单的联系人信息修改
void easy_func(Peo* cont[], int* conts, int sub);				//集合以上三种功能

//-----main_function.c中---------//			跳转到主要的功能中去
void goto_Uni();
void goto_adding();
void goto_deling();
void goto_finding();
void goto_listing();
void goto_reseting();
//-------------------------------//