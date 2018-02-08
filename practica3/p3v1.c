#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t pid1, pid2, pid3, pid4, pid5;
    int status1, status2, status3, status4, status5;

    if ((pid1=fork()) == 0 ) /*primer hijo */{
       
		if((pid3=fork())==0)/*primer nieto */{
		printf(" S Soy el primer nieto (%d, hijo de %d)\n", getpid(), getppid());
		}
		else
		{/*primer hijo */
			/* Esperamos al primer nieto */
			waitpid(pid3, &status3, 0);
			
			printf(" Y Soy el primer hijo (%d, hijo de %d)\n", getpid(), getppid());

			if((pid4=fork())==0)/*segundo nieto */{
			printf(" S Soy el segundo nieto (%d, hijo de %d)\n", getpid(), getppid());
			}
			else{
			/* Esperamos al segundo nieto */
		         waitpid(pid4, &status4, 0);
			}
		}
	}
    else
     { /*  padre */
	/* Esperamos al primer hijo */
	waitpid(pid1, &status1, 0);

         if((pid2=fork()) == 0 )
         { /* segundo hijo  */
		if((pid5=fork())==0)/*tercer nieto */{
		printf(" T Soy el tercer nieto (%d, hijo de %d)\n", getpid(), getppid());
		}
		else
		{/* segundo hijo  */
	     	/* Esperamos al tercer nieto */
		waitpid(pid5, &status5, 0);
		printf(" E Soy el segundo hijo (%d, hijo de %d)\n", getpid(), getppid());

		}
        }
        else
        { /* padre */

	/* Esperamos al segundo hijo */
	waitpid(pid2, &status2, 0);
        printf(" M Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
         }
    }

    return 0;
}
