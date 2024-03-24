#ifndef MAPTILEMANAGER_H
#define MAPTILEMANAGER_H
#include "Psyhw5TileManager.h"
#include "MapGeneration.h"
#include "UtilMapTiles.h"
#pragma once

class MapTileManager
    : public Psyhw5TileManager
{
    public:
        // creates tile manager for whole game screen, made up of 50x50 tiles
        MapTileManager()
            : Psyhw5TileManager(50, 50, 26, 16)
            , mg(26, 16)
        {

        }

        ~MapTileManager()
        {

        }

        virtual void virtDrawTileAt(
            BaseEngine* pEngine,
            DrawingSurface* pSurface,
            int iMapX, int iMapY,
            int iStartPositionScreenX, int iStartPositionScreenY) const override;

    // map operations
    public:
        // want to load map from mg class
        // using memcpy to copy all map values over

    private:
        MapGeneration mg;
        MapTiles mt;
};

#endif /* MAPTILEMANAGER_H */
