chess:
	g++ src/chess.cc src/game/board/board.cc src/game/game/game.cc src/game/player/player.cc src/game/piece/piece.cc src/game/piece/knight.cc src/game/piece/bishop.cc src/game/piece/rook.cc src/game/piece/pawn.cc src/game/piece/kig.cc src/game/piece/queen.cc  src/bot/bot.cc src/game/board/move.cc src/node/node.cc -g -o chess
