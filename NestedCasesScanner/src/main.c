/**
* Name: Umit Demirci
* Lab: Lab 4 Nested Cases Scanner
* Date: 10/1/19
**/


//
//  main.c (driver for a scanner test)
//
//  Created by Bieszczad, A.J. on 9/20/17.
//  Copyright (c) 2017 CSUCI. All rights reserved.
//
//  ASSUMES: Lecture 1, 2, 3, 4

#include "scanner.h"

int main(int argc, char **argv)
{
    freopen(argv[1], "r", stdin);

    TOKEN *token = NULL;
    char *token2str[] = {"INVALID", "NUMBER", "IDENT", "ASSIGNMENT", "SEMICOLON", "LPAREN", "RPAREN", "PLUS", "MINUS",
                         "MULT", "DIV", "MOD", "REPEAT", "PRINT", "END_OF_INPUT"};
    printf("\n");
    while ((token = scanner()) != NULL)
    {
        // TODO replace the if-else with a call to printToken

        // call print token
        printToken(&token);
        freeToken(&token);
        fflush(stdout);
    }
    printf("\n");
    exit(EXIT_SUCCESS);
}