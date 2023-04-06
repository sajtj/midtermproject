#include "cell.h"
using namespace std;

class Cell : public Genome
{
protected:
    vector<Genome> cromozoms;

public:
    Cell(int n)
    {
        for (int i = 0; i < n; i++)
        {
            string DNA1;
            string DNA2;
            Genome cromozom;
            cout << i + 1 << " Cromozom : " << endl;
            cin >> DNA1 >> DNA2;
            cromozom.DNA[0] = DNA1;
            cromozom.DNA[1] = DNA2;
            for (int j = 0; j < cromozom.DNA[0].size(); j++)
            {
                cromozom.dna1.push_back(cromozom.DNA[0][j]);
                cromozom.dna2.push_back(cromozom.DNA[1][j]);
            }
            cromozoms.push_back(cromozom);
        }
    }
    void margcell()
    {
        int t = 0;
        int n = cromozoms.size();
        for (int i = 0; i < n; i++)
        {
            int index_mokamel = 0;
            int index_joft_AT = 0;
            int index_joft_CG = 0;
            vector<char> d1;
            vector<char> d2;
            vector<char> mokamel;
            d1 = cromozoms[t].dna1;
            d2 = cromozoms[t].dna2;
            for (int k = 0; k < d1.size(); k++)
            {
                if (d1[k] == 'A')
                {
                    mokamel.push_back('T');
                }
                else if (d1[k] == 'T')
                {
                    mokamel.push_back('A');
                }
                else if (d1[k] == 'C')
                {
                    mokamel.push_back('G');
                }
                else if (d1[k] == 'G')
                {
                    mokamel.push_back('C');
                }
            }
            for (int j = 0; j < d1.size(); j++)
            {
                if (d2[j] != mokamel[j])
                {
                    index_mokamel++;
                }
                if ((d1[j] == 'A' and d2[j] == 'T') or (d1[j] == 'T' and d2[j] == 'A'))
                {
                    index_joft_AT++;
                }
                else if ((d2[j] == 'C' and d1[j] == 'G') or (d2[j] == 'G' and d1[j] == 'C'))
                {
                    index_joft_CG++;
                }
            }
            if ((index_mokamel > 5) or (index_joft_AT > 3 * index_joft_CG))
            {
                cromozoms.erase(cromozoms.begin() + t);
            }
            else
            {
                t++;
            }
        }
    }
    void bigjahesh(string a, int n, string b, int m)
    {
        // replacing in n omin cromozom :
        vector<char> d1 = cromozoms[n - 1].dna1;
        vector<char> d2 = cromozoms[n - 1].dna2;
        string mokamel;
        string a1 = "";
        string a2 = "";
        int f = 0;
        int v = 0;
        bool h = true;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] == 'A')
            {
                mokamel = mokamel + 'T';
            }
            else if (b[i] == 'T')
            {
                mokamel = mokamel + 'A';
            }
            else if (b[i] == 'C')
            {
                mokamel = mokamel + 'G';
            }
            else if (b[i] == 'G')
            {
                mokamel = mokamel + 'C';
            }
        }
        for (int i = 0; i < cromozoms[n - 1].dna1.size(); i++)
        {
            a1 = "";
            a2 = "";
            if (i == cromozoms[n - 1].dna1.size() - 1)
            {
                cout << a << " not found in " << n << " cromozom." << endl;
                h = false;
            }
            if (cromozoms[n - 1].dna1[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a1 = a1 + cromozoms[n - 1].dna1[j];
                }
                if (a1 == a)
                {
                    if (a.size() >= b.size())
                    {
                        for (int j = i; j < a.size() + i; j++)
                        {
                            if (f >= b.size())
                            {
                                v = i + f;
                                d1.erase(d1.begin() + v);
                                d2.erase(d2.begin() + v);
                            }
                            else
                            {
                                d1.at(j) = b[f];
                                d2.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                    else
                    {
                        for (int j = i; j < b.size() + i; j++)
                        {
                            if (f >= a.size())
                            {
                                d1.insert(d1.begin() + j, b[f]);
                                d2.insert(d2.begin() + j, mokamel[f]);
                                f++;
                            }
                            else
                            {
                                d1.at(j) = b[f];
                                d2.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                }
            }
            else if (cromozoms[n - 1].dna2[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a2 = a2 + cromozoms[n - 1].dna2[j];
                }
                if (a2 == a)
                {
                    if (a.size() >= b.size())
                    {
                        for (int j = i; j < a.size() + i; j++)
                        {
                            if (f >= b.size())
                            {
                                d2.erase(d2.begin() + j);
                                d1.erase(d1.begin() + j);
                            }
                            else
                            {
                                d2.at(j) = b[f];
                                d1.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                    else
                    {
                        for (int j = i; j < a.size(); j++)
                        {
                            if (f >= b.size())
                            {
                                d2.insert(d2.begin() + j, b[f]);
                                d1.insert(d1.begin() + j, mokamel[f]);
                                f++;
                            }
                            else
                            {
                                d2.at(j) = b[f];
                                d1.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
        if (h == true)
        {
            cout << n << " cromozom : ";
            for (int i = 0; i < d1.size(); i++)
            {
                cout << d1[i];
            }
            cout << endl
                 << "             ";
            for (int i = 0; i < d2.size(); i++)
            {
                cout << d2[i];
            }
            cout << endl;
        }
        // replacing in m omin cromozom :
        d1.clear();
        d2.clear();
        d1 = cromozoms[m - 1].dna1;
        d2 = cromozoms[m - 1].dna2;
        mokamel = "";
        a1 = "";
        a2 = "";
        f = 0;
        h = true;
        v = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 'A')
            {
                mokamel = mokamel + 'T';
            }
            else if (a[i] == 'T')
            {
                mokamel = mokamel + 'A';
            }
            else if (a[i] == 'C')
            {
                mokamel = mokamel + 'G';
            }
            else if (a[i] == 'G')
            {
                mokamel = mokamel + 'C';
            }
        }
        for (int i = 0; i < cromozoms[n - 1].dna1.size(); i++)
        {
            a1 = "";
            a2 = "";
            if (i == cromozoms[n - 1].dna1.size() - 1)
            {
                cout << b << " not found in " << m << " cromozom." << endl;
                h = false;
            }
            if (cromozoms[m - 1].dna1[i] == b[0])
            {
                for (int j = i; j < b.size() + i; j++)
                {
                    a1 = a1 + cromozoms[m - 1].dna1[j];
                }
                if (a1 == b)
                {
                    if (b.size() >= a.size())
                    {
                        for (int j = i; j < b.size() + i; j++)
                        {
                            if (f >= a.size())
                            {
                                v = i + f;
                                d1.erase(d1.begin() + v);
                                d2.erase(d2.begin() + v);
                            }
                            else
                            {
                                d1.at(j) = a[f];
                                d2.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                    else
                    {
                        for (int j = i; j < a.size() + i; j++)
                        {
                            if (f >= b.size())
                            {
                                d1.insert(d1.begin() + j, a[f]);
                                d2.insert(d2.begin() + j, mokamel[f]);
                                f++;
                            }
                            else
                            {
                                d1.at(j) = a[f];
                                d2.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                }
            }
            else if (cromozoms[m - 1].dna2[i] == b[0])
            {
                for (int j = i; j < b.size() + i; j++)
                {
                    a2 = a2 + cromozoms[m - 1].dna2[j];
                }
                if (a2 == b)
                {
                    if (b.size() >= a.size())
                    {
                        for (int j = i; j < b.size() + i; j++)
                        {
                            if (f >= a.size())
                            {
                                d2.erase(d2.begin() + j);
                                d1.erase(d1.begin() + j);
                            }
                            else
                            {
                                d2.at(j) = a[f];
                                d1.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                    else
                    {
                        for (int j = i; j < b.size(); j++)
                        {
                            if (f >= a.size())
                            {
                                d2.insert(d2.begin() + j, a[f]);
                                d1.insert(d1.begin() + j, mokamel[f]);
                                f++;
                            }
                            else
                            {
                                d2.at(j) = a[f];
                                d1.at(j) = mokamel[f];
                                f++;
                            }
                        }
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
        if (h == true)
        {
            cout << m << " cromozom : ";
            for (int i = 0; i < d1.size(); i++)
            {
                cout << d1[i];
            }
            cout << endl
                 << "             ";
            for (int i = 0; i < d2.size(); i++)
            {
                cout << d2[i];
            }
            cout << endl;
        }
    }
    void smalljahesh(char x, char y, int n, int m)
    {
        // changing n omin cromozom :
        char mokamel;
        if (y == 'A')
        {
            mokamel = 'T';
        }
        else if (y == 'T')
        {
            mokamel = 'A';
        }
        else if (y == 'C')
        {
            mokamel = 'G';
        }
        else if (y == 'G')
        {
            mokamel = 'C';
        }
        int index = 0;
        int t = 0;
        vector<char> d1 = cromozoms[n - 1].dna1;
        vector<char> d2 = cromozoms[n - 1].dna2;
        for (int i = 0; i < dna1.size(); i++)
        {
            if (cromozoms[n - 1].dna1[i] == x or cromozoms[n - 1].dna2[i] == x)
            {
                index++;
            }
        }
        if (index >= 0)
        {
            for (int i = 0; i < cromozoms[n - 1].dna1.size(); i++)
            {

                if (cromozoms[n - 1].dna1[i] == x or cromozoms[n - 1].dna2[i] == x)
                {
                    if (cromozoms[n - 1].dna1[i] == x)
                    {
                        d1.at(i) = y;
                        d2.at(i) = mokamel;
                        t++;
                    }
                    else if (cromozoms[n - 1].dna2[i] == x)
                    {
                        d2.at(i) = y;
                        d1.at(i) = mokamel;
                        t++;
                    }
                }
            }
            cout << n << " cromozom : ";
            for (int i = 0; i < d1.size(); i++)
            {
                cout << d1[i];
            }
            cout << endl
                 << "             ";
            for (int i = 0; i < d2.size(); i++)
            {
                cout << d2[i];
            }
            cout << endl;
        }
        else
        {
            cout << "there isn't " << x << " in " << n << " cromozom." << endl;
        }
        // changing m omin cromozom :
        // char mokamel;
        if (x == 'A')
        {
            mokamel = 'T';
        }
        else if (x == 'T')
        {
            mokamel = 'A';
        }
        else if (x == 'C')
        {
            mokamel = 'G';
        }
        else if (x == 'G')
        {
            mokamel = 'C';
        }
        index = 0;
        t = 0;
        d1.clear();
        d2.clear();
        d1 = cromozoms[m - 1].dna1;
        d2 = cromozoms[m - 1].dna2;
        for (int i = 0; i < dna1.size(); i++)
        {
            if (cromozoms[m - 1].dna1[i] == y or cromozoms[m - 1].dna2[i] == y)
            {
                index++;
            }
        }
        if (index >= 0)
        {
            for (int i = 0; i < cromozoms[m - 1].dna1.size(); i++)
            {

                if (cromozoms[m - 1].dna1[i] == y or cromozoms[m - 1].dna2[i] == y)
                {
                    if (cromozoms[m - 1].dna1[i] == y)
                    {
                        d1.at(i) = x;
                        d2.at(i) = mokamel;
                        t++;
                    }
                    else if (cromozoms[m - 1].dna2[i] == y)
                    {
                        d2.at(i) = x;
                        d1.at(i) = mokamel;
                        t++;
                    }
                }
            }
            cout << m << " cromozom : ";
            for (int i = 0; i < d1.size(); i++)
            {
                cout << d1[i];
            }
            cout << endl
                 << "             ";
            for (int i = 0; i < d2.size(); i++)
            {
                cout << d2[i];
            }
            cout << endl;
        }
        else
        {
            cout << "there isn't " << y << " in " << m << " cromozom." << endl;
        }
    }
    void revers(string a, int n)
    {
        vector<char> d1 = cromozoms[n - 1].dna1;
        vector<char> d2 = cromozoms[n - 1].dna2;
        string mokamel;
        string rmokamel;
        string a1;
        string ra1;
        string a2;
        string ra2;
        int t = 0;
        int index = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 'A')
            {
                mokamel = mokamel + 'T';
            }
            else if (a[i] == 'T')
            {
                mokamel = mokamel + 'A';
            }
            else if (a[i] == 'C')
            {
                mokamel = mokamel + 'G';
            }
            else if (a[i] == 'G')
            {
                mokamel = mokamel + 'C';
            }
        }
        for (int i = 0; i < cromozoms[n - 1].dna1.size(); i++)
        {
            a1 = "";
            a2 = "";
            if (cromozoms[n - 1].dna1[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a1 = a1 + cromozoms[n - 1].dna1[j];
                }
                if (a1 == a)
                {
                    index++;
                    ra1 = "";
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        ra1 = ra1 + a1[k];
                    }
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        rmokamel = rmokamel + mokamel[k];
                    }
                    for (int j = i; j < a.size() + i; j++)
                    {
                        d1.at(j) = ra1[t];
                        d2.at(j) = rmokamel[t];
                        t++;
                    }
                    break;
                }
            }
            else if (cromozoms[n - 1].dna2[i] == a[0])
            {
                for (int j = i; j < a.size() + i; j++)
                {
                    a2 = a2 + cromozoms[n - 1].dna2[j];
                }
                if (a2 == a)
                {
                    index++;
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        ra2 = ra2 + a2[k];
                    }
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        rmokamel = rmokamel + mokamel[k];
                    }
                    for (int j = i; j < a.size() + i; j++)
                    {
                        d2.at(j) = ra2[t];
                        d1.at(j) = rmokamel[t];
                        t++;
                    }
                    break;
                }
            }
        }
        if (index == 0)
        {
            cout << a << " not found in " << n << " cromozom." << endl;
        }
        else
        {
            cout << n << " cromozom : ";
            for (int i = 0; i < d1.size(); i++)
            {
                cout << d1[i];
            }
            cout << endl
                 << "             ";
            for (int i = 0; i < d2.size(); i++)
            {
                cout << d2[i];
            }
            cout << endl;
        }
    }
    string mokamel(string a)
    {
        string ma;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 'A')
            {
                ma = ma + 'T';
            }
            else if (a[i] == 'T')
            {
                ma = ma + 'A';
            }
            else if (a[i] == 'C')
            {
                ma = ma + 'G';
            }
            else if (a[i] == 'G')
            {
                ma = ma + 'C';
            }   
        }
        return ma;
    }
    void palindrom(int n)
    {
        vector<char> d1 = cromozoms[n - 1].dna1;
        string str;
        string rstr;
        string mokamel_rstr;
        string newstr;
        string ns;
        int j = 0;
        for (int i = 0; i < d1.size(); i++)
        {
            str = "";
            newstr = "";
            ns = "";
            j = i;
            while (newstr.size() < d1.size())
            {
                ns = "";
                str = str + d1[j];
                rstr = str;
                j++;
                if (j >= 2 + i)
                {
                    reverse(rstr.begin() , rstr.end());
                    mokamel_rstr = mokamel(rstr);
                    newstr = str + mokamel_rstr;
                    for (int k = i; k < newstr.size() + i; k++)
                    {
                        ns = ns + d1[k];
                    }
                    if (ns == newstr)
                    {
                        cout << newstr << "  ";
                        break;
                    }
                    
                }
            }
        }
        vector<char> d2 = cromozoms[n - 1].dna2;
        str = "";
        rstr = "";
        mokamel_rstr = "";
        newstr = "";
        ns = "";
        j = 0;
        for (int i = 0; i < d2.size(); i++)
        {
            str = "";
            newstr = "";
            ns = "";
            j = i;
            while (newstr.size() < d2.size())
            {
                ns = "";
                str = str + d2[j];
                rstr = str;
                j++;
                if (j >= 2 + i)
                {
                    reverse(rstr.begin() , rstr.end());
                    mokamel_rstr = mokamel(rstr);
                    newstr = str + mokamel_rstr;
                    for (int k = i; k < newstr.size() + i; k++)
                    {
                        ns = ns + d2[k];
                    }
                    if (ns == newstr)
                    {
                        cout << newstr << "  ";
                        break;
                    }
                    
                }
            }
        }
    }
};

int main()
{
    Genome G1("ATCAGTAGT", "CTCAGT", "GAGTCA");
    Genome G2("ATGC", "TTATCG", "AATAGC");
    // G1.smalljahesh('A', 'C', 2);
    // G1.printdan2();
    // G1.bigjahesh("TCAG", "ATC" );
    // G1.revers("GTCA");
    Cell c1(1);
    // c1.margcell();
    // c1.bigjahesh("ACAT", 1, "CGAC", 2);
    // c1.smalljahesh('A' , 'C' , 1 , 2);
    // c1.revers("CTG", 2);
    // c1.palindrom(1);
    return 0;
}