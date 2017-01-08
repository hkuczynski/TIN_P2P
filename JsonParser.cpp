//
// Created by hubert on 05.01.17.
//

#include "JsonParser.h"
#include "Exceptions.h"

using namespace std;

Message* JsonParser::parse(string jsonMessage) {
    Message *messageToReturn;
    Json::Value parsedJson;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(jsonMessage, parsedJson);
    if (parsingSuccessful)
    {
        Json::Value messageTypeVal = parsedJson[Constants::JsonKeys::type];
        const char* messageType = messageTypeVal.asCString();

        if (strcmp(messageType, Constants::MessageTypes::hello) == 0) {
            // hello, is it me you loking for?
            messageToReturn = new MessageHello();
        } else if (strcmp(messageType, Constants::MessageTypes::requestFile) == 0) {
            string hostName2 = parsedJson[Constants::JsonKeys::hostName].asString();
            string fileName = parsedJson[Constants::JsonKeys::fileName].asString();
            unsigned int fileSize = parsedJson[Constants::JsonKeys::fileSize].asUInt();
            unsigned int offset = parsedJson[Constants::JsonKeys::offset].asUInt();
            messageToReturn = new MessageRequestFile(hostName2, fileName, fileSize, offset);
        } else if (strcmp(messageType, Constants::MessageTypes::requestList) == 0) {

        } else if (strcmp(messageType, Constants::MessageTypes::newFile) == 0) {

        } else if (strcmp(messageType, Constants::MessageTypes::veto) == 0) {

        } else if (strcmp(messageType, Constants::MessageTypes::deleteFile) == 0) {

        } else {
            throw UnknownMessageException();
        }

    } else {
        throw JsonParsingException();
    }

    return messageToReturn;
}