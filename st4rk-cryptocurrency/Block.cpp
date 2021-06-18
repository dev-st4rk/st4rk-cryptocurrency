/*
    Project name: Stark Cryptocurrency 
    File name:    Block.cpp
    Created by Henrique Gonçalves Lourenço Silva on 14/06/21.
*/
#include <stdio.h>
#include <string>
#include "Block.hpp"
#include "TransactionData.hpp"

//===================== CONSTRUCTOR WITH PARAMS ================================
Block::Block(int idx, TransactionData d, size_t cd_prev_hash) {
  index = idx;
  data = d;
  previous_hash = cd_prev_hash;
  block_hash = generate_hash();
}

//======================== PRIVATE FUNCTIONS ==================================
int Block::get_index() {
  return index;
}

// Includes previous_hash in generation for the process of generating a hash for the current block

size_t Block::generate_hash() {
  // String for transaction data created
  std::string toHashS = std::to_string(data.vl_amount) + data.receiver_key + data.sender_key + std::to_string(data.timestamp);

  // Combine 2 hashs
  std::hash < std::string > transaction_data_hash; // hashes transaction data string
  std::hash < std::string > cd_prev_hash; // re-hashes previous hash (for combination)

  // Combine hahshes and get the size_t, for block hash
  return transaction_data_hash(toHashS) ^ (cd_prev_hash(std::to_string(previous_hash)) << 1);
}

//======================== PUBLIC FUNCTIONS ==================================
size_t Block::get_hash() {
  return block_hash;
}

size_t Block::get_previous_hash() {
  return previous_hash;
}

bool Block::bl_hash_valid() {
  return generate_hash() == get_hash();
}