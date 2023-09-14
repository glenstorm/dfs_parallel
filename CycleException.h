#ifndef _CYCLE_EXCEPTION_H_GUARD_
#define _CYCLE_EXCEPTION_H_GUARD_

class CycleException: public std::exception
{
public:

    explicit CycleException(const char* message)
        : msg_(message) {}

    explicit CycleException(const std::string& message)
        : msg_(message) {}

    virtual ~CycleException() noexcept {}

    virtual const char* what() const noexcept {
       return msg_.c_str();
    }

protected:
    std::string msg_;
};

#endif
	// _CYCLE_EXCEPTION_H_GUARD_
