//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_MESSAGECONTAINER_H
#define TIN_P2P_MESSAGECONTAINER_H

#include "Message.h"
#include <queue>
using namespace std;

class MessageContainer {

public:

    MessageContainer();

    Message get();

    void put(Message msg);

private:
    queue<Message> messagesQueue;

};


#endif //TIN_P2P_MESSAGECONTAINER_H
