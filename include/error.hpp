//
// EPITECH PROJECT, 2018
//  
// File description:
//  
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

#include <exception>
#include <string>

class Error: public std::exception {
    public:
        virtual const char* what() const throw();
        Error(std::string const& msg="") throw();
        virtual ~Error() throw();

    private:
        std::string _errorMsg;
};

#endif /* !ERROR_HPP_ */