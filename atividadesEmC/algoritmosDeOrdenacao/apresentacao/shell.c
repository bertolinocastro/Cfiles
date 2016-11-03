

		Shell sort:

Método de ordenação feito por Donald Shell (origem do nome).
	- Em 1959, enquanto na universidade de Cincinnati.

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

(Ver animação do Insertion Sort e do Bubble Sort)



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
	int j, aux, tam, m;
	tam = N - 1;
	do{
		m = 0;
		for( j = 0 ; j < tam ; ++j ){
			if( elementos[j] > elementos[j+1] ){
				aux = elementos[j];
				elementos[j] = elementos[j+1];
				elementos[j+1] = aux;
				m = j;
			}
		}
		tam = m;
	}while( tam >= 1 );
}

Como dito, os 'ãos' consumem, então, vamos dar nomes aos bois!



//



void bubble_sort( void ){
	int j, aux, tam, m; // op1 = int j, op2 = int aux, op3 = int tam;
	tam = N - 1; // op0 = tam = N - 1;
	do{
		m = 0; // op4 = m = 0;
		for( j = 0 ; j < tam ; ++j ){ // op5 = j = 0, c6 = j < tam, op7 = ++j;
			if( elementos[j] > elementos[j+1] ){ // c8 = elem.[j]>elem.[j+1];
				aux = elementos[j]; // op9 = aux = elem.[j];
				elementos[j] = elementos[j+1]; // op10 = elem.[j] = elem.[j+1];
				elementos[j+1] = aux; // op11 = elem.[j+1] = aux;
				m = j; // op12 = m = j; 
			}
		}
		tam = m; // op13 = tam = m;
	}while( tam >= 1 ); // c14 = tam >= 1;
}

Notemos que cada constante 'c*' e 'op*' deve ser entendida como comando-n/operacao-n.
Esse comando representa uma instrução para o processador, vista do
médio nível - por conta do código estar escrito em C (posteriormente,
veremos de forma superficial o mesmo código em baixo nível).

Cada um desses comandos é excecutado uma ou mais vezes, dependendo da
lógica por trás do algoritmo e da quantidade de chaves a ser ordenada.
A isso chamamos de Complexidade de um algoritmo - usualmente representada
por O( ? ).



//



void bubble_sort( void ){
	int j, aux, tam, m; // op1 = int j, op2 = int aux, op3 = int tam;
	tam = N - 1; // op0 = tam = N - 1;
	do{
		m = 0; // op4 = m = 0;
		for( j = 0 ; j < tam ; ++j ){ // op5 = j = 0, c6 = j < tam, op7 = ++j;
			if( elementos[j] > elementos[j+1] ){ // c8 = elem.[j]>elem.[j+1];
				aux = elementos[j]; // op9 = aux = elem.[j];
				elementos[j] = elementos[j+1]; // op10 = elem.[j] = elem.[j+1];
				elementos[j+1] = aux; // op11 = elem.[j+1] = aux;
				m = j; // op12 = m = j; 
			}
		}
		tam = m; // op13 = tam = m;
	}while( tam >= 1 ); // c14 = tam >= 1;
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
	int j, aux, tam, m; // op1 = int j, op2 = int aux, op3 = int tam;
	tam = N - 1; // op0 = tam = N - 1;
	do{
		m = 0; // op4 = m = 0;
		for( j = 0 ; j < tam ; ++j ){ // op5 = j = 0, c6 = j < tam, op7 = ++j;
			if( elementos[j] > elementos[j+1] ){ // c8 = elem.[j]>elem.[j+1];
				aux = elementos[j]; // op9 = aux = elem.[j];
				elementos[j] = elementos[j+1]; // op10 = elem.[j] = elem.[j+1];
				elementos[j+1] = aux; // op11 = elem.[j+1] = aux;
				m = j; // op12 = m = j; 
			}
		}
		tam = m; // op13 = tam = m;
	}while( tam >= 1 ); // c14 = tam >= 1;
}

Analisando o algoritmo do Bubble Sort, podemos observar que alguns desses comandos
serão executados uma só vez, são eles:

	- op1, op2, op3, op0;

Ademais, vemos outros que serão executados uma ou mais vezez, visto que estão dentro de
um loop. Vocês acham que em todas as situações estes outros serão sempre executados?!

(Ver animações com as diversas situações: 1, 2, 3, 4 <-> N = 10)



//



void bubble_sort( void ){
	int j, aux, tam, m; // op1 = int j, op2 = int aux, op3 = int tam;
	tam = N - 1; // op0 = tam = N - 1;
	do{
		m = 0; // op4 = m = 0;
		for( j = 0 ; j < tam ; ++j ){ // op5 = j = 0, c6 = j < tam, op7 = ++j;
			if( elementos[j] > elementos[j+1] ){ // c8 = elem.[j]>elem.[j+1];
				aux = elementos[j]; // op9 = aux = elem.[j];
				elementos[j] = elementos[j+1]; // op10 = elem.[j] = elem.[j+1];
				elementos[j+1] = aux; // op11 = elem.[j+1] = aux;
				m = j; // op12 = m = j; 
			}
		}
		tam = m; // op13 = tam = m;
	}while( tam >= 1 ); // c14 = tam >= 1;
}

Vejamos os comandos que compõem loops:

	- op4, op5, c6, op7, c8 ...

Ademais, quantas vezes cada um deles será executado? É notório que
boa parte deles, em algum momento, depende de N. Mas isso ainda não
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
	int j, aux, tam, m; // op1 = int j, op2 = int aux, op3 = int tam;
	tam = N - 1; // op0 = tam = N - 1;
	do{
		m = 0; // op4 = m = 0;
		for( j = 0 ; j < tam ; ++j ){ // op5 = j = 0, c6 = j < tam, op7 = ++j;
			if( elementos[j] > elementos[j+1] ){ // c8 = elem.[j]>elem.[j+1];
				aux = elementos[j]; // op9 = aux = elem.[j];
				elementos[j] = elementos[j+1]; // op10 = elem.[j] = elem.[j+1];
				elementos[j+1] = aux; // op11 = elem.[j+1] = aux;
				m = j; // op12 = m = j; 
			}
		}
		tam = m; // op13 = tam = m;
	}while( tam >= 1 ); // c14 = tam >= 1;
}

Logo, os comandos in-loop seriam executados dessa forma:

	- op4 : 1 ou N - 1 // Explicação na última operação
	- op5 : 1 ou N - 1 // Idem
	- c6 : N + (N - 1) + (N - 2) + ... + 1 // Começa com N, pois esse loop
		// só termina quando a comparação é executada e retorna falso.
		// É a operação que mais custa processamento, pois sempre será
		// feita até varrer todo o vetor, pelo menos uma vez.
		// Executado até que atinja o tamanho.
		// Na primeira iteração, varre até o tam - 1
		// Nas seguintes a tendência é que ele varra, pelo menos,
		// a anterior - 1.
		// Dessa forma, a quantidade total de execuções dessa operação
		// é uma soma finita de termos em uma P.A..
		// Sendo assim, pela lei de Gauss:
	-> c6 : (N + 1)/2
	- op7 : ((N + 1) - 1)/2 -> N/2 // Mesmo fenômero da c6
	- c8 : N/2 // Mesmo do anterior
	- op9 : 0 ou N/2 // Aqui entra a diferenciação entre Best e Worst case
	- op10 : 0 ou N/2 // Idem
	- op11 : 0 ou N/2 // Idem
	- op12 : 0 ou N/2 // Idem
	- op13 : 1 ou N - 1 // Explicação na última operação
	- c14 : 1 ou N // É executado este número de vezes por conta de que
		// em cada iteração, o for interno rearranjou todo o vetor até a
		// última posição (não ordenou, apenas rearranjou), que está no lugar
		// correto, logo, tam irá decrementar sempre que o loop interno passar
		// o valor de j para m.
		// Então, no pior dos casos, esse do{}while será executado para todos os
		// índices do vetor.



//



Analisando os dois pontos de vista de forma matemática, temos:

- Worst:
	
	op1 + op2 + op3 + op4*N*(N-1) + op5*N*(N-1) + c6*N*(N+1)/2 + op7*N*N/2 + 
	c8*N*N/2 + op9*N*N/2 + op10*N*N/2 + op11*N*N/2 + op12*N*N/2 + op13*N + c14*N

- Best:

	op1 + op2 + op3 + op4*1 + op5*1 + c6*N*1 + op7*N*1 + c8*N*1 + op9*N*0 +
	op10*N*0 + op11*N*0 + op12*N*0 + op13*1 + c14*1

Cada caso é diferente e para o Bubble Sort essa diferença é um tanto quanto
significativa.

(Ver animação de ambas as situações -> 2, 3, <-> N = 40) -> Observem que
o número de passos executados são muito diferentes e que eles tendem a se
distanciar muito quanto maior for o tamanho de n.



//



Àquela análise matemática que fizemos do código damos o nome de complexidade.
Usualmente, para a área de T.I., essa complexidade se representa por O( ? ) (Big 'Oh').

Existem outras que, e.g., determinam o comportamento assintótico das funções de complexidade,
como Big 'Theta', 'Omega' e seus respectivos Smalls, mas é uma análise muito abstrata
e matemática da situação, então, voltemos ao Big 'Oh'.

De primeiro momento, vamos analisar apenas o pior caso para o Bubble Sort:

O( ? ) = op1 + op2 + op3 + op4*n*(n-1) + op5*n*(n-1) + c6*n*(n+1)/2 + op7*n*n/2 + 
	c8*n*n/2 + op9*n*n/2 + op10*n*n/2 + op11*n*n/2 + op12*n*n/2 + op13*n + c14*n

Com todos os custos em mãos, vamos simplificar essa equação para melhorar o entedimento.



//



O( ? ) = a + b*(n-1)*(n) + c*(n)*(n/2) + d*(n)

	   = a + n*(d) + (n² - n)*(c/2 - b)

	   = c*n² + (d - b)*n + a

	   = x*n² + y*n + z

	   onde:

	   a = op1 + op2 + op3
	   b = op4 + op5 
	   c = op7 + op8 + op9 + op10 + op11 + op12
	   d = op13 + op14

Resumindo, a complexidade do Bubble Sort no pior caso é:

O( ? ) = x*n² + y*n + z



//



Porém, sempre que vocês forem pesquisar ou ler conteúdos sobre crescimento de funções,
vão se deparar com a rotineira atenção apenas ao termo de maior grau. Para o caso do
Bubble Sort supracitado, por exemplo, a complexidade sempre é escrita por O( n² ), que
é simplesmente o termo de maior grau da equação.

	O( ? ) = x*n² + y*n + z => O( n² )

Mas, indo para o lado da matemática, por que esquece-se dos termos "alheios"?

A resposta é simples: Porque não fazem diferença!

O que distancia o resultado de duas equações de mesmo grau com termos de diferentes
constantes e etc são as infinitas casas decimais que separam Chico de Francisco. Ou seja,
nem com uma variável do tipo Ultra Big Monstruosa Birl Long Triple Double seria possível
notar essa diferença para valores altos.



//


E vocês me perguntam: - Por que essa diferença é minima?

Primeiramente, porque, de fato, o resultado das equações é próximo, e, em segundo,
o que realmente faz diferença na matemática é a ordem de crescimento de uma função,
ou simplesmente ordem. Visto que, quando N --> (+1/0.0) as constantes e variáveis de
menor grau não influenciam nem 1% na imagem da função.



//



Façamos experimentalmente: Calculem nas duas situações
	- n² + n
	- n²

Ambas com n = Google. Comparem os resultados e observem que a diferença entre
as duas é ínfima, logo, o termo de menor grau ( n¹ ) não é de grande influência
nessas equações de análise de complexidade.

É nítido que para todo n >> n0 o fator que realmente importa é o n².

(Ver plotagem do gráfico de n² e de n² + n <-> gnuplot plot e replot) -> Observem que,
para altos valores, os dois gráficos basicamente são os mesmos, as duas curvas
se tornam "únicas".

Estamos convencidos?!



//



Visto tudo isso, estamos convencidos de que a complexidade do algoritmo Bubble Sort
é O( n² ). E no melhor caso, porém?

Vejamos os custos novamente:

	op1 + op2 + op3 + op4*1 + op5*1 + c6*N*1 + op7*N*1 + c8*N*1 + op9*N*0 +
	op10*N*0 + op11*N*0 + op12*N*0 + op13*1 + c14*1

Observem que apenas os termos internos, ou seja, os que pertencem ao if, são os que
possuem multiplicador 0. Sendo assim, a equação se tornaria a seguinte:

	op1 + op2 + op3 + op4 + op5 + c6*N + op7*N + c8*N + op13 + c14

A equação na sua forma reduzida é: O( ? ) = x*n + z, onde os termos x e z representam
as constantes da equação. Logo:

	O( ? ) = x*n + z => O( n )



//



É notório que agora os termos de grau 2 sumiram, podemos supor que o algoritmo se
tornou mais eficiente, certo?

(Rever animação do Bubble Sort com situações 2, 3 ) -> Após toda essa explicação,
fica evidente que os algoritmos são situacionais. Hora são bons/rápidos, hora são
ruins/lentos.

(Ver gráfico de n² e n <-> gnuplot) -> Mostrando em termos gráficos, é possível
ver a discrepância de passos/execuções ocorrida com o Bubble Sort.



//



Assimilando tudo o que foi explicado até o momento faz tornar fácil o entendimento
do porquê Shell propôs um substituto para o Bubble Sort.

O que falta, então, para terminarmos a linha de raciocínio é fazer a análise do código
do Shell Sort. Vamos, entretanto, pular algumas etapas, às vistas de já sabermos como
chegar até o fim delas.

Por início, como já falamos antes que o Shell Sort é um Insertion Sort aprimorado,
vamos analisar a parte interna, que seria o próprio Insertion Sort.



//



void insertion_sort( void ){
	int i, j, aux; // custos 1
	for( i = 1 ; i < N ; ++i ){ // custo 1 , (N-1)*custos , (N-2)*custos
		aux = elementos[i]; // (N-1)*custos
		for( j = i - 1 ; j >= 0 && aux < elementos[j] ; --j ){
			// (N-1)*custos , { 1 + 2 + ... + N}*(N-2) ou 1 , { 1 + 2 + ... + N}*(N-2) ou 0
			elementos[j+1] = elementos[j]; // { 1 + 2 + ... + N}*(N-1) ou 0
		}
		elementos[j+1] = aux; // (N-2)
	}
}

Seguindo os mesmos princípios do Bubble Sort, vamos direto à complexidade, ignorando as constantes:

Worst:

	O( ? ) = z + y*n + x*n² => O( n² )

Best:

	O( ? ) = z + y*n => O( n )

Observamos que esses Big 'Oh' possuem as mesmas complexidades do Bubble Sort, então, onde está
o aprimoramento do Shell? Veremos em seguida.



//



Lembram que no código do Shell tinha o "pulo do gato"? O 'Gap' que servia pra conectar o pessoal
de Cajazeiras com a Terra? O que fazia as 'bolhas telepáticas'? Então, é ele a grande sacada de tudo.

Retifico aqui que foi mudado o gap utilizado, doravante utilizaremos o gap definido por Shell, pois é
de simples análise. Vamos ao Código:

void shell_sort( void ){
	int i, j, aux, gap = floor(N/2);
	// Não contamos os custos de achar/criar o Gap, pois isso não faz parte do código em si.
	// Seria possível utilizar gaps predeterminados em um vetor, por exemplo.

	do{
		for( i = gap; i < N; ++i ){ // (N-gap)*(log(n))
			aux = elementos[i]; // (N-gap)*(log(n))
			for( j = i - gap; j >= 0 && aux < elementos[j]; j -= gap ){ 
				// (log(n))*(N-gap) ou log(n)
				elementos[j+gap] = elementos[j];
				// (log(n))*(N-gap) ou 0
			}
			elementos[j+gap] = aux; // (N-gap)*(log(n))
		}
	}while( (gap=floor(gap/2)) >= 1 ); // floor(log(n))
	// Loop externo será executado quantas vezes forem possíveis até que se atinja o valor 1.
	// Porém, para calcular a quantidade de vezes que isso será possível, demanda a utilização
	// de logaritmo, pois, pelas divisões serem sempre por dois, cada uma delas gera um "nível",
	// assim, a quantidade de níveis que o valor de N vai permitir atingir será de floor(log[2](n)).

}

Seguindo os mesmos princípios do Insertion Sort, vamos direto à complexidade, ignorando as constantes:

Worst:

	O( ? ) = z + y*n + x*n² => O( n² )

Best:

	O( ? ) = z + y*n => O( n*log(n) )



//



Bom, como vocês puderam observar, o Worst-case deu um O( n² ), o que não foi um grande
avanço se comparado com o Bubble e o Insertion Sort, e, além disso, piorou o Best-case,
que antes era O( n ) e agora passou a ser O( n*log(n) ), ou seja, cadê o aprimoramento
do algoritmo?!

De fato, na prática, é possível observar uma diferença para os piores casos dos três,
porém, na análise abstrata do Big 'Oh', caímos nessa perda.

(Ver animação Shell e Insertion <-> 3, N = 40)-> Observar diferença em performance.

Como, porém, o Shell Sort se tornou de fato um aprimoramento?!

Se lembram da tabela de 'Gaps' que mostramos logo no começo?! Vamos dar uma olhada nos
resultados dela.

(Ver shel_sort_average_number_comparision...) -> Observem que, mesmo a sequência de 'Gaps'
do próprio Shell não estando presente, é notório uma diferença enorme dentre as sequências
definidas.

Sendo assim, o aprimoramento de Shell foi promissor, levando em consideração os 'Gaps'
sucessores ao dele.



//



Ademais, como dito no começo, o Shell Sort fazia as 'bolhas telepáticas' com o intuito
de encurtar a distância entre elas, sendo assim, é possível afirmar que isso de fato
reduz também o número de comparações entre os elementos da sequência principal.

Como as comparações são feitas por um comando interno ao corpo do Shell Sort, é possível
administrar sua quantidade de comparações no melhor caso e pior caso.É possível, também,
observar esse fenômeno empiricamente.

Seguindo os comentários do código passado, para esse 'Gap' utilizado, o melhor e pior caso
de C( ? ) seria:

Worst:
	
	C( ? ) = log(n)*n => C( n*log(n) )

Best:
	
	C( ? ) = log(n) = > C( log(n) )



//



Ademais, relembrando as perguntas iniciais, vários dos pontos tangíveis à eficiência de
um algoritmo foram respondidos, mas alguns pontos ficaram de fora, pois são mais simples.

	« Seria um algoritmo com baixo consumo de memória? Com poucos passos de
	execução? Com poucas comparações? Com poucas trocas necessárias?
	Com um código simples, curto e de fácil implementação? Seria um algoritmo
	estável?! Com tempo de execução curto? »

Vamos às suposições que faltaram:

1. « Seria um algoritmo estável?! »

Bom, por definição, algoritmos estáveis são aqueles em que valores iguais, do ponto de vista
dos parâmetros analisados, permanecem com suas posições relativas inalteradas até o fim da
ordenação, e.g.:

	Nessa sequência: { 1 , 2 , 1, 4 }, observem que possuimos dois valores iguais, dois números
	1. Pela definição, o número 1 da casa 0 e o número 1 da casa 2 devem manter suas posições
	relativas, ou seja, em qualquer novo rearranjo que eles possuam, o da casa 0 deve, obrigato-
	riamente, estar a esquerda do 1 da casa 2.

	Para facilitar a visualização, poremos coringas na sequência principal: { 1a, 2, 1b, 4}.
	As letras não têm valor para a nossa ordenação, são ilustrativas.
	Ao reordenar esse vetor, seu vetor final deve ser, obrigatoriamente: { 1a, 1b, 2, 4} e
	nunca { 1b ,1a, 2, 4}.

	Ademais, vale ressaltar que isso depende de quais fatores você está analisando para reordenar,
	e.g., caso queira reordenar um vetor de floats apenas pelo seus valores inteiros.

	{ 1.7, 3.5, 1.5, 2.4 } => { 1.7, 1.5, 2.4, 3.5 }

	Observe que mesmo o valor 1.7 sendo maior que o 1.5, ele deve se manter a esquerda, pois
	sua determinação de ordenação foi apenas o valor dos inteiros, logo, para o algoritmo ser estável,
	deve-se manter a ordem relativa de chaves iguais.

Após todo esse embasamento, é entendível que o Shell Sort não seja um algoritmo estável.
Seu funcionamento apenas tende a se comportar com estabilidade nas subsequências quando analisadas pela
primeira vez, porém, sempre que a sequência principal é reanalisada, sua estabilidade é comprometida.


2. « Seria um algoritmo com baixo consumo de memória? »

Ao analisarmos o código do Shell Sort é possível inferir que ele seja um algoritmo de baixo consumo
de memória, visto que utiliza pouquíssimas variáveis de apoio, não faz utilização de alocação
dinâmica e não cria um empilhamento na memória, o "Call Stack", principalmente por conta de ser
uma chamada única à sua função.

Para deixar mais claro, podemos comparar com o código de outros ordenadores, tal como o Quick Sort.

O Quick Sort em si é um algoritmo muito mais eficiênte em termos de tempo de execução e número de
trocas e comparações do que o Shell Sort, porém, por ser um algoritmo recursivo, cria um empilhamento
enorme na memória para cada chamada das funções. Em termos de empilhamento, o Merge Sort é o campeão,
pois, além de ser recursivo, utiliza vetores dinâmicos auxiliares para cara recursão.

void quick_sort_starter( int *vet, int left, int right ){
	int r;
	if( right > left ){
		r = quick_sort_divisor( vet, left, right );
		quick_sort_starter( vet, left, r-1 ); // 1ª Chamada recursiva da função
		quick_sort_starter( vet, r+1, right ); // 2ª Chamada recursiva da função
	}
}
// Trecho de código apenas da função invocadora do Quick Sort.
// O algoritmo ainda possui a particionadora, que não é recursiva nem utiliza alocação dinâmica.


