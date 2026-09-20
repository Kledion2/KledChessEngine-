#include "board.h"

int Board::rankOf(int square) const {
  assert(square >= 0 && square < 64);
  return square / 8;
}
int Board::fileOf(int square) const {
  assert(square >= 0 && square < 64);
  return square % 8;
}
bool Board::colorOf(int square) const {
  assert(square >= 0 && square < 12);
  return (board[square] <= 6) ? WHITE : BLACK;
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
void Board::putPiece(int from, int to) {
  assert(from >= 0 && from < 64 && to >= 0 && to < 64);
  Bitboards[board[from]] |= square_bb(to);
  board[to] = board[from];
}
void Board::makeMove(int from, int to) {
  if (checkLegal(from, to)) {
    putPiece(from, to);
    removePiece(from);
  }
}
bool Board::checkLegal(int from, int to) const {
  return false;
  return true;
}
