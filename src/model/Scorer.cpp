#include "model/Scorer.hpp"

namespace model{

bool Scorer::update(DealResult const& dealResult)
{
	if(dealResult.contract.level > dealResult.tricksWon - 6)
		return false;
	int teamId = dealResult.contract.player%2;
	int extraTricks = dealResult.contract.level - dealResult.tricksWon + 6;
	if(dealResult.contract.denomination==Denomination::CLUBS || 
		dealResult.contract.denomination==Denomination::DIAMONDS)
	{
		gameResult.under[teamId]+=dealResult.contract.level
								*20*dealResult.contract.multiplier;
		gameResult.over[teamId]+=extraTricks
								*20*dealResult.contract.multiplier;
	}
	else if(dealResult.contract.denomination==Denomination::HEARTS || 
		dealResult.contract.denomination==Denomination::SPADES)
	{
		gameResult.under[teamId]+=dealResult.contract.level
								*30*dealResult.contract.multiplier;
		gameResult.over[teamId]+=extraTricks
								*30*dealResult.contract.multiplier;
	}
	else
	{
		gameResult.under[teamId]+=(dealResult.contract.level*30+10)
									*dealResult.contract.multiplier;
		gameResult.over[teamId]+=extraTricks
								*30*dealResult.contract.multiplier;
	}
	return gameResult.under[0] > 200 || gameResult.under[1] > 200;
	
}
GameResult Scorer::getResult() const{
	return gameResult;
}
	

} // namespace model
