#ifndef MONTY_FILE
#define MONTY_FILE

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_buff - str
 * @key: char key
 * @stream: char stream
 * @f: FILE f
 */
typedef struct global_buff
{
	char *key;
	char *stream;
	FILE *f;
} gBuff;

extern gBuff b;

/* parsingFile.c */
void readFile(char *file);
void parseFile(char *code, stack_t **stack, unsigned int line);
int checkFile(char *file);

/* getOp.c */
void free_all(stack_t *stack);
void getOp(stack_t **stack, unsigned int counter, char *code);

/* _pint.c */
void _pint(stack_t **stack, unsigned int line);

/* _push.c */
void _push(stack_t **stack, unsigned int line);

/* _pall.c */
void _pall(stack_t **h, unsigned int count);

/* _pop.c */
void _pop(stack_t **stack, unsigned int line);

/* math.c */
void _add(stack_t **stack, unsigned int line);
void _sub(stack_t **stack, unsigned int line);
void _mul(stack_t **stack, unsigned int line);
void _div(stack_t **stack, unsigned int line);
void _mod(stack_t **stack, unsigned int line);

/* _swap.c */
void _swap(stack_t **stack, unsigned int line);

/* _nop.c */
void _nop(stack_t **stack, unsigned int line);

/* printFunc.c */
void _rotl(stack_t **stack, unsigned int line);

#endif
