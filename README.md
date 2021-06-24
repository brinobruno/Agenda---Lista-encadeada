# Agenda---Lista-encadeada
Uma agenda de contatos com 5 funcionalidades utilizando lista encadeada - projeto para estudo.

	O minhaGenda é um programa com o intuito de treinar meus conhecimentos de lista encadeada que estou aprendendo na faculdade, em Estrutura de Dados.
	O código está praticamente 100% em inglês - exceto pelos outputs do usuário. Decidi começar essa prática para estruturar meu inglês técnico no âmbito de TI, tendo em vista que pretendo um dia trabalhar com pessoas do mundo todo, talvez no próprio exterior.
  
	Incluo bibliotecas muito comuns do C++, e estou usando namespace com std visto que não teria nenhum conflito com as funcionalidades que eu planejei para o código.
	Logo depois crio 3 structs, a do Contato (contact), Nó (node) e da Lista (List), e estou usando typedef para não ter que ficar repetindo struct sempre que for chama-la.
  
	Na struct do nó, conto com um ponteiro com a struct do contato, um ponteiro pro próximo, e um pro anterior (next, before), e na lista, conto com um ponteiro do nó do começo e do além de um inteiro para contabilizar pro usuário a quantia de contatos, a partir de incrementação.
  
	Tem uma função do tipo inteira pro menu, com os outputs de opções para o usuários, recolho a resposta através do inteiro option, e crio um if com while para avisar o usuário caso o mesmo responda de forma equívoca.
  
	Posteriormente, criei uma função do tipo void para o registro, recebo o seguintes parâmetros: uma lista via ponteiro, nome, número de telefone e e-mail. Todas são strings por contas de símbolos no telefone, como o (+código) e hífen, e o mesmo para o e-mail.
	Crio um contato dinamicamente, e vou apontando os ponteiros que irão armazenar os dados do usuário, Também crio o Nó de forma dinâmica e aponto o próximo e o anterior para o endereço de memória NULL.
  
	Em seguida, testo se a lista está vazia através de uma função chamada "IsEmpty", e se essa condição for verdadeira, o começo e o final da minha lista apontam para new2 - novo. E caso essa condição não seja verdadeira, O meu ponteiro auxiliar (helper) se aponta pro final, o próximo pro novo, anterior para o auxiliar e o final para o novo, e também incremento o tamanho, independente da condição.
  
	Também criei uma função de impressão de contatos, chamada print, que receba a lista via ponteiro, novamente, verifico se a lista está vazia, caso não esteja, meu auxiliar aponta pro começo, e vou imprimindo em iteração while, enquanto o auxiliar for diferente de NULL, que seria o fim da lista, depois de cada iteração o auxiliar aponta pro próximo até chegar ao NULL.
  
	Criei uma impressão invertida, onde a única diferença é que o auxiliar aponta pro fim, e durante a iteração o auxiliar vai andando pra trás, apontando para o anterior, então recapitulando: ao invés de início, fim. E ao invés de próximo, anterior. Essa é a printBackwards - para trás. E no fim das duas também é impresso o valor.
	Também há uma função para esvaziar a lista de contatos, onde o atual (current) é igual a referência, e o próximo, NULL. E em um laço while, o próximo sempre se torna o atual->próximo e deleta o atual, (free), e volta a ser o próximo.
  
	A função main é extremamente simples, declaro as variáveis, aponto o começo e início da lista para o NULL - que é imprescindível para o funcionamento da lista, e crio um DoWhile, com cada case chamando uma função e passando o endereço da lista.
	
