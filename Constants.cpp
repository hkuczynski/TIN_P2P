//
// Created by lukasz on 06.01.17.
//

#include "Constants.h"

namespace Constants {
    namespace JsonKeys {
        const char* type = "type";
        const char* hostName = "hostName";
        const char* fileName = "fileName";
        const char* fileSize = "fileSize";
        const char* offset = "offset";
    }

    namespace MessageTypes {
        const char* hello = "Hello";
        const char* requestFile = "RequestFile";
        const char* requestList = "RequestList";
        const char* newFile = "NewFile";
        const char* veto = "Veto";
        const char* deleteFile = "Delete";
    }

    namespace File {
        const unsigned int partSize = 256;
    }
}