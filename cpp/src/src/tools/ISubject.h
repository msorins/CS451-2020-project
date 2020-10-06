#include "IOBserver.h"

#ifndef I_SUBJECT
#define I_SUBJECT

namespace da
{
    namespace tools
    {
        class ISubject
        {
        public:
            virtual ~ISubject(){};
            virtual void Attach(IObserver *observer) = 0;
            virtual void Detach(IObserver *observer) = 0;
            virtual void Notify() = 0;
        };

    } // namespace tools
} // namespace da

#endif
