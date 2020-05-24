#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

int GetClassSymbol(char c) {
    switch (c) {
    case 'r':
        return 0;
    case 'e':
        return 1;
    case 'a':
        return 2;
    case 'p':
        return 3;
    case 'n':
        return 4;
    case 'd':
        return 5;
    case 't':
        return 6;
    case 'o':
        return 7;
    case 'm':
        return 8;
    case 'i':
        return 9;
    case 'u':
        return 10;
    default:
        return 11;
    }
}

int main() {
    char S[100];    // the line from the file

    int M[][12] =
    {
        {1, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5},
        {-5, 2, 7, -5, -5, -5, -5, -5, -5, -5, -5, -5},
        {12, -5, -5, 3, -5, 15, -5, -5, -5, -5, -5, -5},
        {-5, 4, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5},
        {-5, -5, 5, -5, -5, 5, -5, -5, -5, -5, -5, -5},
        {-5, -5, -5, -5, -5, -5, 6, -5, -5, -5, -5, -5},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-5, -5, -5, -5, 8, -5, -5, -5, -5, -5, -5, -5},
        {-5, -5, -5, -5, -5, 9, -5, -5, -5, -5, -5, -5},
        {-5, -5, -5, -5, -5, -5, -5, 10, -5, -5, -5, -5},
        {-5, -5, -5, -5, -5, -5, -5, -5, 11, -5, -5, -5},
        {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2},
        {-5, -5, 7, -5, -5, -5, -5, -5, -5, -5, 13, -5},
        {-5, -5, -5, -5, 14, -5, -5, -5, -5, -5, -5, -5},
        {-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3},
        {-5, -5, -5, -5, -5, -5, -5, -5, -5, 16, -5, -5},
        {-5, -5, -5, -5, -5, -5, -5, -5, 17, -5, -5, -5},
        {-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4},
    }; // matrix of movements

    const char* out[] = { "Word repeat ", "Word random ", "Word rerun ", "Word redim ", "Other symbol " };

    FILE* in = fopen("lexer.dat", "r");
    FILE* outFile = fopen("output.txt", "w");

    fprintf(outFile, "%s", "");
    fclose(outFile);

    outFile = fopen("output.txt", "a");

    S[0] = '\0';
    int i = 0;
    int ST = 0; // initial condition
    char outStr[] = "";

    while (1)
    {
        if ((ST == 0) && (S[i] == '\0'))
        {
            if (fgets(S, 100, in) == NULL) {
                cout << "End of work" << endl;
                fputs("End of work\n", outFile);
                return 0;
            }
            i = 0;
        }

        int CL = GetClassSymbol(S[i]);
        ST = M[ST][CL];// automats movement

        i++;
        if (ST < 0) // checking whether that is the final condition
        {
            // if not other symbol
            if (ST != -5)
            {
                i--;
                cout << out[-ST - 1];
                fputs(out[-ST - 1], outFile);
                puts("");
                fprintf(outFile, "%c", '\n');
            }

            // return to the initial condition
            ST = 0;
        }
    }
    return 0;
}
