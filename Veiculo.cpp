#include <string>
using namespace std;

class Veiculo {
    protected:
    int codigo;
    string descricao;
    string modelo;
    string cor;
    string placa;
    float diaria;
    int ocupantes;
    char status;

    public:
    void setDescricao(string descricao) {
        this->descricao = descricao;
    }

    void setModelo(string modelo) {
        this->modelo = modelo;
    }

    void setCor(string cor) {
        this->cor = cor;
    }

    void setPlaca(string placa) {
        this->placa = placa;
    }

    void setDiaria(float diaria) {
        this->diaria = diaria;
    }

    void setOcupantes(int ocupantes) {
        this->ocupantes = ocupantes;
    }

    void setStatus(char status) {
        this->status = status;
    }
};
