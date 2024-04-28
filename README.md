# Chess

My goal is to make a chess game in cpp.

after this task done , i would like to make a bot ,

-A classic minmax algoritm with a classic heuristic

-next a RN full-connected,
mostly 64-40-20-10-1
    input: board , heuristic
    output: -n < heuristic < n

## RUN

make -B && ./chess

## NOTATION

pawn:

    [letter][number]
    ex: e4
    [letter][number][=][FIGURE]
    ex: e8=Q

figures:

    King : K
    Queen : Q
    Knight : N
    Bishop : B
    Rook : R

    [FIGURE][letter][number]
    ex:
    Nf6
    Re4
    Kb4

castling:

    little roc:
        0-0
        or
        O-O
    big roc:
        0-0-0
        or
        O-O-O

ambiguous moves:

    [FIGURES][spec][letter][number]
    ex:
    Reb6
    R3b6

    [spec][letter][number]
    ex:
    cd5
    be3

## description of the current version


The game of chess is fully implemented.

Need more tests to be sure everything right !

> [!CAUTION]
> A move that not follow the notation is a undefined behavior and will mostly output a non-valid move

if the game end by a fifty rule , the list of moves is printed.

## FUTURE FEATURES ?

- save and load games,

- parse into FNE for more portability,

- add some parameter for a better UX

- should more use the new class "game::Move" , to simplify code and avoid bugs !

- a front end in a local server in a web page

- an OCR for parse a image in a game

## BOTING

### current goal

A bot with minimal heuristic
link a value to a moves and select the best
named *victor* (or *vivi* for black)

> [!NOTE]
> bot available , working in progress ~ 600 elo lol

### Next goal

a bot with  heuristic,
expand the second in a tree with minmax and alphabeta!
named *no_name_for_now*

### add prom moves for futur bots

need to add promotion move for bots

> [!TIP]
> auto-promotion in Queen for now

# game's behavior exemple:

> [!TIP]
> You now can select who play vs who (player and bot)

> [!NOTE]
> if you select '4' (bot vs bot) , you become spectator of two bot playing randomly

```
  -white--|--black-
1. player vs player
2. player vs bot
3. bot    vs player
4. bot    vs bot

mode: 1

white name: dolvui

black name: not_dolvui

8;|r||n||b||q||k||b||n||r|
7;|p||p||p||p||p||p||p||p|
6;| || || || || || || || |
5;| || || || || || || || |
4;| || || || || || || || |
3;| || || || || || || || |
2;|P||P||P||P||P||P||P||P|
1;|R||N||B||Q||K||B||N||R|
  ------------------------
  |a||b||c||d||e||f||g||h|
you got 20 legal moves, use it with wisdom ..


 dolvui with the white pieces to move: e4

8;|r||n||b||q||k||b||n||r|
7;|p||p||p||p||p||p||p||p|
6;| || || || || || || || |
5;| || || || || || || || |
4;| || || || ||P|| || || |
3;| || || || || || || || |
2;|P||P||P||P|| ||P||P||P|
1;|R||N||B||Q||K||B||N||R|
  ------------------------
  |a||b||c||d||e||f||g||h|
you got 20 legal moves, use it with wisdom ..


 not_dolvui with the black pieces to move: e5

8;|r||n||b||q||k||b||n||r|
7;|p||p||p||p|| ||p||p||p|
6;| || || || || || || || |
5;| || || || ||p|| || || |
4;| || || || ||P|| || || |
3;| || || || || || || || |
2;|P||P||P||P|| ||P||P||P|
1;|R||N||B||Q||K||B||N||R|
  ------------------------
  |a||b||c||d||e||f||g||h|
you got 29 legal moves, use it with wisdom ..


 dolvui with the white pieces to move: Bb5

8;|r||n||b||q||k||b||n||r|
7;|p||p||p||p|| ||p||p||p|
6;| || || || || || || || |
5;| ||B|| || ||p|| || || |
4;| || || || ||P|| || || |
3;| || || || || || || || |
2;|P||P||P||P|| ||P||P||P|
1;|R||N||B||Q||K|| ||N||R|
  ------------------------
  |a||b||c||d||e||f||g||h|
you got 26 legal moves, use it with wisdom ..


 not_dolvui with the black pieces to move: Nc6

8;|r|| ||b||q||k||b||n||r|
7;|p||p||p||p|| ||p||p||p|
6;| || ||n|| || || || || |
5;| ||B|| || ||p|| || || |
4;| || || || ||P|| || || |
3;| || || || || || || || |
2;|P||P||P||P|| ||P||P||P|
1;|R||N||B||Q||K|| ||N||R|
  ------------------------
  |a||b||c||d||e||f||g||h|
you got 32 legal moves, use it with wisdom ..


 dolvui with the white pieces to move: Qf3

8;|r|| ||b||q||k||b||n||r|
7;|p||p||p||p|| ||p||p||p|
6;| || ||n|| || || || || |
5;| ||B|| || ||p|| || || |
4;| || || || ||P|| || || |
3;| || || || || ||Q|| || |
2;|P||P||P||P|| ||P||P||P|
1;|R||N||B|| ||K|| ||N||R|
  ------------------------
  |a||b||c||d||e||f||g||h|
you got 30 legal moves, use it with wisdom ..


 not_dolvui with the black pieces to move: Na5

8;|r|| ||b||q||k||b||n||r|
7;|p||p||p||p|| ||p||p||p|
6;| || || || || || || || |
5;|n||B|| || ||p|| || || |
4;| || || || ||P|| || || |
3;| || || || || ||Q|| || |
2;|P||P||P||P|| ||P||P||P|
1;|R||N||B|| ||K|| ||N||R|
  ------------------------
  |a||b||c||d||e||f||g||h|
you got 42 legal moves, use it with wisdom ..


 dolvui with the white pieces to move: Qf7

8;|r|| ||b||q||k||b||n||r|
7;|p||p||p||p|| ||Q||p||p|
6;| || || || || || || || |
5;|n||B|| || ||p|| || || |
4;| || || || ||P|| || || |
3;| || || || || || || || |
2;|P||P||P||P|| ||P||P||P|
1;|R||N||B|| ||K|| ||N||R|
  ------------------------
  |a||b||c||d||e||f||g||h|
you got 0 legal moves, use it with wisdom ..

 no legal moves


 dolvui win by checkmate


 not_dolvui was defeated ;(


 End of the game
```

# Complexity

here some points :
```
x in nb of games
y in milliseconds

(1,70)
(10,645)
(300,19197)
(600,32350)
(1000,58446)
(1800,83499)
(2000,102078)
(2500,141559)
(5000,277788)
(10000,541299)
(50000,2695755)

test with print enable ,

aproximation with a linar function:

O(x) =~ 54x + 462
```

![screenshot](https://github.com/dolvui/Chess/blob/main/plot_complexity.png)
