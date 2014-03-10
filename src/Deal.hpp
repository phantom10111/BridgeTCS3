
class Deal{
private:
public:
	Deal(std::pair<Player> first, std::pair<Player> second);
	void dealCards(Deck deck);
	std::vector<Card> getKthPlayerCards(int k);
};
