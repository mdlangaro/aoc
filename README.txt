_____________________________

	Cergaro Stack 
_____________________________

README.txt
v1

Obrigado por baixar Cergaro Stack.

Este arquivo cont�m informa��es sobre o programa, sua utiliza��o, como rod�-lo ou compil�-lo.
________________________

CONTE�DO:
________________________
 
1) SOBRE

2) UTILIZA��O

3) LISTA DE INSTRU��ES

4) EXECUTANDO O SCRIPT DE MANEIRA ALTERNATIVA
___________________________________________

1) SOBRE
_____________________

Cergaro Stack � um simulador open source de arquitetura de pilha. O script
pode ser rodado em ambos os Sistemas Operacionais Windows e Linux.

Para utilizar o programa o usu�rio disp�e de uma s�rie de instru��es -que 
se encontram listadas e explicadas em uma se��o posterior do documento-,
de uma mem�ria de 256 endere�os de 32 bits cada e uma pilha com espa�o 
para 16 valores de ponto flutuante de precis�o simples.

Para executar o programa, basta clicar no arquivo "main.exe", o programa 
funciona no formato de terminal, onde dever�o ser digitadas as instru��es
e tamb�m onde aparecer�o os resultados e mensagens.

Caso o arquivo main.exe n�o funcione ou opte-se por n�o utiliz�-lo, o usu�rio
pode abrir o c�digo fonte "main.cpp" em uma IDE de sua prefer�ncia
(recomenda-se o uso do Visual Studio Code, cujas orienta��es estar�o dispon�veis
na se��o 4) e executar o c�digo nela.

_____________________

2) UTILIZA��O
______________________

N�o h� sensibilidade de caso, ou seja, as instru��es podem ser escritas em caixa baixa,
caixa alta ou de forma mista, n�o havendo interfer�ncia na execu��o do programa.
	
Para as instru��es que recebem um operando (pushi, push e pop), faz-se necess�rio a 
separa��o por espa�o em branco (' ') entre a opera��o
e o seu respectivo operando, caso contr�rio haver� erro na execu��o do programa. Tamb�m
� necess�rio ressaltar que a ordem de digita��o � sempre 
Opera��o -> Operando (quando houver), caso haja invers�o na ordem acarretar� em erro.

Ap�s a instru��o de encerramento (Hlt), ser� exibido ao usu�rio quais endere�os foram
modificados por ele e quais foram os �ltimos valores armazenados nos respectivos endere�os.

______________________

3)LISTA DE INSTRU��ES


    Instru��o					Descri��o
__________________________________________________________


Pushi valor		Insere no topo da pilha o valor imediato fornecido como operando da instru��o. 
			Caso a pilha esteja cheia, uma mensagem indicando o problema (stack overflow) ser� entregue ao usu�rio.



Push endere�o		Insere na pilha uma c�pia do valor contido na mem�ria no endere�o fornecido como operando da instru��o,
			� necess�rio utilizar a nota��o hexadecimal para a escrita do endere�o.
			Caso a pilha esteja cheia, uma mensagem indicando o problema (stack overflow) ser� entregue ao usu�rio.	



Pop endere�o		Retira um valor do topo da pilha e copia-o para a mem�ria no endere�o fornecido como operando da instru��o,
			� necess�rio utilizar
			a nota��o hexadecimal para a escrita do endere�o.
			Caso a pilha esteja vazia, uma mensagem indicando o problema (stack underflow) ser� entregue ao usu�rio.



Size			Exibe o tamanho atual da pilha do programa para o usu�rio, permitindo que ele tenha controle das opera��es
			que precisa e deseja executar.


Top			Exibe o valor armazenado no topo da pilha sem removê-lo.


Input			Usu�rio insere a palavra "input", aperta a tecla ENTER e, logo a seguir, insere o valor que deseja adicionar
			no topo da pilha. 


Print			Retira um valor do topo da pilha e exibe-o no dispositivo de sa�da padr�o do usu�rio.
			Caso a pilha n�o possua valores suficientes para a opera��o, uma mensagem indicando o problema (stack underflow)
			ser� entregue ao usu�rio.


Add			Retira dois valores do topo da pilha (A e B na ordem de retirada) e calcula B+A, inserindo o resultado no topo 
			da pilha.Caso a pilha n�o possua valores suficientes para a opera��o, uma mensagem indicando o problema
			(stack underflow) ser� entregue ao usu�rio.
	

Sub			Retira dois valores do topo da pilha (A e B na ordem de retirada) e calcula B-A, inserindo o resultado no topo
			da pilha. Caso a pilha n�o possua valores suficientes para a opera��o, uma mensagem indicando o problema
			(stack underflow) ser� entregue ao usu�rio.


Mul			Retira dois valores do topo da pilha (A e B na ordem de retirada) e calcula B*A, inserindo o resultado no topo
			da pilha. Caso a pilha n�o possua valores suficientes para a opera��o, uma mensagem indicando o problema 
			(stack underflow) ser� entregue ao usu�rio.


Div			Retira dois valores do topo da pilha (A e B na ordem de retirada) e calcula B/A, inserindo o resultado no topo
			da pilha. Caso o segundo valor retirado da pilha (B) seja igual a zero, uma mensagem indicando o problema 
			(divis�o por zero) ser� entregue ao usu�rio.
			Caso a pilha n�o possua valores suficientes para a opera��o, uma mensagem indicando o problema (stack underflow)
			ser� entregue ao usu�rio.



Swap			Inverte a ordem dos dois valores no topo da pilha.
			Caso a pilha n�o possua valores suficientes para a opera��o, uma mensagem indicando o problema (stack underflow)
			ser� entregue ao usu�rio.


Drop			Descarta o valor no topo da pilha.
			Caso a pilha n�o possua valores suficientes para a opera��o, uma mensagem indicando o problema (stack underflow)
			ser� entregue ao usu�rio.


Dup			Insere uma c�pia do valor atual que est� no topo da pilha.
			Caso a pilha esteja cheia, uma mensagem indicando o problema (stack overflow) ser� entregue ao usu�rio.	
			Caso a pilha n�o possua valores suficientes para a opera��o, uma mensagem indicando o problema (stack underflow)
			ser� entregue ao usu�rio.


Hlt			Encerra a execu��o do programa.
______________________

4) COMO COMPILAR
______________________

Para compilar é necessário estar em uso do sistema operacional Linux e possuir o compilador g++. 
Por meio do terminal, navegue até a pasta onde ambos os arquivos, main.cpp e cerbaroFunctions.cpp, estão localizados.
Digite o seguinte comando: g++ main.cpp -o NomeDoSeuArquivo
Onde NomeDoSeuArquivo pode ser de sua escolha.
Para executar o programa, na mesma navegação, digite o comando: ./NomeDoSeuArquivo, como antes, substituindo o NomeDoSeuArquivo pelo nome escolhido.
