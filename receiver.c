#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

int main(){
	char *shared_memory;
	int shmid = shmget((key_t)6969, 1024, 0666);
	printf("shmid is %d\n", shmid);
	shared_memory = shmat(shmid, NULL, 0);
	printf("Process attached at %p\n", shared_memory);
	printf("Data read from shared memory is: %s", (char *)shared_memory); 
}
