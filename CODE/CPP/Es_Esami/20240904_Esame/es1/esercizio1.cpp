#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void print_clauses(int **clauses);

int main(int argc, char const *argv[])
{
   if (argc != 2)
   {
      cout << "Errore, passa gli args";
      return 1;
   }
   fstream in = fstream(argv[1], ios::in);
   if (!in.is_open())
   {
      cout << "Errore apertura file";
      return 1;
   }

   int tot_claus = 0;
   int tot_vars = 0;

   { // HEader controls
      char tmp[20];

      in >> tmp;
      if (strcmp(tmp, "p") != 0)
      {
         cout << "Errore header 1";
         in.close();
         return 1;
      }

      in >> tmp;
      if (strcmp(tmp, "cnf") != 0)
      {
         cout << "Errore header 2";
         in.close();
         return 1;
      }

      in >> tot_claus;
      in >> tot_vars;
      if (tot_claus <= 0 || tot_vars <= 0)
      {
         cout << "Errore header 3";
         in.close();
         return 1;
      }
   }

   int **claus = new int *[tot_claus + 1];
   claus[tot_claus] = nullptr;

   for (int j = 0; j < tot_claus; j++)
   {
      int n_vars;
      in >> n_vars;

      int *curr_claus = new int[n_vars + 1];

      for (int i = 0; i < n_vars; i++)
      {
         if (in.eof())
         {
            cout << "Errore nella lettura 1";
            in.close();
            for (int i = 0; i < (tot_claus + 1); i++)
            {
               delete claus[i];
            }
            delete[] claus;
            return 1;
         }

         char curc;
         in.get(curc);

         if (curc != ' ' && i < n_vars - 1)
         {
            cout << "Errore nella lettura 2";
            in.close();
            for (int i = 0; i < (tot_claus + 1); i++)
            {
               delete claus[i];
            }
            delete[] claus;
            return 1;
         }

         in >> curr_claus[i];
         if (abs(curr_claus[i]) > tot_vars || curr_claus[i] == 0)
         {
            cout << "Errore nella lettura 3";
            in.close();
            for (int i = 0; i < (tot_claus + 1); i++)
            {
               delete claus[i];
            }
            delete[] claus;
            return 1;
         }
      }
      if (in.get() != '\n' && j < tot_claus - 1)
      {
         cout << "Errore nella lettura 4";
         in.close();
         for (int i = 0; i < (tot_claus + 1); i++)
         {
            delete claus[i];
         }
         delete[] claus;
         return 1;
      }

      curr_claus[n_vars] = 0;
      claus[j] = curr_claus;
   }

   print_clauses(claus);

   // Closing
   in.close();
   for (int i = 0; i < (tot_claus + 1); i++)
   {
      delete claus[i];
   }
   delete[] claus;

   return 0;
}

void print_clauses(int **clauses)
{
   int max_var = 0;
   int i = 0;
   while (clauses[i] != nullptr)
   {
      int j = 0;
      while (clauses[i][j] != 0)
      {
         cout << clauses[i][j] << " ";
         j++;
         if (clauses[i][j] > max_var)
            max_var = clauses[i][j];
      }
      cout << clauses[i][j] << endl;

      i++;
   }

   cout << "p cnf " << i << " " << max_var;
}