
/*

 * a.c

 * write a random number between 0 and 999 to the shm every 1 second

*/

#include<stdio.h>

#include<unistd.h>

#include<sys/shm.h>

#include<stdlib.h>

#include<error.h>

int main(){

	int shm_id;

	int *share;

	int num;

	srand(time(NULL));

	shm_id = shmget (1234, getpagesize(), IPC_CREAT);

	if(shm_id == -1){

		perror("shmget()");

	}

	share = (int *)shmat(shm_id, 0, 0);

	while(1){

		num = random() % 1000;

		*share = num;

		printf("write a random number %d\n", num);

		sleep(1);

	}

	return 0;

}

