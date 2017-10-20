#include <iostream>
#include <string>

using namespace std;

class Data {
public:
    Data() = default ;
    Data(int dia, int mes, int ano) : dia_{dia} , mes_{mes}, ano_{ano} {}
    void MostreData() {cout << dia_ << '/'<< mes_ << '/' << ano_ << endl; }
private:
    int dia_ ;
    int mes_ ;
    int ano_ ;
};

class CPF {
public:
    CPF() = default ;
    CPF(int cpf) : cpf_{cpf} {}
    int get_c() {
        return cpf_ ;
    }
    void MostreCPF() {
        cout << cpf_ << endl;
    }
private:
    int cpf_ ;
};

class RG {
public:
    RG()= default ;
    RG(int rg) : rg_{rg}{}
    void MostreRG() {
        cout << rg_ << endl;
    }
private:
    int rg_ ;
};

class Pessoa{
public:
    Pessoa()= default ;
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
    void set_nome (string nome) {
        nome_ = nome ;
    }
    void set_dataNascimento (Data d) {
        dataNascimento_ = d ;
    }
    void set_cpf (int cpf) {
        cpf_ = cpf ;
    }
    void set_rg (int rg) {
        rg_ = rg ;
    }
    void set_nome_mae (string nome) {
        nome_mae_ = nome ;
    }

    int get_cpf () {
        return cpf_.get_c() ;
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
 
    Funcionario() : Pessoa{} , dataDeContratacao_{} , salario_{} {}
    Funcionario(string nome, Data dataNascimento , CPF cpf , RG  rg , string nome_mae , Data dataDeContratacao, float salario )
    : Pessoa{nome, dataNascimento , cpf , rg , nome_mae} , dataDeContratacao_{dataDeContratacao} , salario_{salario} {}
    void MostreFunc() {
        MostreInfo() ;
        cout << "salario : " << salario_ << endl << "data de contratacao : " ;
        dataDeContratacao_.MostreData() ;
    }
    void set_data (Data d) {
        dataDeContratacao_ = d ;
    }
    void set_salario(float s) {
        salario_ = s ;
    }
    float get_salario() {
        return salario_ ;
    }
private:
    Data dataDeContratacao_;
    float salario_ ;
};

class Cadastro : public Funcionario {
public:
    Cadastro() : Funcionario{} , quantidade_{0} , f_{nullptr} {}
    Cadastro(int quantidade) {
        quantidade_ = quantidade ;
        f_ = new Funcionario[quantidade_] ;
        string nome , nome_mae ;
        int cpf, rg , dia_n , dia_c , mes_n , mes_c , ano_n , ano_c ;
        float salario ;
        for (int i{0} ; i < quantidade_ ; i++) {
            cout << "Digite o nome do funcionario "<< i+1 << ": " ;
            cin >> nome ;
            f_[i].set_nome(nome) ;
            cout << "Digite o nome da mae do funcionario "<< i+1 << ": " ;
            cin >> nome_mae ;
            f_[i].set_nome(nome_mae) ;
            cout << "Digite a data de nascimento do funcionario " << i+1 << "(dia/mes/ano): " ;
            cin >> dia_n ;
            cin >> mes_n ;
            cin >> ano_n ;
            Data d{dia_n,mes_n,ano_n} ;
            f_[i].set_dataNascimento(d) ;
            cout << "Digite o cpf do funcionario "<< i+1 << ": " ;
            cin >> cpf ;
            f_[i].set_cpf(cpf) ;
            cout << "Digite o rg do funcionario "<< i+1 << ": " ;
            cin >> rg ;
            f_[i].set_rg(rg) ;
            cout << "Digite a data de contratacao do funcionario " << i+1 << "(dia/mes/ano): " ;
            cin >> dia_c ;
            cin >> mes_c ;
            cin >> ano_c ;
            Data dc{dia_c, mes_c, ano_c} ;
            f_[i].set_data(dc) ;
            cout << "Digite o salario do funcionario " << i+1 << "(dia/mes/ano): " ;
            cin >> salario ;
            f_[i].set_salario(salario) ;
            //f_[i](nome, (Data{dia_n,mes_n,ano_n}), cpf , rg , nome_mae , (Data{dia_c,mes_c,ano_c}), salario) ;
        }
    }    
    void MostreCadastro() {
        for (int i{0} ; i < quantidade_  ; i++) {
            f_[i].MostreFunc() ;
        }    
    }
    void busca_funcionario (int cpf) {
        for (int i{0} ; i < quantidade_ ; i++) {
            
            if(f_[i].get_cpf() == cpf) {
                f_[i].MostreFunc() ;
                return ;
            }
        }
        cout << "Funcionario não encontrado!" << endl ;
    }

    float salario_total() {
        float salario{0} ;
        for(int i{0} ; i < quantidade_ ; i++) {
            salario += f_[i].get_salario() ;
        }
        return salario ;
    }

    ~Cadastro() {
        delete [] f_ ;
    }

private:
    int quantidade_ ;
    Funcionario *f_ ;
};

int main () {
    //Pessoa pessoa{"Joao Silva", Data{1,1,1998} ,222 , 555 ,"Joana"};
    //pessoa.MostreInfo() ;
    //Funcionario f{"Joao Silva", Data{1,1,1998} ,222 , 555 ,"Joana",Data{2,2,2012}, 500.00 };
    //f.MostreFunc() ;

    int n , cpf ;
    cout << "Digite a quantidade de funcionarios da sua empresa : " ;
    cin >> n ;
    Cadastro empresa{1} ;
    empresa.MostreCadastro() ;
    
    cout << "Digite o cpf do funcionario que você deseja encontrar : " ;
    cin >> cpf ;
    empresa.busca_funcionario(cpf) ;

    cout << "O salario de todos os funcionarios da empressa somados é de : " << empresa.salario_total() << endl ;

}