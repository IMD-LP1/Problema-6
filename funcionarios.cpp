#include <iostream>
#include <string>

using namespace std;

class data {
public:
  data() = default;
	data(int dia, int mes, int ano) : dia_{dia}, mes_{mes}, ano_{ano} {}
	void mostre_data() { cout << dia_ << "/" << mes_  << "/" << ano_ << endl; }
   void set_data(int dia, int mes, int ano)
   {
      dia_ = dia;
      mes_ = mes;
      ano_ = ano;
   }
private:
	int dia_;
	int mes_;
	int ano_;
};



class cadastro_cpf {
public:
	cadastro_cpf() = default;
	cadastro_cpf(int cpf) : cpf_{cpf} {}
	
	int get_cpf(){ return cpf_;}
  void set_cpf(int cpf) {
	    cpf_ = cpf;
	}

private:

int cpf_;
};

class cadastro_rg {
public:
	cadastro_rg() = default;
	cadastro_rg(int rg) : rg_{rg} {}
	
		int get_rg(){return rg_;}
  	void set_rg(int rg) {
	    rg_ = rg;
	}

private:
	int rg_;
};

class pessoa : public data , public cadastro_rg , public cadastro_cpf{
public:
  pessoa() = default;
	pessoa(string nome, data data_nascimento)
	: nome_{nome}, data_nascimento_{data_nascimento} {}
	void mostre_info(){
		cout << nome_ << " nasceu em ";
		mostre_data();
	}
	
	string get_nome(){return nome_;}
  void set_nome(string nome) {
	    nome_ = nome;
	}
	    string get_nome_mae(){return nome_mae_;}
  void set_nome_mae(string nome_mae) {
	    nome_mae_ = nome_mae;
	}

private:
	string nome_;
	data data_nascimento_;
	string nome_mae_;
};

class funcionarios : public pessoa {
public:
  funcionarios() : pessoa{} {}
	
  int get_salario(){return salario_;}
  void set_salario(int salario) {
	    salario_ = salario;
	  }

	int get_data_contrato(){return data_contrato_;}
	void set_data_contrato(int dia, int mes, int ano) {
	    data contrato{dia, mes, ano};
			
	}
	  
private:
  int data_contrato_;
	int salario_;
	
};

class cadastro {
public:
  cadastro(int n) : n_{n} {
    f_ = new funcionarios [n_];
    if (not(f_))
    exit(EXIT_FAILURE);
    }
    ~cadastro(){
    	delete[] f_;
    	f_= nullptr;
    }
    
    void ler_funcionario(int n){
      for(int i{0} ; i < n ; i++){
        int n, dia, mes, ano, data, cpf, rg;
        string nome, nome_mae;
        
        cout << "Nome do funcionario: ";
        cin >> nome;
        f_[i].set_nome(nome);

        cout << "CPF:";
        cin >> cpf;
        f_[i].set_cpf (cpf); 

        cout << "RG:";
        cin >> rg;
        f_[i].set_rg(rg);
        
        cout << "Data de nascimento :";
        cin >> dia;
        cin >> mes;
        cin >> ano;
        f_[i].set_data(dia, mes, ano);
        
        
        cout << "Nome da mãe :";
        cin >> nome_mae;
        f_[i].set_nome_mae(nome_mae);
        
        cout << "Salario R$ :";
          cin >> n;
          f_[i].set_salario(n);
          
        cout << "Data de contratação :";
        cin >> dia;
        cin >> mes;
        cin >> ano;
        f_[i].set_data_contrato(dia, mes, ano);

      }	
      		cout << "Funcionarios Cadastrados!!"; 
    }
      void imprimir_funcionario(int n){
        for (int i{0}; i < n ; i++){
          cout << f_[i].get_nome() << endl;

          cout << "CPF :" <<  f_[i].get_cpf() << endl;

          cout << "RG :" << f_[i].get_rg() << endl;

          cout << "Salario :" << f_[i].get_salario() << endl;

          f_[i].mostre_info();

          cout << "Nome da mae :" << f_[i].get_nome_mae() << endl;

          cout << f_[i].get_nome() << " começou a trabalhar em ";
					f_[i].mostre_data();
        }
      } 
    	
    	int soma_salarios(int n){
    		int soma = 0;
    		for(int i {0} ; i < n ; i++){
    			soma = soma + f_[i].get_salario();
    		}
    		return soma;
    	}

    	int busca_cpf(int n){
    		int busca;
    		cout << "informe o cpf a ser buscado :";
    		cin >> busca;
    		for (int i{0}; i < 1 ; i++){
    				if( busca == f_[i].get_cpf())
    					cout << f_[i].get_nome() << endl;

          	cout << "CPF :" <<  f_[i].get_cpf() << endl;

          	cout << "RG :" << f_[i].get_rg() << endl;

          	cout << "Salario :" << f_[i].get_salario() << endl;

          	f_[i].mostre_info();

          	cout << "Nome da mae :" << f_[i].get_nome_mae() << endl;

          	cout << f_[i].get_nome() << " começou a trabalhar em ";
						f_[i].mostre_data();
						return 0;
    		}
    		cout << "Cpf não encontrado !\n";
    	}
    
   
private:
 funcionarios* f_;
 int n_;
};   
 
// Problema na impressão do menu
int menu(int n, cadastro& objeto){
	int num;
	
	cout << " 1- Imprimir informações de um funcionario com base no seu cpf.\n";
	cout << " 2- Imprimir informações completas de todos os funcionarios.\n";
	cout << " 3- computar e imprimir a soma dos salarios de todos os funcionarios.\n";
	cin >> num;

	switch(num) {
		
		case 1:
			objeto.busca_cpf(n);
			break;
		case 2:
			objeto.imprimir_funcionario(n);
			break;
		case 3:
			cout << "soma dos salarios de todos os funcionarios : " <<  objeto.soma_salarios(n) << endl;
			break;
		default:
			return 0;	
			break;
	}

}    


int main () 
{
	int n;

  cout << " Informe o numero de funcionarios da empresa : ";
  cin >> n;

  cadastro objeto{n};
  
  objeto.ler_funcionario(n);
  
  menu(n, objeto);
}