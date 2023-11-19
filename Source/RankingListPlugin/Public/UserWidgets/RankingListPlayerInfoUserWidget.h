// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"  // Include for UTextBlock
#include "Components/Image.h"      // Include for UImage
#include "RankingListPlayerInfoUserWidget.generated.h"

USTRUCT(BlueprintType)
struct RANKINGLISTPLUGIN_API FRankingListPlayerInfo
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PlayerName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PlayerScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* PlayerAvatar;

	bool operator<(const FRankingListPlayerInfo& Other) const
	{
		return PlayerScore < Other.PlayerScore;
	}
	
	bool operator>(const FRankingListPlayerInfo& Other) const
	{
		return PlayerScore > Other.PlayerScore;
	}
	
};

/**
 *
 */
UCLASS()
class RANKINGLISTPLUGIN_API URankingListPlayerInfoUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	FRankingListPlayerInfo PlayerInfo;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerName;

	UPROPERTY(meta = (BindWidget))
	UImage* PlayerAvatar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerScore;

	UFUNCTION(BlueprintCallable)
	void SetPlayerInfo(const FRankingListPlayerInfo NewPlayerInfo);

	UFUNCTION(BlueprintCallable)
	FRankingListPlayerInfo GetPlayerInfo() const;
};
