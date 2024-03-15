#ifndef WALLTILEMANAGER_H
#define WALLTILEMANAGER_H
#include "Psyhw5TileManager.h"
#pragma once

class WallTileManager
    : public Psyhw5TileManager
{
    public:
        // creates tile manager for whole game screen, made up of 50x50 tiles
        WallTileManager()
            : Psyhw5TileManager(50, 50, 26, 16)
        {

        }

        virtual void virtDrawTileAt(
            BaseEngine* pEngine,
            DrawingSurface* pSurface,
            int iMapX, int iMapY,
            int iStartPositionScreenX, int iStartPositionScreenY) const override;

    // map operations
    public:
        void setBorder() {
            int * p = m_pData;
            for(int x=0; x<m_iMapWidth; x++) {
                for(int y=0; y<m_iMapHeight; y++) {
                    if(x==0 || x==m_iMapWidth-1) {
                        *(p+(x*y)) = 1;
                    }else if(y==0 || y==m_iMapHeight-1) {
                        *(p+(x*y)) = 1;
                    }
                }
            }
        }

        void setWallPositions();

        void saveWallPositions() {
            int * p = m_pData;
            for(int x=0; x<m_iMapWidth; x++) {
                for(int y=0; y<m_iMapHeight; y++) {
                    if(*(p+(x*y)) == 1) {
                        WallMap.push_back(std::pair<int, int>(x, y));
                    }
                }
            }
        }

    private:
        std::vector<std::pair<int, int>> WallMap;
};

#endif /* WALLTILEMANAGER_H */
