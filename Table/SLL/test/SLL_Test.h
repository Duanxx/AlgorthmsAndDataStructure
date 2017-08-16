/*****************************************************************************
*                                                                            *
*  @file     SLL_Test.h                                                           *
*  @brief    ��������ͷ�ļ�                                                      *
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

#define SLL_TEST_LEN    10

RET_E SLL_IsListMatched(pSLL_NODE_S arrNodeList[], ULONG ulLen, pSLL_S pSll, char *szTestStr);
RET_E SLL_TEST();
RET_E SLL_init_TEST();
RET_E SLL_addNodeToHead_TEST();
RET_E SLL_addNodeToTail_TEST();
RET_E SLL_deleteFromHead_TEST();
RET_E SLL_deleteFromTail_TEST();
RET_E SLL_displayList_TEST();
RET_E SLL_isInList_TEST();


#endif //end of #ifndef _SLL_TEST_H_