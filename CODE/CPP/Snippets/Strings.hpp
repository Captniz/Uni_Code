using namespace std;

#include <iostream>

namespace str
{
    //  ###################################
    //  #           DECLARATIONS          #
    // ####################################

    int Length_Str(char *str);
    void Resize_Str(char *str);
    int ToInt_Str(char *str);
    char *ToCharArr_Str(string str);
    char *Copy_Str(char *str);
    int Compare_Str(char *str1, char *str2);
    char *Concat_Str(char *str1, char *str2);
    char *Substr_Str(char *str, int start, int end);
    char *Reverse_Str(char *str);
    char *ToLower_Str(char *str);
    char *ToUpper_Str(char *str);
    char *Trim_Str(char *str);
    char *Replace_Str(char *str, char *oldStr, char *newStr);
    char *Insert_Str(char *str, char *substr, int index);
    char *Delete_Str(char *str, int start, int end);
    int CountSubstr_Str(char *str, char *find);
    char **Split_Str(char *str, char *separator);
    char **Split_Str(char *str, char **separator, int n_sep);

    //  ###################################
    //  #           DEFINITIONS           #
    // ####################################

    /**
     * @brief Calcola la lunghezza di una stringa.
     *
     * @param str Puntatore di stringa.
     * @return Lunghezza della stringa.
     */
    int Length_Str(char *str)
    {
        int length = 0;
        while (str[length] != '\0')
        {
            length++;
        }
        return length;
    }

    /**
     * @brief Ridimensiona una stringa alla corretta dimensione dell'array.
     *
     * @param str Puntatore di stringa.
     */
    void Resize_Str(char *str)
    {
        int len = Length_Str(str);
        char *resized = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            resized[i] = str[i];
        }
        resized[len] = '\0';
        str = resized;
        delete[] resized;
        return;
    }

    /**
     * @brief Converte una stringa in un intero.
     *
     * @param str Puntatore di stringa.
     * @return Intero convertito.
     */
    int ToInt_Str(char *str)
    {
        int num = 0;
        int sign = 1;
        int i = 0;
        if (str[0] == '-')
        {
            sign = -1;
            i++;
        }
        while (str[i] != '\0')
        {
            num = num * 10 + str[i] - '0';
            i++;
        }
        return num * sign;
    }

    /**
     * @brief Converte una stringa in un array di caratteri.
     *
     * @param str Stringa.
     * @return Puntatore di array di caratteri.
     */
    char *ToCharArr_Str(string str)
    {
        char *charArr = new char[str.length() + 1];
        for (int i = 0; i < str.length(); i++)
        {
            charArr[i] = str[i];
        }
        charArr[str.length()] = '\0';
        return charArr;
    }

    /**
     * @brief Copia una stringa.
     *
     * @param str Puntatore di stringa.
     * @return Puntatore di stringa copiata.
     */
    char *Copy_Str(char *str)
    {
        int len = Length_Str(str);
        char *copy = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            copy[i] = str[i];
        }
        copy[len] = '\0';
        return copy;
    }

    /**
     * @brief Confronta due stringhe.
     *
     * @param str1 Prima stringa.
     * @param str2 Seconda stringa.
     * @return 0 se le stringhe sono uguali, -1 se la prima è minore, 1 se la seconda è minore.
     */
    int Compare_Str(char *str1, char *str2)
    {
        int len1 = Length_Str(str1);
        int len2 = Length_Str(str2);
        if (len1 != len2)
        {
            return len1 < len2 ? -1 : 1;
        }
        for (int i = 0; i < len1; i++)
        {
            if (str1[i] < str2[i])
            {
                return -1;
            }
            else if (str1[i] > str2[i])
            {
                return 1;
            }
        }
        return 0;
    }

    /**
     * @brief Concatena due stringhe.
     *
     * @param str1 Prima stringa.
     * @param str2 Seconda stringa.
     * @return Puntatore di stringa concatenata.
     */
    char *Concat_Str(char *str1, char *str2)
    {
        int len1 = Length_Str(str1);
        int len2 = Length_Str(str2);

        char *concat = new char[len1 + len2 + 1];
        for (int i = 0; i < len1; i++)
        {
            concat[i] = str1[i];
        }
        for (int i = 0; i < len2; i++)
        {
            concat[len1 + i] = str2[i];
        }
        concat[len1 + len2] = '\0';
        return concat;
    }

    /**
     * @brief Estrae una sottostringa.
     *
     * @param str Stringa.
     * @param start Indice di inizio.
     * @param end Indice di fine.
     * @return Puntatore di sottostringa.
     */
    char *Substr_Str(char *str, int start, int end)
    {
        char *substr = new char[end - start + 1];
        for (int i = 0; i < end - start; i++)
        {
            substr[i] = str[start + i];
        }
        substr[end - start] = '\0';
        return substr;
    }

    /**
     * @brief Inverte una stringa.
     *
     * @param str Stringa.
     * @return Puntatore di stringa invertita.
     */
    char *Reverse_Str(char *str)
    {
        int len = Length_Str(str);
        char *reverse = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            reverse[i] = str[len - i - 1];
        }
        reverse[len] = '\0';
        return reverse;
    }

    /**
     * @brief Converte una stringa in minuscolo.
     *
     * @param str Stringa.
     * @return Puntatore di stringa in minuscolo.
     */
    char *ToLower_Str(char *str)
    {
        int len = Length_Str(str);
        char *lower = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            lower[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + 32 : str[i];
        }
        lower[len] = '\0';
        return lower;
    }

    /**
     * @brief Converte una stringa in maiuscolo.
     *
     * @param str Stringa.
     * @return Puntatore di stringa in maiuscolo.
     */
    char *ToUpper_Str(char *str)
    {
        int len = Length_Str(str);
        char *upper = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            upper[i] = str[i] >= 'a' && str[i] <= 'z' ? str[i] - 32 : str[i];
        }
        upper[len] = '\0';
        return upper;
    }

    /**
     * @brief Rimuove spazi bianchi all'inizio e alla fine di una stringa.
     *
     * @param str Stringa.
     * @return Puntatore di stringa senza spazi bianchi.
     */
    char *Trim_Str(char *str)
    {
        int start = 0;
        int end = Length_Str(str) - 1;
        while (str[start] == ' ')
        {
            start++;
        }
        while (str[end] == ' ')
        {
            end--;
        }
        return Substr_Str(str, start, end + 1);
    }

    /**
     * @brief Sostituisce una sottostringa con un'altra.
     *
     * @warning Buffer massimo di 256 caratteri.
     *
     * @param str Stringa.
     * @param oldStr Sottostringa da sostituire.
     * @param newStr Nuova sottostringa.
     * @return Puntatore di stringa con la sottostringa sostituita.
     */
    char *Replace_Str(char *str, char *oldStr, char *newStr)
    {
        char *replace = new char[256];
        int i = 0;
        int l = 0;
        while (i < Length_Str(str))
        {
            bool found = true;
            for (int j = 0; j < Length_Str(oldStr); j++)
            {
                if (str[i + j] != oldStr[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                for (int j = 0; j < Length_Str(newStr); j++)
                {
                    replace[j + l] = newStr[j];
                }
                l += Length_Str(newStr);
                i += Length_Str(oldStr);
            }
            else
            {
                replace[l] = str[i];
                i++;
                l++;
            }
        }
        replace[l] = '\0';
        str::Resize_Str(replace);
        return replace;
    }

    /**
     * @brief Inserisce una sottostringa in una stringa.
     *
     * @param str Stringa.
     * @param substr Sottostringa.
     * @param index Indice di inserimento.
     * @return Puntatore di stringa con la sottostringa inserita.
     */
    char *Insert_Str(char *str, char *substr, int index)
    {
        int len = Length_Str(str);
        int lenSub = Length_Str(substr);
        char *insert = new char[len + lenSub + 1];
        for (int i = 0; i < index; i++)
        {
            insert[i] = str[i];
        }
        for (int i = 0; i < lenSub; i++)
        {
            insert[index + i] = substr[i];
        }
        for (int i = 0; i < len - index; i++)
        {
            insert[index + lenSub + i] = str[index + i];
        }
        insert[len + lenSub] = '\0';
        return insert;
    }

    /**
     * @brief Elimina una sottostringa da una stringa, date le coordinate.
     * @attention Se si vuole cancellare una sottostringa, data la sottostringa stessa, si può usare Replace_Str.
     *
     *
     * @param str Stringa.
     * @param start Indice di inizio.
     * @param end Indice di fine.
     * @return Puntatore di stringa con la sottostringa eliminata.
     */
    char *Delete_Str(char *str, int start, int end)
    {
        int len = Length_Str(str);
        char *del = new char[len - (end - start) + 1];
        for (int i = 0; i < start; i++)
        {
            del[i] = str[i];
        }
        for (int i = 0; i < len - end; i++)
        {
            del[start + i] = str[end + i];
        }
        del[len - (end - start)] = '\0';
        return del;
    }

    /**
     * @brief Conta le occorrenze di una sottostringa in una stringa.
     *
     * @param str Stringa.
     * @param find Sottostringa da cercare.
     * @return Numero di occorrenze.
     */
    int CountSubstr_Str(char *str, char *find)
    {
        int ctr = 0;
        for (int i = 0; i < Length_Str(str); i++)
        {
            bool found = true;
            for (int j = 0; j < Length_Str(find); j++)
            {
                if (str[i + j] != find[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                ctr++;
        }
        return ctr;
    }

    /**
     * @brief Divide una stringa in sottostringhe, dato un separatore.
     *
     * @param str Stringa.
     * @param separator Sottostringa separatore.
     * @return Array di sottostringhe.
     */
    char **Split_Str(char *str, char *separator)
    {
        int len = Length_Str(str);
        int lenSep = Length_Str(separator);
        char **split = new char *[len];
        int ctr = 0;

        for (int i = 0; i < len; i++)
        {
            bool found = true;
            for (int j = 0; j < lenSep; j++)
            {
                if (str[i + j] != separator[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                split[ctr] = Substr_Str(str, 0, i);
                str = Substr_Str(str, i + lenSep, len);
                len = Length_Str(str);
                i = 0;
                ctr++;
            }
        }

        split[ctr] = Substr_Str(str, 0, len);

        return split;
    }

    /**
     * @brief Divide una stringa in sottostringhe, date le coordinate.
     *
     * @param str Stringa.
     * @param separator Array di sottostringhe separatrici.
     * @return Array di sottostringhe.
     */
    char **Split_Str(char *str, char **separator, int n_sep)
    {
        int len = Length_Str(str);
        char **split = new char *[len];
        int ctr = 0;
        int lenSep = 0;

        for (int i = 0; i < len; i++)
        {
            bool found = true;
            for (int j = 0; j < n_sep; j++)
            {
                lenSep = Length_Str(separator[j]);
                for (int k = 0; k < lenSep; k++)
                {
                    found = true;
                    if (str[i + k] != separator[j][k])
                    {
                        found = false;
                        break;
                    }
                }

                if (found)
                    break;
            }
            if (found)
            {
                split[ctr] = Substr_Str(str, 0, i);
                str = Substr_Str(str, i + lenSep, len);
                len = Length_Str(str);
                i = 0;
                ctr++;
            }
        }

        split[ctr] = Substr_Str(str, 0, len);

        return split;
    }

} // namespace str
