#include"matriculas.h"
#include"displays.h"
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
    Disciplina* novaDisciplina = new Disciplina(data[1], data[2], stoi(data[3]));
    Disciplinas.addDisciplina(novaDisciplina);

    cout << "Adicionado com sucesso" << endl;

    if(show) showDataDisciplina(data);
}

void removerDisciplina() {
    string *data = new string[4];
    getDataDisciplina(data);
    Disciplina* DisciplinaEscolhida = new Disciplina(data[1], data[2], stoi(data[3]));
    Disciplinas.removeDisciplina(DisciplinaEscolhida);

    cout << "Removido com sucesso" << endl;
}

void consultarDisciplinas() {
    string *data = new string[4];
    getDataDisciplina(data);
    Disciplina* DisciplinaEscolhida = new Disciplina(data[1], data[2], stoi(data[3]));
    NodeDisciplina* queryResult = Disciplinas.searchDisciplina(DisciplinaEscolhida);
    if(queryResult != nullptr) queryResult->disciplina->infoDisciplina();
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

void menuInicialFeatures(int userResponse, bool& wannaQuit) {
    switch (userResponse) {
    case 0:
        wannaQuit = true;
        return;
    case 1:
        // menuAlunos();
        break;
    case 2:
        menuDisciplinas();
        break;
    }
}

void menuInicial() {
    bool quit = false;
 
    while(!quit) {
        displayMenuInicial();
        int response;
        cout << "Escolha uma opção: ";
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