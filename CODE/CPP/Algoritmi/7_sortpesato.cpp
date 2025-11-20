#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

/* REGOLE:
 * 0) Gli elementi sono tutti diversi, anzi sono precisamente tutti gli interi fra 1 e N
 * 1) Ad ogni turno potete scambiare due elementi a scelta dell’array
 * 2) Per scambiare due elementi si paga un prezzo pari alla somma dei due elementi
 *
 * DOMANDE:
 * 1) Posso prendere i numeri al momento o devo averli in un array?
 * 2) Mi vieta di cercare numeri specifici?
 */

int N = 0;
int min_index = 0;
int score = 0;
int moves = 0;

void swap_vector_elements(vector<int> *A, int i, int j)
{
    int temp = A->at(i);
    A->at(i) = A->at(j);
    A->at(j) = temp;

    // cout << "Swapping " << A->at(j) << " and " << A->at(i) << "\n";

    score += A->at(i) + A->at(j);
    moves++;
    min_index = j;

    return;
}

void search_next_min(vector<int> *A)
{
    int curr_min = A->at(min_index);

    for (int i = 0; i < N; i++)
        if (A->at(i) == curr_min + 1)
            min_index = i;
}

int search_target(vector<int> *A, int target)
{
    for (int i = 0; i < N; i++)
        if (A->at(i) == target)
            return i;
    return -1;
}

void write_output()
{
    ofstream out("output.txt");
    out << moves << " " << score << "\n";
    out.close();
}

void swap_with_min(vector<int> *A)
{
    // cout << "min_index read to " << min_index << "\n";
    while (A->at(min_index) == min_index + 1)
    {
        // cout << "Element at min index " << min_index << " is already correct with value " << A->at(min_index) << "\n";
        if (min_index == N - 1) // Error prone
        {
            write_output();
            exit(0);
        }
        search_next_min(A);
    }

    int target_index = search_target(A, min_index + 1);
    // cout << "Current min index: " << min_index << " with value " << A->at(min_index) << "\n";
    // cout << "Target index: " << target_index << " with value " << A->at(target_index) << "\n";
    swap_vector_elements(A, min_index, target_index);
}

int main(int argc, char const *argv[])
{
    ifstream in("input.txt");
    in >> N;

    if (N <= 1)
    {
        ofstream out("output.txt");
        out << "0 0\n";
        out.close();
        return 0;
    }

    vector<int> *A = new vector<int>(N);

    for (int i = 0; i < N; i++)
    {
        int curr;
        in >> curr;
        if (curr == 1)
            min_index = i;

        A->at(i) = curr;
    }
    in.close();

    // cout << "min_index initialized to " << min_index << "\n";

    for (;;)
        swap_with_min(A);

    return 0;
}
