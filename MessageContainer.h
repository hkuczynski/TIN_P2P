//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_MESSAGECONTAINER_H
#define TIN_P2P_MESSAGECONTAINER_H


#include "Message.h"

class MessageContainer {

    Message get();

    void put(Message msg);
};


#endif //TIN_P2P_MESSAGECONTAINER_H
