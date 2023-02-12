#include <stdio.h>
#include <stdbool.h>
#include <string.h>


enum sudokuFlags
{

    COMPLETE = 1,
    INCOMPLETE_BUT_VIABLE = 2,
    NON_VIABLE = 3

};
typedef enum sudokuFlags SudokuFlags;


struct nonViableSudokuResult
{

    bool rows[9];
    bool cols[9];
    bool subMatrices[9];

};
typedef struct nonViableSudokuResult NonViableSudokuResult;


struct sudoku
{

    int matrix[3][3][3][3];
    SudokuFlags result;
    NonViableSudokuResult nonViableResult;
    
};
typedef struct sudoku Sudoku;



void inputSudokuMatrix(int matrix[3][3][3][3])
{

    for(int i = 0; i < 3; ++i)
    {
        for(int k = 0; k < 3; ++k)
        {
            for(int j = 0; j < 3; ++j)
            {
                for(int l = 0; l < 3; ++l)
                {
                    scanf("%d", &matrix[i][j][k][l]);
                }
            }
        }
    }

}


bool hasEmptyCells(int matrix[3][3][3][3])
{

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                for(int l = 0; l < 3; ++l)
                {
                    if (matrix[i][j][k][l] == 0) {
                        return true;
                    }
                }
            }
        }
    }

    return false;

}


bool isSubMartixViable(int subMatrix[3][3])
{
    
    bool digitsPresent[10] = { 0 }; // or use memset

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            int digit = subMatrix[i][j];
            if(digit == 0) {
                continue;
            }

            if(digitsPresent[digit] == true) {
                return false;
            }

            digitsPresent[digit] = true;
        }
    }

    return true;

}


bool areSubMatricesNonViable(int matrix[3][3][3][3], bool isNonViable[9])
{
    
    bool areNonViable = false;
    
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            bool isViable = isSubMartixViable(matrix[i][j]);
            isNonViable[(3 * i) + j] = !isViable;
            if(isViable == false) {
                areNonViable = true;
            }
        }
    }

    return areNonViable;

}


bool isRowViable(int matrix[3][3][3][3], int row)
{

    int i, k;
    if(row <= 3) {
        i = 0;
        k = row - 1;
    } else if (row <= 6) {
        i = 1;
        k = row % 4;
    } else {
        i = 2;
        k = row % 7;
    }

    bool digitsPresent[10] = { 0 }; // or use memset

    for(int j = 0; j < 3; ++j)
    {
        for(int l = 0; l < 3; ++l)
        {
            int digit = matrix[i][j][k][l];
            if(digit == 0) {
                continue;
            }

            if(digitsPresent[digit] == true) {
                return false;
            }

            digitsPresent[digit] = true;
        }
    }

    return true;

}

bool areRowsNonViable(int matrix[3][3][3][3], bool isNonViable[9])
{

    bool areNonViable = false;

    for(int i = 1; i <= 9; ++i) {
        bool isViable = isRowViable(matrix, i);
        isNonViable[i-1] = !isViable;
        if(isViable == false) {
            areNonViable = true;
        }
    }

    return areNonViable;

}


bool isColViable(int matrix[3][3][3][3], int col)
{

    int j, l;
    if(col <= 3) {
        j = 0;
        l = col - 1;
    } else if (col <= 6) {
        j = 1;
        l = col % 4;
    } else {
        j = 2;
        l = col % 7;
    }

    bool digitsPresent[10] = { 0 }; // or use memset

    for(int i = 0; i < 3; ++i)
    {
        for(int k = 0; k < 3; ++k)
        {
            int digit = matrix[i][j][k][l];
            if(digit == 0) {
                continue;
            }

            if(digitsPresent[digit] == true) {
                return false;
            }

            digitsPresent[digit] = true;
        }
    }

    return true;

}

bool areColsNonViable(int matrix[3][3][3][3], bool isNonViable[9])
{

    bool areNonViable = false;

    for(int i = 1; i <= 9; ++i) {
        bool isViable = isColViable(matrix, i);
        isNonViable[i-1] = !isViable;
        if(isViable == false) {
            areNonViable = true;
        }
    }

    return areNonViable;

}


void verifySudoku(Sudoku *s)
{
    
    bool isIncomplete = hasEmptyCells(s->matrix);

    bool subMatricesNonViability = areSubMatricesNonViable(s->matrix, s->nonViableResult.subMatrices);
    bool rowsNonViability = areRowsNonViable(s->matrix, s->nonViableResult.rows);
    bool colsNonViablitilty = areColsNonViable(s->matrix, s->nonViableResult.cols);

    if(subMatricesNonViability == true || rowsNonViability == true || colsNonViablitilty == true) {
        s->result = NON_VIABLE;
    } else if(isIncomplete == true) {
        s->result = INCOMPLETE_BUT_VIABLE;
    } else {
        s->result = COMPLETE;
    }

}


void printNonViableValues(bool isNonViable[9])
{
    for(int i = 0; i < 9; ++i) {
        if(isNonViable[i] == true) {
            printf(" %d", i+1);
        }
    }
    printf("\n");
}


void printSudokuOutput(Sudoku s)
{

    if(s.result == COMPLETE) {
        printf("complete\n");
    } else if(s.result == INCOMPLETE_BUT_VIABLE) {
        printf("incomplete but viable\n");
    } else {
        
        printf("non-viable\n");
        printf("\trows:");
        printNonViableValues(s.nonViableResult.rows);
        printf("\tcols:");
        printNonViableValues(s.nonViableResult.cols);
        printf("\tsub-matrices:");
        printNonViableValues(s.nonViableResult.subMatrices);

        for(int i = 0; i < 9; ++i) {
            printf("%d ", s.nonViableResult.subMatrices[i]);
        }

    }

}


int inputNoOfSudokus()
{
    int n;
    scanf("%d", &n);
    return n;
}

void inputSudokus(int n, Sudoku s[])
{
    for(int i = 0; i < n; ++i) {
        inputSudokuMatrix(s[i].matrix);
    }
}

void verifySudokus(int n, Sudoku s[])
{
    for(int i = 0; i < n; ++i)
    {
        verifySudoku(&s[i]);
    }
}

void printSudokuOutputs(int n, Sudoku s[])
{
    for(int i = 0; i < n; ++i)
    {
        printSudokuOutput(s[i]);
    }
}


int main()
{

    int n;
    n = inputNoOfSudokus();
    Sudoku s[n];
    inputSudokus(n, s);
    verifySudokus(n, s);
    printSudokuOutputs(n, s);
    return 0;

}