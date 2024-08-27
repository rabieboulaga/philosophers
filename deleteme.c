
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void)
{
    char *rl;
    rl = readline("Prompt > ");
    printf("%s\n", rl);
    free(rl);
    return (0);
}
