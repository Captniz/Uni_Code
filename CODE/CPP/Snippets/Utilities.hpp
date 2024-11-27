using namespace std;

#include <iostream>
#include <cstring>
#include <fstream>

namespace utl
{
    //  ###################################
    //  #           DECLARATIONS          #
    // ####################################

    int Random_Utl(int max, int min);
    template <typename T>
    int Input_Utl(string message);
    template <typename T>
    void Swap_Utl(int &a, int &b);
    double Average_Utl(int *arr, int size);
    int Max2_Utl(int a, int b);
    int Min2_Utl(int a, int b);
    int Max3_Utl(int a, int b, int c);
    int Min3_Utl(int a, int b, int c);
    int MaxN_Utl(int *arr, int size);
    int MinN_Utl(int *arr, int size);
    int *TimeNormalize_Utl(int sec, int min, int hour, int day);
    fstream OpenFile_Utl(string filename, ios_base::openmode mode);

    //  ###################################
    //  #           DEFINITIONS           #
    // ####################################

    /**
     * @brief Genera un numero random.
     *
     * @param max Valore massimo del random.
     * @param min Valore minimo del random.
     * @return Numero random.
     */
    int Random_Utl(int max, int min)
    {
        srand(time(NULL));
        return rand() % (max - min + 1) + min;
    }

    /**
     * @brief Richiesta di input dall'utente.
     *
     * @warning Not secure, use sparingly, prone to break. Remember to cast and check.
     *
     * @param message Messaggio da stampare.
     * @return Dato inserito dall'utente.
     */
    template <typename T>
    T Input_Utl(string message)
    {
        T input;
        cout << message;
        cin >> input;
        return input;
    }

    /**
     * @brief Scambia due variabili.
     *
     * @param a Primo valore.
     * @param b Secondo valore.
     */
    template <typename T>
    void Swap_Utl(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    /**
     * @brief Calcola la media di un array di interi.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     * @return Media dell'array.
     */
    double Average_Utl(int *arr, int size)
    {
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum / size;
    }

    /**
     * @brief Calcola il massimo tra due valori.
     *
     * @param a Primo valore.
     * @param b Secondo valore.
     * @return Massimo tra i due valori.
     */
    int Max2_Utl(int a, int b)
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
    int Min2_Utl(int a, int b)
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
    int Max3_Utl(int a, int b, int c)
    {
        return Max2_Utl(Max2_Utl(a, b), c);
    }

    /**
     * @brief Calcola il minimo tra tre valori.
     *
     * @param a Primo valore.
     * @param b Secondo valore.
     * @param c Terzo valore.
     * @return Minimo tra i tre valori.
     */
    int Min3_Utl(int a, int b, int c)
    {
        return Min2_Utl(Min2_Utl(a, b), c);
    }

    /**
     * @brief Calcola il massimo tra N valori.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     * @return Massimo tra i valori dell'array.
     */
    int MaxN_Utl(int *arr, int size)
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
    int MinN_Utl(int *arr, int size)
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
    int *TimeNormalize_Utl(int sec, int min = 0, int hour = 0, int day = 0)
    {
        int *time = new int[4];
        time[0] = sec % 60;
        time[1] = (sec / 60 + min) % 60;
        time[2] = (sec / 3600 + min / 60 + hour) % 24;
        time[3] = sec / 86400 + min / 1440 + hour / 24 + day;
        return time;
    }

    /**
     * @brief Apre un file.
     *
     * @param filename Nome del file.
     * @param mode Modalità di apertura.
     * @return Oggetto fstream.
     */
    fstream OpenFile_Utl(string filename, ios_base::openmode mode)
    {
        fstream file;
        file.open(filename, mode);
        if (!file)
        {
            cout << "Errore nell'apertura del file." << endl;
            exit(1);
        }
        return file;
    }
} // namespace utl
