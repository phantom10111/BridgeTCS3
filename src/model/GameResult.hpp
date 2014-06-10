#ifndef GAMERESULT_HPP
#define GAMERESULT_HPP

#include<vector>

namespace model {

struct GameResult {
	std::array<int, 2> under;
	std::array<int, 2> over;
};

} // namespace model

#endif
