/*****************************************************************************
*                                                                            *
*  @file     SLL.c                                                           *
*  @brief    ����ʵ���ļ�                                                      *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-11                                                      *
*                                                                            *
*****************************************************************************/


#include "Table/SLL/src/SLL.h"

/**
* @brief   �������ʼ��
*       ������ĳ�ʼ�������ǽ��������ͷָ���βָ����Ϊ��
*       ͬʱ��������ĸ�����Ϊ0
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

