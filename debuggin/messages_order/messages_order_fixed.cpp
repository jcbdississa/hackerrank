//source : https://www.hackerrank.com/challenges/messages-order/problem?isFullScreen=true
/*
TODO:
    1- Add a software layer over the top of a network protocol to preserve order
        1.1 - Implement class Message with the following specs
            - a variable of type string
            - a getter to access to previous variable
            - overload the < operator inside the method fix_order that maintain message ordering
            - add anything other (class, methods, ...) even additional constructor, but make sure 
              to provide an empty constructor
        1.2 - Implement class MessageFactory with the following specs
            - must have an empty constructor
            - implement a method Message create_message(const string& text) that return its argument
              text as a Message object
            - add anything other (class, methods, ...)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
    public: 
    static int number_of_messages_;

    Message() {}
    Message(const string& text) {
        message_text_ = text;
        number_of_messages_++;
        message_index_ = number_of_messages_;
    }
    const string& get_text() {
        return message_text_;
    }
    const int& get_index() {
        return message_index_;
    }
    bool operator<(Message message_1) {
         return this->message_index_ < message_1.get_index();
    }
private:
    string message_text_;
    int message_index_;
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text);
    }
};

int Message::number_of_messages_ = 0;

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}