/*****************************************************************************
*                                                                            *
*  @file     duanxxType.h                                                    *
*  @brief    �Զ������                                                       *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-12                                                      *
*                                                                            *
*****************************************************************************/

#ifndef _DUANXX_TYPE_H_
#define _DUANXX_TYPE_H_

#include <stdlib.h>

typedef unsigned char   uchar;
typedef unsigned int    uint;
typedef unsigned long   ulong;

typedef enum _RET
{
    DUANXX_OK = 0,
    DUANXX_ERR = 1,
    DUANXX_RESERVED = 2   /** reserved */
}RET_E;

#endif //end of #ifndef _DUANXX_TYPE_H_