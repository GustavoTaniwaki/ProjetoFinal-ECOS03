#ifndef KERNEL_ECOS03.h
#define KERNEL_ECOS03.h

#define MAX_PROCESSES 20
#define MAX_BUFFER 10
#define QUANTUM_TIME 1

typedef struct { //estrutura dos processos
    int id;
    int arrivalTime;
    int executionTime;
    int priority;
} Process;

typedef struct { //estrutura da fila
    Process processes[MAX_BUFFER];
    int head;
    int tail;
    int size;
} Buffer;

void initBuffer(Buffer* buffer);
bool isBufferEmpty(Buffer* buffer);
bool isBufferFull(Buffer* buffer);
void addProcess(Buffer* buffer, Process p, Buffer* waitingQueue);
void removeProcess(Buffer* buffer, int index);
void enqueue(Buffer* q, Process p);
Process dequeue(Buffer* q);

void SRTN_Scheduler(Process processes[], int num_processes);
void Priority_Scheduler(Process processes[], int num_processes);


#endif