#include <iostream>
#include <cstdio>
#include <map>
#include <unordered_map>

using namespace std;
FILE *outFd;

#define MAX_CLIENTS 100000
#define MAX_MSG_PER_CLIENT 100

// This function is used to send a message to a client.
// params:
//  clientId - client identifier
//  msgId - message identifier
//  msgAge - message Age
//  more - true if more messages are to be sent to the client as part of
//         processing the current command.
void sendMessage(int clientId, int msgId, int msgAge, bool more) {
    fprintf(outFd, "(%d, %d, %d)%c", clientId, msgId, msgAge, more?' ':'\n');
}

// hold client registration, clientID => window_size
map<int, int> active_clients;
// This function is called on "register-client" input.
void registerClient(int clientId, int window) {
    int size = active_clients.size();
    if (size >= MAX_CLIENTS) {
        // max clients limit reached
        cout << "Server can support upto " << MAX_CLIENTS << "clients, active clients are " << size << endl;
        return;
    }
    auto itr = active_clients.find(clientId);
    if (itr == active_clients.end()) {
        // add new client with window size
        active_clients[clientId] = window;
        cout << "Registering a new client with id " << clientId << endl;
    } else {
        // client is already registered, so ignore..
    }
}

// This function is called on "new-message" input.
// Use the provided sendMessage() function to send a message to the client.  The
// `more` argument to sendMessage should be false when called from this
// function.

// store message into the 
// map< clientID, <msgId, msgAge> > message_queue;
map< int, map<int, int> > msg_queue;
void newMessage(int clientId, int msgId, int msgAge) {
    // check if client is registerd or not
    auto itr = active_clients.find(clientId);
    if (itr == active_clients.end()){
        cout << "Client with id " << clientId << " is not registered!" << endl;
        return;
    }
    
    // if window is available, send the message 
    if (active_clients[clientId] > 0) {
        sendMessage(clientId, msgId, msgAge, false);
        active_clients[clientId]--;
    } else {
        // window is not available so queue the message
        auto itr = msg_queue.find(clientId);
        if (itr == msg_queue.end()) {
            // no messages into queue so far, so add queue the current message
            msg_queue[clientId].insert(pair<int, int>(msgId, msgAge));
        } else {
            // queue already has some messages, so add new message based on age
            auto itr = msg_queue.find(clientId);
        }
    }
}

// This function is called on "adjust-window" input.
// Use the provided sendMessage() function to send a message to the client.
// If multiple messages have to be sent due to message window adjustment, the
// `more` argument to sendMessage() should be false for the last message (and
// true for all others).
void adjustWindow(int clientId, int windowSize) {
    // Implement this
}

int main() {
    string cmd;
    int clientId, window, msgId, msgAge;
    outFd = fopen("output.txt", "w");
    int i = 0;
    while (true) {
        cin >> cmd;
        if (cmd == "register-client") {
            cin >> clientId >> window;
            registerClient(clientId, window);
        } else if (cmd == "new-message") {
            cin >> clientId >> msgId >> msgAge;
            newMessage(clientId, msgId, msgAge);
        } else if (cmd == "adjust-window") {
            cin >> clientId >> window;
            adjustWindow(clientId, window);
        } else if (cmd == "exit") {
            break;
        }
    }
    return 0;
}
