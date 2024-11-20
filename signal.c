#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void noSeMata(int signum)
{
    printf("Reciibi señal %d\n", signum);
    printf("No se puede matar");
}

int condition = 1;
void endCycle(int signum)
{
    condition = 20;
    printf("Continue");
}

int main(int argc, char const *argv[])
{
    signal(2, noSeMata);
    signal(10, endCycle);
    while (condition == 1)
    {
        printf("Trabajando \n");
        sleep(2);
    }
    printf("Terminad");
    return 0;
}