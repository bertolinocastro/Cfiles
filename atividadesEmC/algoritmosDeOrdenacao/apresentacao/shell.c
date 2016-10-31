

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
seu emepcílho quanto à ordem O( n^2 ).

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
todos os que resultarem em 1 na etapa final, estão
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

(Ver shell_gaps_tabela.png)


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




