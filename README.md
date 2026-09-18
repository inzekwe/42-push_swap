*This project has been created as part of the 42 curriculum by kenhuama, inzekwe.*

---

## Descrição

O programa ***`push_swap`*** recebe uma sequência de números inteiros e deve ordená-los utilizando apenas um conjunto limitado de operações sobre duas pilhas:

- Stack A
- Stack B

O programa recebe os inteiros como argumentos, seleciona automaticamente a melhor estratégia de ordenação com base no nível de desordem dos dados, e imprime na saída padrão a sequência de operações que ordena a pilha.

---

## Contribuições

| Estudante | Contribuições |
|---|---|
| **inzekwe** | Desenvolvimento das lógicas de ordenação (Simple, Medium, Complex, Adaptive), parse de argumentos e flags, e desenvolvimento das operações de pilha |
| **kenhuama** | Planejamento da rotina de testes, definição da estrutura organizacional do código, divisão de funções do sistema e elaboração do manual e relatórios |

---
## Fluxo do programa

```
+---------------------------+
|           main            |
+-------------+-------------+
              |
    +---------+---------+
    | Parse de flags    |  --simple / --medium / --complex / --adaptive / --bench
    +---------+---------+
              |
    +---------+---------+
    | Parse de números  |  validação, duplicatas, overflow
    +---------+---------+
              |
    +---------+---------+
    | Inicialização     |  aloca A e B, zera contadores
    +---------+---------+
              |
    +---------+---------+
    |   ft_dispatch()   |  calcula disorder → escolhe estratégia
    +---------+---------+
              |
    +---------+----------+----------+----------+
    |         |          |          |          |
 SIMPLE    MEDIUM    COMPLEX    ADAPTIVE
              |
    +---------+---------+
    | --bench (opcional)|  imprime métricas no stderr
    +-------------------+
```

---

### Fluxo — Simple O(n²)

```
ft_push_swap()
      |
      +--[ já ordenado? ]---> retorna
      |
      +--[ size == 2 ]-------> sa (se necessário) → retorna
      |
      +--[ size == 3 ]-------> ft_sort_three() → retorna
      |
      v
ft_selection_sort_push()
      |
      | enquanto size_a > 3:
      |   ft_find_min_index()
      |   ft_rotate_to_top()    (ra ou rra)
      |   pb()
      v
ft_sort_three()               ordena os 3 restantes em A
      |
      v
pa() repetido                 devolve B para A
```

---

### Fluxo — Medium O(n√n)

```
ft_push_swap_medium()
      |
      v
ft_normalize()                ranks[] : valor → índice 0..n-1
      |
      v
ft_build_map()                rank_map[] : valor ↔ rank (tabela de consulta)
      |
free(ranks)
      |
      v
ft_push_chunks()
      |
      | para cada chunk (√n grupos):
      |   ft_push_one_chunk()
      |     examina A uma vez
      |     se pertence ao chunk e não é top3 → pb()
      |     se rank < mid do chunk            → rb() (heurística)
      |     senão                             → ra()
      v
ft_sort_three()               ordena os 3 maiores que ficaram em A
      |
      v
ft_restore_max()
      |
      | enquanto size_b > 0:
      |   ft_find_max_index_b()
      |   ft_rotate_remaining_b()   (rb ou rrb)
      |   pa()
      v
free(rank_map)
```

---

### Fluxo — Complex O(n log n)

```
ft_push_swap_complex()
      |
      v
ft_normalize()                ranks[] : valor → índice 0..n-1
      |
      v
ft_radix_lsd()
      |
      | substitui A pelos ranks
      |
      | para cada bit b de 0 até n(log(n)):
      |   ft_radix_pass()
      |     percorre A inteiro (size_a + size_b vezes):
      |       bit b do topo == 0 → pb()
      |       bit b do topo == 1 → ra()
      |     devolve tudo de B → pa() repetido
      v
free(ranks)
```

---

### Fluxo — Adaptive

```
ft_push_swap_adaptive()
      |
      | disorder recebido do dispatcher
      |
      +--[ disorder < 0.20 ]---> ft_push_swap()        O(n²)
      |
      +--[ disorder < 0.50 ]---> ft_push_swap_medium()  O(n√n)
      |
      +--[ disorder >= 0.50 ]--> ft_push_swap_complex() O(n log n)
```

---

## Operações disponíveis

| Operação | Descrição |
|---|---|
| `sa` | Troca os 2 primeiros elementos de A |
| `sb` | Troca os 2 primeiros elementos de B |
| `ss` | `sa` e `sb` simultaneamente |
| `pa` | Move o topo de B para o topo de A |
| `pb` | Move o topo de A para o topo de B |
| `ra` | Rotaciona A: o primeiro elemento vai para o final |
| `rb` | Rotaciona B: o primeiro elemento vai para o final |
| `rr` | `ra` e `rb` simultaneamente |
| `rra` | Rotação inversa de A: o último vai para o início |
| `rrb` | Rotação inversa de B: o último vai para o início |
| `rrr` | `rra` e `rrb` simultaneamente |

---

## Instruções

```bash
make
./push_swap 5 3 1 4 2
./push_swap --simple 5 3 1 4 2
./push_swap --medium 5 3 1 4 2
./push_swap --complex 5 3 1 4 2
./push_swap --adaptive 5 3 1 4 2
./push_swap --bench 5 3 1 4 2
```

Também aceita argumentos como string única:

```bash
./push_swap "5 3 1 4 2"
```

---

## Flags disponíveis

| Flag | Descrição |
|---|---|
| `--simple` | Força o algoritmo O(n²) |
| `--medium` | Força o algoritmo O(n√n) |
| `--complex` | Força o algoritmo O(n log n) |
| `--adaptive` | Seleciona automaticamente com base no disorder (padrão) |
| `--bench` | Exibe métricas detalhadas no stderr após a ordenação |
| `--count` | Exibe apenas o total de operações, sem imprimir os movimentos |

---

## Estratégias de ordenação

### 1. Simple — O(n²) — `--simple`

**Algoritmo:** Selection Sort adaptado para pilhas.

**Como funciona:**
A cada passo, encontra o menor elemento de A, rotaciona a pilha até ele ficar no topo e o empurra para B. Quando restam 3 elementos em A, ordena com `sort_three`. Depois devolve tudo de B para A com `pa` repetido.

**Exemplo com `[5, 3, 1, 4, 2]`:**

```
A=[5,3,1,4,2]  B=[]

Menor é 1 (índice 2) → ra ra → A=[1,4,2,5,3]
pb → A=[4,2,5,3]  B=[1]

Menor é 2 (índice 1) → ra → A=[2,5,3,4]
pb → A=[5,3,4]  B=[2,1]

sort_three → A=[3,4,5]

pa → A=[2,3,4,5]
pa → A=[1,2,3,4,5]  ✅
```

**Complexidade:** O(n²) em número de operações Push_swap geradas.

---

### 2. Medium — O(n√n) — `--medium`

**Algoritmo:** Chunk Sort com normalização de ranks.

**Como funciona:**
Primeiro normaliza os valores em ranks consecutivos (0 a n-1). Depois divide os ranks em `√n` grupos (chunks). Para cada chunk, varre A e empurra para B os elementos que pertencem àquele grupo — com um `rb` heurístico para melhorar a distribuição interna. Os 3 maiores ranks ficam em A para o `sort_three`. Depois reconstrói A retirando sempre o maior elemento de B (`ft_restore_max`).

**Exemplo com `[9, 3, 7, 1, 5]` (ranks: `[4,1,3,0,2]`):**

```
√5 ≈ 3 chunks, tamanho 2:
  chunk 0: ranks 0-1 → valores 1, 3
  chunk 1: ranks 2-3 → valores 5, 7
  chunk 2: rank  4   → valor  9  ← fica em A

Após chunks: A=[7,5,9]  B=[3,1,...]
sort_three  → A=[5,7,9]
restore_max → pa(5) pa(3) pa(1) → A=[1,2,3,5,7,9]  ✅
```

**Complexidade:** O(n√n) em número de operações Push_swap geradas.  
*Nota: `ft_normalize` é O(n²) internamente, mas é executada uma única vez e reutilizada por Complex.*

---

### 3. Complex — O(n log n) — `--complex`

**Algoritmo:** Radix Sort LSD (Least Significant Bit) adaptado para pilhas.

**Como funciona:**
Normaliza os valores em ranks (0 a n-1) e substitui os elementos de A pelos seus ranks. Para cada bit `b` de 0 até `ceil(log₂(n))`, percorre A inteiro: se o bit `b` do rank do topo é 0, empurra para B (`pb`); se é 1, rotaciona (`ra`). Ao final de cada passagem, devolve tudo de B para A com `pa`. Após todas as passagens, A está ordenado pelos ranks.

**Exemplo com `[3, 1, 2]` (ranks: `[2, 0, 1]`):**

```
A=[2,0,1]  (ranks após normalize)

Bit 0:
  topo=2 (bin 10), bit0=0 → pb → B=[2]
  topo=0 (bin 00), bit0=0 → pb → B=[0,2]
  topo=1 (bin 01), bit0=1 → ra → A=[1]
  pa pa → A=[1,0,2]  B=[]

Bit 1:
  topo=1 (bin 01), bit1=0 → pb → B=[1]
  topo=0 (bin 00), bit1=0 → pb → B=[0,1]
  topo=2 (bin 10), bit1=1 → ra → A=[2]
  pa pa → A=[0,1,2]  ✅
```

**Complexidade:** O(n log n) em número de operações Push_swap geradas.

---

### 4. Adaptive — baseado em disorder — `--adaptive` (padrão)

**Como funciona:**
Calcula o **disorder** da pilha antes de qualquer movimento — um valor entre 0 e 1 que mede o grau de desordem (razão entre inversões existentes e inversões possíveis). Com base nesse valor, seleciona automaticamente a estratégia mais eficiente:

| Disorder | Estratégia | Complexidade |
|---|---|---|
| < 0.20 | Simple | O(n²) |
| 0.20 – 0.49 | Medium | O(n√n) |
| ≥ 0.50 | Complex | O(n log n) |

**Justificativa dos thresholds:**
- Disorder baixo (< 0.20): a pilha está quase ordenada. Poucas inversões significam que o Simple, mesmo sendo O(n²), gera poucos movimentos na prática.
- Disorder médio (0.20–0.49): o Chunk Sort equilibra bem custo de implementação e número de operações.
- Disorder alto (≥ 0.50): a pilha está muito desordenada. O Radix LSD garante O(n log n) independentemente da distribuição inicial.

---

## Benchmark mode — `--bench`

Quando a flag `--bench` é passada, o programa imprime no stderr após a ordenação:

```
[bench] disorder: 46.66%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 23
[bench] sa: 1  sb: 0  ss: 0  pa: 7  pb: 7
[bench] ra: 0  rb: 0  rr: 0  rra: 4  rrb: 3  rrr: 1
```

---

## Decisões arquiteturais

### Separação de responsabilidades

O projeto segue um princípio consistente: cada arquivo tem uma responsabilidade única e bem definida.

| Camada | Arquivos | Responsabilidade |
|---|---|---|
| Operações | `ft_swap.c`, `ft_push.c`, `ft_rotate.c`, `ft_reverse.c` | Executar e imprimir cada operação |
| Parse | `ft_parse_args.c`, `ft_parse_utils.c`, `ft_parse_flags.c` | Validar entradas e interpretar flags |
| Dispatch | `ft_dispatch.c` | Calcular disorder e despachar para a estratégia correta |
| Estratégias | `ft_push_swap.c`, `ft_push_swap_medium.c`, `ft_push_swap_complex.c`, `ft_push_swap_adaptive.c` | Implementar cada algoritmo |
| Helpers | `ft_normalize.c`, `ft_build_rank_map.c`, `ft_push_chunks.c`, `ft_restore_max.c`, `ft_radix_lsd.c` | Suporte às estratégias |
| Benchmark | `ft_count.c`, `ft_disorder.c`, `ft_bench.c` | Métricas e relatórios |

### `ft_normalize` como componente compartilhado

`ft_normalize` converte valores arbitrários em ranks consecutivos (0 a n-1). Ela é utilizada tanto pelo Medium (via `ft_build_map`) quanto pelo Complex (diretamente pelo Radix). Essa decisão evita duplicação e mantém a função com uma única responsabilidade: produzir uma representação ordinal dos dados.

### `ft_build_map` como componente exclusivo do Medium

`ft_build_map` constrói uma tabela de consulta `valor → rank` (`t_rank_map`). Ela existe exclusivamente para o Medium, que precisa consultar o rank de um valor enquanto A está sendo modificado pelas operações. O Complex não precisa dessa tabela porque opera diretamente sobre os ranks após substituir os valores em A.

### Convenção de memória

Toda função que retorna um ponteiro alocado (`ft_normalize`, `ft_build_map`) transfere a propriedade da memória ao chamador, que é responsável por chamar `free()`. Essa convenção está documentada no código e seguida consistentemente em todas as estratégias.

### Ciclo de vida do `disorder`

O disorder é calculado uma única vez dentro de `ft_dispatch`, antes de qualquer operação de ordenação. Ele é passado como parâmetro para `ft_push_swap_adaptive` e para `ft_print_bench`. Não é armazenado em nenhuma struct — nasce, é usado e morre dentro do dispatcher. Isso mantém `t_flags` representando exclusivamente a configuração do usuário.

---

## Recursos

- [Arquitetura limpa](https://danvitoriano.medium.com/clean-architecture-a35688308e29)
- [Radix Sort explicado](https://en.wikipedia.org/wiki/Radix_sort)
- [Chunk Sort](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [selection sort](https://ww2.inf.ufg.br/~hebert/disc/aed1/AED1_04_ordenacao1.pdf)

### Uso de IA

A IA (Claude, Anthropic) foi utilizada como ferramenta de apoio ao longo do projeto para:
- Discussão e refinamento de decisões arquiteturais
- Revisão de responsabilidades de funções
- Identificação de bugs durante o desenvolvimento
- Geração de trechos de código posteriormente revisados, compreendidos e adaptados pelos estudantes

Todo o código presente no repositório foi compreendido e validado pelos dois estudantes antes de ser incorporado ao projeto.
