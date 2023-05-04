#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

/* For the output remove s and */
/* Declare a buffer for user input of size 2048 */
static char input[2048];

/* Fake readline function */
char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(input, 2048, stdin);
	char* cpy = malloc(strlen(input)+1);
	strcpy(cpy, input);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
#include <history.h>
#endif

/* Exchanging s with th */
char *replace_s_with_th(char *str) {
    char *result = malloc(strlen(str) * 2 + 1);
    char *dst = result;
    for (; *str; ++str) {
        if (*str == 's') {
            *dst++ = 't';
            *dst++ = 'h';
        } else {
            *dst++ = *str;
        }
    }
    *dst = '\0';
    return result;
}

int main(int argc, char** argv) {

  /* Print Version and Exit Information */
  puts("Lithpy Verthion 0.0.0.0.1");
  puts("Prethth Ctrl+c to Exit\n");

  /* In a never ending loop */
  while (1) {

    /* Output our prompt */
	char* input = readline("lithpy> ");
	add_history(input);

	char *replaced_str = replace_s_with_th(input);
    /* Echo input back to user */
	printf("No you're a %s\n", replaced_str);
	
	free(replaced_str);
	free(input);
  }

  return 0;
}