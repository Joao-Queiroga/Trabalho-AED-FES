#include <string>
using namespace std;

class Cliente {
    protected:
    int codigo;
    string nome;
    string endereco;
    string telefone;

    public:
    void setCodigo(int codigo) {
        this->codigo = codigo;
    }

    int getCodigo() { return this->codigo; }

    void setNome(string nome) {
        this->nome = nome;
    }

    string getNome() { return this->nome }

    void setEndereco(string endereco) {
        this->endereco = endereco;
    }

    string getEndereco() { return this->endereco }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }

    string getTelefone() { return this->telefone }
};
