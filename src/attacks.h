#include "board.h"
#include <array>
#include <cmath>
// attacchi cavallo generati a compile time
constexpr bool knightMoves(int from, int to) {
  if (from == to)
    return false;
  int diffFile = fileOf(from) - fileOf(to);
  int diffRank = rankOf(from) - rankOf(to);
  if (diffFile < 0)
    diffFile = -diffFile;
  if (diffRank < 0)
    diffRank = -diffRank;
  return (diffFile == 1 && diffRank == 2) || (diffFile == 2 && diffRank == 1);
}

constexpr bool kingMoves(int from, int to) {
  if (from == to)
    return false;
  int diffFile = fileOf(from) - fileOf(to);
  int diffRank = rankOf(from) - rankOf(to);
  if (diffFile < 0)
    diffFile = -diffFile;
  if (diffRank < 0)
    diffRank = -diffRank;
  return (diffFile <= 1 && diffRank <= 1);
}
constexpr bool blackPawnMoves(int from, int to) {
  if (from == to)
    return false;
  int diffFile = fileOf(from) - fileOf(to);
  int diffRank = rankOf(from) - rankOf(to);
  if (diffFile < 0)
    diffFile = -diffFile;
  return (diffFile == 1 && diffRank == 1);
}
constexpr bool whitePawnMoves(int from, int to) {
  if (from == to)
    return false;
  int diffFile = fileOf(from) - fileOf(to);
  int diffRank = rankOf(from) - rankOf(to);
  if (diffFile < 0)
    diffFile = -diffFile;
  return (diffFile == 1 && diffRank == -1);
}
constexpr std::array<Bitboard, 64> knightTable() {
  std::array<Bitboard, 64> attacks{};
  for (int from = 0; from < 64; from++) {
    for (int to = 0; to < 64; to++) {
      if (knightMoves(from, to)) {
        attacks[from] |= (1ULL << to);
      }
    }
  }

  return attacks;
}
constexpr std::array<Bitboard, 64> kingTable() {
  std::array<Bitboard, 64> attacks{};
  for (int from = 0; from < 64; from++) {
    for (int to = 0; to < 64; to++) {
      if (kingMoves(from, to)) {
        attacks[from] |= (1ULL << to);
      }
    }
  }
  return attacks;
}
constexpr std::array<Bitboard, 64> blackPawnTable() {
  std::array<Bitboard, 64> attacks{};
  for (int from = 0; from < 64; from++) {
    for (int to = 0; to < 64; to++) {
      if (blackPawnMoves(from, to)) {
        attacks[from] |= (1ULL << to);
      }
    }
  }
  return attacks;
}
constexpr std::array<Bitboard, 64> whitePawnTable() {
  std::array<Bitboard, 64> attacks{};
  for (int from = 0; from < 64; from++) {
    for (int to = 0; to < 64; to++) {
      if (whitePawnMoves(from, to)) {
        attacks[from] |= (1ULL << to);
      }
    }
  }
  return attacks;
}

constexpr auto kingAttacks = kingTable();
constexpr auto knightAttacks = knightTable();
constexpr auto blackPawnAttacks = blackPawnTable();
constexpr auto whitePawnAttacks = whitePawnTable();
