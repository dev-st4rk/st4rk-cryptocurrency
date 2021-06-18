/*
    Project name: Stark Cryptocurrency 
    File name:    main.cpp
    Created by Henrique Gonçalves Lourenço Silva on 14/06/21.
*/
#include <iostream>
#include <ctime>
#include <vector>
#include "TransactionData.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"

using namespace std;

int main() {
  //======================== START BLOCKCHAIN ==================================
  Blockchain stark_coin;

  //====================== DATA FOR FIRST BLOCK ================================
  time_t data1Time;
  TransactionData data1(1.5, "Henrique", "Ricardo", time( & data1Time));
  stark_coin.addBlock(data1);

  time_t data2Time;
  TransactionData data2(0.2233, "Gláucia", "Wladimir", time( & data2Time));
  stark_coin.addBlock(data2);

  stark_coin.printChain();

  printf("\nIs chain still valid? %d\n", stark_coin.bl_chain_valid());

  Block * hackBlock = stark_coin.get_latest_block();
  hackBlock -> data.vl_amount = 10000;
  hackBlock -> data.receiver_key = "João";

  stark_coin.printChain();

  printf("\nIs chain still valid? %d\n", stark_coin.bl_chain_valid());

  return 0;
}