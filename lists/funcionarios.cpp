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
        cout << nome_ << '\n' << "nasceu em " ;
        dataNascimento_.MostreData() ;
        cout << "cpf : ";
        cpf_.MostreCPF() ;
        cout << "rg : " ;
        rg_.MostreRG() ; 
        cout << "nome da mae : " << nome_mae_ << endl;;
    }
private:
    string nome_ ;
    Data dataNascimento_ ;
    CPF cpf_ ;
    RG rg_ ;
    string nome_mae_ ;
};

class Funcionario : public Pessoa{
public:
    Funcionario(string nome, Data dataNascimento , CPF cpf , RG  rg , string nome_mae ,
                Data dataDeContratacao, float salario , Pessoa pessoa)
    : Pessoa{nome, dataNascimento , cpf , rg , nome_mae} , dataDeContratacao_{dataDeContratacao} , salario_{salario}{}
    void MostreFunc() {
        MostreInfo() ;
        cout << "salario : " << salario_ << endl << "data de contratacao : " ;
        dataDeContratacao_.MostreData() ;
    }
private:
    Data dataDeContratacao_;
    float salario_ ;
};

int main () {
    Funcionario f{Data{2,2,2012}, 500.00 ,"Joao Silva", Data{1,1,1998} ,222 , 555 ,"Joana"};
    f.MostreFunc() ;
}