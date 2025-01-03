using namespace std;

#include <iostream>

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
    // int Size();
    // int Levels();
    // void Add(T data);
    // T Get_LevelOrder();
    // T Get_Min();
    // T Get_Max();
    // T* Get_PreOrder();
    // T* Get_PostOrder();
    // T* Get_InOrder();
    // T* Get_LevelOrder();
    // void Print();
    // void Print_PreOrder();
    // void Print_PostOrder();
    // void Print_InOrder();
    // void Print_LevelOrder();
    // void Balance();
    // DoubleNode_Stc<T> Find(T data);

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

        DoubleLinkedList_Stc(T fill, int size = 1)
        {
            this->head = NULL;
            for (int i = 0; i < size; i++)
            {
                Add(fill);
            }
        }

        DoubleLinkedList_Stc(T fill[], int size = 1)
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
    private:
        int size;
        int levels;
        DoubleNode_Stc<T> *root;

    public:
        // #### Method Declarations ####

        // int Size();
        // int Levels();
        // void Add(T data);
        // T Get_LevelOrder();
        // T Get_Min();
        // T Get_Max();
        // T* Get_PreOrder();
        // T* Get_PostOrder();
        // T* Get_InOrder();
        // T* Get_LevelOrder();
        // void Print();
        // void Print_PreOrder();
        // void Print_PostOrder();
        // void Print_InOrder();
        // void Print_LevelOrder();
        // void Balance();
        // DoubleNode_Stc<T> Find(T data);

        // #### Constructors & Destroyers ####

        Tree_Stc()
        {
            this->root = NULL;
            size = 0;
            levels = 0;
        }

        Tree_Stc(T fill)
        {
            this->size = 0;
            levels = 0;
            this->root = NULL;
            Add(fill);
        }

        Tree_Stc(T fill[], int size = 1)
        {
            this->size = 0;
            levels = 0;
            this->root = NULL;
            for (int i = 0; i < size; i++)
            {
                Add(fill[i]);
            }
        }

        void Destroy(DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL)
            {
                node = root;
            }
            if (node != NULL)
            {
                if (node->prev != NULL)
                {
                    Destroy(node->prev);
                }

                if (node->next != NULL)
                {
                    Destroy(node->next);
                }

                delete node;
            }
        }

        ~Tree_Stc()
        {
            Destroy();
        }

        // #### Getters ####

        /**
         * @brief Restituisce il numero di nodi dell'albero.
         */
        int Size()
        {
            return size;
        }

        /**
         * @brief Restituisce il numero di livelli dell'albero.
         */
        int Levels()
        {
            return levels;
        }

        /**
         * @brief Restituisce il dato minore dell'albero.
         *
         * @return Dato minore.
         */
        T Get_Min(DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL)
            {
                node = root;
            }

            if (node->prev == NULL)
            {
                return node->data;
            }
            else
            {
                return Get_Min(node->prev);
            }
        }

        /**
         * @brief Restituisce il dato maggiore dell'albero.
         *
         * @return Dato maggiore.
         */
        T Get_Max(DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL)
            {
                node = root;
            }

            if (node->next == NULL)
            {
                return node->data;
            }
            else
            {
                return Get_Max(node->next);
            }
        }

        /**
         * @brief Restituisce i dati dell'albero in un array in pre-ordine.
         * (radice, sinistra, destra).
         *
         * @return T* Array di dati.
         */
        T *Get_PreOrder(DoubleNode_Stc<T> *node = NULL, T *arr = NULL, int *index = nullptr)
        {
            if (node == NULL && arr == NULL && index == nullptr)
            {
                node = root;
                arr = new T[size];
                index = new int(0);
            }

            if (node != NULL)
            {
                arr[*index] = node->data;
                *index += 1;
                Get_PreOrder(node->prev, arr, index);
                Get_PreOrder(node->next, arr, index);
            }

            return arr;
        }

        /**
         * @brief Restituisce i dati dell'albero in un array in post-ordine.
         * (sinistra, destra, radice).
         *
         * @return T* Array di dati.
         */
        T *Get_PostOrder(DoubleNode_Stc<T> *node = NULL, T *arr = NULL, int *index = nullptr)
        {
            if (node == NULL && arr == NULL && index == nullptr)
            {
                node = root;
                arr = new T[size];
                index = new int(0);
            }

            if (node != NULL)
            {
                Get_PostOrder(node->prev, arr, index);
                Get_PostOrder(node->next, arr, index);
                arr[*index] = node->data;
                *index += 1;
            }

            return arr;
        }

        /**
         * @brief Restituisce i dati dell'albero in un array in ordine.
         * (sinistra, radice, destra).
         *
         * @return T* Array di dati.
         */
        T *Get_InOrder(DoubleNode_Stc<T> *node = NULL, T *arr = NULL, int *index = nullptr)
        {
            if (node == NULL && arr == NULL && index == nullptr)
            {
                node = root;
                arr = new T[size];
                index = new int(0);
            }

            if (node != NULL)
            {
                Get_InOrder(node->prev, arr, index);
                arr[*index] = node->data;
                *index += 1;
                Get_InOrder(node->next, arr, index);
            }

            return arr;
        }

        /**
         * @brief Restituisce i dati dell'albero in un array in ordine per livelli.
         * (radice, primo livello, secondo livello, ...).
         *
         * @return T* Array di dati.
         */
        T *Get_LevelOrder(DoubleNode_Stc<T> *node = NULL, T *arr = NULL, int *index = nullptr)
        {
            if (node == NULL && arr == NULL && index == nullptr)
            {
                node = root;
                arr = new T[size];
                index = new int(0);
            }

            if (node != NULL)
            {
                Queue_Stc<DoubleNode_Stc<T> *> queue = Queue_Stc<DoubleNode_Stc<T> *>();
                queue.Enqueue(node);

                while (!queue.isEmpty())
                {
                    DoubleNode_Stc<T> *current = queue.DequeueV();
                    arr[*index] = current->data;
                    *index += 1;

                    if (current->prev != NULL)
                        queue.Enqueue(current->prev);

                    if (current->next != NULL)
                        queue.Enqueue(current->next);
                }
            }

            return arr;
        }

        // #### Setters ####

        /**
         * @brief Aggiunge un nodo all'albero.
         *
         * @param data Dato da inserire.
         */
        void Add(T data)
        {
            DoubleNode_Stc<T> *node = new DoubleNode_Stc<T>(data);
            int lvl_ctr = 1;

            if (root == NULL)
            {
                root = node;
                levels = 1;
            }
            else
            {
                DoubleNode_Stc<T> *current = root;

                while (true)
                {
                    if (data < current->data)
                    {
                        if (current->prev == NULL)
                        {
                            current->prev = node;
                            lvl_ctr++;
                            break;
                        }
                        else
                        {
                            current = current->prev;
                            lvl_ctr++;
                        }
                    }
                    else
                    {
                        if (current->next == NULL)
                        {
                            current->next = node;
                            lvl_ctr++;
                            break;
                        }
                        else
                        {
                            current = current->next;
                            lvl_ctr++;
                        }
                    }
                }
            }

            if (lvl_ctr > levels)
            {
                levels = lvl_ctr;
            }
            size++;
        }

        // #### Methods ####

        /**
         * @brief Stampa l'albero.
         */
        void Print(int lvl = 0, DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL && lvl == 0)
                node = root;

            if (node != NULL)
            {
                Print(lvl + 1, node->next);
                for (int i = 0; i < lvl; i++)
                {
                    cout << "   ";
                }
                cout << node->data << endl;
                Print(lvl + 1, node->prev);
            }
        }

        /**
         * @brief Stampa l'albero in pre-ordine.
         * (radice, sinistra, destra).
         */
        void Print_PreOrder(DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL)
                node = root;

            if (node != NULL)
            {
                cout << node->data << " ";

                if (node->prev != NULL)
                    Print_PreOrder(node->prev);

                if (node->next != NULL)
                    Print_PreOrder(node->next);
            }
        }

        /**
         * @brief Stampa l'albero in post-ordine.
         * (sinistra, destra, radice).
         */
        void Print_PostOrder(DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL)
                node = root;

            if (node != NULL)
            {
                if (node->prev != NULL)
                    Print_PostOrder(node->prev);

                if (node->next != NULL)
                    Print_PostOrder(node->next);

                cout << node->data << " ";
            }
        }

        /**
         * @brief Stampa l'albero in ordine.
         * (sinistra, radice, destra).
         */
        void Print_InOrder(DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL)
                node = root;

            if (node != NULL)
            {
                if (node->prev != NULL)
                    Print_InOrder(node->prev);

                cout << node->data << " ";

                if (node->next != NULL)
                    Print_InOrder(node->next);
            }
        }

        /**
         * @brief Stampa l'albero in ordine per livelli.
         * (radice, primo livello, secondo livello, ...).
         */
        void Print_LevelOrder(DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL)
                node = root;

            if (node != NULL)
            {
                Queue_Stc<DoubleNode_Stc<T> *> queue = Queue_Stc<DoubleNode_Stc<T> *>();
                queue.Enqueue(node);

                while (!queue.isEmpty())
                {
                    DoubleNode_Stc<T> *current = queue.DequeueV();
                    cout << current->data << " ";

                    if (current->prev != NULL)
                        queue.Enqueue(current->prev);

                    if (current->next != NULL)
                        queue.Enqueue(current->next);
                }
            }
        }

        /**
         * @brief Bilancia l'albero.
         */
        void Balance()
        {
            if (size == 0)
                return;

            T even_save = (T)NULL;
            bool even = false;
            int arr_size = size;

            if (size % 2 == 0)
            {
                even = true;
                even_save = Get_InOrder()[arr_size - 1];
                arr_size--;
            }

            int arr_index = size / 2;

            // Get data
            T *arr_cpy = Get_InOrder();
            T **arr = new T *[arr_size];

            for (int i = 0; i < arr_size; i++)
                arr[i] = &arr_cpy[i];

            // Reset
            Destroy();
            root = NULL;
            size = 0;
            levels = 0;

            // Add root
            Add(*arr[arr_index]);
            arr[arr_index] = nullptr;
            arr_index /= 2;

            while (arr_index >= 0)
            {
                for (int i = arr_index; i < arr_size; i += ((arr_index == 0 ? 1 : arr_index) * 2))
                {
                    if (arr[i] != nullptr)
                    {
                        Add(*arr[i]);
                        arr[i] = nullptr;
                    }
                }
                if (arr_index == 0)
                {
                    break;
                }
                arr_index /= 2;
            }

            if (even)
            {
                Add(even_save);
            }
        }

        void Blanace2()
        {
            // Es. Arr
            // 0 1 2 3 4 5 6 7 8 9
            // TODO

            int tree_size = size;
            int left_size = 0;
            int right_size = 0;
            T *arr = Get_InOrder();

            Destroy();
            root = NULL;
            size = 0;
            levels = 0;

            Add(arr[tree_size / 2]);
            left_size = tree_size / 2;
            right_size = tree_size - left_size - 1;

            int left_index = left_size / 2;
            int right_index = right_size / 2;

            while (true)
            {
            }
        }

        /**
         * @brief Cerca un dato nell'albero.
         *
         * @param data Dato da cercare.
         *
         * @return DoubleNode_Stc<T> Nodo contenente il dato.
         * @return NULL Se il dato non è presente.
         */
        DoubleNode_Stc<T> Find(T data, DoubleNode_Stc<T> *node = NULL)
        {
            if (node == NULL)
                node = root;

            if (node == NULL)
                return NULL;

            if (node->data == data)
                return *node;

            if (data < node->data)
                return Find(data, node->prev);
            else
                return Find(data, node->next);
        }
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
