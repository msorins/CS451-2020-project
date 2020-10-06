#include <iostream>
#include <list>
#include <string>

#include "IObserver.h"
#include "Subject.h"

#ifndef OBSERVER_DEF
#define OBSERVER_DEF

class Observer : public IObserver
{
public:
    Observer(Subject &subject) : subject_(subject)
    {
        this->subject_.Attach(this);
        std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
        this->number_ = Observer::static_number_;
    }
    virtual ~Observer()
    {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Update(const std::string &message_from_subject) override
    {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList()
    {
        subject_.Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo()
    {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    Subject &subject_;
    static int static_number_;
    int number_;
};

int Observer::static_number_ = 0;

#endif
