// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#include "WMPlayerState.h"

AWMPlayerState::AWMPlayerState()
{
	Kills = 0;
	Deaths = 0;
	ObjectivesCompleted = 0;
}

void AWMPlayerState::AddScoreAmount(int32 Amount)
{
	// Native APlayerState provides GetScore() and SetScore()
	SetScore(GetScore() + Amount);
}

void AWMPlayerState::AddKill()
{
	Kills++;
}

void AWMPlayerState::AddDeath()
{
	Deaths++;
}

void AWMPlayerState::AddObjectiveCompleted()
{
	ObjectivesCompleted++;
}

void AWMPlayerState::ResetMissionStats()
{
	Kills = 0;
	Deaths = 0;
	ObjectivesCompleted = 0;
	SetScore(0.0f);
}