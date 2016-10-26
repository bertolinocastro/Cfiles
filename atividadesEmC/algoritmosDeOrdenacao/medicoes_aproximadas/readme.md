#Pasta das Medições aproximadas

###Estruturas consistem em:

1. Script executável (.c) da funcionalidade/operação a ser mensurada;  
2. Arquivo de saída constando todos os valores aferidos para medição;  
  1. Conteúdo dos arquivos deve obedecer a ordem de medições:  
    1. Arquivo em formato .txt;  
    2. O conteúdo de saída será expresso em ms (milissegundos), quando grandeza for o tempo;  
    3. Experimentos feitos com 10.000 (dez mil) amostras;  
    4. Cada amostra consiste em duas medições. Uma anterior à op/func e outra ulterior, ambas devidamente nomeadas no arquivo de saída;  
    5. Erros humanos são improváveis, logo, não devem ser considerados;  
    6. Desvios grotescos, acima ou abaixo de 10% da média +- o desvio padrão, devem ser desconsiderados;  
3. Arquivo com o código desassemblado.  