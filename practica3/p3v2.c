#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{	int pidH,pidL,pid0,pidD,pidN,pidU,pidA,pidM;
	pidH=fork();
	if(pidH>0)/*Padre letra O*/
	{	waitpid(pidH,NULL,0);
		pidL=fork();
		if(pidL>0)/*letra O*/
		{	waitpid(pidL,NULL,0);
			pidD=fork();
			if(pidD>0)/*letra O*/
			{	waitpid(pidD,NULL,0);
				printf("O\n");
			}
			if(pidD==0)/*letra D*/
			{	pidU=fork();
				if(pidU>0)/*letra D*/
				{	waitpid(pidU,NULL,0);
					pidN=fork();
					if(pidN>0)/*letra D*/
					{	waitpid(pidN,NULL,0);
						printf("D\n");
					}
					if(pidN==0)/*letra N*/
					{	printf("N\n");
					}
				}
				if(pidU==0)/*letra U*/
				{	pidA=fork();
					if(pidA>0)/*letra U*/
					{	waitpid(pidA,NULL,0);
						pidM=fork();
						if(pidM>0)/*letra U*/
						{	waitpid(pidM,NULL,0);
							printf("U\n");
						}
						if(pidM==0)/*letra M*/
						{	printf("M\n");
						}
					}
					if(pidA==0)
					{	printf("A\n");
					}
				}
			}
		}
		if(pidL==0)/*letra L*/
		{	pid0=fork();
			if(pid0>0)/*letra L*/
			{	waitpid(pid0,NULL,0);
				printf("L\n");
			}
			if(pid0==0)/*letra 0*/
			{	printf("0\n");
			}
		}
	}
	if(pidH==0)/*hijo letra H*/
	{	printf("H\n");
	}
}
