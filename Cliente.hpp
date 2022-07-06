#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class Cliente {
    protected:
    int codigo;
    string nome;
    string endereco;
    string telefone;

    public:
    Cliente(int codigo, string nome, string endereco, string telefone) {
        this->codigo = codigo;
        this->nome = nome;
        this->endereco = endereco;
        this->telefone = telefone;
    }

    int getCodigo() {
        return this->codigo;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    string getNome() {
        return this->nome;
    }

    void setEndereco(string endereco) {
        this->endereco = endereco;
    }

    string getEndereco() {
        return this->endereco;
    }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }

    string getTelefone() {
        return this->telefone;
    }
};


void cadastraCliente(vector<Cliente>& clientes) {
    string nome,endereco,telefone; 
    getline(cin,nome);
    getline(cin,endereco);
    getline(cin,telefone);
    Cliente cliente = *new Cliente (clientes.size(),nome,endereco,telefone);         
}

void gravaClientes(vector<Cliente>& clientes) {
    ofstream arquivo("Cliente.txt", ios::out|ios::trunc);
        if (arquivo.is_open()) {
            for (int i = 0; i < clientes.size(); i++ ) {
                arquivo << clientes[i].getCodigo() << endl; 
                arquivo << clientes[i].getNome() << endl; 
                arquivo << clientes[i].getEndereco() << endl; 
                arquivo << clientes[i].getTelefone() << endl;               
            }
            arquivo.close();
        }
}

void getCliente(vector<Cliente>& clientes) {
    ifstream arquivo("clientes.txt", ios::in);
    if (arquivo.is_open()){
        while (!arquivo.eof()){
            int codigo;
            string nome,endereco,telefone;
            arquivo >> codigo;
            getline(arquivo,nome);
            getline(arquivo,endereco);
            getline(arquivo,telefone);
            arquivo >> nome;
            arquivo >> endereco;
            arquivo >> telefone;
            Cliente cliente = *new Cliente(codigo,nome,endereco,telefone);
            clientes.push_back(cliente);
        }   
           arquivo.close();
    }
}

Cliente* getClienteByCodigo(vector<Cliente>& clientes, int codigo) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].getCodigo() == codigo) {
            return &clientes[i];
        }
    }
    return NULL;
}
