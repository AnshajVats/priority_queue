#include<stdio.h>
#include<stdlib.h>

#include "priority_queue.h"





typedef struct data {

	int value;
	int priority;

}Data;


typedef struct priority_queue {
	int size;
	int capcity;
	Data* heap;
	
}Priority;

void fix_up(Priority* pQueue, int index);
void fix_down(Priority* pQueue, int index);

PRIORITY_QUEUE priority_queue_init_default(void)
{
	Priority* pQueue;
	pQueue = (Priority*)malloc(sizeof(Priority));
	if (pQueue != NULL)
	{
		pQueue->size = 0;
		pQueue->capcity = 7;
		pQueue->heap = (Data*) malloc(sizeof(Data) * pQueue->capcity);
		if (pQueue->heap == NULL)
		{
			free(pQueue);
			pQueue = NULL;
		}
	}
	return pQueue;

}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
	Priority* pQueue = (Priority*)hQueue;
	Data* data;
	int i;


	if (pQueue->size >= pQueue->capcity)
	{
		data = (Data*)malloc(sizeof(Data) * pQueue->capcity*2);
		if (data == NULL)
		{
			return FAILURE;
		}

		for (i = 0; i < pQueue->size; i++)
		{
			data[i] = pQueue->heap[i];
		}

		free(pQueue->heap);
		pQueue->heap = data;
		pQueue->capcity *=2;
		
	}
	
		pQueue->heap[pQueue->size].value = data_item;
		pQueue->heap[pQueue->size].priority = priority_level;
		fix_up(pQueue,pQueue->size);
		pQueue->size++;


		return SUCCESS;
			
}


Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
	Data temp;
	Priority* pQueue = (Priority*)hQueue;

	if (pQueue->size <= 0)
	{
		return FAILURE;
	}

	temp = pQueue->heap[0];
	pQueue->heap[0] = pQueue->heap[pQueue->size-1];
	pQueue->heap[pQueue->size-1] = temp;

	(pQueue->size)--;
	//printf("inside before fix down\n");
	fix_down(pQueue, 0);
	//printf("insisde after fix down\n");




}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
	Priority* pQueue = (Priority*)hQueue;
	if (pQueue->size > 0)
	{
		if (pStatus != NULL)
		{
			*pStatus = SUCCESS;
		}
		return pQueue->heap[0].value;
	}
	 if (pStatus != NULL)
	{
		*pStatus = FAILURE;
	}
	return -9999;




}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
	Priority* pQueue = (Priority*)hQueue;
	if (pQueue->size > 0)
	{
		return FALSE;
	}
	return TRUE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
	Priority* pQueue = (Priority*)*phQueue;

	free(pQueue->heap);
	free(pQueue);

	*phQueue = NULL;


}


void fix_up(Priority* pQueue, int index)
{
	Data temp;
	int index_of_parent = (index - 1) / 2;
	//printf("index of parent :%d\n", index_of_parent);
		if (index != 0)
		{

			if ( pQueue->heap[index].priority> pQueue->heap[index_of_parent].priority)
			{

				
				//swap
				temp = pQueue->heap[index];
				pQueue->heap[index] = pQueue->heap[index_of_parent];
				pQueue->heap[index_of_parent] = temp;
				

				fix_up(pQueue,index_of_parent);
			}
			
		}

}

void fix_down(Priority* pQueue, int index)
{
	int left_child = (index * 2) + 1;
	int right_child = (index * 2) + 2;
	Data temp;


	if (right_child < pQueue->size)
	{
		if (pQueue->heap[left_child].priority > pQueue->heap[right_child].priority)
		{
			if (pQueue->heap[left_child].priority > pQueue->heap[index].priority)
			{

				temp = pQueue->heap[left_child];
				pQueue->heap[left_child] = pQueue->heap[index];
				pQueue->heap[index] = temp;

				fix_down(pQueue, left_child);

			}
		}
		else
		{
			if (pQueue->heap[right_child].priority > pQueue->heap[index].priority)
			{
				temp = pQueue->heap[right_child];
				pQueue->heap[right_child] = pQueue->heap[index];
				pQueue->heap[index] = temp;

				fix_down(pQueue, right_child);
			}


		}
	


	}
	else if (left_child < pQueue->size)
	{
		if (pQueue->heap[left_child].priority > pQueue->heap[index].priority)
		{
			temp = pQueue->heap[left_child];
			pQueue->heap[left_child] = pQueue->heap[index];
			pQueue->heap[index] = temp;
			fix_down(pQueue, left_child);
		}
	}

}