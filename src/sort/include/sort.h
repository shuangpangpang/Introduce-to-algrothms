#include <stdio.h>
#include <stdlib.h>

/*****************ERROR NUM**********************************************************/
#define SORT_OK					0
#define SORT_PARAM_ERROR		-1

#define FALSE					0
#define	TRUE					1


/******************************************Function declear********************************/

/********************************************************************************
Function Name : insert_sort
Description   :插入排序
Invocation    :
Parameters    : 	@pArray		--待排序的参数
				@uArraySize	--待排序的参数的个数
				@uSortFlag	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
int insert_sort(int *pArray, unsigned int uArraySize, unsigned int uSortFlag);

/********************************************************************************
Function Name : select_sort
Description   :选择排序
Invocation    :
Parameters    : 	@pArray		--待排序的参数
				@uArraySize	--待排序的参数的个数
				@uSortFlag 	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
int select_sort(int *pArray, unsigned int uArraySize, unsigned int uSortFlag);

/********************************************************************************
Function Name : merge_sort
Description   :归并排序
Invocation    :
Parameters    : 	@pArray		--待排序的参数
				@uArraySize	--待排序的参数的个数
				@uSortFlag 	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
int merge_sort(int *pArray, unsigned int uArraySize, unsigned int uSortFlag);

/********************************************************************************
Function Name : bubble_sort
Description   :冒泡排序
Invocation    :
Parameters    : 	@pArray		--待排序的参数
				@uArraySize	--待排序的参数的个数
				@uSortFlag 	--0降序，其他升序
Return Value  : 0 -- sort OK; other -- sort error.
********************************************************************************/
int bubble_sort(int *pArray, unsigned int uArraySize, unsigned int uSortFlag);

