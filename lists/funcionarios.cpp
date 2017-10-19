#include <iostream>
#include <string>

using namespace std;

class Data {
public:
    Data(int dia, int mes, int ano) : dia_{dia} , mes_{mes}, ano_{ano} {}
    void MostreData() {cout << dia_ << '/'<< mes_ << '/' << ano_ << endl; }
private:
    int dia_ ;
    int mes_ ;
    int ano_ ;
};

class CPF {
public:
    CPF(int cpf) : cpf_{cpf} {}
    void MostreCPF() {
        cout << cpf_ << endl;
    }
private:
    int cpf_ ;
};

class RG {
public:
    RG(int rg) : rg_{rg}{}
    void MostreRG() {
        cout << rg_ << endl;
    }
private:
    int rg_ ;
};

class Pessoa{
public:
    Pessoa(string nome, Data dataNascimento , CPF cpf , RG  rg , string nome_mae) 
    : nome_{nome} , dataNascimento_{dataNascimento} , cpf_{cpf} , rg_{rg} , nome_mae_{nome_mae} {}
    void MostreInfo() {
        cout << nome_ << '\n' << " nasceu em " << dataNascimento_.MostreData() <<
        "cpf : " << cpf_.MostreCPF() << "rg : " << rg_.MostreRG() << "nome da mae : " << nome_mae_ << endl;;
    }
private:
    string nome_ ;
    Data dataNascimento_ ;
    CPF cpf_ ;
    RG rg_ ;
    string nome_mae_ ;
};


int main () {
    Pessoa pessoa{"Joao Silva", Data{1,1,1998} ,222 , 555 ,"Joana" };
    pessoa.MostreInfo() ;
}