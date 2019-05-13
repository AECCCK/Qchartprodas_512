
#pragma once
#ifndef EPHL_LIB_H
#define EPHL_LIB_H
/*                              **************
|******************************** EPHL_lib.h *********************************
|*                              **************
|*
|*  Author: Franck Fauvel, MDS Aero Support Corporation
|*
|*  Description:
|*    This file contains the declarations of the functions which can be called
|*    from C and Fortran programs to access CVT channel values.
|*
|*  Interface Functions:
|*
|*  Notes:
|*    For ANSI C compilation, "ANSI_C" must be defined to compiler (typically
|*    using "-D ANSI_C" on the compiler command line).
|*    ANSI_dec.h is unreleased software and cannot be used here.
|*
|*  Date created: Tue Feb 14 18:24:31 1995
|*
|*  Related documents:
|*
|*  Modification history:
|*   Date       Initial  NCR#    Function Name     Description
|*   ----       -------  ------  -------------     -----------
|*   27 Feb 96  RB               none              Added SCCS identification
|*   20 Mar 96  FF               none              Added eEPHL_RETURN,
|*                                                 eEPHL_RW, eEPHL_CONN_TYPE,
|*                                                 EPHL_MAX_HBT_ERR, EPHL_BAD_VALUE
|*    9 Oct 96  KP               none              ANSI conversion
|*   23 Oct 96  KP               none              ANSI conversion
|*    9 Jan 97  RB               none              Remove ANSI_dec.h (unreleased)
|*   11 Feb 97  QC               none              Added EPHL_HEADER structure,
|*                                                 EPHL_HEADER_LEN, and function
|*                                                 prototype for EPHL_read_header
|*   24 Feb 97  RB               none              Removed freshly inserted tabs
|*   29 Mar 97  RB               none              Added note to EPHL_BAD_VALUE
|*    3 Apr 97  MP               none              Added IPC timeout values forclient
|*    7 May 97  QC               none              Removed duplicate prototypes                                                   :
|*                                                 EPHL_write_list_addr();
|*                                                 EPHL_read_list_addr();
|*   14 May 97  TT      A1504    NA                Added SCCS variables.
|*   20 May 97  QC      A1514    EPHL_close        Added function prototype
|*    3 Jun 97  QC      A1699    none              Modified EPHL_HEADER structure
|*                                                 to include test name
|*   17 Jun 97  TT      A1176    NA                ANSI coversion
|*   21 Aug 97  QC      A1352    NA                Changed EPHL_HEADER_LEN to
|*                                                 60
|*   01 Dec 97  RS      A3441    NA                Added test_id to the
|*                                                 EPHL_HEADER structure
|*   21 Aug 00  SB                                 Add Win32 struct and include
|*                                                   lv_struct.h
|*   24 Aug 00  SB                                 Add EPHL_NOT_INIT error definition
|*   14 Jan 03  MZ      A7762    N/A               Add eEX_OPCODE
|*   23 Jun 04  BQ      12014    N/A               Add C++ support
|*   05 May 05  MZ      13216    N/A               Added new opcode and interface function
|*   14 Jan 05  AC      16049    N/A               Added new integer type
|****************************************************************************/
/* DO NOT REMOVE THE FOLLOWING SCCS ID DECLARATION */
/* SCCS id variable that shows up when "what" is used on this executable */
static char EPHL_lib_h[] = "@(#) EDASNG:include/$RCSfile: EPHL_lib.h,v $; Version $Revision: 33010 $; extracted $Date: 2014-10-22 15:32:45 -0400 (Wed, 22 Oct 2014) $, MDS Aero";

//#ifdef _WIN32
//#include "LV_strucs.h"       // Include file for labview type
//#endif /* _WIN32 */

#define  EPHL_CLI_TIMEOUT    10  /* EX_driver IPC Client Timeout value (sec) */

#ifndef _PRODAS
#define EPHL_HOST "edas_rt"
#else
#define EPHL_HOST "rtehost"
#endif

/* If you change this define, need to be update in the LabView Ext
    Hook wrapper for all string define with this size. */
#define EPHL_UNIT_LEN 26

    /* If you change this define, need to be update in the LabView Ext
         Hook wrapper for all string define with this size. */
#define EPHL_HEADER_LEN 60

         /* opcode to call the External Hooks Server */
typedef enum {
    /* 0 */   EX_GET_ADDR,
    /* 1 */   EX_WRITE_VAL_NAME,
    /* 2 */   EX_READ_VAL_NAME,
    /* 3 */   EX_WRITE_VAL_ADDR,
    /* 4 */   EX_READ_VAL_ADDR,
    /* 5 */   EX_READ_INFO_NAME,
    /* 6 */   EX_QUIT,
    /* 7 */   EX_RW_VAL_NAME,
    /* 8 */   EX_GET_HBT_ERR,
    /* 9 */   EX_READ_HEADER,
    /* 10 */  EX_WRITE_VQ_NAME,
    /* 11 */  EX_READ_VQ_NAME,
    /* 12 */  EX_WRITE_VQ_ADDR,
    /* 13 */  EX_READ_VQ_ADDR,
    /* 14 */  EX_RW_VQ_NAME
} eEX_OPCODE;

/* typedef defining the channel type */
typedef enum {
    EPHL_FP_CHAN,
    EPHL_DISC_CHAN,
    EPHL_INT_CHAN
} eEPHL_CHAN_TYPE;

/* structure returned by EPHL_read_channel_info */
/* and EPHL_read_list_info */
typedef struct {
    float            scan_rate;
    eEPHL_CHAN_TYPE  chan_type;
    char             unit[EPHL_UNIT_LEN];
    char             pad1[4 - (EPHL_UNIT_LEN % 4)];
    float            min;
    float            max;
} EPHL_CHAN_INFO;

/* structure returned by EPHL_read_header */
typedef struct {
    char             engine_name[EPHL_HEADER_LEN];
    char             test_name[EPHL_HEADER_LEN];
    char             testcell_name[EPHL_HEADER_LEN];
    char             eng_serial_num[EPHL_HEADER_LEN];
    char             eng_build_num[EPHL_HEADER_LEN];
    int              test_id;
}EPHL_HEADER;

//#ifdef _WIN32
/* bundle returned by EPHL_read_header_lv, specific to LabView */
//typedef struct {
//  LStrHandle       engine_name;
 // LStrHandle       test_name;
 // LStrHandle       testcell_name;
 // LStrHandle       eng_serial_num;
 // LStrHandle       eng_build_num;
//  int32            test_id;
//} EPHL_HEADER_LV;

/* structure returned by EPHL_read_channel_info_lv*/
/* and EPHL_read_list_info_lv, specific to LabView*/
//typedef struct {
 // FP32_ARR_HDL     scan_rate;
 // I32_ARR_HDL      chan_type;
 // STR_ARR_HDL      unit;
//  FP32_ARR_HDL     min;
//  FP32_ARR_HDL     max;
//} EPHL_CHAN_INFO_ARRAY_LV;

//typedef struct {
//  float32          scan_rate;
//  int32            chan_type;
///  LStrHandle       unit;
//  float32          min;
//  float32          max;
//} EPHL_CHAN_INFO_LV;

//#endif /* _WIN32 */


/* return code from External Hooks Server to client */
/* contained in reply buffer ( first 4 bytes ) */
/* and return code from EPHL interface functions */
typedef enum {
    EPHL_NOT_CONNECTED = -1,
    EPHL_OK,
    EPHL_ERROR,
    EPHL_BAD_MODE,
    EPHL_NEW_CONFIG,
    EPHL_NOT_CONFIGURED,
    EPHL_BAD_CHANNEL,
    EPHL_NOT_INIT
} eEPHL_RETURN;

/* type of operation to do on a channel */
typedef enum {
    EPHL_READ,
    EPHL_WRITE
} eEPHL_RW;

/* type of connection */
typedef enum {
    EPHL_SOCKET,
    EPHL_SH_MEM
} eEPHL_CONN_TYPE;

/* max length of heartbeat and error channel names */
#define EPHL_MAX_HBT_ERR  41

/* value for a bad channel */
#define EPHL_BAD_VALUE    -99999.0
/* NOTE: should be the same definition as BAD_VALUE in the EDAS CVT */

#ifdef __cplusplus
extern "C"
{
#endif

    /* Use "-D ANSI_C" on compile line to use ANSI C */
#ifdef ANSI_C

/* ANSI C compiler function declarations */
    extern eEPHL_RETURN EPHL_write_channel(char* name, float value);
    extern eEPHL_RETURN EPHL_write_list(int num_ch, char** names,
        float* values);
    extern eEPHL_RETURN EPHL_read_channel(char* name, float* value);
    extern eEPHL_RETURN EPHL_read_list(int num_ch, char** names,
        float* values);
    extern eEPHL_RETURN EPHL_get_addr(int num_ch, char** names,
        int* addresses);
    extern eEPHL_RETURN EPHL_write_list_addr(int num_ch, int *addr,
        float* values);
    extern eEPHL_RETURN EPHL_read_list_addr(int num_ch, int *addr,
        float* values);
    extern eEPHL_RETURN EPHL_read_channel_info(char* name,
        EPHL_CHAN_INFO* info);
    extern eEPHL_RETURN EPHL_read_list_info(int num_ch, char** names,
        EPHL_CHAN_INFO* infos);
    extern eEPHL_RETURN EPHL_rw_list(int num_ch, char** names,
        float* values, eEPHL_RW* rw_list);
    extern eEPHL_RETURN EPHL_get_hbt_err(char* hbt_channel, int hbt_len,
        char* err_channel, int err_len);
    extern eEPHL_RETURN EPHL_init(eEPHL_CONN_TYPE conn_type,
        char* serv_key);
    extern eEPHL_RETURN EPHL_read_header(EPHL_HEADER* header_info);
    extern eEPHL_RETURN EPHL_close(void);

    extern eEPHL_RETURN EPHL_write_channel_vq(char* name, float value, int quality);
    extern eEPHL_RETURN EPHL_write_list_vq(int num_ch, char** names,
        float* values, int *qualities);
    extern eEPHL_RETURN EPHL_read_channel_vq(char *name, float *value, int *quality);
    extern eEPHL_RETURN EPHL_read_list_vq(int num_of_ch, char **names,
        float *values, int *qualities);
    extern eEPHL_RETURN EPHL_write_list_addr_vq(int num_ch, int *addr,
        float* values, int *qualities);
    extern eEPHL_RETURN EPHL_read_list_addr_vq(int num_ch, int *addr,
        float* values, int *qualities);
    extern eEPHL_RETURN EPHL_rw_list_vq(int num_of_ch, char **names, float *values,
        int *qualities, eEPHL_RW *rw_list);

#ifndef _WIN32
    extern int EPHL_write_channel_(char* name, float* value, int name_sz);
    extern int EPHL_write_list_(int* num_ch, char** names, float* vals,
        int name_sz);
    extern int EPHL_read_channel_(char *name, float* val, int name_sz);
    extern int EPHL_read_list_(int* num_ch, char** names, float* vals,
        int name_sz);
    extern int EPHL_init_(int conn_type, char* serv_key,
        int serv_key_size);
#endif /* _WIN32 */

#ifdef _WIN32
    extern eEPHL_RETURN EPHL_write_list_lv(STR_ARR_HDL All_Channel_Names,
        float *values);
    extern eEPHL_RETURN EPHL_read_list_lv(STR_ARR_HDL All_Channel_Names,
        float *values);
    extern eEPHL_RETURN EPHL_rw_list_lv(STR_ARR_HDL All_Channel_Names,
        float *values, eEPHL_RW *rw_list);
    extern eEPHL_RETURN EPHL_get_addr_lv(STR_ARR_HDL All_Channel_Names,
        int *addresses);
    extern eEPHL_RETURN EPHL_read_header_lv(EPHL_HEADER_LV *header_info);
    extern eEPHL_RETURN EPHL_read_list_info_lv(STR_ARR_HDL All_Channel_Names,
        EPHL_CHAN_INFO_ARRAY_LV *infos);
    extern eEPHL_RETURN EPHL_read_channel_info_lv(char *name,
        EPHL_CHAN_INFO_LV *infos);



#endif /* _WIN32 */

    /* Non-ANSI C compiler function declarations */
#else

    extern eEPHL_RETURN EPHL_write_channel();
    extern eEPHL_RETURN EPHL_write_list();
    extern eEPHL_RETURN EPHL_read_channel();
    extern eEPHL_RETURN EPHL_read_list();
    extern eEPHL_RETURN EPHL_get_addr();
    extern eEPHL_RETURN EPHL_write_list_addr();
    extern eEPHL_RETURN EPHL_read_list_addr();
    extern eEPHL_RETURN EPHL_read_channel_info();
    extern eEPHL_RETURN EPHL_read_list_info();
    extern eEPHL_RETURN EPHL_rw_list();
    extern eEPHL_RETURN EPHL_get_hbt_err();
    extern eEPHL_RETURN EPHL_init();
    extern eEPHL_RETURN EPHL_read_header();
    extern eEPHL_RETURN EPHL_close();
    extern eEPHL_RETURN EPHL_write_channel_vq();
    extern eEPHL_RETURN EPHL_write_list_vq();
    extern eEPHL_RETURN EPHL_read_channel_vq();
    extern eEPHL_RETURN EPHL_read_list_vq();
    extern eEPHL_RETURN EPHL_write_list_addr_vq();
    extern eEPHL_RETURN EPHL_read_list_addr_vq();
    extern eEPHL_RETURN EPHL_rw_list_vq();



#ifndef _WIN32  /* in a dll, only C can be used! */
    extern int EPHL_write_channel_();
    extern int EPHL_write_list_();
    extern int EPHL_read_channel_();
    extern int EPHL_read_list_();
    extern int EPHL_init_();
#endif /* _WIN32 */

#ifdef _WIN32
    extern eEPHL_RETURN EPHL_write_list_lv();
    extern eEPHL_RETURN EPHL_read_list_lv();
    extern eEPHL_RETURN EPHL_rw_list_lv();
    extern eEPHL_RETURN EPHL_get_addr_lv();
    extern eEPHL_RETURN EPHL_read_header_lv();
    extern eEPHL_RETURN EPHL_read_list_info_lv();
    extern eEPHL_RETURN EPHL_read_channel_info_lv();


#endif /* _WIN32 */

#endif
#ifdef __cplusplus
}
#endif

#endif /* EPHL_LIB_H */
/************************ THIS IS THE END OF THE FILE ***********************/



