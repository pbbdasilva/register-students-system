#include<string>
#include<unordered_map>
#include<iostream>
#include<new>
using namespace std;
 
class Aluno {
    string matricula;
    string nome;
    long long int cpf;
    float periodo;
 
public:
    Aluno(string _matricula, string _nome, long long int _cpf, float _periodo) {
        matricula = _matricula;
        nome = _nome;
        cpf = _cpf;
        periodo = _periodo;
    }
 
    void infoAluno() {
        cout << "Matricula: " << matricula << endl;
        cout << "Nome: " << nome << endl;
        cout << "cpf: " << cpf << endl;
        cout << "periodo: " << periodo << endl;
    }
 
    float getPeriodo() {
        return periodo;
    }
 
    string getMatricula() {
        return matricula;
    }
};
 
struct NodeAluno {
    Aluno* aluno;
    NodeAluno* next;
 
    NodeAluno() : aluno(nullptr), next(nullptr) {}
    NodeAluno(Aluno* x) : aluno(x), next(nullptr) {}
};
 
class Disciplina {
    string nomeDisciplina;
    string nomeProfessor;
    int creditos;
    unordered_map<float, NodeAluno*> turmaPorPeriodo;
 
public:
    Disciplina(string _nomeDisciplina, string _nomeProfessor, int _creditos) {
        nomeDisciplina = _nomeDisciplina;
        nomeProfessor = _nomeProfessor;
        creditos = _creditos;
    }

    Disciplina(string _nomeDisciplina) {
        nomeDisciplina = _nomeDisciplina;
    }
 
    void infoDisciplina() {
        cout << "Nome da disciplina: " << nomeDisciplina << endl;
        cout << "nome do professor: " << nomeProfessor << endl;
        cout << "creditos: " << creditos << endl;
    }
 
    void addAluno(Aluno* estudante) {
        NodeAluno* ptrAluno = new NodeAluno(estudante);
 
        if(turmaPorPeriodo[estudante->getPeriodo()] == nullptr) turmaPorPeriodo[estudante->getPeriodo()] = ptrAluno;
        else {
            NodeAluno* aux;
            aux = turmaPorPeriodo[estudante->getPeriodo()];
 
            while(aux->next != nullptr) aux = aux->next;
            
            aux->next = ptrAluno;
        }
    }
 
    NodeAluno* searchAluno(Aluno* estudante) {
        NodeAluno* ptrAluno = turmaPorPeriodo[estudante->getPeriodo()];
 
        while(ptrAluno != nullptr) {
            if(ptrAluno->aluno->getMatricula() == estudante->getMatricula()) return ptrAluno;
 
            ptrAluno = ptrAluno->next;
        }
 
        return nullptr;
    }
 
 
    void removeAluno(Aluno* estudante) {
        if(estudante == nullptr) return;
        else if(searchAluno(estudante) == nullptr) return;
        
        NodeAluno* ptrHead = turmaPorPeriodo[estudante->getPeriodo()];
        NodeAluno* ptrAluno = searchAluno(estudante);
 
        if(ptrAluno == ptrHead) {
            cout << "head equal item to remove\n";
            // remove head
            turmaPorPeriodo[estudante->getPeriodo()] = turmaPorPeriodo[estudante->getPeriodo()]->next;
            delete ptrAluno;
        } else {
            while(ptrHead->next->aluno->getMatricula() != ptrAluno->aluno->getMatricula()) ptrHead = ptrHead->next;
            // now we are at the previous node of the one we want to remove
            ptrHead->next = ptrAluno->next;
            delete ptrAluno;
        }
    }
 
    NodeAluno* getHead(float periodo) {
        return turmaPorPeriodo[periodo];
    }
 
    void printTurma(float periodo) {
        NodeAluno* head = turmaPorPeriodo[periodo];
        cout << "Inicio da turma\n\n";
        while(head != nullptr) {
            head->aluno->infoAluno();
            cout << "\n";
            head = head->next;
        }
 
        cout << "Fim da turma\n\n";
    }
 
    string getNomeDisciplina() {
        return nomeDisciplina;
    }
};
 
struct NodeDisciplina {
    Disciplina* disciplina;
    NodeDisciplina* next;
 
    NodeDisciplina() : disciplina(nullptr), next(nullptr) {}
    NodeDisciplina(Disciplina* x) : disciplina(x), next(nullptr) {}
};

struct listaDisciplinas {
    NodeDisciplina *ptrInicio;
 
    listaDisciplinas() : ptrInicio(nullptr) {}
    listaDisciplinas(NodeDisciplina* x) : ptrInicio(x) {}
 
    void addDisciplina(Disciplina* novaDisciplina) {
        NodeDisciplina* ptrDisciplina = new NodeDisciplina(novaDisciplina);
 
        if (ptrInicio == nullptr) {
            ptrInicio = ptrDisciplina;
        }
        else {
            NodeDisciplina *aux;
            aux = ptrInicio;
 
            while (aux->next != nullptr){
                aux = aux->next;
            }
 
            aux->next = ptrDisciplina;
        }
    }
 
    NodeDisciplina* searchDisciplina(Disciplina* _disciplina) {
        NodeDisciplina* ptrAtual = ptrInicio;
 
        while(ptrAtual != nullptr) {
            if(ptrAtual->disciplina->getNomeDisciplina() == _disciplina->getNomeDisciplina()) return ptrAtual;
 
            ptrAtual = ptrAtual->next;
        }
 
        return nullptr;
    }

    NodeDisciplina* searchDisciplina(string nomeDisciplina) {
        Disciplina *_disciplina = new Disciplina(nomeDisciplina);
        NodeDisciplina* ptrAtual = ptrInicio;
 
        while(ptrAtual != nullptr) {
            if(ptrAtual->disciplina->getNomeDisciplina() == _disciplina->getNomeDisciplina()) return ptrAtual;
 
            ptrAtual = ptrAtual->next;
        }
 
        return nullptr;
    }
 
    void removeDisciplina(Disciplina* _disciplina) {
        if(_disciplina == nullptr) return;
        else if(searchDisciplina(_disciplina) == nullptr) return;
        
        NodeDisciplina* ptrHead = ptrInicio;
        NodeDisciplina* ptrDisciplina = searchDisciplina(_disciplina);
 
        if(ptrDisciplina == ptrHead) {
            // remove head
            ptrInicio = ptrInicio->next;
            delete ptrDisciplina;
        } else {
            while(ptrHead->next->disciplina->getNomeDisciplina() != ptrDisciplina->disciplina->getNomeDisciplina()) ptrHead = ptrHead->next;
            // now we are at the previous node of the one we want to remove
            ptrHead->next = ptrDisciplina->next;
            delete ptrDisciplina;
        }
    }
 
    void printDisciplinas() {
        NodeDisciplina* head = ptrInicio;
        cout << "Inicio da lista de disciplina\n\n";
        while(head != nullptr) {
            head->disciplina->infoDisciplina();
            cout << "\n";
            head = head->next;
        }
 
        cout << "Fim da lista de disciplina\n\n";
    }
};