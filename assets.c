#include <stdio.h>
#include "assets.h"
#include "utilities.h"

#define MAX_ASSETS 100
static Asset assetList[MAX_ASSETS];
static int assetCount = 0;

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) { printf("Asset list full!\n"); return; }
    assetList[assetCount].assetId = readInt("Enter Asset ID: ");
    printf("Enter Asset Name: ");
    scanf("%49s", assetList[assetCount].assetName);
    assetList[assetCount].value = readDouble("Enter Asset Value: ");
    assetCount++;
    printf("Asset added successfully.\n");
}

void listAssets(void) {
    printf("\n--- Asset Records ---\n");
    if (assetCount == 0) { printf("No assets found.\n"); return; }
    for (int i = 0; i < assetCount; i++) {
        printf("ID: %d | Name: %s | Value: %.2f\n", assetList[i].assetId, assetList[i].assetName, assetList[i].value);
    }
}

void saveAssetsText(void) {
    FILE *fp = fopen("data/assets.txt", "w");
    if (fp == NULL) { perror("data/assets.txt"); return; }
    for (int i = 0; i < assetCount; i++) {
        fprintf(fp, "%d|%s|%.2f\n", assetList[i].assetId, assetList[i].assetName, assetList[i].value);
    }
    fclose(fp);
}

void loadAssetsText(void) {
    FILE *fp = fopen("data/assets.txt", "r");
    if (fp == NULL) { perror("data/assets.txt"); return; }
    assetCount = 0;
    while (fscanf(fp, "%d|%49[^|]|%lf\n", &assetList[assetCount].assetId, assetList[assetCount].assetName, &assetList[assetCount].value) == 3) {
        assetCount++;
    }
    fclose(fp);
}