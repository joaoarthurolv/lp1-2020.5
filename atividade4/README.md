# Atividade IV - Linguagem de Programação I - Semestre Suplementar 2020.5

## Sistema de Supermercado

- O sistema de supermercado consiste na leitura de um arquivo de estoque, compra de produtos e verificação de produtos comprados.
- Possui 3 classes principais: Estabelecimento, Cliente e Produto.
- O Programa lê do arquivo de estoque.csv e armazena todos os produtos num vector de Produtos dentro de Estabelecimento.
- Segue para o Menu interativo onde é possuir informar o saldo do cliente, fazer a compra de um produto, checar a sacola do cliente e dos produtos disponíveis no mercado.

## Resalvas acerca do próprio desempenho

- Assumo responsabilidade pelo programa estar incompleto nas seguintes partes: Não diminui a quantidade em estoque quando o produto é comprado e não cria os arquivos caixa_x.txt; 

## Ressalvas acerca da atividade

- Em muitos momentos o documento da atividade se mostrou ambíguo no que se propunha. As dúvidas tiradas no discord pareciam apenas
estancar o sangue dos erros da avaliação. Muitas vezes comecei a desenvolver a funcionalidade mas um pouco depois no documento o que fiz era desmentido ou desnecessário quando outra coisa fora pedida.


## Compilação

- A atividade possui um arquivo makefile. Então, para compilar, basta estar dentro do diretório do projeto e acionar o comando make
no terminal. Depois disso, é só informar o comando "./supermercado".