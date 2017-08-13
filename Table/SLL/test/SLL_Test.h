/*****************************************************************************
*                                                                            *
*  @file     SLL_Test.h                                                           *
*  @brief    单链测试头文件                                                      *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-11                                                      *
*                                                                            *
*****************************************************************************/

#ifndef _SLL_TEST_H_
#define _SLL_TEST_H_

#include "Table/SLL/src/SLL.h"
#include "Common/duanxxTest.h"


RET_E SLL_TEST();
RET_E SLL_init_TEST();
RET_E SLL_addNodeToHead_TEST();
RET_E SLL_addNodeToTail_TEST();
RET_E SLL_deleteFromHead_TEST();
RET_E SLL_deleteFromTail_TEST();


#endif //end of #ifndef _SLL_TEST_H_