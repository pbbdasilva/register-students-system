#include"matriculas.h"
#include"displays.h"
#include<fstream>
listaDisciplinas Disciplinas;
 
void getDataDisciplina(string *input) {
    displayFeatureDisciplina();
    
    for(int i = 0; i < 4; i++) {
        string userInput;
        getline(cin, userInput);
        // cout << "> " << userInput << endl;
        input[i] = userInput;
    }
}
 
void showDataDisciplina(string *input) {
    cout << "\n o x é pra demarcar o fim, sem perigo de ter espaços indesejados" << endl;
    cout << "codigo: " << input[0] << "x" << endl;
    cout << "nome professor: " << input[1] << "x" << endl;
    cout << "nome da disciplina: " << input[2] << "x" << endl;
    cout << "creditos: " << input[3] << "x" << endl;
}
 
void adicionarDisciplina(bool show) {
    string *data = new string[4];
    getDataDisciplina(data);
    Disciplina* novaDisciplina = new Disciplina(data[1], data[2], stoi(data[3]), data[0]);
    Disciplinas.addDisciplina(novaDisciplina);
 
    cout << "Adicionado com sucesso" << endl;
 
    if(show) showDataDisciplina(data);
}
 
void removerDisciplina() {
    string *data = new string[4];
    getDataDisciplina(data);
    Disciplina* DisciplinaEscolhida = new Disciplina(data[1], data[2], stoi(data[3]), data[0]);
    Disciplinas.removeDisciplina(DisciplinaEscolhida);
 
    cout << "Removido com sucesso" << endl;
}
 
void consultarDisciplinas() {
    string periodo;
    string *data = new string[4];
    getDataDisciplina(data);
    Disciplina* DisciplinaEscolhida = new Disciplina(data[1], data[2], stoi(data[3]), data[0]);
    NodeDisciplina* queryResult = Disciplinas.searchDisciplina(DisciplinaEscolhida);
    cout << "Diga o período: ";
    cin >> periodo;
    if(queryResult != nullptr) {
        NodeAluno* aux = queryResult->disciplina->getHead(periodo);

        while(aux != nullptr) aux->aluno->infoAluno(), aux = aux->next;
    }
    else cout << "Não existe no sistema" << endl;
}
 
void disciplinaFeatures(int userResponse, bool& wannaQuit) {
    switch (userResponse) {
    case 0:
        wannaQuit = true;
        return;
    case 1:
        adicionarDisciplina(false);
        break;
    case 2:
        removerDisciplina();
        break;
    case 3:
        consultarDisciplinas();
        break;
    }
}
 
void menuDisciplinas() {
    bool quit = false;
 
    while(!quit) {
        displayMenuDisciplinas();
        int response;
        cin >> response;
        cin.ignore(1,'\n');
 
        disciplinaFeatures(response, quit);
        
        if(quit) return;
    }
}
 
void getDataAluno(string *input) {
    displayFeatureAluno();
    for (int i = 0; i < 4; i++) {
        string userInput;
        getline(cin, userInput);
        input[i] = userInput;
    }
}
 
void removerAluno() {
    string *data = new string[4];
    getDataAluno(data);
    Aluno* novoAluno = new Aluno(data[0], data[1], data[2], data[3]);
 
    NodeDisciplina *ptrHead = Disciplinas.ptrInicio;
 
    while (ptrHead != nullptr) {
        if (ptrHead->disciplina->searchAluno(novoAluno) != nullptr) {
            ptrHead->disciplina->removeAluno(novoAluno);
            ptrHead->disciplina->infoDisciplina();
        }
        ptrHead = ptrHead->next;
    }
}
 
void consultarAlunos() {
    string *data = new string[4];
    getDataAluno(data);
    Aluno* novoAluno = new Aluno(data[0], data[1], data[2], data[3]);
 
    NodeDisciplina *ptrHead = Disciplinas.ptrInicio;
 
    while (ptrHead != nullptr) {
        if (ptrHead->disciplina->searchAluno(novoAluno) != nullptr) ptrHead->disciplina->infoDisciplina();
        ptrHead = ptrHead->next;
    }
}
 
void adicionarAluno() {
    string *data = new string[4];
    getDataAluno(data);
    Aluno* novoAluno = new Aluno(data[0], data[1], data[2], data[3]);
 
    bool enoughDisciplinas = false;
    while(!enoughDisciplinas) {
        string nomeDisciplina;
        cout << "Digite o Nome da Disciplina (0 para parar):\n";
        getline(cin, nomeDisciplina);
 
        if (nomeDisciplina == "0") {
            break;
        } else {
            NodeDisciplina* queryResult = Disciplinas.searchDisciplina(nomeDisciplina);
            if (queryResult == nullptr) {
                cout << "\nEssa disciplina não existe.\n";
                continue;
            } else queryResult->disciplina->addAluno(novoAluno);
        }
    }    
}
  
void alunoFeatures(int userResponse, bool& wannaQuit) {
    switch (userResponse) {
    case 0:
        wannaQuit = true;
        return;
    case 1:
        adicionarAluno();
        break;
    case 2:
        removerAluno();
        break;
    case 3:
        consultarAlunos();
        break;
    }
}
 
void menuAlunos() {
    bool quit = false;
 
    while(!quit) {
        displayMenuAlunos();
        int response;
        cin >> response;
        cin.ignore(1,'\n');
 
        alunoFeatures(response,quit);
 
        if(quit) return;
    }
}

void salvarDados() {
    ofstream file;
    file.open("teste.txt", ios::trunc);
    NodeDisciplina* ptrData = Disciplinas.ptrInicio;

    while(ptrData != nullptr) {
        string dataDisciplina = ">";
        dataDisciplina += ptrData->disciplina->stringfyHeader();
        file << dataDisciplina << endl;
        file << ptrData->disciplina->dataTurma() << endl;
        ptrData = ptrData->next;
    }
}

void loadDados() {
    ifstream file;

}



 
void menuInicialFeatures(int userResponse, bool& wannaQuit) {
    switch (userResponse) {
    case 0:
        wannaQuit = true;
        return;
    case 1:
        menuAlunos();
        break;
    case 2:
        menuDisciplinas();
        break;
    case 3:
        salvarDados();
        break;
    case 4:
        loadDados();
        break;
    }
}
 
void menuInicial() {
    bool quit = false;
 
    while(!quit) {
        displayMenuInicial();
        int response;
        cin >> response;
        cin.ignore(1,'\n');
 
        menuInicialFeatures(response,quit);
 
        if(quit) exit(EXIT_SUCCESS);
    }
} 
 
void testeAdicionarPeloMenu() {
    adicionarDisciplina(true);
}
 
int main() {
    menuInicial();
    // testeAdicionarPeloMenu();
}