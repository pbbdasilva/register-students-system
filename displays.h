#include<iostream>
using namespace std;

void displayMenuInicial() {
    cout << "\nMENU\n";
    cout << "0: Sair\n";
    cout << "1: Alunos\n";
    cout << "2: Disciplinas\n";
}

void displayMenuDisciplinas() {
    cout << "\nBEM-VINDO AO MENU DE DISCIPLINAS\n"
    << "DESEJA FAZER QUAL OPERAÇÃO?\n"
    << "0: VOLTAR AO MENU INICIAL\n"
    << "1: ADICIONAR DISCIPLINA\n"
    << "2: REMOVER DISCIPLINA\n"
    << "3: CONSULTAR DISCIPLINA" << endl << endl;
}

void displayFeatureDisciplina() {
    cout << "OPERAÇÃO COM DISCIPLINAS" << endl;
    cout << "FORNEÇA OS SEGUINTES DADOS:" << endl;
    cout << "CODIGO (4 DIGITOS)" << endl;
    cout << "NOME DA DISCIPLINA" << endl;
    cout << "PROFESSOR DA DISCIPLINA" << endl;
    cout << "CREDITOS DA DISCIPLINA" << endl;
}