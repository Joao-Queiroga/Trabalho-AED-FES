#include <string>
#include "Veiculo.cpp"
#include "Cliente.cpp"
using namespace std;

class Locacao {
    private:
    int codigo;
    string dataRetirada;
    string dataDevolucao;
    string seguro;
    int qntDias;
    Veiculo veiculo;
    int codigoVeiculo;
    Cliente cliente;
    int codigoCliente;
};
