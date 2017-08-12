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

/** 使用宏定义，这样assert可以直接得到错误的文件及行数 */
#define duanxx_Assert(errStr) {\
    if(errStr != NULL)\
    {\
        printf_s("\n%s not pass\n", errStr);\
        assert(0);\
    }\
}

#endif //end of #ifndef _DUANXX_TEST_H_