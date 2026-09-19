#include <cstdint>

struct State {
  uint64_t Zobrist;
};
class Board {
private:
  State state;
  int board[64];
  uint64_t Bitboard[13];
  enum pieces {
    EMPTY = 0,
    W_PAWN,
    W_BISHOP,
    W_KNIGHT,
    W_ROOK,
    W_QUEEN,
    W_KING,
    B_PAWN,
    B_BISHOP,
    B_KNIGHT,
    B_ROOK,
    B_QUEEN,
    B_KING,
  };

public:
  void printBoard();

  void putPiece(int from, int to);
  void removePiece(int from, int to);
  void makeMove(int from, int to);
  void unmakeMove(int from, int to);
  bool checkLegal(int from, int to);
  bool changeTurn();
};
