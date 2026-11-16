
#include <iostream>

using namespace std;

void nQueen(int N);
void nQueenSolver(int **board, int N, int col);
bool isSafeMove(int **board, int N, int row, int col);
void printBoard(int **board, int N);

void nQueen(int N) {

    int **board = new int*[N];

    for (int i = 0; i < N; ++i)
        board[i] = new int[N];


    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = 0;

    nQueenSolver(board, N, 0);


    for (int i = 0; i < N; ++i)
        delete[] board[i];

    delete[] board;
}

void nQueenSolver(int **board, int N, int col) {

    for (int row = 0; row < N; ++row) {

        if (!isSafeMove(board, N, row, col))
            continue;

        board[row][col] = 1;

        if (col == N - 1) {
            printBoard(board, N);
            board[row][col] = 0;
            exit(0); 
        }

    
        nQueenSolver(board, N, col + 1);


        board[row][col] = 0;
    }
}

bool isSafeMove(int **board, int N, int row, int col) {

    
    for (int j = 0; j < col; ++j) {
        if (board[row][j] == 1)
            return false;
    }

    
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void printBoard(int **board, int N) {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << " ";

        cout << endl;
    }

    cout << endl;
}

int main() {

    int N = 4;
    nQueen(N);

    N = 5;
    nQueen(N);

    return 0;
}
