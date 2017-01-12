//
// Created by lukasz on 07.01.17.
//

#ifndef TIN_P2P_TCPMANAGER_H
#define TIN_P2P_TCPMANAGER_H
#include "Connection.h"
#include "FileManager.h"
#include "FileInfoContainer.h"
#include "MessageContainer.h"
#include "LogContainer.h"

/**
 * Klasa zarzadzajaca polczeniami TCP.
 * Tworzy watek sluchacza TCP, ktory akceptuje polaczenia.
 * Tworzy watki zarzadcy pobierania (DownloadHandler).
 */
class TCPManager {

public:
    TCPManager(FileManager*, FileInfoContainer*, bool*, MessageContainer*, LogContainer*);
    ~TCPManager();
    void recieveFile(struct FileInfo*); /*Pobieranie pliku*/
    void sendMyList(string hostName);
    void sendVeto(string host, string fname, unsigned long fsize);
    void test(){
        FileInfo f2("testFile",10232,false,false);
        f2.hostAddress="192.168.0.98";
//        fileInfoContainer->put(f2);
        FileInfo f("testFile",10232,false,false);
        f.hostAddress="192.168.0.10";
        fileInfoContainer->put(f);
        recieveFile(&f2);
    }


private:
    FileManager *fileManager;
    FileInfoContainer *fileInfoContainer;
    MessageContainer* inputMessages;
    LogContainer *logContainer;
    vector<Connection*> connList;
    std::thread id;
    Socket *listenerSocket;
    bool *exitFlag;

    void connectionAccepter();


};


#endif //TIN_P2P_TCPMANAGER_H
