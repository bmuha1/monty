# 0x19. C - Stacks, Queues - LIFO, FIFO

This project is a Monty bytecode interpreter.

## Learning Objectives
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables
- How to work with git submodules

## Data Structures
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```
```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

<b>Monty byte code files</b>

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$
```
```
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$
```

## Supported Commands
- push: Push an element to the stack
- pall: Print all the values on the stack, starting from the top
- pint: Print the value at the top of the stack
- pop: Remove the top element of the stack
- swap: Swap the top two elements of the stack
- add: Add the top two elements of the stack
- nop: Do nothing
- sub: Subtract the top element of the stack from the second element
- div: Divide the second element of the stack by the top element
- mul: Multiply the top two elements of the stack
- mod: Modulus divide the second element of the stack by the top element
- pchar: Print the character at the top of the stack
- pstr: Print the string starting at the top of the stack
- rotl: Rotate the stack to the top
- rotr: Rotate the stack to the bottom
- stack: Set the format of the data to a stack (LIFO) (default behavior)
- queue: Set the format of the data to a queue (FIFO)
