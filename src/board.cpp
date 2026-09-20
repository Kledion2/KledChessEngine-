#include "board.h"

int Board::rankOf(int square) const {
  assert(square >= 0 && square < 64);
  return square / 8;
}
int Board::fileOf(int square) const {
  assert(square >= 0 && square < 64);
  return square % 8;
}

void Board::printBoard() const {
  for (int rank = 7; rank >= 0; rank--) {
    std::cout << "\n";
    for (int file = 0; file <= 7; file++) {
      std::cout << " " << board[8 * rank + file] << " ";
    }
  }
}
void Board::updateTotalOccupancy() {
  totalOccupancy = whiteOccupancy | blackOccupancy;
  return;
}
void Board::changeTurn() { state.turn ^= 1; }

Bitboard Board::getTotalOccupancy() const { return totalOccupancy; }
Bitboard Board::getWhiteOccupancy() const { return whiteOccupancy; }
Bitboard Board::getBlackOccupancy() const { return blackOccupancy; }
Bitboard Board::getEmptyOccupancy() const { return ~totalOccupancy; }

void Board::removePiece(int from) {
  assert(from >= 0 && from < 64 && board[from] != 0);
  Bitboards[board[from]] &= ~square_bb(from);
  board[from] = 0;
  return;
}
void putPiece(int from, int to) {}
