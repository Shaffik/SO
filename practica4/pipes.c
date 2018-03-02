#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
int main()
{
	int i;
	int fd[2];
	char buffer[10];
	pipe(fd);
	for (i=0;i<=10;i++){
	buffer [i]=NULL;
	}
	if(!fork())
	{
		sleep(1);
		read(fd[0], buffer, 2);
		printf("Hijo: he leido \%s \n", buffer);
		printf("HIJO: escribiendo en el PIPE\n");
		buffer[2]='l';
		buffer[3]='a';
		write(fd[1], buffer, 4);
		sleep(2);
		read(fd[0], buffer, 6);
		printf("Hijo: he leido \%s \n", buffer); 
		printf("HIJO: escribiendo en el PIPE\n");
		buffer[6]='u';
		buffer[7]='n';
		write(fd[1], buffer, 8);
		sleep(2);
		read(fd[0], buffer, 10);
		printf("Hijo: he leido \%s \n", buffer);
		exit(0);
	}
	else{		
		printf("PADRE: escribiendo en el PIPE\n");
		buffer[0]='h';
		buffer[1]='o';
		write(fd[1], buffer, 2);
		sleep(2);
		read(fd[0], buffer, 4);
		printf("PADRE: he leido \%s \n", buffer);		
		printf("PADRE: escribiendo en el PIPE\n");
		buffer[4]='_';
		buffer[5]='m';
		write(fd[1], buffer, 6);
		sleep(2);
		read(fd[0], buffer, 8);
		printf("PADRE: he leido \%s \n", buffer);		
		printf("PADRE: escribiendo en el PIPE\n");
		buffer[8]='d';
		buffer[9]='o';
		write(fd[1], buffer, 10);
		sleep(2);
		printf("PADRE: Estoy Muerto :v \n");
		exit(0);
	}
}
