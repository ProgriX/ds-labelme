#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <chrono>

#include <netinet/in.h>

#include "../ds_base/deepstream_app.h"
#include "../logger.h"

struct BBbox
{
    float left, top, width, height, confidence;
    uint64_t id;
    std::string label;
};

struct RecvestResult{
    bool success;
    std::string message;
};

class Client{

public:
    
    enum class State{ disconnected, connected, sending, receiving };
    
    Client(const NvDsSocket& params);
    ~Client();

    State getState();

    void connectToHost();

    void blockingMode();
    void streamMode();
    RecvestResult recvest();

    void addMeta(std::string key);
    void addMeta(std::string key, std::string value);
    void addMeta(std::string key, int64_t value);
    void addMeta(std::string key, uint64_t value);
    void addMetaTime(std::string key, uint64_t value);
    void addBBox(const BBbox& box);

    void sendRaw(std::string message);
    void reconnect();
    void checkSendHangUp();

    void sendMessage();
    void breakConnection();

private:

    void connectionLost();

    std::string _ip;
    int _port;
    std::string _name;
    Logger log;
    State _state;

    int _socket;
    sockaddr_in _host;
    int _flags;
    std::chrono::steady_clock::time_point _lastConnectTime;
};




#endif