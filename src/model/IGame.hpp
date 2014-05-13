#ifndef IGAME_HPP
#define IGAME_HPP

#include "model/GameResult.hpp"

namespace model {

class IGame {
public:
	virtual GameResult perform() = 0;
};

} // namespace model

#endif
