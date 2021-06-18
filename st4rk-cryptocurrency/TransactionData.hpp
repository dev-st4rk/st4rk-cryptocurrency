/*
    Project name: Stark Cryptocurrency 
    File name:    TransactionData.hpp
    Created by Henrique Gonçalves Lourenço Silva on 14/06/21.
*/

#ifndef TransactionData_h
#define TransactionData_h

struct TransactionData {
  float vl_amount;
  std::string sender_key;
  std::string receiver_key;
  time_t timestamp;

  TransactionData() {};

  TransactionData(float amt, std::string sender, std::string receiver, time_t time) {
    vl_amount = amt;
    sender_key = sender;
    receiver_key = receiver;
    timestamp = time;
  };
};

#endif /* TransactionData_h */