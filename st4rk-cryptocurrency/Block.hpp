/*
    Project name: Stark Cryptocurrency 
    File name:    Block.hpp
    Created by Henrique Gonçalves Lourenço Silva on 14/06/21.
*/

#ifndef Block_h
#define Block_h
#include "TransactionData.hpp"

//================================= BLOCK CLASS =======================================
class Block {
  private:
    int index;
  size_t block_hash;
  size_t previous_hash;
  size_t generate_hash();

  public:
    //================================= CONSTRUCTOR =======================================
    Block(int idx, TransactionData d, size_t cd_prev_hash);

  //================================== GET INDEX  =======================================
  int get_index();

  //=============================== GET ORIGINAL HASH ===================================
  size_t get_hash();

  //=============================== GET PREVIOUS HASH ===================================
  size_t get_previous_hash();

  //=============================== TRANSACTION DATA ====================================
  TransactionData data;

  //================================= VALIDATE HASH  ====================================
  bool bl_hash_valid();
};

#endif /* Block_h */