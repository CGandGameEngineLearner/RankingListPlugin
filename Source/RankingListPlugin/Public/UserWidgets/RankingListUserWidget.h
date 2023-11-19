// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "RankingListPlayerInfoUserWidget.h"
#include "RankingListUserWidget.generated.h"


/**
 * 排行榜的UserWidget
 */
UCLASS()
class RANKINGLISTPLUGIN_API URankingListUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TArray<FRankingListPlayerInfo> PlayerInfos;
	
	UFUNCTION(BlueprintCallable)
	void SortRankingList();

	UFUNCTION(BlueprintCallable)
	void SetPlayerInfos(TArray<FRankingListPlayerInfo> NewPlayerInfos);
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadWrite,meta = (BindWidget))
	UListView* RankingListView;

	/*
	 排行榜上展示的玩家信息条目RankingListPlayerInfo的类型
	 */
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TSubclassOf<URankingListPlayerInfoUserWidget> RankingListPlayerInfoSubclassOf;
	
};
