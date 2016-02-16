#include <stdio.h>
#include <string.h>

#define YELLOW "\x1B[33m"
#define NO_COLOR "\x1B[0m"
#define CYAN "\x1B[36m"

main(){
    
    char executable[] ="man";
    char flag[] = "-f";
    char page[100];

    char * args[4];
    args[0] = executable;
    args[1] = flag;
    args[2] = page;
    args[3] = NULL;


    puts(YELLOW "-----Vizzini's online help system-----" NO_COLOR);
    puts("Let a Sicillian with a superior intellect tell you how");
    puts("to use linux.");
    printf(CYAN "Enter man page: " NO_COLOR);
    fflush(stdout);


    fgets(page, 512, stdin);
    page[strlen(page)-1] = '\x00';
    
   if(execvp(args[0], args)==-1){
        puts("FAILED EXECVE");
        perror("execve");
   }

    return 0;
}
