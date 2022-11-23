#include <iostream>
#include <string>
#include "banco.hpp"

using namespace std;

int main(){
    Usuario ralph = Usuario();
    ralph.nome="ralph";
    ralph.setNumeroDaConta("32482-5");

    Usuario carol = Usuario("carol", "12345-2",100 );

    cout<< carol.nome<< ": "<< carol.getSaldo()<< endl;
    cout<< ralph.nome<< ": "<< ralph.getSaldo()<< endl<< endl;
    
    if(carol.saque(40)){
        ralph.deposito(40);
    }
    cout<< carol.nome<< ": "<< carol.getSaldo()<< endl;
    cout<< ralph.nome<< ": "<< ralph.getSaldo()<< endl<< endl;
    
    return 0;
}