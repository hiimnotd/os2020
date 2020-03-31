#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	printf("MAin before fork()\n");
	int pid = fork();
	if (pid == 0) {
		int pid1 = fork(); 
		if (pid1 == 0) {
			printf("I'm child after fork(), launching ps -ef\n");
			char *args[] = {"/bin/ps", "-ef", NULL};
			execvp("/bin/ps", args);
		}
		else {
			wait(NULL);
			printf("I'm parent after fork(), child is %d\n", pid1);
		}
		printf("I'm child after fork(), launching free -h\n");
		char *args[] = {"free", "-h", NULL};
		execvp("free", args);
	}
	else {
		wait(NULL);
		printf("I'm parent after fork(), child is %d\n", pid);
	}
	return 0;
}


