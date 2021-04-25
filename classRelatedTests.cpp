#include"matriculas.h"

void testeConstrutorAluno() {
    Aluno pb("19417", "Pedro Barros", 13589305703, 2020.1);
    pb.infoAluno();
}
 
void testeConstrutorDisciplina() {
    Disciplina disc("Algebra Linear 2", "Zão", 5);
    disc.infoDisciplina();
}
 
void testeAdicionarAluno() {
    Aluno at("19001", "Tourinho", 06700000042, 2020.1);
    Aluno *ptr_at;
    ptr_at = &at;
    Disciplina calc3("Cálculo 3", "Ferreira", 6);
    calc3.addAluno(ptr_at);
    calc3.getHead(2020.1)->aluno->infoAluno();
}
 
void testeSearchAluno(bool insert) {
    Aluno at("19001", "Tourinho", 06700000042, 2020.1);
    Aluno *ptr_at;
    ptr_at = &at;
    Disciplina calc3("Cálculo 3", "Ferreira", 6);
    
    if(insert) calc3.addAluno(ptr_at);
 
    NodeAluno* aux_ptr;
    aux_ptr = calc3.searchAluno(ptr_at);
 
    if(aux_ptr == nullptr && !insert) cout << "OK\n";
    else if(aux_ptr == nullptr) cout << "not OK\naux_ptr is null\n";
    else if(aux_ptr->aluno == ptr_at && insert) cout << "OK\n";
    else cout << "not OK\naux_ptr different from inserted object\n";
}
 
void testeRemoverHeadAluno() {
    Aluno at("19001", "Tourinho", 06700000042, 2020.1);
    Aluno pb("19417", "Pedro Barros", 13589305703, 2020.1);
    Aluno *ptr_at, *ptr_pb;
    ptr_at = &at;
    ptr_pb = &pb;
    Disciplina calc3("Cálculo 3", "Ferreira", 6);
    NodeAluno* aux_ptr;
 
    calc3.addAluno(ptr_at);
    // comment to test removing only one node
    // uncomment to test having another node
    // calc3.addAluno(ptr_pb);
 
    aux_ptr = calc3.getHead(ptr_at->getPeriodo());
    aux_ptr->aluno->infoAluno();
 
    calc3.removeAluno(ptr_at);
    aux_ptr = calc3.getHead(ptr_at->getPeriodo());
    
    if(aux_ptr == nullptr) cout << "ok, null head";
    else if(aux_ptr->aluno != ptr_at) cout << "ok, not head";
    else aux_ptr->aluno->infoAluno();
}
 
void testeRemoverNotHeadAluno() {
    Aluno at("19001", "Tourinho", 06700000042, 2020.1);
    Aluno pb("19417", "Pedro Barros", 13589305703, 2020.1);
    Aluno *ptr_at, *ptr_pb;
    ptr_at = &at;
    ptr_pb = &pb;
    Disciplina calc3("Cálculo 3", "Ferreira", 6);
    NodeAluno* aux_ptr;
 
    calc3.addAluno(ptr_at);
    calc3.addAluno(ptr_pb);
 
    calc3.printTurma(ptr_at->getPeriodo());
 
    calc3.removeAluno(ptr_pb);
 
    calc3.printTurma(ptr_at->getPeriodo());
 
}
 
void testeAdicionarDisciplina() {
    listaDisciplinas disciplinas;
 
    Disciplina fis1("Física 1", "Rômulo", 5);
    Disciplina *ptrFis1;
    ptrFis1 = &fis1;
 
    disciplinas.printDisciplinas();
    disciplinas.addDisciplina(ptrFis1);
    disciplinas.printDisciplinas();
}
 
void testeSearchDisciplina(bool insert) {
    listaDisciplinas disciplinas;
 
    Disciplina fis1("Física 1", "Rômulo", 5);
    Disciplina *ptrFis1;
    ptrFis1 = &fis1;
 
    if(insert) disciplinas.addDisciplina(ptrFis1);
 
    NodeDisciplina* aux_ptr;
    aux_ptr = disciplinas.searchDisciplina(ptrFis1);
 
    if(aux_ptr == nullptr && !insert) cout << "OK\n";
    else if(aux_ptr == nullptr) cout << "not OK\naux_ptr is null\n";
    else if(aux_ptr->disciplina == ptrFis1 && insert) cout << "OK\n";
    else cout << "not OK\naux_ptr different from inserted object\n";
}
 
void testeRemoverDisciplina() {
    listaDisciplinas disciplinas;
 
    Disciplina fis1("Física 1", "Rômulo", 5);
    Disciplina *ptrFis1;
    ptrFis1 = &fis1;
 
    disciplinas.addDisciplina(&fis1);
 
    disciplinas.printDisciplinas();
    disciplinas.removeDisciplina(&fis1);
    disciplinas.printDisciplinas();
}
 
int main() {
    
}