#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
	int fd[2]; //fd[0] for reading and f[1] for writing
	char buff[100];
	pipe(fd);
	int pid = fork();
	if(pid>0) { // parent
		printf("Passing value to child\n");
		write(fd[1], "Hello World !", 13);
	}
	else {
		printf("In child process\n");
		int n = read(fd[0], buff, 100);
		write(1, buff, n);
	}
	
}

