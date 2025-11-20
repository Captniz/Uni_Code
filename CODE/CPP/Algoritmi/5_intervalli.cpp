#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

long N;

/**
 * @brief Prende in input un x detto Floor (pair.first) e
    restituisce l'indice dell'intervallo con il ceil (pair.second) maggiore di x meno distante.

    Se x è maggiore di ogni ceil ritorna interval.size.
 *
 * @param intervals list of all intervals
 * @param x floor
 * @param start start index of the search
 * @param end end index of the search
 * @return index of the found pair
 */
long get_next_ceil_to_floor(vector<pair<long, long>> *intervals, long x, long start, long end)
{
    if (start == end)
        if (x > intervals->at(start).second)
            return start + 1;
        else
            return start;

    long half = (start + ((end - start) / 2));
    pair<long, long> dicotomic_find = intervals->at(half);

    if (dicotomic_find.second - 1 == x)
        return half;
    else if (dicotomic_find.second < x)
        return get_next_ceil_to_floor(intervals, x, half + 1, end);
    else
        return get_next_ceil_to_floor(intervals, x, start, half);
}

/**
 * @brief Prende in input un x detto Ciel (pair.second) e
    restituisce l'indice dell'intervallo con il floor (pair.first) minore di x meno distante.

    Se x è minore di ogni ceil ritorna -1.
 *
 * @param intervals list of all intervals
 * @param x ceil
 * @param start start index of the search
 * @param end end index of the search
 * @return index of the found pair
 */
long get_prev_floor_to_ceil(vector<pair<long, long>> *intervals, long x, long start, long end)
{
    if (start == end)
        if (x < intervals->at(start).first)
            return start - 1;
        else
            return start;

    long half = (start + ((end - start) / 2));
    pair<long, long> dicotomic_find = intervals->at(half);

    if (dicotomic_find.first == x)
        return half;
    else if (dicotomic_find.first < x)
        return get_prev_floor_to_ceil(intervals, x, half + 1, end);
    else
        return get_prev_floor_to_ceil(intervals, x, start, half);
}

pair<long, long> merge_intervals(vector<pair<long, long>> *intervals, pair<long, long> interval, long start, long end)
{
    long min_floor = interval.first;
    long max_ceil = interval.second;

    for (int i = start; i <= end; i++)
    {
        min_floor = min(min_floor, intervals->at(i).first);
        max_ceil = max(max_ceil, intervals->at(i).second);
    }

    return {min_floor, max_ceil};
}

void resolve_interval_insertion(pair<long, long> interval, vector<pair<long, long>> *intervals)
{
    long start_i = get_next_ceil_to_floor(intervals, interval.first, 0, intervals->size() - 1);
    if (start_i == intervals->size())
    {
        intervals->push_back(interval);
        return;
    }

    long end_i = get_prev_floor_to_ceil(intervals, interval.second, 0, intervals->size() - 1);
    if (end_i == -1)
    {
        intervals->insert(intervals->begin(), interval);
        return;
    }

    // cout << "Inserting interval [" << interval.first << ", " << interval.second << "] between indices " << start_i << " and " << end_i << endl;

    if (end_i < start_i)
    {
        intervals->insert((intervals->begin() + start_i), interval);
        return;
    }

    pair<long, long> merge = merge_intervals(intervals, interval, start_i, end_i);

    for (int i = start_i; i <= end_i; i++)
        intervals->erase(intervals->begin() + start_i);

    intervals->insert((intervals->begin() + start_i), merge);
    return;
}

pair<long, long> read_pair(ifstream &in)
{
    long first = 0;
    long second = 0;
    in >> first >> second;

    return {first, second};
}

void find_max_gap(vector<pair<long, long>> *intervals, ofstream &out)
{
    long max_gap = 0;
    long first_interval_index = 0;

    if (intervals->size() < 2)
    {
        out << "0";
        return;
    }

    for (int i = 0; i < intervals->size() - 1; i++)
    {
        long gap = (intervals->at(i + 1).first - intervals->at(i).second);

        if (gap > max_gap)
        {
            max_gap = gap;
            first_interval_index = i;
        }
    }

    if (max_gap == 0)
        out << 0;
    else
        out << intervals->at(first_interval_index).second << " " << intervals->at(first_interval_index + 1).first;
}

void print_intervals(vector<pair<long, long>> *intervals)
{
    for (int i = 0; i < intervals->size(); i++)
        cout << "[" << intervals->at(i).first << ", " << intervals->at(i).second << "] ";
    cout << endl;
}

int main()
{
    vector<pair<long, long>> *intervals = new vector<pair<long, long>>();

    ifstream in("input.txt");
    in >> N;

    intervals->push_back(read_pair(in));

    for (int i = 0; i < N - 1; i++)
    {
        resolve_interval_insertion(read_pair(in), intervals);
        //    print_intervals(intervals);
    }

    ofstream out("output.txt");
    find_max_gap(intervals, out);

    return 0;
}