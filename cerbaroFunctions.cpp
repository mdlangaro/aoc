#include<iostream>
#include<string>
#include<ctype.h>

std::string SplitString(std::string &a, char b){ //a string que se quer separar, seguido  do caracter que determina a separacao, seja espaco ' ', virgula ',', etc
    
	std::string newString; //nova string contendo a palavra separada que sera retornada
    int stringSize = a.size(), index=0; // variavel index recebera o indice do char b
    bool separate= false; //mantem-se falso enquanto nao encontrar o char b

    while(true){
        for(int i=0; i<stringSize; i++){

            if(a[i]== b){ //caso encontre-se o char b
                separate = true; //muda o valor para verdadeiro, indicando que o character foi encontrado
                index=i; //index recebe o indice onde o char b foi encontrado na string
                break; 
            }

			else if(separate == false){ //enquanto nao for encontrado o char b
                newString += (char)tolower(a[i]); //concatena na nova string todos os chars da string original, convertendo-os para lowercase
            }
        }

    a.erase(0,index+1); //apaga tudo que houver entre os indices zero e o valor da variavel index+1, serve para eliminar a palavra separada da string original
    return newString; //retorna a nova string, contendo apenas uma palavra
    }
  }//finaliza SplitString



int convertHexDigit_toDecimal(char c){ //converte o valor de um digito (char) de hexadecimal para decimal 
	if (c >= '0' && c <= '9') 
	{
		return int(c) - 48;
	}
	else if (c >= 'A' && c <= 'F') 
	{
		return int(c) - 55;
	}
	else if (c >= 'a' && c <= 'f')
	{
		return int(c) - 87;
	}
	else
	{
		return -1; 
	}
}//finaliza

int hexConvert(std::string s){//Converte um numero de hexadecimal para decimal 
	int result = 0;
	int multiplier = 1;
	
	for (int i = s.length() - 1; i >= 0; i--)//iteracao na string passada por parametro
	{
		result += convertHexDigit_toDecimal(s[i]) * multiplier; //converte cada char da string para decimal e soma na variavel
		multiplier *= 16; //mantem a base 16 para cada nova operacao
	}
	return result;
}//finaliza hexConvert
