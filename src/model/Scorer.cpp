#include "model/Scorer.hpp"

namespace model{

Scorer::Scorer()
{
	gameResult.under[0] = 0;
	gameResult.under[1] = 0;
	gameResult.over[0] = 0;
	gameResult.over[1] = 0;
	gamesWon[0] = 0;
	gamesWon[1] = 0;
}

bool Scorer::isVulnerable(int nr)
{
	return (gamesWon[nr] >= 1);
}

bool Scorer::update(DealResult const& dealResult)
{
	//honorBonus
	gameResult.over[0]+=dealResult.honorBonus[0];
	gameResult.over[1]+=dealResult.honorBonus[1];
	int teamId = dealResult.contract.player%2;
	if(dealResult.contract.level > dealResult.tricksWon - 6)
	{
		int underTricks = dealResult.contract.level - dealResult.tricksWon + 6;
		// Penalty points
		if(dealResult.contract.multiplier == 1)
		{
			if(isVulnerable(teamId))
				gameResult.over[1-teamId] += 100 * underTricks;
			else
				gameResult.over[1-teamId] += 50 * underTricks;
		}
		else if(dealResult.contract.multiplier == 2)
		{
			if(underTricks == 1)
			{
				if(isVulnerable(teamId))
					gameResult.over[1-teamId] += 200;
				else
					gameResult.over[1-teamId] += 100;
			}
			else if(underTricks == 2 || underTricks == 3)
			{
				if(isVulnerable(teamId))
					gameResult.over[1-teamId] += 200 + (underTricks - 1) * 300;
				else
					gameResult.over[1-teamId] += 100 + (underTricks - 1) * 200;
			}
			else
			{
				if(isVulnerable(teamId))
					gameResult.over[1-teamId] += 800 + (underTricks - 3) * 300;
				else
					gameResult.over[1-teamId] += 500 + (underTricks - 3) * 300;
			}
		}
		else if(dealResult.contract.multiplier == 4)
		{
			if(underTricks == 1)
			{
				if(isVulnerable(teamId))
					gameResult.over[1-teamId] += 400;
				else
					gameResult.over[1-teamId] += 200;
			}
			else if(underTricks == 2 || underTricks == 3)
			{
				if(isVulnerable(teamId))
					gameResult.over[1-teamId] += 400 + (underTricks - 1) * 600;
				else
					gameResult.over[1-teamId] += 200 + (underTricks - 1) * 400;
			}
			else
			{
				if(isVulnerable(teamId))
					gameResult.over[1-teamId] += 1600 + (underTricks - 3) * 600;
				else
					gameResult.over[1-teamId] += 1000 + (underTricks - 3) * 600;
			}
		}
		return false;
	}
	int extraTricks = -(dealResult.contract.level - dealResult.tricksWon + 6);
	// Contract points
	if(dealResult.contract.denomination==Denomination::CLUBS || 
		dealResult.contract.denomination==Denomination::DIAMONDS)

		gameResult.under[teamId]+=dealResult.contract.level
								* 20 * dealResult.contract.multiplier;
	else if(dealResult.contract.denomination==Denomination::HEARTS || 
		dealResult.contract.denomination==Denomination::SPADES)

		gameResult.under[teamId]+=dealResult.contract.level
								* 30 * dealResult.contract.multiplier;
	else
		gameResult.under[teamId]+=(dealResult.contract.level*30+10)
									*dealResult.contract.multiplier;
	// Overtake points
	if(dealResult.contract.multiplier == 1)
	{
		if(dealResult.contract.denomination==Denomination::CLUBS || 
			dealResult.contract.denomination==Denomination::DIAMONDS)

			gameResult.over[teamId]+=extraTricks * 20;
		else if(dealResult.contract.denomination==Denomination::HEARTS || 
			dealResult.contract.denomination==Denomination::SPADES)

			gameResult.over[teamId]+=extraTricks * 30;
		else
			gameResult.over[teamId]+=extraTricks * 30;
	}
	else if(dealResult.contract.multiplier == 2)
	{
		if(isVulnerable(teamId))
			gameResult.over[teamId] += 200 * extraTricks;
		else
			gameResult.over[teamId] += 100 * extraTricks;
	}
	else if(dealResult.contract.multiplier == 4)
	{
		if(isVulnerable(teamId))
			gameResult.over[teamId] += 400 * extraTricks;
		else
			gameResult.over[teamId] += 200 * extraTricks;		
	}
	// Slam bonus
	if(dealResult.contract.level == 6)
	{
		if(isVulnerable(teamId))
			gameResult.over[teamId] += 750;
		else
			gameResult.over[teamId] += 500;			
	}
	else if(dealResult.contract.level == 7)
	{
		if(isVulnerable(teamId))
			gameResult.over[teamId] += 1500;
		else
			gameResult.over[teamId] += 1000;	
	}
	// Doubled or redoubled bonus
	if(dealResult.contract.multiplier == 2)
	{
		gameResult.over[teamId]+=50;
	}
	else if(dealResult.contract.multiplier == 4)
	{
		gameResult.over[teamId]+=100;
	}
	bool result = false;
	if(gameResult.under[teamId] >= 100)
	{ 
		result = true;
		gamesWon[teamId]++;
		gameResult.over[teamId] += gameResult.under[teamId];
		gameResult.under[teamId] = 0;
		gameResult.over[1-teamId] += gameResult.under[1-teamId];
		gameResult.under[1-teamId] = 0;	
	}
	// Rubber bonus, TODO- unfinished rubbers
	if(gamesWon[teamId] == 2)
	{
		if(isVulnerable(1-teamId))
			gameResult.over[teamId] += 500;
		else
			gameResult.over[teamId] += 700;
	}
	return result;
}
GameResult Scorer::getResult() const{
	return gameResult;
}

} // namespace model
