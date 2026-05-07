#include <iostream>
#include <fstream>
#include <vector>
#include <array>

using namespace std;

template <typename T, std::size_t N>
class FixedQueue
{
    std::array<T, N> data{};
    std::size_t head = 0;
    std::size_t tail = 0;
    std::size_t count = 0;

public:
    bool empty() const { return count == 0; }
    bool full() const { return count == N; }
    std::size_t size() const { return count; }

    void push(const T &value)
    {
        if (full())
            throw std::runtime_error("queue full");
        data[tail] = value;
        tail = (tail + 1) % N;
        ++count;
    }

    void pop()
    {
        if (empty())
            throw std::runtime_error("queue empty");
        head = (head + 1) % N;
        --count;
    }

    T &front()
    {
        if (empty())
            throw std::runtime_error("queue empty");
        return data[head];
    }
};

struct Commissione
{
    FixedQueue<int, 2> Exp;
    FixedQueue<int, 3> Rng;
};

int const N = 25;
int const K = 5;

Commissione Comms[K];
int Prof[N] = {3, 0, 4, 1, 2, 2, 4, 0, 3, 1, 4, 2, 0, 1, 3, 3, 4, 1, 0, 2, 1, 4, 3, 0, 2};

int fun(Commissione C[K], int P[N])
{
    int FillCtr = 0;

    if (N < K * 5)
        return 1;

    for (int i = 0; i < N; i++)
        if (!(C[P[i]].Exp.full()))
            C[P[i]].Exp.push(i);
        else
        {
            if (C[FillCtr].Rng.full())
                FillCtr++;
            C[FillCtr].Rng.push(i);
        }
    return 0;
}

void printComms(Commissione C[K])
{
    for (int i = 0; i < K; i++)
    {
        cout << "Commissione " << i << ":\n";
        cout << "  Esperti: ";
        while (!C[i].Exp.empty())
        {
            cout << C[i].Exp.front() << " ";
            C[i].Exp.pop();
        }
        cout << "\n  Rappresentanti: ";
        while (!C[i].Rng.empty())
        {
            cout << C[i].Rng.front() << " ";
            C[i].Rng.pop();
        }
        cout << "\n\n";
    }
}

int main()
{
    fun(Comms, Prof);
    printComms(Comms);

    return 0;
}