#include <stdio.h>
#include <pthread.h>

void* printHola(void* arg)
{
    int pid = *((int*)arg);
    printf("HOLA DESDE EL HILO %d\n", pid);
    pthread_exit(NULL); // Le dice al hilo prinicpal que lo espere de ejecutarse
}

int saldo;
void* incrementaSaldo()
{
    saldo += 100;
    pthread_exit(NULL);
}

// Hilo prinicpal
int main(int argc, char const *argv[])
{
    int NUMBER_THREADS = 20;
    // Variable para controlar los hilos con su identificadores
    pthread_t hilosStatus[NUMBER_THREADS];

    int pids[NUMBER_THREADS];
    saldo = 0;
    // Creacion de hilos
    for (int i = 0; i < NUMBER_THREADS; i++)
    {
        pids[i] = i;
        pthread_create(&hilosStatus[i], NULL, incrementaSaldo, NULL); // Conviertiendo un tipo de dato entero a uno generio
    }

    for (int i = 0; i < NUMBER_THREADS; i++)
    {
        pthread_join(hilosStatus[i], NULL); //  Espera a que termine el hilo y atrapa valores si existe en pthread_exit
    }

    printf("Saldo total: %d\n", saldo);
    pthread_exit(NULL);
}