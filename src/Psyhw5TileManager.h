#pragma once
#include "BaseEngine.h"
#include "DisplayableObject.h"
#include "DrawingSurface.h"
#include "TileManager.h"
#include "Tank.h"

#ifndef PSYHW5TILEMANAGER_H
#define PSYHW5TILEMANAGER_H

class Psyhw5TileManager
    : public TileManager
{
    public:

        Psyhw5TileManager()
            : TileManager(50, 50, 24, 14)
        {
            iVisibleTileCount = 0;
            iTilesActive = 0;
        }

        Psyhw5TileManager(int iTileHeight, int iTileWidth)
            : TileManager(iTileHeight, iTileWidth)
        {
            iVisibleTileCount = 0;
            iTilesActive = 0;
        }

        Psyhw5TileManager(int iTileHeight, int iTileWidth, int iMapWidth, int iMapHeight)
            : TileManager(iTileHeight, iTileWidth, iMapWidth, iMapHeight)
        {
            iVisibleTileCount = 0;
            iTilesActive = 0;
        }

        virtual void virtDrawTileAt(
            BaseEngine* pEngine,
            DrawingSurface* pSurface,
            int iMapX, int iMapY,
            int iStartPositionScreenX, int iStartPositionScreenY) const override;

    // Additions to tile manager
    public:
        // Changes all visible tiles back to red
        void resetTiles(BaseEngine* pEngine, DrawingSurface* pSurface);

        // Changes which tiles are visible
        void newTileLayout(BaseEngine* pEngine, DrawingSurface* pSurface, int iVisibleTiles);

        // returns the amount of visible tiles that are green
        int getTilesActive() const { return iTilesActive;}

        // check if the object has moved over a tile using its middle top, bottom, left and right XY
        void checkMove(BaseEngine* pEngine, DrawingSurface* pSurface, Tank* pTank);

        // If tile is visible and has been moved over then change to green
        bool activateTile(BaseEngine* pEngine, DrawingSurface* pSurface, int iScreenX, int iScreenY);

    private:
        int iVisibleTileCount;
        int iTilesActive;
};

#endif /* PSYHW5TILEMANAGER_H */
