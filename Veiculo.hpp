#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Veiculo {
    protected:
    unsigned int codigo;
    string descricao;
    string modelo;
    string cor;
    string placa;
    float diaria;
    int ocupantes;
    bool disponivel = true;

    public:
    Veiculo(int codigo, string descricao, string modelo, string cor, string placa, float diaria, int ocupantes) {
        this->codigo = codigo;
        this->descricao = descricao;
        this->modelo = modelo;
        this->cor = cor;
        this->placa = placa;
        this->diaria = diaria;
        this->ocupantes = ocupantes;
    }

    Veiculo(int codigo, string descricao, string modelo, string cor, string placa, float diaria, int ocupantes, bool disponivel) {
        this->codigo = codigo;
        this->descricao = descricao;
        this->modelo = modelo;
        this->cor = cor;
        this->placa = placa;
        this->diaria = diaria;
        this->ocupantes = ocupantes;
        this->disponivel = disponivel;
    }

    int getCodigo() {
        return this->codigo;
    }

    void setDescricao(string descricao) {
        this->descricao = descricao;
    }

    string getDescricao() {
        return this->descricao;
    }

    void setModelo(string modelo) {
        this->modelo = modelo;
    }

    string getModelo() {
        return this->modelo;
    }

    void setCor(string cor) {
        this->cor = cor;
    }

    string getCor() {
        return this->cor;
    }

    void setPlaca(string placa) {
        this->placa = placa;
    }

    string getPlaca() {
        return this->placa;
    }

    void setDiaria(float diaria) {
        this->diaria = diaria;
    }

    float getDiaria() {
        return this->diaria;
    }

    void setOcupantes(int ocupantes) {
        this->ocupantes = ocupantes;
    }

    int getOcupantes() {
        return this->ocupantes;
    }

    bool estaDisponivel() {
        return this->disponivel;
    }

    void setDisponivel(bool disponivel) {
        this->disponivel = disponivel;
    }
};

void cadastraVeiculo(vector<Veiculo>& veiculos) {
    string descricao, modelo, cor, placa;
    float diaria;
    int ocupantes;
    getline(cin, descricao);
    getline(cin, modelo);
    cin >> cor;
    cin >> placa;
    cin >> diaria;
    cin >> ocupantes;
    Veiculo veiculo = *new Veiculo(veiculos.size(), descricao, modelo, cor,placa, diaria, ocupantes);
    veiculos.push_back(veiculo);
}

void gravaVeiculos(vector<Veiculo>& veiculos) {
    ofstream arquivo("Veiculos.txt", ios::out|ios::trunc);
    if (arquivo.is_open()) {
        for (int i = 0; i < veiculos.size(); i++) {
            arquivo << veiculos[i].getCodigo() << endl;
            arquivo << veiculos[i].getDescricao() << endl;
            arquivo << veiculos[i].getModelo() << endl;
            arquivo << veiculos[i].getCor() << endl;
            arquivo << veiculos[i].getPlaca() << endl;
            arquivo << veiculos[i].getDiaria() << endl;
            arquivo << veiculos[i].getOcupantes() << endl;
            arquivo << veiculos[i].estaDisponivel() << endl;
        }
        arquivo.close();
    }
}

Veiculo* getVeiculoByCodigo(vector<Veiculo>& veiculos, int codigo) {
    int i;
    for (i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].getCodigo() == codigo) {
            return &veiculos[i];
        }
    }
    return NULL;
}

void getVeiculos(vector<Veiculo>& veiculos) {
    ifstream arquivo("Veiculos.txt", ios::in);
    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            int codigo, ocupantes;
            string descricao, modelo, cor, placa;
            float diaria;
            bool disponivel;
            arquivo >> codigo;
            getline(arquivo, descricao);
            getline(arquivo, modelo);
            arquivo >> cor;
            arquivo >> placa;
            arquivo >> diaria;
            arquivo >> ocupantes;
            arquivo >> disponivel;
            Veiculo veiculo = *new Veiculo(codigo, descricao, modelo, cor, placa, diaria, ocupantes, disponivel);
            veiculos.push_back(veiculo);
        }
        arquivo.close();
    }
}
