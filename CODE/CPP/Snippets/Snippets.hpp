using namespace std;

#include <iostream>

namespace mix
{
    int RandomQuick_Mix(int max, int min);
    void Swap_Mix(int &a, int &b);
    int Max2_Mix(int a, int b);
    int Min2_Mix(int a, int b);
    int Max3_Mix(int a, int b, int c);
    int Min3_Mix(int a, int b, int c);
    int MaxN_Mix(int *arr, int size);
    int MinN_Mix(int *arr, int size);
    int *TimeNormalize_Mix(int sec, int min, int hour, int day);

    /**
     * @brief Genera un numero random.
     *
     * @param max Valore massimo del random.
     * @param min Valore minimo del random.
     * @return Numero random.
     */
    int RandomQuick_Mix(int max, int min)
    {
        srand(time(NULL));
        return rand() % (max - min + 1) + min;
    }

    /**
     * @brief Scambia due valori.
     *
     * @param a Primo valore.
     * @param b Secondo valore.
     */
    void Swap_Mix(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    /**
     * @brief Calcola il massimo tra due valori.
     *
     * @param a Primo valore.
     * @param b Secondo valore.
     * @return Massimo tra i due valori.
     */
    int Max2_Mix(int a, int b)
    {
        return a > b ? a : b;
    }

    /**
     * @brief Calcola il minimo tra due valori.
     *
     * @param a Primo valore.
     * @param b Secondo valore.
     * @return Minimo tra i due valori.
     */
    int Min2_Mix(int a, int b)
    {
        return a < b ? a : b;
    }

    /**
     * @brief Calcola il massimo tra tre valori.
     *
     * @param a Primo valore.
     * @param b Secondo valore.
     * @param c Terzo valore.
     * @return Massimo tra i tre valori.
     */
    int Max3_Mix(int a, int b, int c)
    {
        return Max2_Mix(Max2_Mix(a, b), c);
    }

    /**
     * @brief Calcola il minimo tra tre valori.
     *
     * @param a Primo valore.
     * @param b Secondo valore.
     * @param c Terzo valore.
     * @return Minimo tra i tre valori.
     */
    int Min3_Mix(int a, int b, int c)
    {
        return Min2_Mix(Min2_Mix(a, b), c);
    }

    /**
     * @brief Calcola il massimo tra N valori.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     * @return Massimo tra i valori dell'array.
     */
    int MaxN_Mix(int *arr, int size)
    {
        int max = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }

    /**
     * @brief Calcola il minimo tra N valori.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     * @return Minimo tra i valori dell'array.
     */
    int MinN_Mix(int *arr, int size)
    {
        int min = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        return min;
    }

    /**
     * @brief Dati secondi, minuti, ore e giorni, normalizza il tempo.
     *
     * @param sec Secondi.
     * @param min Minuti.
     * @param hour Ore.
     * @param day Giorni.
     * @return Puntatore di array di interi con tempo normalizzato. Dimensione: 4.
     */
    int *TimeNormalize_Mix(int sec, int min = 0, int hour = 0, int day = 0)
    {
        int *time = new int[4];
        time[0] = sec % 60;
        time[1] = (sec / 60 + min) % 60;
        time[2] = (sec / 3600 + min / 60 + hour) % 24;
        time[3] = sec / 86400 + min / 1440 + hour / 24 + day;
        return time;
    }
} // namespace mix

namespace mat
{

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
    void Print_Mat(int **mat, int row, int col)
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
     * @param mat Matrice di interi.
     * @param row Numero di righe.
     * @param col Numero di colonne.
     */
    void Zero_Mat(int **mat, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = 0;
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

} // namespace mat

namespace arr
{

    /**
     * @brief Crea un array random.
     *
     * @param size Dimensione dell'array.
     * @param min Valore minimo del random.
     * @param max Valore massimo del random.
     * @return Puntatore di array di interi random.
     */
    int *Random_Arr(int size, int min, int max)
    {
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % (max - min + 1) + min;
        }
        return arr;
    }

    /**
     * @brief Stampa array.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     */
    void Print_Arr(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /**
     * @brief Azzera array.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     */
    void Zero_Arr(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    /**
     * @brief Controlla se l'indice è valido nell'array.
     *
     * @param index Indice.
     * @return true se l'indice è valido, false altrimenti.
     */
    bool IndexValid_Arr(int size, int index)
    {
        return index >= 0 && index < size;
    }

    /**
     * @brief Copia array.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     * @return Puntatore di array di interi copiato.
     */
    int *Copy_Arr(int *arr, int size)
    {
        int *copy = new int[size];
        for (int i = 0; i < size; i++)
        {
            copy[i] = arr[i];
        }
        return copy;
    }

    /**
     * @brief Sorta array.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     */
    void Sort_Arr(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    /**
     * @brief Inverte array
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     */
    void Reverse_Arr(int *arr, int size)
    {
        for (int i = 0; i < size / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

} // namespace arr
