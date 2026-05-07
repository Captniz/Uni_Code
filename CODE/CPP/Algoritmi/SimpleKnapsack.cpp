#include <iostream>
#include <vector>
using namespace std;

int SimpleKnapsack(int *memo, int *V, int limit, int target)
{
    if (limit < 0)
        return target;

    if (target < V[limit])
        return SimpleKnapsack(memo, V, (limit - 1), target);

    if (memo[target] != -1)
        return memo[target];

    int remainder;
    int tmp;

    // Non prendo l'item
    remainder = SimpleKnapsack(memo, V, (limit - 1), target);

    // Prendo l'item
    tmp = SimpleKnapsack(memo, V, limit, (target - V[limit]));

    // Remainder è il resto minore tra i due alberi
    remainder = remainder < tmp ? remainder : tmp;

    return remainder;
};

int SimpleKnapsackWrap(int *V, int limit, int target)
{
    limit--;
    // Limit è l'indice massimo dell'array V, quindi limit = n - 1

    // Creazione della matrice memo, inizializzata a 0
    int *memo = new int[target + 1];
    for (int i = 0; i <= target; i++)
        memo[i] = -1;

    for (int i = 1; i < target; i++)
        memo[i] = SimpleKnapsack(memo, V, limit, i);

    // stampa memo
    cout << "memo = [ ";
    for (int i = 0; i < target; i++)
        cout << memo[i] << " ";
    cout << "]" << endl;

    return target - SimpleKnapsack(memo, V, limit, target);
}

int main()
{
    int V[] = {10, 6, 4};
    int n = 3;
    int W = 8;

    cout << "Best sum: " << SimpleKnapsackWrap(V, n, W) << endl;

    return 0;
}