// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/TextBlock.h"
#include "..\..\Public\UserWidgets\RankingListPlayerInfoUserWidget.h"




void URankingListPlayerInfoUserWidget::SetPlayerInfo(const FRankingListPlayerInfo NewPlayerInfo)
{
	this->PlayerInfo=NewPlayerInfo;
	PlayerAvatar->SetBrushFromTexture(NewPlayerInfo.PlayerAvatar,false);
	PlayerName->SetText(FText::FromString(NewPlayerInfo.PlayerName));
	int32 int32PlayerScore=PlayerInfo.PlayerScore;
	FString stringPlayerScore = FString::FromInt(int32PlayerScore);
	this->PlayerScore->SetText(FText::FromString(stringPlayerScore));
}

FRankingListPlayerInfo URankingListPlayerInfoUserWidget::GetPlayerInfo() const
{
	return this->PlayerInfo;
}
