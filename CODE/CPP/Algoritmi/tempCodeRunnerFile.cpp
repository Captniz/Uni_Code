
        }
        cout << "\n  Rappresentanti: ";
        while (!C[i].Rng.empty())
        {
            cout << C[i].Rng.front() << " ";
            C[i].Rng.pop();
        }
    }