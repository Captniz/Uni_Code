#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <unordered_set>
using namespace std;

/* REGOLE:
 * 1. Babbo Natale Esagonale sceglie un triangolo che non sia primo o ultimo nella fila.
 * 2. Babbo Natale Esagonale consegna due regali al triangolo scelto.
 * 3. Il triangolo scelto dona uno dei suoi regali al triangolo di fronte. Se il triangolo scelto è girato verso sinistra, sceglierà il primo triangolo sulla sua sinistra.
 *4. I due triangoli vanno a giocare insieme fuori dalla fila
 */

int N = 0;
// int debug = 0; //! DEBUG
unordered_set<int> *results = new unordered_set<int>();

void get_possible_starts(vector<pair<int, int>> *tri);
void find_possible_paths(vector<pair<int, int>> *tri, int start_index);

void print_unordered_set(unordered_set<int> *s, ofstream &out)
{
    out << s->size() << endl;
    for (const int &i : *s)
        out << i << " ";
}

void print_vector_pairs(vector<pair<int, int>> *v)
{
    int size = v->size();
    for (int i = 0; i < size; i++)
        cout << "{" << v->at(i).first << "," << v->at(i).second << "} ";
    cout << endl;
}

void shorten_vector(vector<pair<int, int>> *tri, int start_index)
{
    for (int i = start_index + 2; i < tri->size(); i++)
        tri->at(i - 2) = tri->at(i);
    tri->resize(tri->size() - 2);
}

void rebuild_vector(vector<pair<int, int>> *tri, int rebuild_index, pair<int, int> start_pair, pair<int, int> target_pair)
{
    tri->resize(tri->size() + 2, {0, 0});

    for (int i = tri->size() - 3; i >= rebuild_index; i--)
        tri->at(i + 2) = tri->at(i);

    tri->at(start_pair.second) = start_pair;
    tri->at(start_pair.second + start_pair.first) = target_pair;
}

void get_possible_starts(vector<pair<int, int>> *tri)
{
    // Removes the possibility of start from situations like >>> and ><
    //! Should NEVER GET CALLED IF SIZE < 3
    int size = tri->size();

    for (int i = 1; i < size - 1; i++)
    {
        int curr = tri->at(i).first;

        if (curr == 1)
        {
            if (tri->at(i + 1).first == -1) // check ><
            {
                find_possible_paths(tri, i);
                i++;
                continue;
            }
            else if (i + 2 < size - 1 && tri->at(i + 2).first == 1) // check >>>
            {
                find_possible_paths(tri, i);
                i++; // salta il prossimo
                continue;
            }
        }
        else if (i + 2 < size - 1 && tri->at(i + 1).first + tri->at(i + 2).first == -2) // check <<<
        {
            find_possible_paths(tri, i);
            i++; // salta il prossimo
            continue;
        }
        find_possible_paths(tri, i);
    }
}

void find_possible_paths(vector<pair<int, int>> *tri, int start_index)
{
    // Find the minimum index to delete, this because we always delete two adjacent triangles
    int start_value = tri->at(start_index).first;
    pair<int, int> target_pair = tri->at(start_index + start_value);
    int min_deletion_index = start_value == 1 ? start_index : start_index - 1;

    // Shift left the vector from the deletion index
    shorten_vector(tri, min_deletion_index);

    // Verify base case
    if (tri->size() == 3)
    {
        results->insert((tri->at(1).first == -1 ? tri->at(2).second : tri->at(0).second));

        // Rebuild the vector to its previous state
        rebuild_vector(tri, min_deletion_index, {start_value, start_index}, target_pair);

        return;
    }

    // Recurive case
    get_possible_starts(tri);

    // Rebuild the vector to its previous state
    rebuild_vector(tri, min_deletion_index, {start_value, start_index}, target_pair);

    return;
}

int main(int argc, char const *argv[])
{
    // Leggi in input
    ifstream in("input.txt");
    in >> N;

    if (N <= 1)
    {
        in.close();
        ofstream out("output.txt");
        out << "0";
        out.close();
        return 0;
    }

    vector<pair<int, int>> *tri = new vector<pair<int, int>>();

    for (int i = 0; i < N; i++)
    {
        char c;
        in >> c;

        if (c == 's')
            tri->push_back({-1, i}); // sinistra
        else
            tri->push_back({1, i}); // destra
    }

    in.close();

    if (N <= 3)
    {
        ofstream out("output.txt");
        out << 1 << "\n"
            << (tri->at(1).first == -1 ? tri->at(2).second : tri->at(0).second);
        out.close();
        return 0;
    }

    // Parti con il leggere i possibili inizi
    get_possible_starts(tri);

    ofstream out("output.txt");
    print_unordered_set(results, out);
    out.close();

    return 0;
}
