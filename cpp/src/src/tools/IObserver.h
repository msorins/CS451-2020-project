#include <string>

#ifndef I_OBSERVER
#define I_OBSERVER

namespace da
{
    namespace tools
    {
        class IObserver
        {
        public:
            virtual ~IObserver(){};
            virtual void Update(const std::string &message_from_subject) = 0;
        };
    } // namespace tools
} // namespace da

#endif