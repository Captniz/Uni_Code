using namespace std;

#include <iostream>

namespace mat
{
    //  ###################################
    //  #           DECLARATIONS          #
    // ####################################

    int **Random_Mat(int row, int col, int min, int max);
    template <typename T>
    void Print_Mat(T **mat, int row, int col);
    template <typename T>
    void Zero_Mat(T **mat, int row, int col);
    bool CoordsValid_Mat(int row, int col, int i, int j);
    template <typename T>
    int **Copy_Mat(T **mat, int row, int col);
    int Determinant_Mat(int **mat, int n);

    //  ###################################
    //  #           DEFINITIONS           #
    // ####################################

    /**
     * @brief Crea una matrice random.
     *
     * @param row Numero di righe.
     * @param col Numero di colonne.
     * @param min Valore minimo del random.
     * @param max Valore massimo del random.
     * @return Puntatore di matrice di interi random.
     */
    int **Random_Mat(int row, int col, int min, int max)
    {
        srand(time(NULL));
        int **mat = new int *[row];
        for (int i = 0; i < row; i++)
        {
            mat[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = rand() % (max - min + 1) + min;
            }
        }
        return mat;
    }

    /**
     * @brief Stampa matrice.
     *
     * @param mat Matrice di interi.
     * @param row Numero di righe.
     * @param col Numero di colonne.
     */
    template <typename T>
    void Print_Mat(T **mat, int row, int col)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    /**
     * @brief Azzera matrice.
     *
     * @param mat Matrice di char.
     * @param row Numero di righe.
     * @param col Numero di colonne.
     */
    template <typename T>
    void Zero_Mat(T **mat, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = ' ';
            }
        }
    }

    /**
     * @brief Controlla se le coordinate sono valide nella matrice.
     *
     * @param row Numero di righe.
     * @param col Numero di colonne.
     * @param i Indice di riga.
     * @param j Indice di colonna.
     * @return true se le coordinate sono valide, false altrimenti.
     */
    bool CoordsValid_Mat(int row, int col, int i, int j)
    {
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    /**
     * @brief Copia matrice.
     *
     * @param mat Matrice di interi.
     * @param row Numero di righe.
     * @param col Numero di colonne.
     * @return Puntatore di matrice di interi copiata.
     */
    template <typename T>
    T **Copy_Mat(T **mat, int row, int col)
    {
        T **copy = new T *[row];
        for (int i = 0; i < row; i++)
        {
            copy[i] = new T[col];
            for (int j = 0; j < col; j++)
            {
                copy[i][j] = mat[i][j];
            }
        }
        return copy;
    }

    /**
     * @brief Calcola il determinante di una matrice.
     *
     * @param mat Matrice di interi.
     * @param n Dimensione della matrice.
     * @return Determinante della matrice.
     */
    int Determinant_Mat(int **mat, int n)
    {
        int det = 0;
        int add = 1;
        int sub = 1;

        for (int i = 0; i < n; i++)
        {
            add = 1;
            sub = 1;
            for (int j = 0; j < n; j++)
            {
                add *= mat[j][(i + j) % n];
                sub *= mat[j][(i + (n - 1) - j) % n];
            }
            det += add - sub;
        }
        return det;
    }

} // namespace mat
