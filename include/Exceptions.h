#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <stdexcept>

class AnyException : public std::exception
{
public:
    AnyException(const char *message) noexcept : message(message) {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }

private:
    const std::string message;
};

class InvalidBet : public AnyException
{
public:
    InvalidBet() noexcept : AnyException("Your new bet must not exceed your available credits!") {}
};

class InvalidChoice : public AnyException
{
public:
    InvalidChoice(const char *message) noexcept : AnyException(message) {}
};

#endif
