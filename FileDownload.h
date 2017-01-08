//
// Created by hubert on 08.01.17.
//

#ifndef TIN_P2P_FILEDOWNLOAD_H
#define TIN_P2P_FILEDOWNLOAD_H

#include <queue>
#include "File.h"

class FileDownload : public File {

public:

    FileDownload(string name, unsigned int size);

    long getPartToDownload();

    void addPartToDownload(long);

    unsigned long partsLeftCount();

private:
    queue<long> partsLeft;
};


#endif //TIN_P2P_FILEDOWNLOAD_H
