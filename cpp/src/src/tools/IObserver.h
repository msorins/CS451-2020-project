#include <string>

#ifndef I_OBSERVER
#define I_OBSERVER

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void Update(const std::string &message_from_subject) = 0;
};

#endif