

		Shell sort:

Método de ordenação feito por Donald Shell (origem do nome).
	- Em 1959, enquanto na da universidade de Cincinnati.

Shell iniciou sua ideia com base no Bubble Sort, mas desde
sua concepção aquela foi construída por cima do Insertion Sort.


//



A maior problemática vista por Shell era que, naquela época,
os computadores comportavam pouca memória (tanto primária 
quanto secundária) e os algoritmos vigentes, em suma certifi-
cados pelas teses de Harold Seward, consumiam memória exces-
siva para grandes montantes de dados. Além do "Call Stack"
causado pelos métodos 'empilhadeiros' como o Merge Sort vigen-
te (Merging Pairs).



//



A base era utilizar algumas propriedades dos métodos 'Merging'
com os métodos de 'Sifting' (Scattering = Espalhar e analisar
minunciosamente).

Um grande aprimoramento pensado por Shell foi trazer a efi-
ciência de algoritmos como o Merge Sort que eram de ordem
O( n.ln(n) ) (a base do log na época era o número de Euller)
para a 'leveza' dos algoritmos de ordem linear (quebrando
seu empecílho quanto à ordem O( n^2 ).

(Ver Shell_flowchart.png)


//


	Falando um pouco sobre a base: Insertion Sort.

É um algoritmo eficiente para curtas sequências e para sequên-
cias em que as chaves estejam próximas, onde não precisem ser
movimentadas a distâncias grandes. Este sendo falso, entretan-
to, gera demasiada ineficiência, comparada a do Bubble Sort.

(Ver animação do Insertion Sort)


//

	A abstração de Shell.

Para corrigir/improver esse impasse, Shell enxergou a pos-
sibilidade de diminuir os passos entre as grandes distâncias
de ordenação. Ao invés de fazer a ordenação casa a casa (modelo
bolha - Bubble Sort), 'cortou' o espaço que separa os 'longes'
para o 'perto', internamente à sequência.

As comparações e ordenações agora são feitas com 'bolhas tele-
páticas'. Esse corte imaginado por Shell é feito utilizando um
espaçador chamado 'Gap' (que será visto mais adiante).


(Ver bolhas_telepaticas.png) -> Vale observar que as 'bolhas'
são binárias (pares em pares), porém cada comparação binária
resultante é um 'novo elemento', que será comparado com o pró-
ximo par da sequênca.


//


Agora que os 'cortes' - que tinham objetivo de 'aproximar' - 
foram feitos, toma-se a etapa do próprio Insertion Sort.

Dessa forma, a ineficiência a grandes distâncias - quadrática,
diga-se de passagem - é brutalmente reduzida.


//


É visível que, porém, apenas um único 'corte' irá ordenar úni-
ca e exclusivamente as 'bolhas telepáticas' entre si.

Para ordenar a sequência inteira, entretanto, Shell observou
que os 'Gaps' deveriam diminuir a tal ponto de serem equiva-
lentes a um Insertion Sort, ou seja, não existirem mais 'Gaps'.


(Ver shell-sort-demonstration.jpg) -> O decrescimento do 'Gap'
gera menos sequências com cada vez mais membros.

//


	Falando sobre 'Gaps'.

Shell definiu em seu artigo o seguinte gap:

	- floor( N / ( 2^k ) ) >= 1,
	- onde N = tamanho da sequência principal,
	- k é um inteiro qualquer maior ou igual a 1 -
	  que representa cada etapa de novo 'corte'
	- e o resultado progressivo tem seu fim quando
	  chega em 1 .

Essa última determinação vale, obrigatoriamente, pois
o 'Gap' de valor 1 é o mesmo que em uma sequência sem
'cortes' - em que, também, ambos são o mesmo que um
Insertion Sort puro.

Outros 'Gaps' foram definidos desde então, porém,
todos os que resultarem em 1 na etapa final, estarão
corretos.


//


Uma péssima ideia de escolha para 'Gaps' seria a
seguinte sequência:

	- 1 , 2 , 4 , 8 , 16 , 32 ...

Que é basicamente potência de 2.

Por isso, é premeditável um empecilho caso os maiores val-
ores estejam todos em posições ímpares (ou pares, bastando que
seja o oposto dos de menor valor) da sequência principal,
visto que, até o último 'Gap' par ( o 'Gap' = 2 ), os maiores
foram ordenados entre si, nas posições ímpares e os menores
nas posições pares. E, ao final da ordenação, o passo seguinte,
de 'Gap' = 1, irá ordenar todas as 'bolhas', não mais 'telepáticas',
uma a uma. Dessa forma, toda a eficiência pensada por Shell foi
por água a baixo.

É necessário que nunca se use essa sequência de 'Gaps', caso
contrário, Snell jogará a maldição do "Olá Mundo" em você.

Existem inúmeras outras sequências de 'Gaps', tanto teorizadas
cientificamente, quanto comprovadas experimentalmente, que sejam
muito eficientes.

As preferidas são as que geram uma quantidade considerável de
números primos e as em que o incremento decresça exponencialmente.

(Ver shell_gaps_tabela.png) -> *Observação: Não confundir o Sím-
bolo de piso ou de teto com [ ].


//


Agora que já vimos a definição da sequência de 'Gaps' e a definição
do Shell Sort p.d., vamos ao código:

void shell_sort( void ){
	int i, j, aux, gap, exp = 0;
	while( pow( 2, exp ) - 1 < N ) ++exp; /* Hibbard */
	gap = pow( 2, exp ) - 1;

	do{
		for( i = gap; i < N; ++i ){
			aux = elementos[i];
			for( j = i - gap; j >= 0 && aux < elementos[j]; j -= gap ){
				elementos[j+gap] = elementos[j];
			}
			elementos[j+gap] = aux;
		}
	}while( --exp > 0 && (gap = pow( 2, exp ) - 1) >= 1 );
}



// 


O código em si é essencialmente o Insertion Sort -
como previamente dito. Nestas linhas que se seguem,
o núcleo semântico e 99% da escrita do código são os mesmos:

	for( i = gap; i < N; ++i ){
		aux = elementos[i];
		for( j = i - gap; j >= 0 && aux < elementos[j]; j -= gap ){
			elementos[j+gap] = elementos[j];
		}
		elementos[j+gap] = aux;
	}

A única variação deste trecho - aquele 1% - se remete à utilização
do 'Gap' como forma de subsequênciamento da cadeia de chaves principal.


//


O que permite a manufatura desse código ser escrito essencialmente
com base no Insertion Sort, são estas seguintes linhas:


	while( pow( 2, exp ) - 1 < N ) ++exp; /* Hibbard */
	gap = pow( 2, exp ) - 1;

	do{
		
		/* 99% raíz do Insertion */

	}while( --exp > 0 && (gap = pow( 2, exp ) - 1) >= 1 );

Em que a linha 209 procura o limite superior do 'Gap' em relação
à quantidade de chaves na sequência principal e a linha 210
utiliza o 'Gap' imediatamente próximo a essa quantidade - segundo,
obviamente, a fórmulação de Hibbard, utilizada nessa situação.

O loop seguinte (o do{}while()), executa a raíz do Insertion em todas
as subsequências possíveis desse 'Gap' até que o 'corte'se torne inexis-
tente, ou seja, novamente, as 'bolhas telepáticas' não existam mais. No
fim das contas o último loop é puramente o Insertion sort, visto que,
o resultado de pow( 2, 1 ) - 1 é igual a 1.


//


Ademais, como foi fortemente defendido que o Shell Sort é baseadíssimo
no Insertion Sort, cabe uma prova disso. As seguintes linhas são o
código do Insertion Sort:

void insertion_sort( void ){
	int i, j, aux;
	for( i = 1 ; i < N ; ++i ){
		aux = elementos[i];
		for( j = i - 1 ; j >= 0 && aux < elementos[j] ; --j ){
			elementos[j+1] = elementos[j];
		}
		elementos[j+1] = aux;
	}
}


//


Agora, observem as diferenças entre o núcleo dos dois:

	/* Insertion Sort */
	for( i = 1 ; i < N ; ++i ){
		aux = elementos[i];
		for( j = i - 1 ; j >= 0 && aux < elementos[j] ; --j ){
			elementos[j+1] = elementos[j];
		}
		elementos[j+1] = aux;
	}

	/* Shell Sort */
	for( i = gap; i < N; ++i ){
		aux = elementos[i];
		for( j = i - gap; j >= 0 && aux < elementos[j]; j -= gap ){
			elementos[j+gap] = elementos[j];
		}
		elementos[j+gap] = aux;
	}

Atentem-se que o 'Gap', ao chegar ao seu último valor, 1, resulta idên-
ticamente ao próprio Insertion Sort.

Não estão convencidos? Vamos comparar vendo na prática.

(Ver animações do Shell & Insertion)



//



Aqui fica válida uma observação:

Apesar de todo esforço em convencer vocês de que no fim o Shell Sort
se torna o Insertion Sort, é totalmente plausível que esse núcleo
ordenador não seja necessariamente o Insertion Sort. Pode-se usar
o Bubble Sort, Quick Sort, Heap Sort ... Apenas deve-se manter a lógica
dos 'Gaps' para continuar a ser um Shell Sort.

Mas, vamos voltar ao nosso assunto principal.



//



Agora que vimos todo o funcionamento, definição e baseamento do Shell,
vamos analisá-lo para, posteriormente, o comparar performaticamente com
os outros algoritmos existentes - e, claro, comprovar.

Primeiramente, fora... Digo, para vocês, o que seria um algoritmo eficiente?!

Seria um algoritmo com baixo consumo de memória? Com poucos passos de
execução? Com poucas comparações? Com poucas trocas necessárias?
Com um código simples, curto e de fácil implementação? Seria um algoritmo
estável?! Com tempo de execução curto?

A resposta desse questionamento é simples: DEPENDE! :-)



//


Como até agora vimos, toda a luta de Shell foi tornar o Insertion Sort
mais eficiente. Porém, eficiente como?

Como explanado no começo da apresentação, a tentativa de Shell, foi de
aproximar as distantes chaves para facilitar a ordenação final do
Insertion Sort, com o objetivo primário de diminuir vários dos fatores
anteriormente teorizados, como:

	- Os passos de execução;
	- A quantidade de comparações;
	- Tempo gasto.



//



Para isso precisamos saber o seguinte: Como um algoritmo gasta esses fatores?

Não é algo simples de primeira vista, mas é intuitivo e de fácil absorção.

Vocês concordam que cada função, atribuição, declaração, definição, comparação,
operação e outros 'ãos' da programação, devem, obrigatoriamente, consumir quaisquer
umas das teorizações anteriores?!

Então vamos levar eles como nossa base de medição doravante.



//



Observemos o código do Bubble Sort:

void bubble_sort( void ){
	int i , j , aux;
	for( i = 0 ; i < N - 1 ; ++i ){
		for( j = N - 1 ; j >= i + 1 ; --j ){
			if( elementos[j] < elementos[j-1] ){
				aux = elementos[j];
				elementos[j] = elementos[j-1];
				elementos[j-1] = aux;
			}
		}
	}
}

Como dito, os 'ãos' consumem, então, vamos dar nomes aos bois!



//



void bubble_sort( void ){
	int i , j , aux; // c1 = int i, c2 = int j, c3 = int aux;
	for( i = 0 ; i < N - 1 ; ++i ){ // c4 = i = 0, c5 = (i<N-1), c6 = ++i;
		for( j = N - 1 ; j >= i + 1 ; --j ){ // c7 = j = N-1, c8 = j >= i+1, c9 = --j;
			if( elementos[j] < elementos[j-1] ){ // c10 = elem.[j] < elem.[j-1];
				aux = elementos[j];	// c11 = aux = elem.[j];
				elementos[j] = elementos[j-1]; // c12 = elem.[j] = elem.[j-1];
				elementos[j-1] = aux; // c13 = elem.[j-1] = aux;
			}
		}
	}
}

Notemos que cada constante 'c*' deve ser entendida como comando-n.
Esse comando representa uma instrução para o processador, vista do
médio nível - por conta do código estar escrito em C (posteriormente,
veremos de forma superficial o mesmo código em baixo nível).

Cada um desses comandos é excecutado uma ou mais vezes, dependendo da
lógica por trás do algoritmo e de da quantidade de chaves a ser ordenada.
A isso chamamos de Complexidade de um algoritmo - usualmente representada
por O( ? ).



//



void bubble_sort( void ){
	int i , j , aux; // c1 = int i, c2 = int j, c3 = int aux;
	for( i = 0 ; i < N - 1 ; ++i ){ // c4 = i = 0, c5 = (i<N-1), c6 = ++i;
		for( j = N - 1 ; j >= i + 1 ; --j ){ // c7 = j = N-1, c8 = j >= i+1, c9 = --j;
			if( elementos[j] < elementos[j-1] ){ // c10 = elem.[j] < elem.[j-1];
				aux = elementos[j];	// c11 = aux = elem.[j];
				elementos[j] = elementos[j-1]; // c12 = elem.[j] = elem.[j-1];
				elementos[j-1] = aux; // c13 = elem.[j-1] = aux;
			}
		}
	}
}

Cada um desses comandos gera um consumo de memória, tempo e processamento.
Uma forma disso ser medido é através de estatística de medição.

(Ver medicoes_aproximadas/) -> Observem que, como toda medição, não é possível
determinar com exatidão infitina um valor, ou seja, temos um valor aproximado,
que tende a ser perfeito, mas não o é. Notem que as medições obtidas variam de
computador pra computador, linguagem pra linguagem e etc e que apenas foi medido
o tempo.



//



void bubble_sort( void ){
	int i , j , aux; // c1 = int i, c2 = int j, c3 = int aux;
	for( i = 0 ; i < N - 1 ; ++i ){ // c4 = i = 0, c5 = (i<N-1), c6 = ++i;
		for( j = N - 1 ; j >= i + 1 ; --j ){ // c7 = j = N-1, c8 = j >= i+1, c9 = --j;
			if( elementos[j] < elementos[j-1] ){ // c10 = elem.[j] < elem.[j-1];
				aux = elementos[j];	// c11 = aux = elem.[j];
				elementos[j] = elementos[j-1]; // c12 = elem.[j] = elem.[j-1];
				elementos[j-1] = aux; // c13 = elem.[j-1] = aux;
			}
		}
	}
}

Analisando o algoritmo do Bubble Sort, podemos observar que alguns desses comandos
serão executados uma só vez, são eles:

	- c1, c2, c3, c4;

Ademais, vemos outros que serão executados mais de uma vez, visto que estão dentro de
um loop. Vocês acham que em todas as situações estes outros serão sempre executados?!

(Ver animações com as diversas situações: 1, 2, 3, 4 <-> N = 10)



//



void bubble_sort( void ){
	int i , j , aux; // c1 = int i, c2 = int j, c3 = int aux;
	for( i = 0 ; i < N - 1 ; ++i ){ // c4 = i = 0, c5 = (i<N-1), c6 = ++i;
		for( j = N - 1 ; j >= i + 1 ; --j ){ // c7 = j = N-1, c8 = j >= i+1, c9 = --j;
			if( elementos[j] < elementos[j-1] ){ // c10 = elem.[j] < elem.[j-1];
				aux = elementos[j];	// c11 = aux = elem.[j];
				elementos[j] = elementos[j-1]; // c12 = elem.[j] = elem.[j-1];
				elementos[j-1] = aux; // c13 = elem.[j-1] = aux;
			}
		}
	}
}

Vejamos os comandos que compõem loops:

	- c5, c6, c7, c8 ...

Ademais, quantas vezes cada um deles será executado? É notório que
boa parte deles, em algum momento, depende de N. Mas, isso ainda não
responde: Quantas vezes?

Para análise de ordenações, imaginemos qual a pior das situações
que uma sequência se encontraria e sua melhor.



//



Concordamos que a pior e a melhor seriam, respectivamente, quando
a sequência está totalmente desordenada (não existe um par sequer
em que um i < j esteja em ordem direta) e quando a sequência já está
totalmente ordenada.

A isso chamamos de Worst-case e Best-case (há também o Average, mas
vamos nos restringir por aqui), respectivamente.

Então, vamos analisar o algoritmo através desses dois pontos de vista.



//



void bubble_sort( void ){
	int i , j , aux; // c1 = int i, c2 = int j, c3 = int aux;
	for( i = 0 ; i < N - 1 ; ++i ){ // c4 = i = 0, c5 = (i<N-1), c6 = ++i;
		for( j = N - 1 ; j >= i + 1 ; --j ){ // c7 = j = N-1, c8 = j >= i+1, c9 = --j;
			if( elementos[j] < elementos[j-1] ){ // c10 = elem.[j] < elem.[j-1];
				aux = elementos[j];	// c11 = aux = elem.[j];
				elementos[j] = elementos[j-1]; // c12 = elem.[j] = elem.[j-1];
				elementos[j-1] = aux; // c13 = elem.[j-1] = aux;
			}
		}
	}
}

Logo, os comandos in-loop seriam executados dessa forma:

	- c5 : (N - 1) + 1; // +1 por conta da última verificação antes de sair do loop
	- c6 : N - 1; // Executado sempre ao fim de cada iteração do loop
	- c7 : N - 1; // Executado uma vez sempre ao início da 2ª iteração
	- c8 : ((N - 2) + 1) + ((N - 3) + 1) + ((N - 4) + 1) + ... + ((N - (N-1)) + 1);
		// Executado até a sua condição ser falsa quantas vezes a iteração externa
		// reexecutá-la. Note que não se faz a condição (N - N), pois a iteração externa
		// corta o laço antes desse momento ser atingido.
		// Essa execução é a grande chave da questão, é ela quem consome maior processamento.
		// Esse consumo é visívelmente uma soma finita de termos, logo, pela lei de soma
		// de termos finitos de Gauss:
	-> c8 : (N - 2 + 1 + N - 1 + 1) / 2 -> c8 : (2N - 1)/2;
	- c9 : (2N - 2)/2; // Mesmo fenômeno da c8, porém, subtraído de um por só ser executado in-loop
	- c10 : (2N - 2)/2; // Mesmo do anterior
	- c11 : (2N - 2)/2 ou 0; // Aqui é que entra a diferenciação entre Best e Worst case.
	- c12 : (2N - 2)/2 ou 0; // Mesmo do anterior
	- c13 : (2N - 2)/2 ou 0; // Mesmo do anterior



//



Analisando os dois pontos de vista de forma matemática, temos:

- Worst:
	
	c1 + c2 + c3 + c4 + c5*((N-1)+1) + c6*(N-1) + c7*(N-1) + 
	c8*((2N-1)/2)*(N-1) + c9*((2N-2)/2)*(N-1) + c10*((2N-2)/2)*(N-1)
	+ c11*((2N-2)/2)*(N-1) + c12*((2N-2)/2)*(N-1) + c13*((2N-2)/2)*(N-1)

- Best:

	c1 + c2 + c3 + c4 + c5*((N-1)+1) + c6*(N-1) + c7*(N-1) + 
	c8*(2N-1)/2 + c9*(2N-2)/2 + c10*(2N-2)/2 + c11*0*(N-1) +
	c12*0*(N-1) + c13*0*(N-1)

Cada caso é diferente, mas para o Bubble Sort essa diferença é mínima.
(Ver animação de ambas as situações -> 2, 3, <-> N = 40)



//



Por que essa diferença é minima? Primeiramente, porque, de fato, o resultado
das equações é próximo, e, em segundo, o que realmente faz diferença na matemática
é a ordem de crescimento de uma função, ou simplesmente ordem. Visto que, quando
N --> (+1/0.0) as constantes e variáveis de menor grau não influenciam nem 1%
na imagem da função.

Usualmente, para a área de T.I., essa complexidade se representa pro O( ? ).

Logo, vamos analisar apenas o pior caso para o Bubble Sort:

	c1 + c2 + c3 + c4 + c5*((N-1)+1) + c6*(N-1) + c7*(N-1) + 
	c8*((2N-1)/2)*(N-1) + c9*((2N-2)/2)*(N-1) + c10*((2N-2)/2)*(N-1)
	+ c11*((2N-2)/2)*(N-1) + c12*((2N-2)/2)*(N-1) + c13*((2N-2)/2)*(N-1)


O( ? ) = a + 

