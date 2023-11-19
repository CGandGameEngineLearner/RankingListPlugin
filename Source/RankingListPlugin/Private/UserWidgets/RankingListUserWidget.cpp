// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgets/RankingListUserWidget.h"

#include "Components/ListView.h"

void URankingListUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}



void URankingListUserWidget::SetPlayerInfos(TArray<FRankingListPlayerInfo> NewPlayerInfos)
{
	PlayerInfos=NewPlayerInfos;
}

void URankingListUserWidget::SortRankingList()
{
	PlayerInfos.HeapSort([](const FRankingListPlayerInfo& PlayerInfoA,const FRankingListPlayerInfo& PlayerInfoB)->bool
	{
		return PlayerInfoA>PlayerInfoB;
	});
}
