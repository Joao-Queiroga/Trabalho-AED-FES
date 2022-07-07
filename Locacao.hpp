#include <bits/types/time_t.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Veiculo.hpp"
#include "Cliente.hpp"
using namespace std;

class Locacao {
    private:
    unsigned int codigo;
    string dataRetirada;
    //time_t dataRetirada;
    string dataDevolucao;
    bool seguro = false;
    int qntDias;
    bool devolvido;
    Veiculo& veiculo;
    Cliente& cliente;

    public:
    Locacao(int codigo, string dataRetirada, string dataDevolucao, Cliente& cliente, Veiculo& veiculo):cliente { cliente }, veiculo{ veiculo } {
        this->codigo = codigo;
        this->dataRetirada = dataRetirada;
        this->dataDevolucao = dataDevolucao;
        veiculo.setDisponivel(false);
    }

    int getCodigo() {
        return this->codigo;
    }

    string getDataRetirada() {
        return this->dataRetirada;
    }

    string getDataDevolucao() {
        return this->dataDevolucao;
    }

    void setSeguro(bool seguro) {
        this->seguro = seguro;
    }

    bool getSeguro() {
        return this->seguro;
    }

    int getQntDias() {
        return this->qntDias;
    }

    int getCodigoVeiculo() {
        return this->veiculo.getCodigo();
    }

    int getCodigoCliente() {
        return this->cliente.getCodigo();
    }
};

void aluga(vector<Locacao>& locacoes, vector<Veiculo>& veiculos, vector<Cliente>& clientes) {
    int codigoCliente, ocupantes;
    string dataRetirada, dataDevolucao;
    cout << "Digite o codigo do cliente que irá alugar um veiculo: ";
    cin >> codigoCliente;
    cout << "Digite a data de devolucao do veiculo :";
    cin >> dataDevolucao;
    cout << "Digite o numero de ocupantes desejados no veículo: ";
    cin >> ocupantes;
    dataRetirada = "Hoje";
}

void gravaLocacao(vector<Locacao>& locacoes) {
    ofstream arquivo("Locacoes.txt", ios::out|ios::trunc);
    if (arquivo.is_open()) {
        for (int i = 0; i < locacoes.size(); i++) {
            arquivo << locacoes[i].getCodigo() << endl;
            arquivo << locacoes[i].getDataRetirada() << endl;
            arquivo << locacoes[i].getDataDevolucao() << endl;
            arquivo << locacoes[i].getSeguro() << endl;
            arquivo << locacoes[i].getCodigoVeiculo() << endl;
            arquivo << locacoes[i].getCodigoCliente() << endl;
        }
    }
}

void getLocacoes(vector<Locacao>& locacoes, vector<Veiculo>& veiculos, vector<Cliente>& clientes) {
    ifstream arquivo("Locacoes.txt", ios::in);
    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            int codigo;
            string dataRetirada, dataDevolucao;
            bool seguro;
            int codigoVeiculo, codigoCliente;
            arquivo >> codigo;
            arquivo >> dataRetirada;
            arquivo >> dataDevolucao;
            arquivo >> seguro;
            arquivo >> codigoVeiculo;
            arquivo >> codigoCliente;
            Veiculo *veiculo = getVeiculoByCodigo(veiculos, codigoVeiculo);
            Cliente *cliente = getClienteByCodigo(clientes, codigoCliente);
            Locacao locacao = *new Locacao(codigo, dataRetirada, dataDevolucao, *cliente, *veiculo);
            locacao.setSeguro(seguro);
            locacoes.push_back(locacao);
        }
        arquivo.close();
    }
}
