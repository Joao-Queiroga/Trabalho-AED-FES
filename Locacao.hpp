#include <string>
#include "Veiculo.hpp"
#include "Cliente.hpp"
using namespace std;

class Locacao {
    private:
    int codigo;
    string dataRetirada;
    string dataDevolucao;
    string seguro;
    int qntDias;
    Veiculo& veiculo;
    Cliente& cliente;

    public:
    Locacao(Cliente& cliente, Veiculo& veiculo):cliente { cliente }, veiculo{ veiculo } {
    }
    string getDataRetirada() {
        return this->dataRetirada;
    }

    string getDataDevolucao() {
        return this->dataDevolucao;
    }

    void setSeguro(string seguro) {
        this->seguro = seguro;
    }

    string getSeguro() {
        return this->seguro;
    }

    int getQntDias() {
        return this->qntDias;
    }

    void setVeiculo(Veiculo& veiculo) {
        this->veiculo = veiculo;
    }
};
