/**
* Name: Umit Demirci
* Lab: Lab 4 Nested Cases Scanner
* Date: 10/1/19
**/


#ifndef __SCANNER_H

#define __SCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum
{
    INVALID_TOKEN = 0,
    NUMBER_TOKEN,
    IDENT_TOKEN,
    ASSIGNMENT_TOKEN,
    SEMICOLON_TOKEN,
    LPAREN_TOKEN,
    RPAREN_TOKEN,
    PLUS_TOKEN,
    MINUS_TOKEN,
    MULT_TOKEN,
    DIV_TOKEN,
    MOD_TOKEN,
    REPEAT_TOKEN,
    PRINT_TOKEN,
    END_OF_INPUT_TOKEN
} TOKEN_TYPE;

typedef union
{
    int number;
    char *string;
    char in;
} TOKEN_VALUE;

typedef struct token
{
    TOKEN_TYPE type;
    TOKEN_VALUE val;
} TOKEN;

TOKEN *scanner();

void ungetToken(TOKEN **);

void freeToken(TOKEN **);

void printToken(TOKEN **);

#define BUF_SIZE 128
#define MAX_LINE_LENGTH 256

#endif