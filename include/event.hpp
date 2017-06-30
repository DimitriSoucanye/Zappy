#ifndef _EVENT_HPP_
#define _EVENT_HPP_

#include <string>

class IEvent
{
public:
    virtual ~IEvent();
    virtual callEvent() = 0;
};

#endif /* !_EVENT_HPP_ */
