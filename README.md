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
the column or row is specify in the notation which not implemented now

### draw
check about stalemate , 50 rule etc

may keep track of the game with a manager to do all the dirty work

### nice features

-save and load games,
-parse into FNE for more portability,

## boting

### first goal

just make a bot with random moves
bearly work ~ named *jeff*

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
