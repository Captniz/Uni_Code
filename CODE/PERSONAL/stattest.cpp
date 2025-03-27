#include <iostream>
#include <random>
#include <stack>
#include <ctime>

using namespace std;

int experiment(int run_experiment_times);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    double avg = 0;
    int iterations = 10;
    double ctr_success = 0;
    long run_experiment_times = 100000000;

    for (int x = 0; x < iterations; x++)
    {
        cout << "Iteration " << (x + 1) << endl;

        ctr_success = experiment(run_experiment_times);

        cout << "Success achieved in " << ctr_success << " cases" << endl;
        cout << "Success rate: " << ctr_success / run_experiment_times * 100 << "%  --  " << ctr_success << "/" << run_experiment_times << endl;
        avg += ctr_success / run_experiment_times * 100;
        cout << "---------------------------------" << endl
             << endl;
    }

    cout << "Average success rate: " << avg / iterations << "%";
}

int experiment(int run_experiment_times)
{
    int maxdice = 6;
    int maxpool = 18;
    int target_prob = 7;
    int target_num = 4;
    int pool = 0;
    int dice = 0;
    stack<char> res;
    double ctr_success = 0;

    for (int i = 0; i < run_experiment_times; i++)
    {
        dice = rand() % maxdice + 1;

        for (int j = 0; j < dice; j++)
        {
            pool = rand() % maxpool + 1;

            if (pool <= target_prob)
                res.push('R');
            else
                res.push('N');
        }

        if (res.size() >= target_num)
        {
            int ctr = 0;

            //cout<<"Size:"<<res.size()<<endl;

            while (!res.empty())
            {
                //cout<<res.top()<<" "<<endl;

                if (res.top() == 'R')
                    ctr++;
                res.pop();
            }

            if (ctr >= target_num)
            {
                ctr_success++;
                //cout<<"Success"<<endl;
            }
        }
    }

    return ctr_success;
}