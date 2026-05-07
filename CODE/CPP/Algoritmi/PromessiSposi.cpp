#include <iostream>
#include <vector>

using namespace std;

int FindSubstring(const string &s, const string &text)
{
    vector<int> dp(s.size(), 0);
    int limit = 0;

    for (int i = 0; i < text.size(); i++)
        for (int j = 0; j <= limit; j++)
            if (text[i] == s[j])
            {
                // Limits to the next letter of the substring to avoid unnecessary checks
                limit = ((limit + 1) > s.size() ? s.size() : (limit + 1));
                if (j == 0)
                {
                    dp[j]++;
                    break; // Stops when found
                }
                else
                {
                    dp[j] += dp[(j - 1)];
                    break; // Stops when found
                }
            }

    // llulluuccuc

    //         L |  U  |  C
    // VAL  :  3 |  3  |  1
    // COMB :  3 |  7  |  1

    return dp[s.size() - 1];
}

int main(int argc, char const *argv[])
{
    string s = "lucia";
    string text = "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli, vien, quasi a un tratto, a ristringersi, e a prender corso e figura di fiume, tra un promontorio a destra, e un’ampia costiera dall’altra parte; e il ponte, che ivi congiunge le due rive, par che renda ancor più sensibile all’occhio questa trasformazione, e segni il punto in cui il lago cessa, e l’Adda rincomincia, per ripigliar poi nome di lago dove le rive, allontanandosi di nuovo, lascian l’acqua distendersi e rallentarsi in nuovi golfi e in nuovi seni.";

    cout << FindSubstring(s, text);
    return 0;
}
