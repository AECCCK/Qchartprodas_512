#pragma once
#ifndef EXTERNALHOOK_H
#define EXTERNALHOOK_H
#include <string>
#include"ephl_lib.h"


using namespace std;
//定义所有导出函数
typedef eEPHL_RETURN(*readfunc)(char* , float* );   //EPHL_read_channel
typedef eEPHL_RETURN(*initfunc)(eEPHL_CONN_TYPE , char* ); //EPHL_init
typedef eEPHL_RETURN(*closefunc)(void);    //EPHL_close
typedef eEPHL_RETURN(*write_channel)(char*, float);//EPHL_write_channel
typedef eEPHL_RETURN(*write_channel_vq)(char*, float, int); //EPHL__write_channel_vq
typedef eEPHL_RETURN(*write_list)(int, char**, float*);//EPHL_write_list
typedef eEPHL_RETURN(*write_list_vq)(int, char**, float*, int*);//EPHL_write_list_vq
typedef eEPHL_RETURN(*read_header)(EPHL_HEADER*); //EPHL_read_HEADER
typedef eEPHL_RETURN(*read_channel_vq)(char*, float*, int*); //EPHL_read_channel_vq
typedef eEPHL_RETURN(*read_list)(int, char**, float*);//EPHL_read_list
typedef eEPHL_RETURN(*read_list_vq)(int, char**, float*, int*);//EPHL_read_list_vq
typedef eEPHL_RETURN(*read_channel_info)(char*, EPHL_CHAN_INFO*);//EPHL_read_channel_info
typedef eEPHL_RETURN(*read_list_info)(int, char**, EPHL_CHAN_INFO*); //EPHL_read_list_info
typedef eEPHL_RETURN(*rw_list)(int, char**, float*, eEPHL_RW*);// EPHL_rw_list
typedef eEPHL_RETURN(*rw_list_vq)(int, char**, float*, int*, eEPHL_RW*);//EPHL_rw_list_vq
typedef eEPHL_RETURN(*write_list_addr)(int, int*, float*);//EPHL_write_list_addr
typedef eEPHL_RETURN(*write_list_addr_vq)(int, int*, float*, int*);//EPHL_write_list_addr_vq
typedef eEPHL_RETURN(*read_list_addr)(int, int*, float*);//EPHL_read_list_addr
typedef eEPHL_RETURN(*read_list_addr_vq)(int, int*, float*, int*);//EPHL_read_list_addr_vq





//void prodas_initial(void); //prodas_initial函数原型:初始化服务器与prodas链接
 //float通道函数原型:服务器从prodas提取通道名称和数值
//void prodas_close(void); //prodas_close函数原型:关闭服务器与prodas链接



#endif

 // EXTERNALHOOK_H


