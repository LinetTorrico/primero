#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
//esta es la modificacion,,,,,,,,,,,,,,,,//
#define READ_END    0   
#define WRITE_END   1   

/*#define FILE_NAME  "file.txt"    nombre del archivo donde escribir */

int main(int argc, char* argv[])   
{
	FILE *p;
    int fd1[2],fd2;
    int status, pid;
 // char path[] = "file.txt";
   char *path=argv[3];
   if (argc != 4)  /* Valido la entrada de parametros */
       {
     printf("uso : [comando] [comando]  [nombre.txt]  ejemplo -> ls sort hola.txt \n"); 

       exit (1);
       } 
   p=fopen(path,"w");
   fclose(p);
    pipe(fd1);              
    printf("verifique el archivo : %s ahi se guardo comando_ent comando_sal.\n",path);

    pid = fork();     

    if(pid == 0)                /* hijo 1, ejecuta "[comando] [comando]" */
    {              
        close(fd1[READ_END]); 
        dup2(fd1[WRITE_END], STDOUT_FILENO); 
        close(fd1[WRITE_END]);  
       // execlp("/bin/ls", "ls", "/home/publica/varios", NULL);
        execlp (argv[1], argv[1], NULL);
       
	 perror(argv[0]);
    }
    else                          /* padre */
    { 
       
		
     
          fd2 = open(path, O_WRONLY);
	 
          close(fd1[WRITE_END]);
          dup2(fd1[READ_END], STDIN_FILENO);
          close(fd1[READ_END]);
          dup2(fd2, STDOUT_FILENO);		          
         execlp(argv[2],argv[2],NULL);
	// execlp("/bin/sort", "sort", NULL);
           printf("verifique  %s\n");

	  
     }
   
 
   exit(EXIT_SUCCESS);
}
