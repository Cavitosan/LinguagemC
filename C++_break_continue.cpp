/******************************************************************************

Procedência de operadores: Da esquerda para direita - Caso de (), será resolvido primeiro o mais aninhado

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    while (true){
        n++;
        
        if (n >= 10) {
            break; //Encerra o ciclo
        }else {
            if (n == 4 || n ==6) {
                continue; //Encerra um unico ciclo
            }
        }
        cout << n << endl;
    }
    
    
    int i = 0;
    cout << "Informe um número: "<< endl;
    cin >> i;
    
    while (i < 100){
        i ++;
        
        if (i == 20){
            break;
            
        }else if (i > 10 and i < 15){
            continue;
        }
    
        cout << i << endl; // O resultado desejado do ciclo deve estar após as condições
    }
    



    return 0;
}
