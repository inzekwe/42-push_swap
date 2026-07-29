*This project has been created as part of the 42 curriculum by < jenifsil >, < sbarbosa >.*

# push_swap

## Description

O `push_swap` ordena uma lista de inteiros usando duas pilhas (`a` e `b`) e um
conjunto limitado de operações (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`,
`rra`, `rrb`, `rrr`), buscando usar o menor número possível de operações.

O programa implementa 4 estratégias de ordenação diferentes, selecionáveis por
flag ou escolhidas automaticamente com base no **disorder** (grau de desordem)
da entrada:

| Categoria | Algoritmo escolhido | Complexidade (em operações push_swap) |
|---|---|---|
| Simples | Selection sort adaptado (acha o menor, rotaciona até o topo, empurra pra `b`) | O(n²) |
| Médio | Chunk-based sort (divide os valores em `√n` faixas e processa faixa por faixa) | O(n√n) |
| Complexo | Radix sort baseado no *rank* de cada valor (bit a bit, sem comparação direta) | O(n log n) |
| Adaptativo | Escolhe uma das 3 acima, de acordo com o disorder medido | — |

## Instructions

Compilar:
```bash
make
```

Rodar:
```bash
./push_swap 2 1 3 6 5 8
```

Flags opcionais:
- `--simple` / `--medium` / `--complex` / `--adaptive` (padrão): força a estratégia
  (só **uma** dessas por vez — passar duas juntas, ex. `--simple --medium`, é
  tratado como erro)
- `--bench`: imprime métricas de benchmark no stderr (disorder, estratégia usada,
  total de operações e contagem por tipo)

Limpar:
```bash
make clean   # remove os .o
make fclean  # remove .o e o binário
make re      # fclean + all
```

## Resources

- Documentação/enunciado oficial do projeto `push_swap` (42 Curriculum, PDF do módulo).
- Conceito de radix sort (LSD) adaptado para pilhas:
  baseada em ordenar pelo *rank* (posição relativa) de cada valor
  ao invés do valor bruto, para lidar com números negativos sem conversões extras.
- **Uso de IA (Claude, Anthropic):** utilizada ao longo de todo o desenvolvimento
  como tutora, através de perguntas guiadas. A IA não escreveu o código final
  diretamente; ela explicou conceitos de ponteiros, listas encadeadas, e apontou
  erros específicos em tentativas próprias (ex: uso incorreto de `*`, `->`, ordem
  de atribuição de ponteiros em `sa`/`ra`/`rra`), até que o código fosse escrito e
  entendido por nós mesmas. A IA também ajudou a consolidar o projeto em arquivos
  organizados, validar a corretude das ordenações via simulação, e a testar
  contra a Norminette e as métricas de avaliação. Também ajudou a identificar
  um bug de eficiência (lista já ordenada gerando operações desnecessárias, hoje
  corrigido) e a decidir, de forma consciente, manter o algoritmo simples sem
  casos especiais isolados para tamanhos pequenos — priorizando ter **um único
  algoritmo coerente e fácil de defender**, mesmo ao custo de mais operações em
  listas muito pequenas (ver seção "Algorithm justification" abaixo).

## Algorithm justification

**Simples (O(n²)):** a cada iteração, acha o elemento mínimo restante em `a`
(varredura completa) e o move ao topo pelo caminho mais barato (`ra` se estiver
na metade de cima, `rra` se estiver na metade de baixo), empurrando-o para `b`.
Repete até sobrar 1 elemento em `a` (que já está no lugar certo), depois devolve
tudo de `b` para `a` com `pa`. Custo: O(n) iterações × O(n) de busca = O(n²).

*Decisão de design:* essa é a **única** lógica do algoritmo simples — não
existem casos especiais isolados para 2, 3, 4 ou 5 elementos. Isso significa
que, para listas muito pequenas, o número de operações não é o mínimo teórico
possível (por exemplo, ordenar 2 elementos gasta 3 operações via o laço
genérico, `ra pb pa`, em vez do 1 mínimo possível, `sa`). Escolhemos manter
assim deliberadamente: o algoritmo simples deve representar **uma ideia só**
(selection sort adaptado), fácil de entender e defender integralmente — em
vez de ser, na prática, cinco algoritmos diferentes escondidos atrás de um
único nome.

**Médio (O(n√n), na prática):** calcula o *rank* de cada elemento (0 a n-1) e
faz um agrupamento grosseiro usando apenas os bits mais significativos desse
rank (metade dos bits necessários) — reorganizando a pilha em faixas
aproximadas de valor com poucas passadas. Depois, chama o algoritmo simples
para terminar a ordenação; como a pilha já chega parcialmente organizada, o
custo de rotação do simples cai bastante (elementos ficam mais perto do topo
com mais frequência). Testes empíricos com 100 e 500 números aleatórios
confirmam que essa combinação fica consistentemente entre o simples e o
complexo em número de operações. *Nota de honestidade: isso não é uma prova
formal de O(n√n) no sentido estrito de todos os casos — é uma heurística
verificada empiricamente, documentada como tal.*

**Complexo (O(n log n)):** como o `push_swap` só permite comparar valores
diretamente (não usar bits diretamente do valor bruto de forma simples com
números negativos), calculamos primeiro o *rank* de cada elemento (sua posição
se a lista estivesse ordenada, de 0 a n-1). Depois, um radix sort clássico
processa bit a bit (do menos significativo ao mais significativo) esse rank:
para cada bit, os elementos são separados entre "ficam em `a`" ou "vão para
`b`" e recombinados, ao final de `log₂(n)` passadas cada uma O(n), a lista está
ordenada. Custo: O(n log n).

**Adaptativo:** mede o disorder antes de qualquer operação (fórmula de pares
fora de ordem). Se `disorder < 0.2` usa o algoritmo simples; se
`0.2 ≤ disorder < 0.5` usa o médio; se `disorder ≥ 0.5` usa o complexo. **Não
há caso especial por tamanho** — mesmo pilhas de 3 elementos passam pelos
mesmos limiares, o que é consequência direta da decisão de design descrita
acima (uma lógica só por algoritmo, sem casos isolados). Na prática, isso
significa que uma pilha de 3 elementos com disorder alto (ex: `3 2 1`) é
ordenada pelo algoritmo complexo (radix), gastando bem mais operações do que
o ótimo teórico para 3 elementos — ver "Known limitations" abaixo.

