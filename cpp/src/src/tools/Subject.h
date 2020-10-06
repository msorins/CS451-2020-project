#include <iostream>
#include <list>
#include <string>
#include "ISubject.h"
#include "IObserver.h"
#include "../sockets/Data.h"

#ifndef SUBJECT_DEF
#define SUBJECT_DEF

namespace da
{
    namespace tools
    {
        class Subject : public ISubject
        {
        public:
            virtual ~Subject()
            {
                std::cout << "Goodbye, I was the Subject.\n";
            }

            /**
   * The subscription management methods.
   */
            void Attach(IObserver *observer) override
            {
                list_observer_.push_back(observer);
            }
            void Detach(IObserver *observer) override
            {
                list_observer_.remove(observer);
            }
            void Notify() override
            {
                std::list<IObserver *>::iterator iterator = list_observer_.begin();
                while (iterator != list_observer_.end())
                {
                    (*iterator)->Update(message_);
                    ++iterator;
                }
            }

            void CreateMessage(std::string message = "Empty")
            {
                this->message_ = message;
                Notify();
            }

        private:
            std::list<IObserver *> list_observer_;
            std::string message_;
        };

    } // namespace tools
} // namespace da

#endif