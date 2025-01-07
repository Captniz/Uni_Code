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
    T Input_Utl(char message[]);
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
    int HextoDec_Utl(char *num);
    int BintoDec_Utl(char *num);
    char *DectoHex_Utl(int num);
    char *DectoBin_Utl(int num);
    int AnytoDec_Utl(char *num, int base);
    char *DectoAny_Utl(int num, int base);

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
    int
    Random_Utl(int max, int min)
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
    T Input_Utl(char message[])
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

    /**
     *@brief Converte un numero esadecimale in decimale.
     *
     *@param num Numero esadecimale.
     *@ return Numero decimale.
     */
    int HextoDec_Utl(char *num)
    {
        int len = strlen(num);
        int base = 1;
        int dec = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (num[i] >= '0' && num[i] <= '9')
            {
                dec += (num[i] - 48) * base;
                base *= 16;
            }
            else if (num[i] >= 'A' && num[i] <= 'F')
            {
                dec += (num[i] - 55) * base;
                base *= 16;
            }
        }
        return dec;
    }

    /**
     *@brief Converte un numero binario in decimale.
     *
     *@param num Numero binario.
     *@ return Numero decimale.
     */
    int BintoDec_Utl(char *num)
    {
        int len = strlen(num);
        int base = 1;
        int dec = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (num[i] == '1')
            {
                dec += base;
            }
            base *= 2;
        }
        return dec;
    }

    /**
     *@brief Converte un numero decimale in esadecimale.
     *
     *@param num Numero decimale.
     *@ return Numero esadecimale.
     */
    char *DectoHex_Utl(int num)
    {
        char *hex = new char[100];
        int i = 0;
        while (num != 0)
        {
            int temp = 0;
            temp = num % 16;
            if (temp < 10)
            {
                hex[i] = temp + 48;
            }
            else
            {
                hex[i] = temp + 55;
            }
            i++;
            num /= 16;
        }
        hex[i] = '\0';
        return hex;
    }

    /**
     *@brief Converte un numero decimale in binario
     *
     * @param num Numero decimale.
     * @return Numero binario.
     */
    char *DectoBin_Utl(int num)
    {
        char *bin = new char[100];
        int i = 0;
        while (num != 0)
        {
            bin[i] = num % 2 + 48;
            i++;
            num /= 2;
        }
        bin[i] = '\0';
        return bin;
    }

    /**
     *@brief Converte un numero in base base in decimale.
     *
     * @param num Numero.
     * @param base Base del numero.
     * @return Numero decimale.
     */
    int AnytoDec_Utl(char *num, int base)
    {
        int len = strlen(num);
        int dec = 0;
        int power = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            if (num[i] >= '0' && num[i] <= '9')
            {
                dec += (num[i] - 48) * power;
                power *= base;
            }
            else if (num[i] >= 'A' && num[i] <= 'Z')
            {
                dec += (num[i] - 55) * power;
                power *= base;
            }
        }
        return dec;
    }

    /**
     *@brief Converte un numero decimale in una base base.
     *
     * @param num Numero decimale.
     * @param base Base del numero.
     * @return Numero nella base base.
     */
    char *DectoAny_Utl(int num, int base)
    {
        char *res = new char[100];
        int i = 0;
        while (num != 0)
        {
            int temp = 0;
            temp = num % base;
            if (temp < 10)
            {
                res[i] = temp + 48;
            }
            else
            {
                res[i] = temp + 55;
            }
            i++;
            num /= base;
        }
        res[i] = '\0';
        return res;
    }
} // namespace utl
