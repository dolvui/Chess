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
    [letter][number][=][PROM]
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

## description of the current version

### classic moves

classic game of chess ,
boting on the way
some feature still missing
not a big deal tho

## future features

### specify move

when 2 pieces can make the same move,
for instance , two rook can move at the same square,
a move like :
    Rb4
become:
    Rbeb4 or R3b4

> [!WARNING]
> The column or row is specify in the notation which not implemented now

> [!WARNING]
> The pawn cannot check for now

> [!WARNING]
> En passant not implement for now


### draw
check about stalemate , 50 rule etc

may keep track of the game with a manager to do all the dirty work

### nice features

-save and load games,
-parse into FNE for more portability,

## boting

### first goal

just make a bot with random moves
> [!NOTE]
> bearly work ~ he can caslte !
named *jeff*

### second goal

a bot with minimal heuristic
link a value to a moves and select the best
named *victor*

### third goal

a bot with minimal heuristic,
expand the second in a tree!
named *no_name_for_now*

### add prom moves for futur bots

need to add promotion move for bots

# game's behavior exemple:

> [!IMPORTANT]
> right now the game is played white_player vs black_bot

```
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
