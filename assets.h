#ifndef ASSETS_H
#define ASSETS_H

typedef struct {
    int assetId;
    char assetName[50];
    double value;
} Asset;

void addAsset(void);
void listAssets(void);
void saveAssetsText(void);
void loadAssetsText(void);

#endif