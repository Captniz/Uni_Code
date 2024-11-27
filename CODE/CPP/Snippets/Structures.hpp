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
