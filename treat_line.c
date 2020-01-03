#include <header.h>

void treat_line(stack_t **head, char *line, unsigned int line_number)
{
        char *token = NULL;

        token = strtok(line , " \n");
        while (token == " ")
                token = strtok(null, " \n");
        treat_token(token);
}
