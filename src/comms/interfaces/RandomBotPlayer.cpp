/*
 * RandomBotPlayer.cpp
 */

#include "RandomBotPlayer.h"
#include "poker_utils/CommonFunctions.h"

namespace ConcretePlayers {

using std::string;
using std::stringstream;

static int bot_index = 0;

RandomBotPlayer::RandomBotPlayer() :
	m_total_balance(MONEY_ZERO)
{
	++bot_index;
	m_name = "Bot #" + PokerUtils::AutoToString(bot_index);

}

bool RandomBotPlayer::IsPlaying() {
	return true;
}

string RandomBotPlayer::GetName() {
	return m_name;
}
Money RandomBotPlayer::GetTotalBalance() {
	return m_total_balance;
}

void RandomBotPlayer::SetTotalBalance(Money new_value) {
	m_total_balance += new_value;
}

//Random bot does not care!
void RandomBotPlayer::DealerAnnounce(std::string dealer) {}
void RandomBotPlayer::SmallBlindAnnounce(std::string payer, Money amount) {}
void RandomBotPlayer::BigBlindAnnounce(std::string payer, Money amount) {}
void RandomBotPlayer::OpponentMoneyUpdate(std::string player, Money pot, Money bank) {}
void RandomBotPlayer::OpponentCardAnnounce(std::string player, const Hand& players_hand) {}
void RandomBotPlayer::WinnerAnnounce(std::string player, Money winnings) {}

void RandomBotPlayer::ChatMessage(std::string sender, std::string message) {}

//I don't even care what cards I have!
void RandomBotPlayer::CardDealt(const Hand& hand, const Card& new_card) {}

GameChoice RandomBotPlayer::MakeChoice(Money minimum_bid) {

	int blind_decision = rand() % 4;

	GameChoice gc;

	switch(blind_decision) {
		case (0):
			gc.choice = FOLD;
			return gc;
		case (1):
		case (2):
			gc.choice = CALL;
			return gc;
		default:
			if (m_total_balance < minimum_bid)
				gc.choice = FOLD;
			else {
				gc.choice = RAISE;
				gc.value = minimum_bid + 1;
			}
			return gc;
	}
}

} /* namespace ConcretePlayers */
