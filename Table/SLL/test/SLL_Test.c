/*****************************************************************************
*                                                                            *
*  @file     SLL_Test.c                                                      *
*  @brief    单链测试实现文件                                                  *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-12                                                      *
*                                                                            *
*****************************************************************************/

#include <string.h>
#include "Table/SLL/test/SLL_Test.h"


/**
* @brief 单链表测试
*/
ulong SLL_TEST()
{
    (void)SLL_init_TEST();

    return DUANXX_OK;
}

/**
* @brief 单链表初始化测试
*   测试内容：
*   1、  Input：pSLL 为 NULL
*        Opera :  无
*   
*   2、  Input : pSLL 为正常输入
*        Opera : 判断 pSLL内容是否正确
*                pHead、pTail应为NULL
*                num应为0
*/
ulong SLL_init_TEST()
{
    /** Test 1 */
    pSLL_S pSLL = NULL;
    if( SLL_init(pSLL) != DUANXX_ERR)
    {
        duanxx_Assert("SLL_init_TEST : Test 1 ");
    }

    /** Test 2 */
    pSLL = (pSLL_S)malloc(sizeof(SLL_S));    
    memset(pSLL, 0, sizeof(SLL_S));
    SLL_init(pSLL);
    if (pSLL->pHead != NULL ||
        pSLL->pTail != NULL ||
        pSLL->num != 0)
    {
        duanxx_Assert("SLL_init_TEST : Test 2 ");
    }

    printf_s("SLL_init_TEST pass \n");

    return DUANXX_OK;
}