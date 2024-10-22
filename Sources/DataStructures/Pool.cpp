#include "Pool.hpp"

Pool::Pool (void) {
	std::cout << "Pool Default Constructor Called" << std::endl;
}

Pool::Pool (Pool const & src)
{
	std::cout << "Pool Copy Constructor Called" << std::endl;
	*this = src;
}

Pool & Pool::operator=(Pool const & rhs)
{
	std::cout << "Pool Copy Assignement Operator Called" << std::endl;
	if (this != &rhs)
		//this->arg = rhs.getArg();
	return *this;
}

Pool::~Pool (void) {
	std::cout << "Pool Default Destructor Called" << std::endl;