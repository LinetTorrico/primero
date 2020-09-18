#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int i,j;
          
   
	     if(fork()==0){
		     
			     for(j=0;j<2;j++){
				     if(fork()==0){
					     break;
				     }
				     
			     }
		     
//		     break;
	     
	     
	     }
	   

	printf("proceso ,  PID= %d,ID  padre=%d ejecutandose \n",getpid(),getppid());
     sleep(1);
	exit(EXIT_SUCCESS);

}
