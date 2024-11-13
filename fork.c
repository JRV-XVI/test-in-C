#include <stdio.h>
#include <unistd.h>

int main() 
{
	int a = 5;
	int pid = fork(); // Process ID PID
	if (pid == 0) {
		printf("Soy el proceso hijo a = %d\n", a);
		execl("./hello", "hello", "Juan", "yo", (char *) NULL);
		return 0;
	}
	printf("Soy el proceso padre, a = %d\n", a);
	sleep(5);
	return 0;
}
