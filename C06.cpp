#include <stdio.h>
#include <string.h>
#include <iostream>

struct pollaio
{
    int numero;
    char nome[20];
    int prodotti[4]={0,0,0,0}; //Extra, Grandi, Medie, Scarti
};

//calcola il valore delle uova prodette, inclusi i costi di scarto
int valore(pollaio p){
    int valori[]={20,15,10,-5};
    int valore=0;
    for (int i = 0; i < 4; i++) valore+= p.prodotti[i]*valori[i];
    return valore;
}

//conta il totale di uova prodotte, escluso lo scarto
int conta(pollaio p){
    int totale=0;
    for (int i = 0; i < 3; i++) totale+= p.prodotti[i];
    return totale;
}

//visualizza sullo schermo il contenuto dell'array
void visualizza(pollaio pollai[], int n){
    for (int indice=0; indice<n; indice++) 
    {
        std::cout<< pollai[indice].numero
        <<" "<<pollai[indice].nome<<" " 
        <<" - valore prodotto: "<<valore(pollai[indice])
        <<" - totale uova: "<<conta(pollai[indice])
        <<" - per tipo (Extra Grandi Medie Scarto): ";
        for (int i = 0; i < 4; i++) std::cout<<pollai[indice].prodotti[i]<<" ";
        std::cout<<"\n";
    }
}

void ordinamento(pollaio pollai[], int n){
    //ordino
    pollaio temp; //record di swap
    for(int j = 0; j < n - 1; j++) {
        for(int i = 0; i < n - 1; i++) {
            if (valore(pollai[i]) < valore(pollai[i + 1])) 
            {   //scambio per criterio principale
                temp = pollai[i];
                pollai[i] = pollai[i + 1];
                pollai[i + 1] = temp;
            } else { //il criteri principale da UGUAGLIANZA?
                if (valore(pollai[i]) == valore(pollai[i + 1]))
                { //sono nel caso particolare
                    if(conta(pollai[i]) < conta(pollai[i + 1]))
                    {   //scambio per criterio secondario
                        temp = pollai[i];
                        pollai[i] = pollai[i + 1];
                        pollai[i + 1] = temp;
                    } //scambio per criterio secondario (quante uova totali)
                } //caso di valori uguali
            } //scambio per criterio principale (valore delle uova prodotte)
        } //ciclo interno
    } //ciclo esterno
}

int main(int argc, char const *argv[])
{   //array precaricato di nomi da usare generato dalla AI
    char nomiFiori[12][20] = 
        {"Rosa","Garofano","Tulipano","Giglio","Narciso","Orchidea", 
        "Girasole", "Viola", "Margherita","Gelsomino", "Lavanda", "Dalia" };
    //una array di "fino a" 10 professori di tipo professore
    pollaio pollai[12];
    //numero di elementi effettivamente presenti nell'array
    int nPollai=12; 

    //genero 12 pollai con il numero di uova casuale
    for (int p = 0; p < nPollai; p++)
    {
        pollai[p].numero=1; //numero il pollaio
        strcpy(pollai[p].nome,nomiFiori[p]); //prendo il nome dall'elenco
        for (int i = 0; i < 4; i++) pollai[p].prodotti[i]=(rand() % 3); //genero un numero tra 0 e 2
    }

    std::cout<<"\nArray originale:\n";
    // visualizzo prima di ordinare
    visualizza(pollai, nPollai);
    //ordino
    ordinamento(pollai, nPollai);
    std::cout<<"\nArray ordinato:\n";
    // visualizzo dopo aver ordinato
    visualizza(pollai, nPollai);
    return 0;
}