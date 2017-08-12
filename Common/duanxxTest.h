/*****************************************************************************
*                                                                            *
*  @file     duanxxTest.h                                                    *
*  @brief    �Զ�������ļ�                                                    *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-11                                                      *
*                                                                            *
*****************************************************************************/

#ifndef _DUANXX_TEST_H_
#define _DUANXX_TEST_H_

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/** ʹ�ú궨�壬����assert����ֱ�ӵõ�������ļ������� */
#define duanxx_Assert(errStr) {\
    if(errStr != NULL)\
    {\
        printf_s("\n%s not pass\n", errStr);\
        assert(0);\
    }\
}

#endif //end of #ifndef _DUANXX_TEST_H_