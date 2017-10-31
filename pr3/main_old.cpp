#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;


struct elem {
    string clave;
    int num;
};


list<elem> OrdenarInsercionLimitado(map<string, int> mapa,int numeros)
{
    bool fin;
    elem actual;
    list<elem>salida;
    elem vacio;
    vacio.clave="";
    vacio.num=0;
    for(int i=0;i<numeros;i++)
        salida.push_back(vacio);
    
    for(auto iter:mapa)
    {
    actual.clave=iter.first;
    actual.num=iter.second;
    fin=false;
        auto it = salida.begin();
        //Usaba un for pero no tira del todo bien
        while(!fin)
        {
            if(actual.num >= it->num)
            {
                salida.insert(it,actual);
                salida.pop_back();
                fin=true;
            }  
            ++it;
            if(it == salida.end())
                fin=true;
        }  
    }
    return salida;     
}

map<string, int> createMap(const vector<string> & words)
{
    map<string, int> wordCount;

    for(auto word : words)
    {
        if(wordCount.find(word) != wordCount.end())
            ++wordCount[word];
        else
            wordCount[word] = 1;
    }

    return wordCount;
}

unordered_map<string, int> createUnorderedMap(const vector<string> & words)
{
    unordered_map<string, int> wordCount;

    for(auto word : words)
    {
        if(wordCount.find(word) != wordCount.end())
            ++wordCount[word];
        else
            wordCount[word] = 1;
    }

    return wordCount;
}

int main()
{
    vector<string> people {{"JP"},{"Victor"},{"Nacho"},{"JP"},{"Lidia"},{"Jorge"},{"Nacho"},{"Nacho"}};
    
    map<string,int> mapa;
    for(auto iter:people)
    {
        if(mapa.find(iter)!=mapa.end())
            ++mapa[iter];
            else
            mapa[iter]=1;
    }
    
    for(auto iter:mapa)
        cout<<iter.first<<","<<iter.second<<endl;
        
    list<elem> people2=OrdenarInsercionLimitado(mapa,2);
    
    cout<<"------"<<endl;
    for(auto iter:people2)
        cout<<iter.clave<<","<<iter.num<<endl;
    
}
