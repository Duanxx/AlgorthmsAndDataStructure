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
    pSLL->ulNum = 0;

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
    /** 1 */
    if (pSll == NULL || pNode == NULL)
    {
        return DUANXX_ERR;
    }

    /** 2 */
    if (pSll->ulNum == 0)
    {
        pSll->pHead = pNode;
        pSll->pTail = pNode;
        pSll->ulNum = 1;
        return DUANXX_OK;
    }

    /** 3 */
    pNode->pNext = pSll->pHead;
    pSll->pHead = pNode;
    pSll->ulNum = pSll->ulNum + 1;

    return DUANXX_OK;
}


/**
* @brief   ������β��ӽڵ�
*           
* @param pSll    ������ָ��
* @param pNode   �ڵ�ָ��
*
*       1����� pSll ���� pNode ��һ��ΪNULL�����˳�
*       2�����������Ľڵ���ĿΪ0��������ͷָ���βָ��ָ��ýڵ㣬������ڵ���ĿΪ1
*       3�����������Ľڵ���Ŀ>=1��������β����ڵ㣬������ڵ���Ŀ����1
*/
RET_E SLL_addNodeToTail(pSLL_S pSll, pSLL_NODE_S pNode)
{
    /** 1 */
    if (pSll == NULL || pNode == NULL)
    {
        return DUANXX_ERR;
    }

    /** 2 */
    if (pSll->ulNum == 0)
    {
        pSll->pHead = pNode;
        pSll->pTail = pNode;
        pSll->ulNum = 1;
        return DUANXX_OK;
    }

    /** 3 */
    pNode->pNext = NULL;
    pSll->pTail->pNext = pNode;
    pSll->pTail = pNode;
    pSll->ulNum = pSll->ulNum + 1;
    return DUANXX_OK;
}


/**
* @brief   �ӵ�����ͷɾ���ڵ�
*
*       ��ʹ��free(ptr);��һ��Ҫ�� ptr = NULL;
*       ����ֱ��ʹ�ú궨�壺DUANXX_Free(ptr)ʵ��
*
* @param pSll    ������ָ��
*
*       1����� pSllΪ NULL�����˳�
*       2�����������Ľڵ���ĿΪ0�����˳�
*       3�����������Ľڵ���ĿΪ1��ɾ���ýڵ㣬��pSll��ͷָ���βָ��Ϊ�գ�pSll�Ľڵ���ĿΪ0
*       4�����������Ľڵ���Ŀ>1��ɾ��ͷ�ڵ㣬pSll�Ľڵ���Ŀ�Լ�1
*
*/
RET_E SLL_deleteFromHead(pSLL_S pSll)
{
    pSLL_NODE_S pTmpNode = NULL;

    /** 1��2 */
    if (pSll == NULL || pSll->ulNum == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    if (pSll->ulNum == 1)
    {
        Duanxx_Free(pSll->pHead);
        SLL_init(pSll);
        return DUANXX_OK;
    }

    /** 4 */
    pTmpNode = pSll->pHead->pNext;
    Duanxx_Free(pSll->pHead);
    pSll->pHead = pTmpNode;
    pSll->ulNum =  pSll->ulNum - 1;

    return DUANXX_OK;
}

/**
* @brief   �ӵ�����β��ɾ���ڵ�
*
*
* @param pSll    ������ָ��
*
*       1����� pSllΪ NULL�����˳�
*       2�����������Ľڵ���ĿΪ0�����˳�
*       3�����������Ľڵ���ĿΪ1��ɾ���ýڵ㣬��pSll��ͷָ���βָ��Ϊ�գ�pSll�Ľڵ���ĿΪ0
*       4�����������Ľڵ���Ŀ>1��ɾ��β�ڵ㣬pSll�Ľڵ���Ŀ�Լ�1
*
*/
RET_E SLL_deleteFromTail(pSLL_S pSll)
{
    pSLL_NODE_S pTmpNode = NULL;

    /** 1��2 */
    if (pSll == NULL || pSll->ulNum == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    if (pSll->ulNum == 1)
    {
        Duanxx_Free(pSll->pTail);
        SLL_init(pSll);
        return DUANXX_OK;
    }

    /** 4 */
    pTmpNode = pSll->pHead;
    while(pTmpNode->pNext != pSll->pTail)
    {
        pTmpNode = pTmpNode->pNext;
    }
    Duanxx_Free(pSll->pTail);
    pSll->pTail = pTmpNode;
    pSll->ulNum = pSll->ulNum - 1;

    return DUANXX_OK;
}

/**
* @brief   �ͷ�һ��������
*
* @param pSll    ������ָ��
*
*       1����� pSllΪ NULL�����˳�
*       2�����������Ľڵ���ĿΪ0�����˳�
*       3�����������Ľڵ���Ŀ>=1����pSll��ͷָ���βָ��Ϊ�գ�pSll�Ľڵ���ĿΪ0
*/
RET_E SLL_freeList(pSLL_S pSll)
{
    pSLL_NODE_S pTmpNode = NULL;
    pSLL_NODE_S pTmpNextNode = NULL;

    /** 1��2 */
    if (pSll == NULL || pSll->ulNum == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    pTmpNode = pSll->pHead;
    while(pTmpNode != NULL)
    {
        pTmpNextNode = pTmpNode->pNext;
        Duanxx_Free(pTmpNode);
        pTmpNode = pTmpNextNode;
    }

    SLL_init(pSll);
    return DUANXX_OK;
}

/**
* @brief   ����������ݴ�ӡ����
*
* @param pSll    ������ָ��
*
*       1����� pSllΪ NULL�����˳�
*       2�����������Ľڵ���ĿΪ0������ʾ����Ϊ��
*       3�����������Ľڵ���Ŀ>=1���������ӡ����
*/
RET_E SLL_displayList(pSLL_S pSll)
{
    ULONG ulIndex = 0;
    pSLL_NODE_S pTmpNode = NULL; 

    /** 1 */
    if (pSll == NULL)
    {
        return DUANXX_ERR;
    }

    /** 2 */
    if (pSll->ulNum == 0)
    {
        printf_s("\n SLL is empty !\n");
        return DUANXX_OK;
    }

    /** 3 */
    pTmpNode = pSll->pHead;
    printf_s("\n SLL is :\n");
    for (ulIndex = 0; ulIndex < pSll->ulNum ; ++ulIndex)
    {
        printf_s("%d", pTmpNode->ulData);
        if (ulIndex != pSll->ulNum - 1)
        {
            printf_s("->");
        }
        pTmpNode = pTmpNode->pNext;
    }

    return DUANXX_OK;
}

/**
* @brief   �����Ƿ���������
*
* @param pSll    ������ָ��
* @param ulData  ����������
*
*       1����� pSllΪ NULL���򷵻ش���
*       2�����������Ľڵ���ĿΪ0���򷵻ش���
*       3�����������Ľڵ���Ŀ>=1�����ز��ҽ��
*/
RET_E SLL_isInList(pSLL_S pSll, ULONG ulData)
{
    pSLL_NODE_S pTmpNode = NULL;

    /** 1,2 */
    if (pSll == NULL || pSll->ulNum == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    pTmpNode = pSll->pHead;
    while (pTmpNode != NULL)
    {
        if (pTmpNode->ulData == ulData)
        {
            return DUANXX_OK;
        }
        pTmpNode = pTmpNode->pNext;
    }

    return DUANXX_ERR;
}

/**
* @brief   ��������ڵ����Ŀ
*
* @param pSll    ������ָ��
* @param ulData  ����������
*
*       1����� pSllΪ NULL���򷵻� -1
*       2�����ص�����Ľڵ���Ŀ
*/
INT32 SLL_count(pSLL_S pSll)
{
    /** 1 */
    if (pSll == NULL)
    {
        return -1;
    }

    /** 2 */
    return pSll->ulNum;
}