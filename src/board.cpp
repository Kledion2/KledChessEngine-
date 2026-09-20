#include "board.h"

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
  const Bitboard sqBB = square_bb(from);
  Bitboards[board[from]] &= ~sqBB;
  bool color = colorOf(board[from]);
  if (!color) {
    whiteOccupancy &= ~sqBB;
  } else {
    blackOccupancy &= ~sqBB;
  }
  totalOccupancy &= ~sqBB;
  board[from] = 0;
  return;
}


void Board::putPiece(int from, int to) {

  assert(from >= 0 && from < 64 && to >= 0 && to < 64);

  const Bitboard sqBB = square_bb(to);

  bool colorFrom = colorOf(board[from]);
  if (colorFrom == WHITE) {
    blackOccupancy &= ~sqBB;
    whiteOccupancy |= sqBB;
  } else {
    whiteOccupancy &= ~sqBB;
    blackOccupancy |= sqBB;
  }

  Bitboards[board[from]] |= sqBB;
  if (board[to] != 0) {
    Bitboards[board[to]] &= ~sqBB;
  }
  board[to] = board[from];
  return;
}


void Board::makeMove(int from, int to) {
  if (checkLegal(from, to)) {
    putPiece(from, to);
    removePiece(from);
    return;
  }
  return;
}


bool Board::checkLegal(int from, int to) const {

}
