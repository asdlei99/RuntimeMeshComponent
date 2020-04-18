// Copyright 2016-2020 Chris Conway (Koderz). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeMeshProvider.h"
#include "RuntimeMeshProviderBox.generated.h"

UCLASS(HideCategories = Object, BlueprintType)
class RUNTIMEMESHCOMPONENT_API URuntimeMeshProviderBox : public URuntimeMeshProvider
{
	GENERATED_BODY()
private:
	mutable FCriticalSection PropertySyncRoot;
	FBoxSphereBounds LocalBounds;

	UPROPERTY(Category = "RuntimeMesh|Providers|Box", VisibleAnywhere, BlueprintGetter=GetBoxRadius, BlueprintSetter=SetBoxRadius)
	FVector BoxRadius;

	UPROPERTY(Category = "RuntimeMesh|Providers|Box", VisibleAnywhere, BlueprintGetter=GetBoxMaterial, BlueprintSetter=SetBoxMaterial)
	UMaterialInterface* Material;
public:
	UFUNCTION(BlueprintCallable)
	FVector GetBoxRadius() const;
	UFUNCTION(BlueprintCallable)
	void SetBoxRadius(const FVector& InRadius);

	UFUNCTION(BlueprintCallable)
	UMaterialInterface* GetBoxMaterial() const;
	UFUNCTION(BlueprintCallable)
	void SetBoxMaterial(UMaterialInterface* InMaterial);


protected:
	void Initialize_Implementation() override;
	FBoxSphereBounds GetBounds_Implementation() override;
	bool GetSectionMeshForLOD_Implementation(int32 LODIndex, int32 SectionId, FRuntimeMeshRenderableMeshData& MeshData) override;
	FRuntimeMeshCollisionSettings GetCollisionSettings_Implementation() override;
	bool HasCollisionMesh_Implementation() override;
	bool GetCollisionMesh_Implementation(FRuntimeMeshCollisionData& CollisionData) override;
	bool IsThreadSafe_Implementation() override;

};
