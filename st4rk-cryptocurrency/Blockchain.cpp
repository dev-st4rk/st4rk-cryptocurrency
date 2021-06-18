/*
    Project name: Stark Cryptocurrency 
    File name:    Blockchain.cpp
    Created by Henrique Gonçalves Lourenço Silva on 14/06/21.
*/
#include <stdio.h>
#include <ctime>
#include <string>
#include "Block.hpp"
#include "Blockchain.hpp"
#include <vector>

//================================= BLOCKCHAIN CONSTRUCTOR ====================================
Blockchain::Blockchain() {
  Block genesis = create_genesis_block();
  chain.push_back(genesis);
}

//================================= PUBLIC CHAIN GETTER =======================================
std::vector < Block > Blockchain::get_chain() {
  return chain;
}

//================================= CREATE THE GENESIS BLOCK ===================================
Block Blockchain::create_genesis_block() {
  //================================= GET CURRENT TIME =======================================
  std::time_t current;

  //======================== SETUP INITIAL TRANSACTION DATA ==================================
  TransactionData d(0, "Genesis", "Genesis", time( & current));

  //============================= RETURN GENESIS BLOCK =======================================
  Block genesis(0, d, 0);
  return genesis;
}

// The pointer is to demonstrate manipulation of transaction data
Block * Blockchain::get_latest_block() {
  return &chain.back();
}

void Blockchain::addBlock(TransactionData d) {
  int index = (int) chain.size();
  std::size_t previous_hash = (int) chain.size() > 0 ? get_latest_block() -> get_hash() : 0;
  Block newBlock(index, d, previous_hash);
  chain.push_back(newBlock);
}

bool Blockchain::bl_chain_valid() {
  std::vector < Block > ::iterator it;

  for (it = chain.begin(); it != chain.end(); ++it) {
    Block current_block = * it;
    if (!current_block.bl_hash_valid()) {
      return false;
    }

    // Check if this is the first item
    if (it != chain.begin()) {
      Block previous_block = * (it - 1);
      if (current_block.get_previous_hash() != previous_block.get_hash()) {
        return false;
      }
    }
  }

  return true;
}

void Blockchain::printChain() {
  std::vector < Block > ::iterator it;

  for (it = chain.begin(); it != chain.end(); ++it) {
    Block current_block = * it;
    printf("\n\n =================== BLOCK ====================");
    printf("\nIndex: %d", current_block.get_index());
    printf("\nAmount: %f", current_block.data.vl_amount);
    printf("\nSender: %s", current_block.data.sender_key.c_str());
    printf("\nReceiver: %s", current_block.data.receiver_key.c_str());
    printf("\nTimestamp: %ld", current_block.data.timestamp);
    printf("\nHash: %zu", current_block.get_hash());
    printf("\nPrevious Hash: %zu", current_block.get_previous_hash());
    printf("\nIs Block Valid?: %d", current_block.bl_hash_valid());
  }
}
