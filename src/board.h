
#include "bitboard.h"
#include <cassert>
#include <cstdint>
#include <iostream>

struct State {
  bool whiteCastleLS[2];
  bool blackCastleLS[2];
  bool turn;
  int enpassantSquare;
};

class Board {

private:
  State state;
  int board[64] = {0};
  Bitboard Bitboards[12];

  Bitboard totalOccupancy;
  Bitboard whiteOccupancy;
  Bitboard blackOccupancy;
  Bitboard emptyOccupancy;

public:
  // void initZobristKey();
  void initBoard();
  void resetBoard();
  void printBoard() const;

  void putPiece(int from, int to);
  void removePiece(int from);
  void makeMove(int from, int to);
  void unmakeMove(int from, int to);
  bool checkLegal(int from, int to) const;
  void changeTurn();

  void updateTotalOccupancy();
  void updateWhiteOccupancy();
  void updateBlackOccupancy();
  void updateEmptyOccupancy();

  Bitboard getTotalOccupancy() const;
  Bitboard getWhiteOccupancy() const;
  Bitboard getBlackOccupancy() const;
  Bitboard getEmptyOccupancy() const;

  int fileOf(int square) const;
  int rankOf(int square) const;


};
