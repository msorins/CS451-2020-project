#include <iostream>
#include <list>
#include <string>

#include "IObserver.h"
#include "Subject.h"

#ifndef OBSERVER_DEF
#define OBSERVER_DEF

#include "../sockets/Data.h"

namespace da
{
    namespace tools
    {
        class Observer : public IObserver
        {
        public:
            Observer(Subject &subject) : subject_(subject)
            {
                this->subject_.Attach(this);
                this->number_ = Observer::static_number_;
            }

            void Update(const da::sockets::Data &message_from_subject) override
            {
                message_from_subject_ = message_from_subject;
            }

            void RemoveMeFromTheList()
            {
                subject_.Detach(this);
            }

        private:
            da::sockets::Data message_from_subject_;
            Subject &subject_;
            static int static_number_;
            int number_;
        };

        int Observer::static_number_ = 0;

    } // namespace tools
} // namespace da

#endif
