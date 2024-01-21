#ifndef RESULT_HPP
#define RESULT_HPP

#include <string>
#include <vector>
#include <stdexcept>

/* NOTE TO SELF:
 * unwrap() is a template function, so it must be defined in the header file
 * Hours sunk: 3
*/

template <typename T> struct Result {
    T value;
    bool success;

    // TODO: use color lib to make the error message red for posix environments
    // TODO: modify color lib to use https://www.computerhope.com/color.htm for
    //       windows compatibility
    T unwrap(std::string errorMessage) {
        if (success) { return value; }
        throw std::runtime_error(errorMessage);
    }
};

#endif // RESULT_HPP
