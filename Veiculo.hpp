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
    char status; // D = disponivel A = alugado

    public:
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

    void setStatus(char status) {
        this->status = status;
    }

    char getStatus() {
        return this->status;
    }
};
