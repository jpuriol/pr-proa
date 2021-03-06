#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <ctype.h>
#include <locale>
#include <fstream>
using namespace std;

struct elem
{
    wstring clave;
    int num;
};

list<elem> OrdenarInsercionLimitado(const map<wstring, int> &, const int &);
list<elem> OrdenarInsercionLimitado(const unordered_map<wstring, int> &, const int &);
vector<wstring> leer(string);
map<wstring, int> crearMapa(vector<wstring>);
unordered_map<wstring, int> crearMapaDesordenado(vector<wstring>);
unordered_map<wstring, int> crearMapaDesordenado(vector<wstring>);

int main()
{
    locale::global(locale("es_ES.utf8"));
    vector<wstring> salida = leer("texto.txt");
    struct timespec ini_time, fin_time;

    clock_gettime(CLOCK_REALTIME, &ini_time);
    map<wstring, int> mapa = crearMapa(salida);
    list<elem> salida2 = OrdenarInsercionLimitado(mapa, 30);
    clock_gettime(CLOCK_REALTIME, &fin_time);

    wcout << "------" << endl;
    wcout << "Ordenar inserción con mapa" << endl;
    wcout << "Tiempo: " << (double)fin_time.tv_sec - (double) ini_time.tv_sec + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9 << endl;
    wcout << "------" << endl; 
    for (auto iter : salida2)
        wcout << iter.clave << "," << iter.num << endl;

    clock_gettime(CLOCK_REALTIME, &ini_time);
    unordered_map<wstring, int> mapa2 = crearMapaDesordenado(salida);
    list<elem> salida3 = OrdenarInsercionLimitado(mapa2, 30);
    clock_gettime(CLOCK_REALTIME, &fin_time);

    wcout << endl << endl << "------" << endl;
    wcout << "Ordenar inserción con mapa desordenado" << endl;
    wcout << "Tiempo: " << (double)fin_time.tv_sec - (double) ini_time.tv_sec + fin_time.tv_nsec * 1e-9 - ini_time.tv_nsec * 1e-9 << endl;
    wcout << "------" << endl;
    for (auto iter : salida3)
        wcout << iter.clave << "," << iter.num << endl;

    return 0;
}

list<elem> OrdenarInsercionLimitado(const map<wstring, int> &mapa, const int &numeros)
{
    bool fin;
    elem actual;
    list<elem> salida;
    elem vacio;
    vacio.num = 0;
    for (int i = 0; i < numeros; i++)
    {
        salida.push_back(vacio);
    }

    for (auto iter : mapa)
    {
        actual.clave = iter.first;
        actual.num = iter.second;
        fin = false;
        auto it = salida.begin();
        //Usaba un for pero no tira del todo bien
        while (!fin)
        {
            if (actual.num >= it->num)
            {
                salida.insert(it, actual);
                salida.pop_back();
                fin = true;
            }
            ++it;
            if (it == salida.end())
                fin = true;
        }
    }
    return salida;
}

list<elem> OrdenarInsercionLimitado(const unordered_map<wstring, int> &mapa, const int &numeros)
{
    bool fin;
    elem actual;
    list<elem> salida;
    elem vacio;
    vacio.num = 0;
    for (int i = 0; i < numeros; i++)
    {
        salida.push_back(vacio);
    }

    for (auto iter : mapa)
    {
        actual.clave = iter.first;
        actual.num = iter.second;
        fin = false;
        auto it = salida.begin();
        //Usaba un for pero no tira del todo bien
        while (!fin)
        {
            if (actual.num >= it->num)
            {
                salida.insert(it, actual);
                salida.pop_back();
                fin = true;
            }
            ++it;
            if (it == salida.end())
                fin = true;
        }
    }
    return salida;
}

vector<wstring> leer(string nombreArchivo)
{
    locale loc = locale();

    vector<wstring> result;
    wchar_t letra;
    wchar_t letraAnt;
    wstring palabra;
    wifstream txt;
    txt.open(nombreArchivo);
    if (txt.is_open())
    {
        while (!txt.eof())
        {
            letraAnt = letra;
            txt.get(letra);
            if (use_facet<ctype<wchar_t>>(locale()).is(ctype<wchar_t>::alpha, letra))
            {
                if (use_facet<ctype<wchar_t>>(locale()).is(ctype<wchar_t>::upper, letra))
                    letra = use_facet<ctype<wchar_t>>(locale()).tolower(letra);
                palabra += letra;
            }
            else
            {
                if (use_facet<ctype<wchar_t>>(locale()).is(ctype<wchar_t>::alpha, letraAnt))
                    result.push_back(palabra);
                palabra.clear();
            }
        }
        txt.close();
    }
    else
    {
        wcout << "Fallo al abrir fichero" << endl;
    }
    return result;
}

map<wstring, int> crearMapa(vector<wstring> salida)
{
    map<wstring, int> mapa;
    for (auto iter : salida)
    {
        if (mapa.find(iter) != mapa.end())
            ++mapa[iter];
        else
            mapa[iter] = 1;
    }
    return mapa;
}

unordered_map<wstring, int> crearMapaDesordenado(vector<wstring> salida)
{
    unordered_map<wstring, int> mapa;
    for (auto iter : salida)
    {
        if (mapa.find(iter) != mapa.end())
            ++mapa[iter];
        else
            mapa[iter] = 1;
    }
    return mapa;
}
