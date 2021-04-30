#include"matriculas.h"
#include"displays.h"
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
listaDisciplinas Disciplinas;
 
void getDataDisciplina(string *input) {
    displayFeatureDisciplina();
    
    for(int i = 0; i < 4; i++) {
        string userInput;
        cout << "- ";
        getline(cin, userInput);
        // cout << "> " << userInput << endl;
        input[i] = userInput;
    }
    cout << "\n";
}
 
void showDataDisciplina(string *input) {
    cout << "\n o x é pra demarcar o fim, sem perigo de ter espaços indesejados" << endl;
    cout << "codigo: " << input[0] << "x" << endl;
    cout << "nome professor: " << input[1] << "x" << endl;
    cout << "nome da disciplina: " << input[2] << "x" << endl;
    cout << "creditos: " << input[3] << "x" << endl;
}
 
void adicionarDisciplina(bool show) {
    string data[4];
    getDataDisciplina(data);
    Disciplina* novaDisciplina = new Disciplina(data[1], data[2], stoi(data[3]), data[0]);
    Disciplinas.addDisciplina(novaDisciplina);
 
    cout << "Adicionada com sucesso" << endl;
 
    if(show) showDataDisciplina(data);

    delete novaDisciplina;
}
 
void removerDisciplina() {
    string data[4];
    getDataDisciplina(data);
    Disciplina* DisciplinaEscolhida = new Disciplina(data[1], data[2], stoi(data[3]), data[0]);
    Disciplinas.removeDisciplina(DisciplinaEscolhida);
 
    cout << "Removido com sucesso" << endl;
    delete DisciplinaEscolhida;
}
 
void consultarDisciplinas() {
    string periodo;
    string data[4];
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

    delete DisciplinaEscolhida;
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
        cout << "- ";
        getline(cin, userInput);
        input[i] = userInput;
    }
    cout << "\n";
}
 
void removerAluno() {
    string data[4];
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

    delete novoAluno;
}
 
void consultarAlunos() {
    string data[4];
    getDataAluno(data);
    Aluno* novoAluno = new Aluno(data[0], data[1], data[2], data[3]);
 
    NodeDisciplina *ptrHead = Disciplinas.ptrInicio;
 
    while (ptrHead != nullptr) {
        if (ptrHead->disciplina->searchAluno(novoAluno) != nullptr) ptrHead->disciplina->infoDisciplina();
        ptrHead = ptrHead->next;
    }

    delete novoAluno;
}
 
void adicionarAluno() {
    string data[4];
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
            } else{
                queryResult->disciplina->addAluno(novoAluno);
                cout << "\nAluno adicionado com sucesso\n";
            }
        }
    }

    delete novoAluno;
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
    file.open("database.txt", ios::trunc);
    NodeDisciplina* ptrNodeDisciplina = Disciplinas.ptrInicio;

    while(ptrNodeDisciplina != nullptr) {
        if(ptrNodeDisciplina->disciplina->getHash().size() == 0) {
            string dataLinha = "";
            dataLinha += ptrNodeDisciplina->disciplina->stringfyHeader();
            dataLinha += ",,,\n";
            file << dataLinha;
        } else {
            for(auto itr : ptrNodeDisciplina->disciplina->getHash()){
                NodeAluno* aux = itr.second;
                
                if (aux == nullptr) {
                    string dataLinha = "";
                    dataLinha += ptrNodeDisciplina->disciplina->stringfyHeader();
                    dataLinha += ",,,\n";
                    file << dataLinha;
                }
                else {
                    while(aux != nullptr) {
                        string dataLinha = "";
                        dataLinha += ptrNodeDisciplina->disciplina->stringfyHeader();
                        dataLinha += aux->aluno->stringfyAluno();
                        file << dataLinha;
                        aux = aux->next;
                    }
                }
            }
        }
        ptrNodeDisciplina = ptrNodeDisciplina->next;
    }
}



void loadDados(){
    // Create a text string, which is used to output the text file
    string MyText;

    // criando string onde será salvo os dados de cada linha
    string data_linha[8];

    // Read from the text file
    ifstream MyReadFile("database.txt");

    // loop while and getline() to read the file line by line
    while (getline (MyReadFile, MyText)) {
        string my_str = MyText;

        stringstream s_stream(my_str); //create string stream from the string
        for (int i = 0; i < 8; i++) {
            string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            data_linha[i] = substr;
        }
        //dados salvos em um array data_linha[]


        // atribuindo os dados da disciplina
        string _nomeDisciplina = data_linha[0];
        string _nomeProfessor = data_linha[1];
        int _creditos = stoi(data_linha[2]);
        string _codigo = data_linha[3];

        // conferir pelo nome se a disciplina existe.
        NodeDisciplina *confere_disciplina;
        confere_disciplina = Disciplinas.searchDisciplina(_nomeDisciplina);
        // se discplina não existir: criar, add aluno (se for o caso) e add discplina à lista de disciplinas
        if (confere_disciplina == nullptr) {
            
            // construindo de fato a nova discplina
            Disciplina *ptr_nova_disciplina = new Disciplina(_nomeDisciplina,_nomeProfessor,_creditos,_codigo);
            
            // se o comando veio também com um aluno,
            // adicionar o aluno à discplina criada
            if (data_linha[4] != "") {
                // atribuindo os dados do aluno
                string _matricula = data_linha[4];
                string _nome = data_linha[5];
                string _cpf = data_linha[6];
                string _periodo = data_linha[7];

                // construindo o aluno
                Aluno *ptr_novo_aluno = new Aluno(_matricula,_nome,_cpf,_periodo);


                // adicionar aluno à disciplina
                ptr_nova_disciplina->addAluno(ptr_novo_aluno);
            }
            

            Disciplinas.addDisciplina(ptr_nova_disciplina);
        }
        else {
        // se a disciplina já existir: apenas adicionar o aluno

            // criando um ponteiro que aponta para tal disciplina
            Disciplina* aponta_disciplina ;
            aponta_disciplina = confere_disciplina->disciplina;
            
            // atribuindo os dados do aluno
            string _matricula = data_linha[4];
            string _nome = data_linha[5];
            string _cpf = data_linha[6];
            string _periodo = data_linha[7];


            // construindo o aluno
            Aluno *ptr_novo_aluno = new Aluno(_matricula,_nome,_cpf,_periodo);

            // adicionar aluno à disciplina
            aponta_disciplina->addAluno(ptr_novo_aluno);
        }

    }

    cout << "\nDados carregados com sucesso.\n";

    // Close the file
    MyReadFile.close();
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