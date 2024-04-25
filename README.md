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

the game seems playble in most of cases , the check features may not finished
at 100% (may need little tweaks)
checkmate is ok.

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

### nice features

-save and load games,
-parse into FNE for more portability,

## boting

### first goal

just make a boat with random moves

### second goal

a bot with minimal heuristic not tree

### third goal

a bot with minimal heuristic , tree

### add prom moves for futur bots
need to add promotion move for bots
