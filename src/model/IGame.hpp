#ifndef IGAME_HPP
#define IGAME_HPP

namespace model {

class IGame {
public:
	virtual GameResult perform() = 0;
};

} // namespace model

#endif
