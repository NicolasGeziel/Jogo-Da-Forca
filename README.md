# Jogo da Forca

Aplicação desenvolvida em C++ que simula o clássico Jogo da Forca. O diferencial técnico deste projeto é a utilização exclusiva da abstração de **Lista Circular Duplamente Encadeada** para representar e manipular todas as estruturas e estados do jogo, demonstrando domínio sobre ponteiros e gerenciamento de memória em baixo nível.

## Características Técnicas

* **Estrutura de Dados Customizada:** Todo o estado da partida (palavra oculta, letras acertadas e histórico de tentativas) é gerenciado por listas circulares desenvolvidas do zero, sem o uso de abstrações prontas da biblioteca padrão.
* **Leitura Dinâmica (File I/O):** O dicionário de palavras não é fixo ("hardcoded"). O sistema carrega as opções dinamicamente a partir de um arquivo `.txt` informado pelo usuário em tempo de execução.
* **Controle de Fluxo:** Sorteio aleatório de palavras com base no tamanho do arquivo carregado e sistema de loop contínuo para múltiplas partidas sem necessidade de reiniciar a aplicação.
