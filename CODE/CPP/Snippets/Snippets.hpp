using namespace std;

#include <iostream>
#include <fstream>

namespace str
{
    //  ###################################
    //  #           DECLARATIONS          #
    // ####################################

    int Length_Str(char *str);
    void Resize_Str(char *str);
    int ToInt_Str(char *str);
    char *ToCharArr_Str(string str);
    char *Copy_Str(char *str);
    int Compare_Str(char *str1, char *str2);
    char *Concat_Str(char *str1, char *str2);
    char *Substr_Str(char *str, int start, int end);
    char *Reverse_Str(char *str);
    char *ToLower_Str(char *str);
    char *ToUpper_Str(char *str);
    char *Trim_Str(char *str);
    char *Replace_Str(char *str, char *oldStr, char *newStr);
    char *Insert_Str(char *str, char *substr, int index);
    char *Delete_Str(char *str, int start, int end);

    //  ###################################
    //  #           DEFINITIONS           #
    // ####################################

    /**
     * @brief Calcola la lunghezza di una stringa.
     *
     * @param str Puntatore di stringa.
     * @return Lunghezza della stringa.
     */
    int Length_Str(char *str)
    {
        int length = 0;
        while (str[length] != '\0')
        {
            length++;
        }
        return length;
    }

    /**
     * @brief Ridimensiona una stringa alla corretta dimensione dell'array.
     *
     * @param str Puntatore di stringa.
     */
    void Resize_Str(char *str)
    {
        int len = Length_Str(str);
        char *resized = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            resized[i] = str[i];
        }
        resized[len] = '\0';
        str = resized;
        delete[] resized;
        return;
    }

    /**
     * @brief Converte una stringa in un intero.
     *
     * @param str Puntatore di stringa.
     * @return Intero convertito.
     */
    int ToInt_Str(char *str)
    {
        int num = 0;
        int len = Length_Str(str);
        for (int i = 0; i < len; i++)
        {
            num = num * 10 + (str[i] - '0');
        }
        return num;
    }

    /**
     * @brief Converte una stringa in un array di caratteri.
     *
     * @param str Stringa.
     * @return Puntatore di array di caratteri.
     */
    char *ToCharArr_Str(string str)
    {
        char *charArr = new char[str.length() + 1];
        for (int i = 0; i < str.length(); i++)
        {
            charArr[i] = str[i];
        }
        charArr[str.length()] = '\0';
        return charArr;
    }

    /**
     * @brief Copia una stringa.
     *
     * @param str Puntatore di stringa.
     * @return Puntatore di stringa copiata.
     */
    char *Copy_Str(char *str)
    {
        int len = Length_Str(str);
        char *copy = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            copy[i] = str[i];
        }
        copy[len] = '\0';
        return copy;
    }

    /**
     * @brief Confronta due stringhe.
     *
     * @param str1 Prima stringa.
     * @param str2 Seconda stringa.
     * @return 0 se le stringhe sono uguali, -1 se la prima è minore, 1 se la seconda è minore.
     */
    int Compare_Str(char *str1, char *str2)
    {
        int len1 = Length_Str(str1);
        int len2 = Length_Str(str2);
        if (len1 != len2)
        {
            return len1 < len2 ? -1 : 1;
        }
        for (int i = 0; i < len1; i++)
        {
            if (str1[i] < str2[i])
            {
                return -1;
            }
            else if (str1[i] > str2[i])
            {
                return 1;
            }
        }
        return 0;
    }

    /**
     * @brief Concatena due stringhe.
     *
     * @param str1 Prima stringa.
     * @param str2 Seconda stringa.
     * @return Puntatore di stringa concatenata.
     */
    char *Concat_Str(char *str1, char *str2)
    {
        int len1 = Length_Str(str1);
        int len2 = Length_Str(str2);

        char *concat = new char[len1 + len2 + 1];
        for (int i = 0; i < len1; i++)
        {
            concat[i] = str1[i];
        }
        for (int i = 0; i < len2; i++)
        {
            concat[len1 + i] = str2[i];
        }
        concat[len1 + len2] = '\0';
        return concat;
    }

    /**
     * @brief Estrae una sottostringa.
     *
     * @param str Stringa.
     * @param start Indice di inizio.
     * @param end Indice di fine.
     * @return Puntatore di sottostringa.
     */
    char *Substr_Str(char *str, int start, int end)
    {
        char *substr = new char[end - start + 1];
        for (int i = 0; i < end - start; i++)
        {
            substr[i] = str[start + i];
        }
        substr[end - start] = '\0';
        return substr;
    }

    /**
     * @brief Inverte una stringa.
     *
     * @param str Stringa.
     * @return Puntatore di stringa invertita.
     */
    char *Reverse_Str(char *str)
    {
        int len = Length_Str(str);
        char *reverse = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            reverse[i] = str[len - i - 1];
        }
        reverse[len] = '\0';
        return reverse;
    }

    /**
     * @brief Converte una stringa in minuscolo.
     *
     * @param str Stringa.
     * @return Puntatore di stringa in minuscolo.
     */
    char *ToLower_Str(char *str)
    {
        int len = Length_Str(str);
        char *lower = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            lower[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + 32 : str[i];
        }
        lower[len] = '\0';
        return lower;
    }

    /**
     * @brief Converte una stringa in maiuscolo.
     *
     * @param str Stringa.
     * @return Puntatore di stringa in maiuscolo.
     */
    char *ToUpper_Str(char *str)
    {
        int len = Length_Str(str);
        char *upper = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            upper[i] = str[i] >= 'a' && str[i] <= 'z' ? str[i] - 32 : str[i];
        }
        upper[len] = '\0';
        return upper;
    }

    /**
     * @brief Rimuove spazi bianchi all'inizio e alla fine di una stringa.
     *
     * @param str Stringa.
     * @return Puntatore di stringa senza spazi bianchi.
     */
    char *Trim_Str(char *str)
    {
        int start = 0;
        int end = Length_Str(str) - 1;
        while (str[start] == ' ')
        {
            start++;
        }
        while (str[end] == ' ')
        {
            end--;
        }
        return Substr_Str(str, start, end + 1);
    }

    /**
     * @brief Sostituisce una sottostringa con un'altra.
     *
     * @warning Buffer massimo di 256 caratteri.
     *
     * @param str Stringa.
     * @param oldStr Sottostringa da sostituire.
     * @param newStr Nuova sottostringa.
     * @return Puntatore di stringa con la sottostringa sostituita.
     */
    char *Replace_Str(char *str, char *oldStr, char *newStr)
    {
        char *replace = new char[256];
        int i = 0;
        int l = 0;
        while (i < Length_Str(str))
        {
            bool found = true;
            for (int j = 0; j < Length_Str(oldStr); j++)
            {
                if (str[i + j] != oldStr[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                for (int j = 0; j < Length_Str(newStr); j++)
                {
                    replace[j + l] = newStr[j];
                }
                l += Length_Str(newStr);
                i += Length_Str(oldStr);
            }
            else
            {
                replace[l] = str[i];
                i++;
                l++;
            }
        }
        replace[l] = '\0';
        str::Resize_Str(replace);
        return replace;
    }

    /**
     * @brief Inserisce una sottostringa in una stringa.
     *
     * @param str Stringa.
     * @param substr Sottostringa.
     * @param index Indice di inserimento.
     * @return Puntatore di stringa con la sottostringa inserita.
     */
    char *Insert_Str(char *str, char *substr, int index)
    {
        int len = Length_Str(str);
        int lenSub = Length_Str(substr);
        char *insert = new char[len + lenSub + 1];
        for (int i = 0; i < index; i++)
        {
            insert[i] = str[i];
        }
        for (int i = 0; i < lenSub; i++)
        {
            insert[index + i] = substr[i];
        }
        for (int i = 0; i < len - index; i++)
        {
            insert[index + lenSub + i] = str[index + i];
        }
        insert[len + lenSub] = '\0';
        return insert;
    }

    /**
     * @brief Elimina una sottostringa da una stringa, date le coordinate.
     * @attention Se si vuole cancellare una sottostringa, data la sottostringa stessa, si può usare Replace_Str.
     *
     *
     * @param str Stringa.
     * @param start Indice di inizio.
     * @param end Indice di fine.
     * @return Puntatore di stringa con la sottostringa eliminata.
     */
    char *Delete_Str(char *str, int start, int end)
    {
        int len = Length_Str(str);
        char *del = new char[len - (end - start) + 1];
        for (int i = 0; i < start; i++)
        {
            del[i] = str[i];
        }
        for (int i = 0; i < len - end; i++)
        {
            del[start + i] = str[end + i];
        }
        del[len - (end - start)] = '\0';
        return del;
    }

} // namespace str

namespace mat
{
    //  ###################################
    //  #           DECLARATIONS          #
    // ####################################

    int **Random_Mat(int row, int col, int min, int max);
    void Print_Mat(int **mat, int row, int col);
    void Print_Mat(double **mat, int row, int col);
    void Zero_Mat(int **mat, int row, int col);
    void Zero_Mat(char **mat, int row, int col);
    bool CoordsValid_Mat(int row, int col, int i, int j);
    int **Copy_Mat(int **mat, int row, int col);
    double **Copy_Mat(double **mat, int row, int col);
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
     * @brief Stampa matrice.
     *
     * @param mat Matrice di double.
     * @param row Numero di righe.
     * @param col Numero di colonne.
     */
    void Print_Mat(double **mat, int row, int col)
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
     * @brief Azzera matrice.
     *
     * @param mat Matrice di char.
     * @param row Numero di righe.
     * @param col Numero di colonne.
     */
    void Zero_Mat(char **mat, int row, int col)
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
    int **Copy_Mat(int **mat, int row, int col)
    {
        int **copy = new int *[row];
        for (int i = 0; i < row; i++)
        {
            copy[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                copy[i][j] = mat[i][j];
            }
        }
        return copy;
    }

    /**
     * @brief Copia matrice.
     *
     * @param mat Matrice di double.
     * @param row Numero di righe.
     * @param col Numero di colonne.
     * @return Puntatore di matrice di double copiata.
     */
    double **Copy_Mat(double **mat, int row, int col)
    {
        double **copy = new double *[row];
        for (int i = 0; i < row; i++)
        {
            copy[i] = new double[col];
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

namespace arr
{
    //  ###################################
    //  #           DECLARATIONS          #
    // ####################################

    int *Random_Arr(int size, int min, int max);
    void Print_Arr(int *arr, int size);
    void Print_Arr(float *arr, int size);
    void Zero_Arr(int *arr, int size);
    bool IndexValid_Arr(int size, int index);
    int *Copy_Arr(int *arr, int size);
    void Sort_Arr(int *arr, int size);
    void Sort_Arr(float *arr, int size);
    void Reverse_Arr(int *arr, int size);

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
    void Print_Arr(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /**
     * @brief Stampa array.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     */
    void Print_Arr(float *arr, int size)
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
     * @brief Sorta array.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     */
    void Sort_Arr(float *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    float temp = arr[i];
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

namespace stc
{
    //  ###################################
    //  #        STRUCT DECLARATIONS      #
    // ####################################

    template <typename T>
    struct Node_Stc;

    template <typename T>
    struct DoubleNode_Stc;

    template <typename T>
    struct LinkedList_Stc;
    //  Node_Stc<T> Get(int index = 0);
    //  T GetV(int index = 0);
    //  int Size();
    //  void Set(T data, int index = 0);
    //  void Insert(T data, int index);
    //  void Remove(int index);
    //  void Substitute(T data, int index);
    //  void Add(T data);
    //  void Print();

    template <typename T>
    struct CircularLinkedList_Stc;
    //  Node_Stc<T> GetCurrent();
    //  T GetVCurrent();
    //  Node_Stc<T> Cycle(int index = 1);
    //  T CycleV(int index = 1);
    //  void Next();
    //  void InsertCurr(T data);
    //  void SetCurr(T data);
    //  void RemoveCurr();
    //  void Print();

    template <typename T>
    struct DoubleLinkedList_Stc;
    //  DoubleNode_Stc<T> Get(int index = 0);
    //  T GetV(int index = 0);
    //  int Size();
    //  void Set(T data, int index = 0);
    //  void Insert(T data, int index);
    //  void Remove(int index);
    //  void Substitute(T data, int index);
    //  void Add(T data);
    //  void Print();

    template <typename T>
    struct Tree_Stc;

    template <typename T>
    struct Stack_Stc;
    //  Node_Stc<T> Top();
    //  T TopV();
    //  Node_Stc<T> Pop();
    //  T PopV();
    //  int Size();
    //  void Push(T data);
    //  void Print();
    //  bool IsEmpty();
    //  bool Find(T data)

    template <typename T>
    struct Queue_Stc;
    //  Node_Stc<T> Head();
    //  T HeadV();
    //  Node_Stc<T> Tail();
    //  T TailV();
    //  Node_Stc<T> Dequeue();
    //  T DequeueV();
    //  int Size();
    //  void Enqueue(T data);
    //  void Print();
    //  bool isEmpty();
    //  bool Find(T data)

    //  ###################################
    //  #        STRUCT DEFINITIONS       #
    // ####################################

    /**
     * @brief Nodo di una lista concatenata.
     *
     * @param data Dato del nodo.
     * @param next Puntatore al prossimo nodo.
     */
    template <typename T>
    struct Node_Stc
    {

        T data;
        Node_Stc *next;

        // #### Constructors & Destroyers ####

        Node_Stc(T data)
        {
            this->data = data;
            this->next = NULL;
        }

        Node_Stc(T data, Node_Stc *next)
        {
            this->data = data;
            this->next = next;
        }
    };

    /**
     * @brief Nodo di una lista concatenata doppia.
     *
     * @param data Dato del nodo.
     * @param next Puntatore al prossimo nodo.
     * @param prev Puntatore al nodo precedente.
     */
    template <typename T>
    struct DoubleNode_Stc
    {
        T data;
        DoubleNode_Stc *next;
        DoubleNode_Stc *prev;

        // #### Constructors & Destroyers ####

        DoubleNode_Stc(T data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        DoubleNode_Stc(T data, DoubleNode_Stc *next, DoubleNode_Stc *prev)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    /**
     * @brief Lista concatenata.
     *
     * @attention Parametri possibili del costruttore:
     *
     * @param size Dimensione della lista.
     * @param fill Dato di riempimento.
     * @param fill[] Array di dati di riempimento.
     */
    template <typename T>
    struct LinkedList_Stc
    {
    private:
        Node_Stc<T> *head;
        Node_Stc<T> *tail;
        int size;

    public:
        // #### Method Declarations ####

        // Node_Stc<T> Get(int index = 0);
        // T GetV(int index = 0);
        // int Size();
        // void Set(T data, int index = 0);
        // void Insert(T data, int index);
        // void Remove(int index);
        // void Substitute(T data, int index);
        // void Add(T data);
        // void Print();

        // #### Constructors & Destroyers ####

        LinkedList_Stc()
        {
            this->head = NULL;
        }

        LinkedList_Stc(int size, T fill)
        {
            this->head = NULL;
            for (int i = 0; i < size; i++)
            {
                Add(fill);
            }
        }

        LinkedList_Stc(int size, T fill[])
        {
            this->head = NULL;
            for (int i = 0; i < size; i++)
            {
                Add(fill[i]);
            }
        }

        ~LinkedList_Stc()
        {
            Destroy();
        }

        void Destroy()
        {
            Node_Stc<T> *current = head;
            Node_Stc<T> *next;
            while (current != NULL)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }

        // #### Getters ####

        /**
         * @brief Restituisce il nodo in una posizione specifica.
         *
         * @param index Indice del nodo.
         */
        Node_Stc<T> Get(int index = 0)
        {
            Node_Stc<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return *current;
        }

        /**
         * @brief Restituisce il dato in una posizione specifica.
         *
         * @param index Indice del nodo.
         */
        T GetV(int index = 0)
        {
            Node_Stc<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->data;
        }

        /**
         * @brief Restituisce la dimensione della lista.
         */
        int Size()
        {
            return size;
        }

        // #### Setters ####

        /**
         * @brief Modifica il dato in una posizione specifica.
         *
         * @param data Dato da inserire.
         * @param index Indice del nodo.
         */
        void Set(T data, int index = 0)
        {
            Node_Stc<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->data = data;
        }

        /**
         * @brief Inserisce un nodo in una posizione specifica.
         *
         * @warning Inserisce un NODO, non un dato, muovendo i nodi successivi.
         *
         * @param data Dato da inserire.
         * @param index Indice del nodo.
         */
        void Insert(T data, int index)
        {
            Node_Stc<T> *node = new Node_Stc<T>(data);
            if (index == 0)
            {
                node->next = head;
                head = node;
            }
            else
            {
                Node_Stc<T> *current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                node->next = current->next;
                current->next = node;
            }
            size++;
        }

        /**
         * @brief Rimuove un nodo in una posizione specifica.
         *
         * @param index Indice del nodo.
         */
        void Remove(int index)
        {
            if (index == 0)
            {
                Node_Stc<T> *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                Node_Stc<T> *current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                Node_Stc<T> *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            size--;
        }

        /**
         * @brief Sostituisce il dato in una posizione specifica.
         *
         * @param data Dato da inserire.
         * @param index Indice del nodo.
         */
        void Substitute(T data, int index)
        {
            Node_Stc<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->data = data;
        }

        /**
         * @brief Aggiunge un nodo alla fine della lista.
         *
         * @param data Dato da inserire.
         */
        void Add(T data)
        {
            Node_Stc<T> *node = new Node_Stc<T>(data);
            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            size++;
        }

        // #### Methods ####

        /**
         * @brief Stampa la lista.
         */
        void Print()
        {
            Node_Stc<T> *current = head;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };

    /**
     * @brief Lista concatenata.
     *
     * @attention Parametri possibili del costruttore:
     *
     * @param size Dimensione della lista.
     * @param fill Dato di riempimento.
     * @param fill[] Array di dati di riempimento.
     */
    template <typename T>
    struct CircularLinkedList_Stc
    {
    private:
        Node_Stc<T> *current;
        int size;

    public:
        // #### Method Declarations ####

        // Node_Stc<T> GetCurrent();
        // T GetVCurrent();
        // Node_Stc<T> Cycle(int index = 1);
        // T CycleV(int index = 1);
        // void Next();
        // void InsertCurr(T data);
        // void SetCurr(T data);
        // void RemoveCurr();
        // void Print();

        // #### Constructors & Destroyers ####

        CircularLinkedList_Stc()
        {
            this->current = NULL;
        }

        CircularLinkedList_Stc(int size, T fill)
        {
            Node_Stc<T> *head = new Node_Stc<T>(fill);
            this->current = head;
            for (int i = 0; i < size - 1; i++)
            {
                current->next = new Node_Stc<T>(fill);
                current = current->next;
            }
            current->next = head;
            this->size = size;
        }

        CircularLinkedList_Stc(int size, T fill[])
        {
            Node_Stc<T> *head = new Node_Stc<T>(fill[0]);
            this->current = head;
            for (int i = 0; i < size - 1; i++)
            {
                current->next = new Node_Stc<T>(fill[i + 1]);
                current = current->next;
            }
            current->next = head;
            this->size = size;
        }

        ~CircularLinkedList_Stc()
        {
            Destroy();
        }

        void Destroy()
        {
            Node_Stc<T> *curr = current;
            Node_Stc<T> *next;
            for (int i = 0; i < size; i++)
            {
                next = curr->next;
                delete curr;
                curr = next;
            }
        }

        // #### Getters ####

        /**
         * @brief Restituisce il nodo corrente.
         */
        Node_Stc<T> GetCurrent()
        {
            return *current;
        }

        /**
         * @brief Restituisce il dato corrente.
         */
        T GetVCurrent()
        {
            return current->data;
        }

        /**
         * @brief Restituisce il nodo corrente e manda avanti il puntatore.
         *
         * @param index Indice del nodo. Default 1 posizione.
         */
        Node_Stc<T> Cycle(int index = 1)
        {
            Node_Stc<T> *tmp = current;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return *tmp;
        }

        /**
         * @brief Restituisce il dato corrente e manda avanti il puntatore.
         *
         * @param index Indice del nodo. Default 1 posizione.
         */
        T CycleV(int index = 1)
        {
            T tmp = current->data;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return tmp;
        }

        // #### Setters ####

        /**
         * @brief Manda avanti il puntatore.
         */
        void Next()
        {
            current = current->next;
        }

        /**
         * @brief Modifica il dato corrente.
         *
         * @param data Dato da inserire.
         */
        void SetCurr(T data)
        {
            current->data = data;
        }

        /**
         * @brief Inserisce un nodo dopo il nodo corrente.
         *
         * @param data Dato da inserire.
         */
        void InsertCurr(T data)
        {
            Node_Stc<T> *node = new Node_Stc<T>(data);
            node->next = current->next;
            current->next = node;
            size++;
        }

        /**
         * @brief Rimuove il nodo corrente.
         */
        void RemoveCurr()
        {
            Node_Stc<T> *toDelete = current;

            // If the list has only one node:
            if (current->next == current)
            {
                current = nullptr; // Break the circular link
                delete toDelete;
                size--;
                return;
            }

            // Find the previous node (to fix the circular link)
            Node_Stc<T> *prev = current;
            while (prev->next != current)
            {
                prev = prev->next;
            }

            // Update links to skip the current node
            prev->next = current->next;

            // Move `current` to the next node
            current = current->next;

            // Delete the old node
            delete toDelete;

            size--;
        }

        // #### Methods ####

        /**
         * @brief Stampa la lista.
         */
        void Print()
        {
            for (int i = 0; i < size; i++)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };

    /**
     * @brief Lista concatenata doppia.
     *
     * @attention Parametri possibili del costruttore:
     *
     * @param size Dimensione della lista.
     * @param fill Dato di riempimento.
     * @param fill[] Array di dati di riempimento.
     */
    template <typename T>
    struct DoubleLinkedList_Stc
    {
    private:
        DoubleNode_Stc<T> *head;
        DoubleNode_Stc<T> *tail;
        int size;

    public:
        // #### Method Declarations ####

        // DoubleNode_Stc<T> Get(int index = 0);
        // T GetV(int index = 0);
        // int Size();
        // void Set(T data, int index = 0);
        // void Insert(T data, int index);
        // void Remove(int index);
        // void Substitute(T data, int index);
        // void Add(T data);
        // void Print();

        // #### Constructors & Destroyers ####

        DoubleLinkedList_Stc()
        {
            this->head = NULL;
        }

        DoubleLinkedList_Stc(int size, T fill)
        {
            this->head = NULL;
            for (int i = 0; i < size; i++)
            {
                Add(fill);
            }
        }

        DoubleLinkedList_Stc(int size, T fill[])
        {
            this->head = NULL;
            for (int i = 0; i < size; i++)
            {
                Add(fill[i]);
            }
        }

        ~DoubleLinkedList_Stc()
        {
            Destroy();
        }

        void Destroy()
        {
            DoubleNode_Stc<T> *current = head;
            DoubleNode_Stc<T> *next;
            while (current != NULL)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }

        // #### Getters ####

        /**
         * @brief Restituisce il nodo in una posizione specifica.
         *
         * @param index Indice del nodo.
         */
        DoubleNode_Stc<T> Get(int index = 0)
        {
            DoubleNode_Stc<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return *current;
        }

        /**
         * @brief Restituisce il dato in una posizione specifica.
         *
         * @param index Indice del nodo.
         */
        T GetV(int index = 0)
        {
            DoubleNode_Stc<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->data;
        }

        /**
         * @brief Restituisce la dimensione della lista.
         */
        int Size()
        {
            return size;
        }

        // #### Setters ####

        /**
         * @brief Modifica il dato in una posizione specifica.
         *
         * @param data Dato da inserire.
         * @param index Indice del nodo.
         */
        void Set(T data, int index = 0)
        {
            DoubleNode_Stc<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->data = data;
        }

        /**
         * @brief Inserisce un nodo in una posizione specifica.
         *
         * @warning Inserisce un NODO, non un dato, muovendo i nodi successivi.
         *
         * @param data Dato da inserire.
         * @param index Indice del nodo.
         */
        void Insert(T data, int index)
        {
            DoubleNode_Stc<T> *node = new DoubleNode_Stc<T>(data);
            if (index == 0)
            {
                node->next = head;
                head = node;
            }
            else
            {
                DoubleNode_Stc<T> *current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                node->next = current->next;
                current->next = node;
            }
            size++;
        }

        /**
         * @brief Rimuove un nodo in una posizione specifica.
         *
         * @param index Indice del nodo.
         */
        void Remove(int index)
        {
            if (index == 0)
            {
                DoubleNode_Stc<T> *temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                DoubleNode_Stc<T> *current = head;
                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                DoubleNode_Stc<T> *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            size--;
        }

        /**
         * @brief Sostituisce il dato in una posizione specifica.
         *
         * @param data Dato da inserire.
         * @param index Indice del nodo.
         */
        void Substitute(T data, int index)
        {
            DoubleNode_Stc<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->data = data;
        }

        /**
         * @brief Aggiunge un nodo alla fine della lista.
         *
         * @param data Dato da inserire.
         */
        void Add(T data)
        {
            DoubleNode_Stc<T> *node = new DoubleNode_Stc<T>(data);
            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            size++;
        }

        // #### Methods ####

        /**
         * @brief Stampa la lista.
         */
        void Print()
        {
            DoubleNode_Stc<T> *current = head;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };

    /**
     * @brief Albero binario.
     *
     * @attention Parametri possibili del costruttore:
     *
     * @param size Dimensione dell'albero.
     * @param fill Dato di riempimento.
     * @param fill[] Array di dati di riempimento.
     */
    template <typename T>
    struct Tree_Stc
    {
        // TODO
    };

    /**
     * @brief Pila.
     *
     * @attention Parametri possibili del costruttore:
     *
     * @param size Dimensione della pila.
     * @param fill Dato di riempimento.
     * @param fill[] Array di dati di riempimento.
     */
    template <typename T>
    struct Stack_Stc
    {
    private:
        Node_Stc<T> *top;
        int size;

    public:
        // #### Method Declarations ####

        // Node_Stc<T> Top();
        // T TopV();
        // Node_Stc<T> Pop();
        // T PopV();
        // int Size();
        // void Push(T data);
        // void Print();
        // bool IsEmpty();
        // bool Find(T data);

        // #### Constructors & Destroyers ####

        Stack_Stc()
        {
            this->top = NULL;
            size = 0;
        }

        Stack_Stc(T fill, int size = 1)
        {
            this->size = 0;
            this->top = NULL;
            for (int i = 0; i < size; i++)
            {
                Push(fill);
            }
        }

        Stack_Stc(T fill[], int size = 1)
        {
            this->size = 0;
            this->top = NULL;
            for (int i = 0; i < size; i++)
            {
                Push(fill[i]);
            }
        }

        ~Stack_Stc()
        {
            Destroy();
        }

        void Destroy()
        {
            Node_Stc<T> *current = top;
            Node_Stc<T> *next;
            while (current != NULL)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }

        // #### Getters ####

        /**
         * @brief Restituisce il nodo in cima alla pila.
         * @warning NON rimuove il nodo
         */
        Node_Stc<T> Top()
        {
            if (top == NULL || size == 0)
            {
                cout << "Stack is empty" << endl;
                return Node_Stc<T>(NULL);
            }
            return *top;
        }

        /**
         * @brief Restituisce il dato in cima alla pila.
         * @warning NON rimuove il nodo
         */
        T TopV()
        {
            if (top == NULL || size == 0)
            {
                cout << "Stack is empty" << endl;
                return (T)NULL;
            }
            return top->data;
        }

        /**
         * @brief Restituisce il nodo in cima alla pila.
         * @warning Rimuove il nodo
         */
        Node_Stc<T> Pop()
        {
            if (top == NULL || size == 0)
            {
                cout << "Stack is empty" << endl;
                return Node_Stc<T>(NULL);
            }

            Node_Stc<T> *temp = top;
            top = top->next;
            size--;
            return *temp;
        }

        /**
         * @brief Restituisce il dato in cima alla pila.
         * @warning Rimuove il nodo
         */
        T PopV()
        {
            if (top == NULL || size == 0)
            {
                cout << "Stack is empty" << endl;
                return (T)NULL;
            }
            Node_Stc<T> *temp = top;
            top = top->next;
            size--;
            return temp->data;
        }

        /**
         * @brief Restituisce la dimensione della pila.
         */
        int Size()
        {
            return size;
        }

        // #### Setters ####

        /**
         * @brief Inserisce un nodo in cima alla pila.
         *
         * @param data Dato da inserire.
         */
        void Push(T data)
        {
            Node_Stc<T> *node = new Node_Stc<T>(data);
            node->next = top;
            top = node;
            size++;
        }

        // #### Methods ####

        /**
         * @brief Stampa la pila.
         */
        void Print()
        {
            Node_Stc<T> *current = top;
            while (current != NULL)
            {
                cout << current->data << " << ";
                current = current->next;
            }
            cout << endl;
        }

        /**
         * @brief Controlla se la pila è vuota.
         *
         * @return true se la pila è vuota, false altrimenti.
         */
        bool IsEmpty()
        {
            return size == 0;
        }

        /**
         * @brief Cerca un dato nella pila.
         *
         * @param data Dato da cercare.
         *
         * @return true se il dato è presente, false altrimenti.
         */
        bool Find(T data)
        {
            Node_Stc<T> *current = top;
            while (current != NULL)
            {
                if (current->data == data)
                {
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    };

    /**
     * @brief Coda.
     *
     * @attention Parametri possibili del costruttore:
     *
     * @param size Dimensione della coda.
     * @param fill Dato di riempimento.
     * @param fill[] Array di dati di riempimento.
     */
    template <typename T>
    struct Queue_Stc
    {
    private:
        Node_Stc<T> *head;
        Node_Stc<T> *tail;
        int size;

    public:
        // #### Method Declarations ####

        // Node_Stc<T> Head();
        // T HeadV();
        // Node_Stc<T> Tail();
        // T TailV();
        // Node_Stc<T> Dequeue();
        // T DequeueV();
        // int Size();
        // void Enqueue(T data);
        // void Print();
        // bool isEmpty();
        // bool Find(T data)

        // #### Constructors & Destroyers ####

        Queue_Stc()
        {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }

        Queue_Stc(T fill, int size = 1)
        {
            this->head = NULL;
            this->tail = NULL;
            for (int i = 0; i < size; i++)
            {
                Enqueue(fill);
            }
        }

        Queue_Stc(T fill[], int size = 1)
        {
            this->head = NULL;
            this->tail = NULL;
            for (int i = 0; i < size; i++)
            {
                Enqueue(fill[i]);
            }
        }

        ~Queue_Stc()
        {
            Destroy();
        }

        void Destroy()
        {
            Node_Stc<T> *current = head;
            Node_Stc<T> *next;
            while (current != NULL)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }

        // #### Getters ####

        /**
         * @brief Restituisce il nodo in testa alla coda.
         * @warning NON rimuove il nodo
         */
        Node_Stc<T> Head()
        {
            if (head == NULL || size == 0)
            {
                cout << "Queue is empty" << endl;
                return Node_Stc<T>(NULL);
            }
            return *head;
        }

        /**
         * @brief Restituisce il dato in testa alla coda.
         * @warning NON rimuove il nodo
         */
        T HeadV()
        {
            if (head == NULL || size == 0)
            {
                cout << "Queue is empty" << endl;
                return (T)NULL;
            }
            return head->data;
        }

        /**
         * @brief Restituisce il nodo in coda alla coda.
         * @warning NON rimuove il nodo
         */
        Node_Stc<T> Tail()
        {
            if (tail == NULL || size == 0)
            {
                cout << "Queue is empty" << endl;
                return Node_Stc<T>(NULL);
            }
            return *tail;
        }

        /**
         * @brief Restituisce il dato in coda alla coda.
         * @warning NON rimuove il nodo
         */
        T TailV()
        {
            if (tail == NULL || size == 0)
            {
                cout << "Queue is empty" << endl;
                return (T)NULL;
            }
            return tail->data;
        }

        /**
         * @brief Restituisce il nodo in testa alla coda.
         * @warning Rimuove il nodo.
         */
        Node_Stc<T> Dequeue()
        {
            if (head == NULL || size == 0)
            {
                cout << "Queue is empty" << endl;
                return Node_Stc<T>(NULL);
            }
            Node_Stc<T> *temp = head;
            head = head->next;
            size--;
            return *temp;
        }

        /**
         * @brief Restituisce il dato in testa alla coda.
         * @warning Rimuove il nodo.
         */
        T DequeueV()
        {
            if (head == NULL || size == 0)
            {
                cout << "Queue is empty" << endl;
                return (T)NULL;
            }
            Node_Stc<T> *temp = head;
            head = head->next;
            size--;
            return temp->data;
        }

        /**
         * @brief Restituisce la dimensione della coda.
         */
        int Size()
        {
            return size;
        }

        // #### Setters ####

        /**
         * @brief Inserisce un nodo in coda alla coda.
         * @param data Dato da inserire.
         */
        void Enqueue(T data)
        {
            Node_Stc<T> *node = new Node_Stc<T>(data);
            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            size++;
        }

        // #### Methods ####

        /**
         * @brief Stampa la coda.
         */
        void Print()
        {
            Node_Stc<T> *current = head;
            while (current != NULL)
            {
                cout << current->data << " << ";
                current = current->next;
            }
            cout << endl;
        }

        /**
         * @brief Controlla se la coda è vuota.
         */
        bool isEmpty()
        {
            return size == 0;
        }

        /**
         * @brief Cerca un dato nella pila.
         *
         * @param data Dato da cercare.
         *
         * @return true se il dato è presente, false altrimenti.
         */
        bool Find(T data)
        {
            Node_Stc<T> *current = head;
            while (current != NULL)
            {
                if (current->data == data)
                {
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    };

} // namespace stc

namespace mix
{
    //  ###################################
    //  #           DECLARATIONS          #
    // ####################################

    int Random_Mix(int max, int min);
    int InputInt_Mix(string message);
    char *InputString_Mix(string message);
    void Swap_Mix(int &a, int &b);
    double Average_Mix(int *arr, int size);
    int Max2_Mix(int a, int b);
    int Min2_Mix(int a, int b);
    int Max3_Mix(int a, int b, int c);
    int Min3_Mix(int a, int b, int c);
    int MaxN_Mix(int *arr, int size);
    int MinN_Mix(int *arr, int size);
    int *TimeNormalize_Mix(int sec, int min, int hour, int day);
    fstream OpenFile_Mix(string filename, ios_base::openmode mode);

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
    int Random_Mix(int max, int min)
    {
        srand(time(NULL));
        return rand() % (max - min + 1) + min;
    }

    /**
     * @brief Richiesta di input dall'utente di un intero.
     *
     * @param message Messaggio da stampare.
     * @return Intero inserito.
     */
    int InputInt_Mix(string message)
    {
        int input;
        cout << message;
        cin >> input;
        return input;
    }

    /**
     * @brief Richiesta di input dall'utente di una stringa.
     *
     * @param message Messaggio da stampare.
     * @return Puntatore di stringa inserita.
     */
    char *InputString_Mix(string message)
    {
        char input[256];
        cout << message;
        cin >> input;

        char *resizedInput = new char[str::Length_Str(input) + 1];
        for (int i = 0; i < (str::Length_Str(input) + 1); i++)
        {
            resizedInput[i] = input[i];
        }

        return resizedInput;
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
     * @brief Calcola la media di un array di interi.
     *
     * @param arr Array di interi.
     * @param size Dimensione dell'array.
     * @return Media dell'array.
     */
    double Average_Mix(int *arr, int size)
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

    /**
     * @brief Apre un file.
     *
     * @param filename Nome del file.
     * @param mode Modalità di apertura.
     * @return Oggetto fstream.
     */
    fstream OpenFile_Mix(string filename, ios_base::openmode mode)
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
} // namespace mix
