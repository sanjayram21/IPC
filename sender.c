#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid = shmget((key_t)6969, 1024, 0666|IPC_CREAT);
	printf("shmid is %d\n" , shmid);
	shared_memory = shmat(shmid, NULL, 0);
	printf("Shared memory address: %p\n",shared_memory);
	printf("Enter data to be stored\n");
	read(0, buff, 100);
	strcpy(shared_memory, buff);
	printf("Data: %s\n", (char *)shared_memory);
}

