/**
* Name: Umit Demirci
* Lab: Lab 4 Nested Cases Scanner
* Date: 10/1/19
**/


#include "scanner.h"

//
// clean up the token structure
//
void freeToken(TOKEN **token)
{
    if (token == NULL)
        return;

    if (*token == NULL)
        return;

    if ((*token)->type == IDENT_TOKEN)
    {
        if ((*token)->val.string != NULL)
        {
            free((*token)->val.string);
        }
    }

    free(*token);
    *token = NULL;
}

//
// check if a collected sequence of characters is a keyword
//
bool isKeyword(TOKEN *token, char *str)
{
    if (strcmp(str, "repeat") == 0)
    token->type = REPEAT_TOKEN;
    else if (strcmp(str, "print") == 0)
        token->type = PRINT_TOKEN;
    else
        return false;

    return true;
}

void printToken (TOKEN **token)
{
    // TODO print the contents of the reference TOKEN
    // printf("\nthe current type is %d", (*token)->type);


    switch ((*token)->type) {
        case 0:
            printf("\ninvalid token");

            break;
        case 1:
            printf("\nnumber token");
            printf("\ntoken value is -> %d\n\n", (*token)->val.number);
            break;
        case 2:
            if ((strcasecmp((*token)->val.string, "repeat") == 0)) {
                // (*token)->type = REPEAT_TOKEN;

                printf("\nrepeat token");
                printf("\ntoken value is -> %s\n\n", (*token)->val.string);


            } else if ((strcasecmp((*token)->val.string, "print") == 0)) {
                // (*token)->type = PRINT_TOKEN;
                printf("\nprint token");
                printf("\ntoken value is -> %s\n\n", (*token)->val.string);

            } else {
                printf("\nidentifier token");
                printf("\ntoken value is -> %s\n\n", (*token)->val.string);

            }
            break;
        case 3:
            printf("\nassignment token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
        case 4:
            printf("\nsemicolon token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
        case 5:
            printf("\nleft parenthesis token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
        case 6:
            printf("\nright parenthesis token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
        case 7:
            printf("\nplus token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
        case 8:
            printf("\nminus token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
        case 9:
            printf("\nmultipication token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
        case 10:
            printf("\ndivision token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
        case 11:
            printf("\nmod token");
            printf("\ntoken value is -> %c\n\n", (*token)->val.in);
            break;
/*        case 12:
            printf("\nrepeat token\n");
            printf("\ntoken value is %c", (*token)->val.in);
            break;
        case 13:
            printf("\nprint token\n");
            printf("\ntoken value is %c", (*token)->val.in);
            break;*/
        case 14:
            break;

    }


}

TOKEN *scanner()
{
    // temporary buffer for collecting characters
    char tempString[BUF_SIZE];

    // acquire space for the new token
    TOKEN *token = (TOKEN *) malloc(sizeof(TOKEN));
    token->type = INVALID_TOKEN;

    char currentChar;
    int tempStringIndex = 0;

    while (currentChar != EOF)
    {
        // populate the while loop
        // read the next character
        // do we change the tken type if so which type
        // then is the cycle over


        currentChar = getc(stdin);
        switch (token->type) {
            case INVALID_TOKEN:
                switch (currentChar) {
                    case ' ':

                    case '\n':

                    case '\t':

                    case '\r':
                        break;
                    case '0'...'9':
                        // change the token type to the correct one
                        // store currentChar om the tempString
                        token->type = NUMBER_TOKEN;
                        tempString[tempStringIndex] = currentChar;
                        tempStringIndex++;
                        break;
                    case 'a'...'z':
                        token->type = IDENT_TOKEN;
                        tempString[tempStringIndex] = currentChar;
                        tempStringIndex++;
                        break;
                    case '(':
                        // do something
                        token->type = LPAREN_TOKEN;
                        token->val.in = currentChar;
                        return token;
                    case ')':
                        token->type = RPAREN_TOKEN;
                        token->val.in = currentChar;
                        return  token;
                    case ';':
                        token->type = SEMICOLON_TOKEN;
                        token->val.in = currentChar;
                        return token;
                    case '=':
                        token->type = ASSIGNMENT_TOKEN;
                        token->val.in = currentChar;
                        return token;
                    case '+':
                        token->type = PLUS_TOKEN;
                        token->val.in = currentChar;
                        return token;
                    case '-':
                        token->type = MINUS_TOKEN;
                        token->val.in = currentChar;
                        return token;
                    case '/':
                        token->type = DIV_TOKEN;
                        token->val.in = currentChar;
                        return token;
                    case '*':
                        token->type = MULT_TOKEN;
                        token->val.in = currentChar;
                        return token;
                    case '%':
                        token->type = MOD_TOKEN;
                        token->val.in = currentChar;
                        return token;
                    default:
                        token->type = END_OF_INPUT_TOKEN;
                        printf("end of input");
                }
                break;

            case NUMBER_TOKEN:

                switch (currentChar) {
                    case '0'...'9':
                        // continue the number (add the currentChar to the tepString)
                        tempString[tempStringIndex] = currentChar;
                        tempStringIndex++;

                        break;
                    default:
                        ungetc(currentChar, stdin);
                        // assign out token's number value token->val.number
                        // return token
                        // assign out token->val.number
                        token->val.number = atol(tempString);
                        return token;
                }
                break;
            case IDENT_TOKEN:
                switch (currentChar) {
                    case 'a'...'z':
                        // continue the id being built
                        token->type = IDENT_TOKEN;
                        tempString[tempStringIndex] = currentChar;
                        tempStringIndex++;
                        break;
                    default:
                        ungetc(currentChar, stdin);

                        if (isKeyword(token, &currentChar)) {
                            // do something
                            return token;
                        } else {
                            // do something
                            // terminate
                            tempString[tempStringIndex] = '\0';
                            // allocate memory
                            token->val.string = malloc(strlen(tempString)+1);
                            strcpy(token->val.string, tempString);

                            return token;
                        }
                }
        }
    }
    return NULL;
}

