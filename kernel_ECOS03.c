#include <stdio.h>
#include <stdbool.h>
#include "kernel_ECOS03.h"

//inicializa o buffer
void initBuffer(Buffer* buffer) { 
    buffer->head = 0;
    buffer->tail = 0;
    buffer->size = 0;

	// Inicializa os processos dom dos dados de stdin
    freopen("stdin.txt", "r", stdin);
    Process processes[MAX_PROCESSES];
    for(int i=0; i<MAX_PROCESSES; i++) {
    	processes[i].id = i+1;
    	scanf("Processo [%d]: \nTempo de Chegada: %d \nDuracao: %d \nPrioridade: %d", 
               i+1, &processes[i].arrivalTime, &processes[i].executionTime, &processes[i].priority);
	}


}

// Indica o buffer estar vazio
bool isBufferEmpty(Buffer* buffer) { 
    if (buffer->size == 0) return 1;
    else return 0;
}

// Indica o buffer estar cheio
bool isBufferFull(Buffer* buffer) { 
    if (buffer->size == MAX_BUFFER) return 1;
    else return 0;
}

// Adiciona um processo no Buffer
void addProcess(Buffer* buffer, Process p, Buffer* waitingQueue) { 
    int i;

    // Verifica se o buffer está cheio e manda ou não para uma fila de espera
    if (isBufferFull(buffer)) { 
        waitingQueue->processes[waitingQueue->tail] = p;
        waitingQueue->tail = (waitingQueue->tail + 1) % MAX_BUFFER;
        waitingQueue->size++;
        return;
    }
    buffer->processes[buffer->tail] = p;
    buffer->tail = (buffer->tail + 1) % MAX_BUFFER;
    buffer->size++;
}

// Remove um processo do Buffer
void removeProcess(Buffer* buffer, int index) { 
    int i;
    for (i = index; i < buffer->size - 1; i++) {
        buffer->processes[i] = buffer->processes[i + 1];
    }
    buffer->size--;
    buffer->tail = (buffer->tail - 1 + MAX_BUFFER) % MAX_BUFFER;
}

// Insere o processo no Fim da Fila
void enqueue(Buffer* q, Process p) { 
    if (!isBufferFull(q)) {
    	q->processes[q->tail] = p;
        q->tail = (q->tail + 1) % MAX_BUFFER;
        q->size++;
    }
}

// Remove o processo no Começo da fila
Process dequeue(Buffer* q) { 
    Process process = q->processes[q->head];
    q->head = (q->head + 1) % MAX_BUFFER;
    q->size--;
    return process;
}

// Escalonador STRN
void SRTN_Scheduler(Process processes[], int num_processes) {
    
}

// Escalonador de Prioridade
void Priority_Scheduler(Process processes[], int num_processes) {

}


int main() {

    //freopen("stdout.txt", "w", stdout);
    return 0;
}
