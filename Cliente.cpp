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

    void setEndereco(string endereco) {
        this->endereco = endereco;
    }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }
};
