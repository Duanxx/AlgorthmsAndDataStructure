/*****************************************************************************
*                                                                            *
*  @file     duanxxTest.h                                                    *
*  @brief    自定义测试文件                                                    *
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

#define Duanxx_TestFail(errStr) {\
    if(errStr != NULL)\
    {\
        printf_s("\n%s not pass\n", errStr);\
        printf_s("  %s line : %d \n", __FILE__,  __LINE__);\
    }\
}


#define Duanxx_Free(ptr) {\
    free(ptr);\
    ptr = NULL;\
}

#endif //end of #ifndef _DUANXX_TEST_H_