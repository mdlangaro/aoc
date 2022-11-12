#include<iostream>
#include<set>
#include<string>

float memory[256];
float pilha[16];

std::string SplitString(std::string &a[]){ //inicia SplitString, recebe a string userInput como parâmetro e separa por espaco
  int stringSize = a.size(), half = 0;
  bool space= false;
  std::string newString;

    for(int i=0; i<stringSize; i++){

      if(a[i] == ' '){
        space=true;
      }
      else if(space==false){
        newString += a[i];
        half++;
      }
    }

    a.erase(0 , half);

    return newString;
} //finaliza SplitString

void stackCheck(float v, float &stack[]){//inicia stackCheck, verifica se resta espaco no stack ou nao, em caso positivo, adiciona no topo
  if(stack.size()<16){
    stack.push_back(v);
  }else{
    std::cout<<"Stack overflow\n";
  }
}//finaliza stackCheck


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
	
	for (int i = s.length() - 1; i >= 0; i--)//iteracao na string parametro
	{
		result += convertHexDigit_toDecimal(s[i]) * multiplier; //converte cada digito para decimal, como explicado na funcao precedente
		multiplier *= 16;
	}
	return result;
}//finaliza hexConvert

int main(){
    std::string userInput, instructions[2];
    std::set<int> history;

    getline(std::cin, userInput);

    for(int i=0; i<2;i++){//cada index do array instructions recebera uma string como valor
      instructions[i] = SplitString(userInput);
    }

    while(instructions[0]!= "hlt"){


      if(instructions[0]== "pushi"){
        float value = stof(instructions[1]);
        stackCheck(value, pilha);
      }
      else if(instructions[0]=="push" || instructions[0]=="pop"){
        int address = hexConvert(instructions[1]);//variavel int que recebe o endereco na memoria que o usuario deseja manipular, ja vem converso a partir de string em hexadecimal
        
        if(instructions[0]=="push"){
        stackCheck(memory[address], pilha);
        history.insert(address);
        }
        else if(instructions[0]== "pop"){
        memory[address]= pilha.top();//necessario escrever funcao top()
        }
      }

      getline(std::cin, userInput); //continua o programa
      for(int i=0; i<2;i++){
      instructions[i] = SplitString(userInput);
    }

    }

    //Quando um endereco na memoria for manipulado
    //history.insert(endereco);
    

    return 0;
}