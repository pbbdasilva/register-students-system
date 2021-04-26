#include<iostream>
using namespace std;
 
void displayMenuInicial() {
    cout << "\nMENU\n";
    cout << "0: Sair\n";
    cout << "1: Alunos\n";
    cout << "2: Disciplinas\n";
    cout << "Escolha uma opção: ";
}
 
void displayMenuDisciplinas() {
    cout << "\nMENU DE DISCIPLINAS\n"
    << "0: MENU\n"
    << "1: Adicionar Disciplina\n"
    << "2: Remover Disciplina\n"
    << "3: Consultar Alunos de uma Disciplina" << endl << endl;
    cout << "Escolha uma opção: ";
}
 
void displayFeatureDisciplina() {
    cout << "\nOPERAÇÃO COM DISCIPLINAS" << endl;
    cout << "Forneça os seguintes dados:" << endl;
    cout << "Código (4 DIGITOS)" << endl;
    cout << "Nome da Disciplina" << endl;
    cout << "Professor da Disciplina" << endl;
    cout << "Créditos da Disciplina" << endl;
    cout << "\n\n";
}
 
void displayMenuAlunos() {
    cout << "\nMENU DE ALUNOS\n";
    cout << "0: MENU\n";
    cout << "1: Adicionar Aluno\n";
    cout << "2: Remover Aluno\n";
    cout << "3: Consultar Disciplinas de um Aluno\n";
    cout << "Escolha uma opção: ";
}
 
void displayFeatureAluno() {
    cout << "\nOPERAÇÃO COM ALUNOS\n"
    << "Forneça os seguintes dados:\n"
    << "Código (5 digitos)\n"
    << "Nome\n"
    << "CPF\n"
    << "Período\n\n";
}