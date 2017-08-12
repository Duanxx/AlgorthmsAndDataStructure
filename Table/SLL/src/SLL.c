/*****************************************************************************
*                                                                            *
*  @file     SLL.c                                                           *
*  @brief    单链实现文件                                                      *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-11                                                      *
*                                                                            *
*****************************************************************************/


#include "Table/SLL/src/SLL.h"

/**
* @brief   单链表初始化
*       单链表的初始化仅仅是将单链表的头指针和尾指针置为空
*       同时将单链表的个数置为0
*/
ulong SLL_init(pSLL_S pSLL)
{
    if (pSLL == NULL)
    {
        return DUANXX_ERR;
    }

    pSLL->pHead = NULL;
    pSLL->pTail = NULL;
    pSLL->num = 0;

    return DUANXX_OK;
}

