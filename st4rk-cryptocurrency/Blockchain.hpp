/*
    Project name: Stark Cryptocurrency 
    File name:    Blockchain.hpp
    Created by Henrique Gonçalves Lourenço Silva on 14/06/21.
*/

#ifndef Blockchain_h
#define Blockchain_h
#include <vector>

//======================== BLOCKCHAIN CLASS ==================================
class Blockchain {
  private:
    Block create_genesis_block();
  std::vector < Block > chain;

  public:
    //======================== CONSTRUCTOR ==================================
    Blockchain();

  //======================== PUBLIC FUNCTIONS ==================================
  std::vector < Block > get_chain();
  Block * get_latest_block();
  bool bl_chain_valid();
  void addBlock(TransactionData data);
  void printChain();
};

#endif /* Blockchain_h */