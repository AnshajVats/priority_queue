#include<stdio.h>
#include<stdlib.h>

#include"priority_queue.h"


int main(int argc, char* argv[])
{
	PRIORITY_QUEUE hQueue;
	hQueue = priority_queue_init_default();
	//int i;

	if (hQueue == NULL)
	{
		printf("failed");
	}
	else
	{
		printf("created\n");
	}
	priority_queue_insert(hQueue, 13, 8);
	priority_queue_insert(hQueue, 20, 1);
	priority_queue_insert(hQueue, 18, 3);
	priority_queue_insert(hQueue, 4, 17);
	priority_queue_insert(hQueue, 5, 16);
	priority_queue_insert(hQueue, 2, 19);
	priority_queue_insert(hQueue, 14, 7);
	priority_queue_insert(hQueue, 12, 9);
	priority_queue_insert(hQueue, 8, 13);
	priority_queue_insert(hQueue, 9, 12);
	priority_queue_insert(hQueue, 3, 18);

	priority_queue_insert(hQueue, 19, 2);
	priority_queue_insert(hQueue, 16, 5);
	priority_queue_insert(hQueue, 10, 11);
	priority_queue_insert(hQueue, 15, 6);
	priority_queue_insert(hQueue, 17, 4);

	Status status=SUCCESS;
    while(!priority_queue_is_empty(hQueue))
	{
		printf("%d\n", priority_queue_front(hQueue, &status));

		if (status == SUCCESS)
		{
			printf("SUCESS\n");
		}
	
		priority_queue_service(hQueue);
		
	}

  priority_queue_destroy(&hQueue);
  
  if (hQueue != NULL)
  {
	  printf("destory fail\n");
  }

	


	return 0;
}