#include <cstdint>

using Bitboard = uint64_t;

enum Colors {
  WHITE=0,
  BLACK=1,
};

enum Pieces {
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
