_____________________________

	Cergaro Stack 
_____________________________

README.txt
v1

Obrigado por baixar Cergaro Stack.

Este arquivo contém informações sobre o programa, sua utilização, como rodá-lo ou compilá-lo.
________________________

CONTEÚDO:
________________________
 
1) SOBRE

2) UTILIZAÇÃO

3) LISTA DE INSTRUÇÕES

4) EXECUTANDO O SCRIPT DE MANEIRA ALTERNATIVA
___________________________________________

1) SOBRE
_____________________

Cergaro Stack é um simulador open source de arquitetura de pilha. O script
pode ser rodado em ambos os Sistemas Operacionais Windows e Linux.

Para utilizar o programa o usuário dispõe de uma série de instruções -que 
se encontram listadas e explicadas em uma seção posterior do documento-,
de uma memória de 256 endereços de 32 bits cada e uma pilha com espaço 
para 16 valores de ponto flutuante de precisão simples.

Para executar o programa, basta clicar no arquivo "main.exe", o programa 
funciona no formato de terminal, onde deverão ser digitadas as instruções
e também onde aparecerão os resultados e mensagens.

Caso o arquivo main.exe não funcione ou opte-se por não utilizá-lo, o usuário
pode abrir o código fonte "main.cpp" em uma IDE de sua preferência
(recomenda-se o uso do Visual Studio Code, cujas orientações estarão disponíveis
na seção 4) e executar o código nela.

_____________________

2) UTILIZAÇÃO
______________________

Não há sensibilidade de caso, ou seja, as instruções podem ser escritas em caixa baixa,
caixa alta ou de forma mista, não havendo interferência na execução do programa.
	
Para as instruções que recebem um operando (pushi, push e pop), faz-se necessário a 
separação por espaço em branco (' ') entre a operação
e o seu respectivo operando, caso contrário haverá erro na execução do programa. Também
é necessário ressaltar que a ordem de digitação é sempre 
Operação -> Operando (quando houver), caso haja inversão na ordem acarretará em erro.

Após a instrução de encerramento (Hlt), será exibido ao usuário quais endereços foram
modificados por ele e quais foram os últimos valores armazenados nos respectivos endereços.

______________________

3)LISTA DE INSTRUÇÕES


    Instrução					Descrição
__________________________________________________________


Pushi valor		Insere no topo da pilha o valor imediato fornecido como operando da instrução. 
			Caso a pilha esteja cheia, uma mensagem indicando o problema (stack overflow) será entregue ao usuário.



Push endereço		Insere na pilha uma cópia do valor contido na memória no endereço fornecido como operando da instrução,
			é necessário utilizar a notação hexadecimal para a escrita do endereço.
			Caso a pilha esteja cheia, uma mensagem indicando o problema (stack overflow) será entregue ao usuário.	



Pop endereço		Retira um valor do topo da pilha e copia-o para a memória no endereço fornecido como operando da instrução,
			é necessário utilizar
			a notação hexadecimal para a escrita do endereço.
			Caso a pilha esteja vazia, uma mensagem indicando o problema (stack underflow) será entregue ao usuário.



Size			Exibe o tamanho atual da pilha do programa para o usuário, permitindo que ele tenha controle das operações
			que precisa e deseja executar.


Input			Usuário insere a palavra "input", aperta a tecla ENTER e, logo a seguir, insere o valor que deseja adicionar
			no topo da pilha. 


Print			Retira um valor do topo da pilha e exibe-o no dispositivo de saída padrão do usuário.
			Caso a pilha não possua valores suficientes para a operação, uma mensagem indicando o problema (stack underflow)
			será entregue ao usuário.


Add			Retira dois valores do topo da pilha (A e B na ordem de retirada) e calcula B+A, inserindo o resultado no topo 
			da pilha.Caso a pilha não possua valores suficientes para a operação, uma mensagem indicando o problema
			(stack underflow) será entregue ao usuário.
	

Sub			Retira dois valores do topo da pilha (A e B na ordem de retirada) e calcula B-A, inserindo o resultado no topo
			da pilha. Caso a pilha não possua valores suficientes para a operação, uma mensagem indicando o problema
			(stack underflow) será entregue ao usuário.


Mul			Retira dois valores do topo da pilha (A e B na ordem de retirada) e calcula B*A, inserindo o resultado no topo
			da pilha. Caso a pilha não possua valores suficientes para a operação, uma mensagem indicando o problema 
			(stack underflow) será entregue ao usuário.


Div			Retira dois valores do topo da pilha (A e B na ordem de retirada) e calcula B/A, inserindo o resultado no topo
			da pilha. Caso o segundo valor retirado da pilha (B) seja igual a zero, uma mensagem indicando o problema 
			(divisão por zero) será entregue ao usuário.
			Caso a pilha não possua valores suficientes para a operação, uma mensagem indicando o problema (stack underflow)
			será entregue ao usuário.



Swap			Inverte a ordem dos dois valores no topo da pilha.
			Caso a pilha não possua valores suficientes para a operação, uma mensagem indicando o problema (stack underflow)
			será entregue ao usuário.


Drop			Descarta o valor no topo da pilha.
			Caso a pilha não possua valores suficientes para a operação, uma mensagem indicando o problema (stack underflow)
			será entregue ao usuário.


Dup			Insere uma cópia do valor atual que está no topo da pilha.
			Caso a pilha esteja cheia, uma mensagem indicando o problema (stack overflow) será entregue ao usuário.	
			Caso a pilha não possua valores suficientes para a operação, uma mensagem indicando o problema (stack underflow)
			será entregue ao usuário.


Hlt			Encerra a execução do programa.
______________________

4) EXECUTANDO O SCRIPT DE MANEIRA ALTERNATIVA
______________________

Nesta seção explicar-se-á como executar o código fonte (que é aberto ao usuário) caso o arquivo main.exe enfrente 
problemas de utilização ou apenas seja desejo do usuário utilizar o programa desta maneira.
Como supramencionado na seção anterior, recomenda-se o uso da IDE Visual Studio Code, pois o exemplo fornecido (que pode ser
aproveitado tanto para linux quanto para windows) envolve seu uso.

Primeiro, o usuário precisa ter instalado a extensão "code runner" em sua máquina, o que facilitará todo o processo. 
Isto pode ser feito ao clicar no ícone com formato semelhante a caixas, na barra à esquerda e digitar "code runner"
na busca e instalá-lo. É necessário fechar e abrir novamente a IDE para que a extensão seja integrada.
Clicando em "file" ou "arquivo" em português, então clica-se em "open file" ou "abrir arquivo" e seleciona-se o código fonte
do programa, "main.cpp". 

Então, a extensão code runner adicionará um ícone em forma de triângulo no canto superior direito, ao clicar neste ícone,
seleciona-se a opção "debug c/c++ file".
Isto abrirá um terminal na parte inferior da IDE, deve-se esperar que o programa seja compilado pela máquina.
Uma vez feita a compilação, clica-se novamente no ícone triangular porém, desta vez, na opção "run code".
Agora o programa estará sendo executado no terminal do VS Code e poderá ser utilizado pelo usuário.
_______________________