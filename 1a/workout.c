#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_SIZE 100

// Define token types
typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_DELIMITER,
    TOKEN_UNKNOWN
} TokenType;

// List of C keywords
const char *keywords[] = {"int", "return", "float", "char", "void", "if", "else", "while", "for", "do"};
int keywordCount = 10;

// Counters for each token type
int keywordCountFound = 0;
int identifierCount = 0;
int operatorCount = 0;
int numberCount = 0;
int delimiterCount = 0;
int argumentCount = 0;

// Function to check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to classify and count tokens
void classifyAndCountToken(char *token, TokenType type) {
    switch (type) {
        case TOKEN_KEYWORD:
            keywordCountFound++;
            printf("%s is a keyword\n", token);
            break;
        case TOKEN_IDENTIFIER:
            identifierCount++;
            printf("%s is an identifier\n", token);
            break;
        case TOKEN_NUMBER:
            numberCount++;
            printf("%s is a number\n", token);
            break;
        case TOKEN_OPERATOR:
            operatorCount++;
            printf("%s is an operator\n", token);
            break;
        case TOKEN_DELIMITER:
            delimiterCount++;
            printf("%s is a delimiter\n", token);
            break;
        default:
            printf("%s is unknown\n", token);
    }
}

// Function to tokenize the input code
void tokenize(char *code) {
    int i = 0;
    char token[MAX_TOKEN_SIZE];
    int tokenIndex = 0;

    while (code[i] != '\0') {
        char currentChar = code[i];

        // Skip whitespace
        if (isspace(currentChar)) {
            i++;
            continue;
        }

        // Handle identifiers and keywords
        if (isalpha(currentChar) || currentChar == '_') {
            tokenIndex = 0;
            while (isalnum(currentChar) || currentChar == '_') {
                token[tokenIndex++] = currentChar;
                currentChar = code[++i];
            }
            token[tokenIndex] = '\0';
            if (isKeyword(token)) {
                classifyAndCountToken(token, TOKEN_KEYWORD);
            } else {
                classifyAndCountToken(token, TOKEN_IDENTIFIER);
            }
            continue;
        }

        // Handle numbers
        if (isdigit(currentChar)) {
            tokenIndex = 0;
            while (isdigit(currentChar)) {
                token[tokenIndex++] = currentChar;
                currentChar = code[++i];
            }
            token[tokenIndex] = '\0';
            classifyAndCountToken(token, TOKEN_NUMBER);
            continue;
        }

        // Handle operators
        if (strchr("+-*/=", currentChar)) {
            token[0] = currentChar;
            token[1] = '\0';
            classifyAndCountToken(token, TOKEN_OPERATOR);
            i++;
            continue;
        }

        // Handle delimiters
        if (strchr("();,{}", currentChar)) {
            token[0] = currentChar;
            token[1] = '\0';
            classifyAndCountToken(token, TOKEN_DELIMITER);
            i++;
            continue;
        }

        // Handle unknown characters
        token[0] = currentChar;
        token[1] = '\0';
        classifyAndCountToken(token, TOKEN_UNKNOWN);
        i++;
    }
}

int main() {
    char code[] = "int main() { int number1, number2, sum; printf(\"Enter two integers: \"); scanf(\"%d %d\", &number1, &number2); sum = number1 + number2; printf(\"%d + %d = %d \", number1, number2, sum); return 0; }";

    printf("Lexical Analysis:\n");
    tokenize(code);

    // Print summary
    printf("Keywords: %d\n", keywordCountFound);
    printf("Identifiers: %d\n", identifierCount);
    printf("Operators: %d\n", operatorCount);
    printf("Numbers: %d\n", numberCount);
    printf("Delimiters: %d\n", delimiterCount);
    printf("Arguments: %d\n", argumentCount);

    return 0;
}