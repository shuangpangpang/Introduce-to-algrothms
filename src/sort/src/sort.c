#include "sort.h"

#define SWAP(n1,n2,tmp)	\
do\
{\
	tmp = n1;\
	n1 = n2;\
	n2 = tmp;\
}while(0)

/********************************************************************************
Function Name : insert_sort
Description   :插入排序
Invocation    :
Parameters    : 	@pArray		--待排序的参数
				@uArraySize	--待排序的参数的个数
				@uSortFlag 	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
int insert_sort(int *pArray, unsigned int uArraySize, unsigned int uSortFlag)
{
	int iOutCnt = 0;
	int iInnerCnt = 0;
	int iKey = 0;
	
	if(uArraySize <=0 || NULL == pArray)
	{
		printf("func[%s] line[%d] : inpunt param is error, pArray = %p, uArraySize = %d\n\t",__FUNCTION__,__LINE__,pArray,uArraySize);
		return SORT_PARAM_ERROR;
	}

	for(iOutCnt = 1; iOutCnt < uArraySize; iOutCnt++)
	{
		iKey = pArray[iOutCnt];
		iInnerCnt = iOutCnt-1;
		while(iInnerCnt >= 0)
		{
			if(uSortFlag)
			{
				if(iKey < pArray[iInnerCnt])/*升序*/
				{
					pArray[iInnerCnt+1] = pArray[iInnerCnt];
					pArray[iInnerCnt] = iKey;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(iKey > pArray[iInnerCnt])/*降序*/
				{
					pArray[iInnerCnt+1] = pArray[iInnerCnt];
					pArray[iInnerCnt] = iKey;
				}
				else
				{
					break;
				}
			}
			iInnerCnt--;
		}
	}
	
	return SORT_OK;
}

/********************************************************************************
Function Name : select_sort
Description   :选择排序
Invocation    :
Parameters    : 	@pArray		--待排序的参数
				@uArraySize	--待排序的参数的个数
				@uSortFlag 	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
int select_sort(int *pArray, unsigned int uArraySize, unsigned int uSortFlag)
{
	int iOutCnt = 0;
	int iInnerCnt = 0;
	int iKey = 0;
	
	if(uArraySize <=0 || NULL == pArray)
	{
		printf("func[%s] line[%d] : inpunt param is error, pArray = %p, uArraySize = %d\n\t",__FUNCTION__,__LINE__,pArray,uArraySize);
		return SORT_PARAM_ERROR;
	}
		
	for(iOutCnt=0; iOutCnt<uArraySize; iOutCnt++)
	{
		for(iInnerCnt=iOutCnt+1;iInnerCnt<uArraySize;iInnerCnt++)
		{
			if(uSortFlag)/*升序*/
			{
				if(pArray[iOutCnt] > pArray[iInnerCnt])
				{
					SWAP(pArray[iOutCnt],pArray[iInnerCnt],iKey);
				}
			}
			else/*降序*/
			{
				if(pArray[iOutCnt] < pArray[iInnerCnt])
				{					
					SWAP(pArray[iOutCnt],pArray[iInnerCnt],iKey);
				}
			}
		}
	}
	return SORT_OK;
}

/********************************************************************************
Function Name : two_sorted_array_merge
Description   :合并数组中的两个有序分部
Invocation    :
Parameters    : 	@pArray		--待合并的数组
				@startIdx	--开始下标
				@midIdx		--分界下标
				@endIdx		--结束下标
				@uSortFlag 	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
void two_sorted_array_merge(int *pArray, int startIdx, int midIdx, int endIdx, unsigned int uSortFlag)
{
	int *pLeft = NULL;
	int *pRight = NULL;
	int iCnt = 0, iLeft = 0, iRight = 0;

	if(startIdx > endIdx || startIdx > midIdx || midIdx > endIdx || NULL == pArray)
	{
		printf("two_sorted_array_merge : Input param Error --  pArray = %p, startIdx = %d, midIdx=%d, endIdx=%d\n",pArray,startIdx,midIdx,endIdx);
		return;
	}

	do{
		pLeft = (int *)malloc((midIdx - startIdx)*sizeof(int));
		if(NULL == pLeft)
		{
			printf("two_sorted_array_merge : no mem left\n");
			goto error;
		}

		pRight = (int *)malloc((endIdx - midIdx + 1)*sizeof(int));
		if(NULL == pRight)
		{
			printf("two_sorted_array_merge : no mem left\n");
			goto error;
		}
	}while(0);

	for(iCnt=startIdx;iCnt<midIdx;iCnt++)
	{
		pLeft[iCnt-startIdx]=pArray[iCnt];
	}

	for(iCnt=midIdx;iCnt<=endIdx;iCnt++)
	{
		pRight[iCnt-midIdx] = pArray[iCnt];
	}

	if(uSortFlag)/*升序*/
	{
		iCnt = startIdx;
		while(iLeft < (midIdx - startIdx) && iRight < (endIdx - midIdx + 1))
		{
			if(pLeft[iLeft] <= pRight[iRight])
			{			
				pArray[iCnt] = pLeft[iLeft];
				iLeft++;
			}
			else
			{
				pArray[iCnt] = pRight[iRight];
				iRight++;
			}
			iCnt++;
		}

		while(iLeft < (midIdx - startIdx))
		{
			pArray[iCnt] = pLeft[iLeft];
			iLeft++;
			iCnt++;			
		}

		while(iRight < (endIdx - midIdx + 1))
		{
			pArray[iCnt] = pRight[iRight];
			iRight++;
			iCnt++;			
		}
	}
	else/*降序*/
	{
		iLeft = midIdx - startIdx-1;
		iRight = endIdx - midIdx;
		iCnt = endIdx;
		while(iLeft >= 0 && iRight >= 0)
		{
			if(pLeft[iLeft] <= pRight[iRight])
			{			
				pArray[iCnt] = pLeft[iLeft];
				iLeft--;
			}
			else
			{
				pArray[iCnt] = pRight[iRight];
				iRight--;
			}
			iCnt--;
		}

		while(iLeft >= 0)
		{
			pArray[iCnt] = pLeft[iLeft];
			iLeft--;
			iCnt--;			
		}

		while(iRight >= 0)
		{
			pArray[iCnt] = pRight[iRight];
			iRight--;
			iCnt--;			
		}
	}
	
error:
	if(pLeft)
	{
		free(pLeft);
	}
	if(pRight)
	{
		free(pRight);
	}
}

/********************************************************************************
Function Name : merge_sort
Description   :归并排序
Invocation    :
Parameters    : 	@pArray		--待排序的参数
				@uArraySize	--待排序的参数的个数
				@uSortFlag 	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
int merge_sort(int *pArray, unsigned int uArraySize, unsigned int uSortFlag)
{
	unsigned int midIdx = uArraySize/2;
	
	if(uArraySize <=0 || NULL == pArray)
	{
		printf("func[%s] line[%d] : inpunt param is error, pArray = %p, uArraySize = %d\n\t",__FUNCTION__,__LINE__,pArray,uArraySize);
		return SORT_PARAM_ERROR;
	}

	if(1 == uArraySize)
	{
		return SORT_OK;
	}

	merge_sort(pArray,midIdx,uSortFlag);
	merge_sort(pArray+midIdx,uArraySize-midIdx,uSortFlag);
	two_sorted_array_merge(pArray,0,midIdx,uArraySize-1,uSortFlag);
	return SORT_OK;
}


/********************************************************************************
Function Name : bubble_sort
Description   :冒泡排序
Invocation    :
Parameters    : 	@pArray		--待排序的参数
				@uArraySize	--待排序的参数的个数
				@uSortFlag 	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
int bubble_sort(int *pArray, unsigned int uArraySize, unsigned int uSortFlag)
{
	int iOutCnt = 0;
	int iInnerCnt = 0;
	int ikey = 0;

	if(uArraySize <=0 || NULL == pArray)
	{
		printf("func[%s] line[%d] : inpunt param is error, pArray = %p, uArraySize = %d\n\t",__FUNCTION__,__LINE__,pArray,uArraySize);
		return SORT_PARAM_ERROR;
	}

	for(iOutCnt=0;iOutCnt<uArraySize;iOutCnt++)
	{
		for(iInnerCnt=0;iInnerCnt<uArraySize-1-iOutCnt;iInnerCnt++)
		{
			if(uSortFlag)	/*升序*/
			{
				if(pArray[iInnerCnt]>pArray[iInnerCnt+1])
				{
					SWAP(pArray[iInnerCnt],pArray[iInnerCnt+1],ikey);
				}
			}
			else
			{
				if(pArray[iInnerCnt]<pArray[iInnerCnt+1])
				{
					SWAP(pArray[iInnerCnt],pArray[iInnerCnt+1],ikey);
				}
			}
		}
	}

	return SORT_OK;
}
