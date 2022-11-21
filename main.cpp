#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <typeinfo>
#include "cerbaroFunctions.cpp"

// definicao de memoria e pilha
float memory[256];

struct pilha
{
  float elementos[16];
  int top = -1;
};

// funcao para obter tamanho da pilha
int stackSize(pilha &stk)
{ 
  return (stk.top) + 1;
}

// funcao para verificar se a pilha esta vazia
bool vazio(const pilha &stk)
{ 
  return stk.top == -1;
}

/*
Recebe uma estutura pilha por parâmetro.
Se vazio, retorna 0, senão, retorna o ultimo elemento inserido na lista.
*/
float elementoDoTopo(const pilha &stk)
{
  if (vazio(stk))
  {
    return 0;
  }
  else
  {
    return stk.elementos[stk.top];
  }
}

// funcao para verificar se a pilha esta cheia
bool cheio(const pilha &stk)
{ 
  return stk.top == 15;
}

// Confere se o tipo do valor passado por parâmetro é o requisitado.
template <typename T>
bool checaTipoFloat(T) {
  return typeid(T) == typeid(float);
}

// insere no topo da pilha
void stackPush(pilha &stk, float value, bool full = false)
{ 
  if (full)
  {
    std::cout << "Stack overflow\n!" << std::endl;
  }
  else if (!checaTipoFloat(value)) {
    std::cout << "O valor inserido nao e um numero decimal.\n" << std::endl;   
  } else {
    stk.elementos[++stk.top] = value;
  }
}

// retira do topo
void stackPop(pilha &stk, bool empty = false)
{ 
  if (empty)
  {
    std::cout << "Stack underflow!\n" << std::endl;
  }
  else
  {
    (stk.top)--;
  }
}

 // verifica a possibilidade de efetuar operacoes aritmeticas
bool mayOP(pilha &stk)
{
  return stackSize(stk) >= 2;
}

// executa operacoes aritmeticas 
void mathOP(pilha &stk, char OpAritmetica)
{ 
  float ultimoInserido, penultimoInserido, resultadoOp;
  switch (OpAritmetica)
  {
  case '+':
    if (mayOP(stk))
    {
      ultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      penultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      resultadoOp = penultimoInserido + ultimoInserido;
      stackPush(stk, resultadoOp);
      std::cout << penultimoInserido << " + " << ultimoInserido << " = " << elementoDoTopo(stk) << std::endl;
    }
    else
    {
      std::cout << "Nao foi possivel realizar a operacao.\nNao ha, pelo menos, dois elementos para realizar a equacao.\n" << std::endl;
    }
    break;
  case '-':
    if (mayOP(stk))
    {
      ultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      penultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      resultadoOp = penultimoInserido - ultimoInserido;
      stackPush(stk, resultadoOp);
      std::cout << penultimoInserido << " - " << ultimoInserido << " = " << elementoDoTopo(stk) << std::endl;
    }
    else
    {
      std::cout << "Nao foi possivel realizar a operacao.\nNao ha, pelo menos, dois elementos para realizar a equacao.\n" << std::endl;
    }
    break;
  case '*':
    if (mayOP(stk))
    {
      ultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      penultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      resultadoOp = penultimoInserido * ultimoInserido;
      stackPush(stk, resultadoOp);
      std::cout << penultimoInserido << " * " << ultimoInserido << " = " << elementoDoTopo(stk) << std::endl;
    }
    else
    {
      std::cout << "Nao foi possivel realizar a operacao.\nNao ha, pelo menos, dois elementos para realizar a equacao.\n" << std::endl;
    }
    break;
  case '/':
    if (elementoDoTopo(stk) == 0)
    {
      std::cout << "Nao foi possivel realizar a operacao\nO divisor vale zero.\n" << std::endl;
      break;
    }
    else if (!mayOP(stk))
    {
      std::cout << "Nao foi possivel realizar a operacao.\nNao ha, pelo menos, dois elementos para realizar a equacao.\n" << std::endl;
    }
    else
    {
      ultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      penultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      resultadoOp = penultimoInserido / ultimoInserido;
      stackPush(stk, resultadoOp);
      std::cout << penultimoInserido << " / " << ultimoInserido << " = " << elementoDoTopo(stk) << std::endl;
    }
    break;
  case 's':
    if (mayOP(stk))
    {
      ultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      penultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
      stackPush(stk, ultimoInserido);
      stackPush(stk, penultimoInserido);
    }
    else
    {
      std::cout << "Nao foi possivel realizar a operacao.\nNao ha, pelo menos, dois elementos para realizar a equacao.\n" << std::endl;
    }
    break;
  case 'd':
    if (!vazio(stk))
    {
      ultimoInserido = elementoDoTopo(stk);
      stackPop(stk);
    }
    else
    {
      std::cout << "Nao foi possivel realizar a operacao.\nNao ha, pelo menos, um elemento para remove-lo.\n" << std::endl;
    }
  case 'c':
    if (!vazio)
    {
      ultimoInserido = elementoDoTopo(stk);
      stackPush(stk, ultimoInserido);
    }
    else
    {
      std::cout << "Nao foi possivel realizar a operacao.\nNao ha, pelo menos, um elemento para duplica-lo.\n" << std::endl;
    }
    break;
  default:
    std::cout << "O programa nao abrange essa operacao aritmetica: " << OpAritmetica << "\n" << std::endl;
    break;
  }
}

//troca o ultimo e penultimo elementos da pilha de lugar entre si
void stackSwap(pilha &stk, bool x)
{ 
  if (x)
  {
    std::cout << "Stack underflow\n" << std::endl;
  }
  else
  {
    float a, b;
    a = stk.elementos[stk.top];
    stackPop(stk);
    b = stk.elementos[stk.top];
    stackPop(stk);

    stackPush(stk, a);
    stackPush(stk, b);
  }
}

int main()
{
  pilha programStack;
  int address;
  std::string userInput;                  // input do usuario
  std::string instructions[2] = {"", ""}; // guardara as instrucoes e valores
  std::map<std::string, int> history; //armazena quais enderecos foram modificados pelo usuario

  while (instructions[0] != "hlt") 
  {
    getline(std::cin, userInput);

    for (int i = 0; i < 2; i++)
    {
      instructions[i] = SplitString(userInput, ' ');
    }

    if (instructions[0] == "pushi")
    {
      stackPush(programStack, stof(instructions[1]), cheio(programStack));
    }

    else if (instructions[0] == "push")
    {            
      address = hexConvert(instructions[1]);
      memory[address] = programStack.elementos[programStack.top];
      history[instructions[1]] = address;
      stackPush(programStack, memory[address], cheio(programStack));
    }

    else if (instructions[0] == "pop")
    {
      if (vazio(programStack))
      {
        std::cout << "Stack underflow\n" << std::endl;
      }
      else
      {        
        address = hexConvert(instructions[1]);
        memory[address] = programStack.elementos[programStack.top];
        history[instructions[1]] = address;
        stackPop(programStack);
      }
    }

    else if (instructions[0] == "print")
    {
      std::cout << elementoDoTopo(programStack) << std::endl;
      stackPop(programStack);
    }

    else if(instructions[0] == "input")
    {
      std::cout<<"Digite o numero que deseja inserir no topo da pilha: \n" << std::endl;
      getline(std::cin, userInput);
      stackPush(programStack, stof(userInput), cheio(programStack));
    }

    else if(instructions[0] == "size")
    {
      std::cout << stackSize(programStack) << std::endl;
    }

    else if (instructions[0] == "top") {
      elementoDoTopo(programStack);
    }

    else if (instructions[0] == "add")
    {
      mathOP(programStack, '+');
    }

    else if (instructions[0] == "sub")
    {
      mathOP(programStack, '-');
    }

    else if (instructions[0] == "mul")
    {
      mathOP(programStack, '*');
    }

    else if (instructions[0] == "div")
    {
      mathOP(programStack, '/');
    }

    else if (instructions[0] == "swap")
    {
      stackSwap(programStack, vazio(programStack));
    }

    else if (instructions[0] == "drop")
    {
      stackPop(programStack);
    }

    else if (instructions[0] == "dup")
    {
      stackPush(programStack, elementoDoTopo(programStack), cheio(programStack));
    } else {
      std::cout << "A operacao " + instructions[0] + " nao foi encontrada.\nCertifique-se que o comando foi digitado corretamente ou escreva \"help\" para visualizar as instrucoes disponiveis.\n" << std::endl;;
    }
    // fim das verificacoes de instrucao
  } // fim do while loop

  // Ao digitar hlt:
  std::cout << "Numero de enderecos manipulados: " << history.size() << std::endl;
  std::cout << "Enderecos manipulados e seus respectivos valores: " << std::endl;

  for (auto &&item : history)
  { // itera em history
    std::cout << item.first << ": " << memory[item.second] << '\n';
  } //exibe primeiro o endereco (em hexadecimal) e, em seguida, o valor float que está armazenado na memoria

  return 0;
}