#include<stdio.h>
#include<stdlib.h>

int main() {
	int pid, pid2,pid3,pid4;
	printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
	printf("PADRE: Soy el proceso padre y el pid de mi padre es: %d\n", getppid());
	pid = fork();
	if (pid) // Este es el proceso padre
	{
		printf("PADRE: Soy el proceso padre y mi pid sigue siendo: %d\n", getpid());
		printf("PADRE: Mi hijo tiene el pid: %d\n", pid);
		sleep(3);
		
		pid2=fork();
		if(pid2){//codigo del padre
		 
		printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
                printf("PADRE: mi hijo tiene el pid: %d\n", pid2);
		}
		else{//codigo del hijo
			printf("Hijoa: Soy el proceso hijo y mi pid es: %d\n",getpid());
                	printf("Hijoa: Mi padre tiene el pid: %d\n", getppid());
			pid3 = fork();
			if(pid3){//codigo padre  proceso hijoa
				printf("Padrea: Soy el proceso hipa y mi pid es: %d\n",getpid());
                        	printf("Padrea: Mi hijo tiene el pid: %d\n", pid3);
				sleep(2);
			}
			else{//nieto
				printf("Nietoa: Soy el proceso hinieto y mi pid es: %d\n",getpid());
                        	printf("Nietoa: Mi padre tiene el pid: %d\n", getppid());

			}
		}
	
	}
	else // Proceso hijo
	{
		printf("HIJOb: Soy el proceso hijo y mi pid es: %d\n", getpid());
		printf("HIJOb: mi padre tiene el pid: %d\n", getppid());
		pid4 = fork();
			if(pid4){//codigo padre  proceso hijoa
				printf("Padreb: Soy el proceso hipa y mi pid es: %d\n",getpid());
                        	printf("Padreb: Mi hijo tiene el pid: %d\n", pid4);
				sleep(2);
			}
			else{//nieto
				printf("Nietob: Soy el proceso hinieto y mi pid es: %d\n",getpid());
                        	printf("Nietob: Mi padre tiene el pid: %d\n", getppid());

			}
	}
}
