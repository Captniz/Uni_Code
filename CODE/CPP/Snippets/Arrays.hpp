using namespace std;

#include <iostream>
#include <cstring>

namespace arr
{
    //  ###################################
    //  #           DECLARATIONS          #
    // ####################################

    int *Random_Arr(int size, int min, int max);
    template <typename T>
    void Print_Arr(T *arr, int size);
    template <typename T>
    void Zero_Arr(T *arr, int size);
    bool IndexValid_Arr(int size, int index);
    template <typename T>
    T *Copy_Arr(T *arr, int size);
    template <typename T>
    void Sort_Arr(T *arr, int size);
    void Sort_Arr(char *arr, int size);
    template <typename T>
    void Reverse_Arr(T *arr, int size);

    //  ###################################
    //  #           DEFINITIONS           #
    // ####################################

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
        srand(time(NULL));
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
    template <typename T>
    void Print_Arr(T *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /**
     * @brief Azzera array con valori NULL.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     */
    template <typename T>
    void Zero_Arr(T *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = (T)NULL;
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
    template <typename T>
    T *Copy_Arr(T *arr, int size)
    {
        T *copy = new T[size];
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
    template <typename T>
    void Sort_Arr(T *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    /**
     * @brief Sorta array.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     */
    void Sort_Arr(char **arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (strcmp(arr[i], arr[j]) > 0)
                {
                    char *temp = arr[i];
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
    template <typename T>
    void Reverse_Arr(T *arr, int size)
    {
        for (int i = 0; i < size / 2; i++)
        {
            T temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

} // namespace arr
