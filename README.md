#Jogo da Forca
Aplicação desenvolvida em C++ que simula o clássico Jogo da Forca. O diferencial técnico deste projeto é a utilização exclusiva da abstração de Lista Circular Duplamente Encadeada para representar e manipular todas as estruturas e estados do jogo, demonstrando domínio sobre ponteiros e gerenciamento de memória.

#Características Técnicas
Estrutura de Dados Customizada: Todo o estado da partida (palavra oculta, letras acertadas e histórico de tentativas) é gerenciado por listas circulares desenvolvidas do zero.

Leitura Dinâmica (File I/O): O dicionário de palavras não é fixo ("hardcoded"). O sistema carrega as opções dinamicamente a partir de um arquivo .txt informado pelo usuário em tempo de execução.

Controle de Fluxo: Sorteio aleatório de palavras com base no tamanho do arquivo carregado e sistema de loop contínuo para múltiplas partidas sem necessidade de reiniciar o programa.# Jogo da Forca
programa para simular o JOGO DA FORCA.  
As palavras que serão adivinhadas pelo jogador serão lidas de um arquivo texto, onde cada linha 
do arquivo armazena uma palavra e existe um número qualquer de linhas no arquivo. O nome do arquivo 
que contém as palavras não sera fixado no programa – sendo, portanto, uma entrada da aplicação. 
Um número aleatório será gerado e usado para recuperar a palavra a ser adivinhada, armazenada nessa 
posição do arquivo. O jogador tentará adivinhar a palavra, letra a letra. Cada letra que o jogador acertar 
sera apresentada na palavra que está sendo adivinhada, na respectiva posição. Uma parte do boneco sera desenhada a cada tentativa frustrada do jogador. As letras 
utilizadas ficarão sempre visíveis para o jogador. Será exibida uma mensagem de sucesso ou de fracasso 
do jogador. O programa vai possibilitar o jogador jogar quantas vezes quiser. 
Utilizado apenas a abstração lista circular para representar as estruturas envolvidas na resolução do 
problema.
