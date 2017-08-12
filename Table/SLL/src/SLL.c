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
RET_E SLL_init(pSLL_S pSLL)
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

/**
* @brief   ������ͷ��ӽڵ�
*           
* @param pSll    ������ָ��
* @param pNode   �ڵ�ָ��
*
*       1����� pSll ���� pNode ��һ��ΪNULL�����˳�
*       2�����������Ľڵ���ĿΪ0��������ͷָ���βָ��ָ��ýڵ㣬������ڵ���ĿΪ1
*       3�����������Ľڵ���Ŀ>=1��������ͷ����ڵ㣬������ڵ���Ŀ����1
*/
RET_E SLL_addNodeToHead(pSLL_S pSll, pSLL_NODE_S pNode)
{
     if (pSll == NULL || pNode == NULL)
     {
         return DUANXX_ERR;
     }

     if (pSll->num == 0)
     {
         pSll->pHead = pNode;
         pSll->pTail = pNode;
         pSll->num = 1;
         return DUANXX_OK;
     }

     pNode->pNext = pSll->pHead;
     pSll->pHead = pNode;
     pSll->num = pSll->num + 1;

     return DUANXX_OK;
}