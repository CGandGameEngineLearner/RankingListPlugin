// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgets/RankingListUserWidget.h"

#include "Components/ListView.h"

void URankingListUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if(RankingListView)
	{
		
		UpdateRankingListView();
	}
}

void URankingListUserWidget:: UpdateRankingListView()
{
	RankingListView->ClearListItems();
	for (auto& PlayerInfo : PlayerInfos)
	{
		URankingListPlayerInfoUserWidget* PlayerInfoUserWidget=CreateWidget<URankingListPlayerInfoUserWidget>(this, RankingListPlayerInfoSubclassOf);
		PlayerInfoUserWidget->SetPlayerInfo(PlayerInfo);
		RankingListView->AddItem(PlayerInfoUserWidget);
	}
}

void URankingListUserWidget::SetPlayerInfos(TArray<FRankingListPlayerInfo> NewPlayerInfos)
{
	PlayerInfos=NewPlayerInfos;
	UpdateRankingListView();
}

void URankingListUserWidget::SortRankingList()
{
	PlayerInfos.HeapSort([](const FRankingListPlayerInfo& PlayerInfoA,const FRankingListPlayerInfo& PlayerInfoB)->bool
	{
		return PlayerInfoA>PlayerInfoB;
	});
	UpdateRankingListView();
}
