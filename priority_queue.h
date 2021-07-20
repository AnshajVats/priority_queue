#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H



typedef enum status{FAILURE, SUCCESS}Status;
typedef enum boolean {FALSE, TRUE}Boolean;

typedef void* PRIORITY_QUEUE;



PRIORITY_QUEUE priority_queue_init_default(void);
Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item);

Status priority_queue_service(PRIORITY_QUEUE hQueue);

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus);

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue);

void priority_queue_destroy(PRIORITY_QUEUE* phQueue);



#endif