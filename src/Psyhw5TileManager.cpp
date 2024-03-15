#include "BaseEngine.h"
#include "DrawingSurface.h"
#include "header.h"

#include "Psyhw5TileManager.h"

void Psyhw5TileManager::virtDrawTileAt(BaseEngine *pEngine,
                                       DrawingSurface *pSurface,
                                       int iMapX, int iMapY,
                                       int iStartPositionScreenX,
                                       int iStartPositionScreenY) const {
    int iMapValue = getMapValue(iMapX, iMapY);
    if(iMapValue == 1) {
        // draw tile red
        pSurface->drawRectangle(iStartPositionScreenX,
                                iStartPositionScreenY,
                                iStartPositionScreenX + getTileWidth() - 1,
                                iStartPositionScreenY + getTileHeight() - 1,
                                0xff0000);
    }else if(iMapValue == 2) {
        // draw tile green
        pSurface->drawRectangle(iStartPositionScreenX,
                                iStartPositionScreenY,
                                iStartPositionScreenX + getTileWidth() - 1,
                                iStartPositionScreenY + getTileHeight() - 1,
                                0x00ff00);
    }
}

void Psyhw5TileManager::resetTiles(BaseEngine* pEngine, DrawingSurface* pSurface) {
    // using a pointer to map data rather than using parent class
    // functions as this will limit the amount of func calls
    int * p = m_pData;

    for(int i=0; i < (m_iMapHeight*m_iMapWidth); i++) {
        // a value of 2 gives a green tile
        // value of 1 gives a red tile, setting all green to red
        if(*(p+i)==2) {
            *(p+i) = 1;
        }
    }
    drawAllTiles(pEngine, pSurface);
    iTilesActive = 0;
}

void Psyhw5TileManager::newTileLayout(BaseEngine* pEngine, DrawingSurface* pSurface, int iVisibleTiles) {
    int * p = m_pData;
    // set all tiles values to 0
    memset(m_pData, 0, sizeof(int)*m_iMapHeight*m_iMapWidth);
    iVisibleTileCount = 0;
    iTilesActive = 0;

    while(iVisibleTileCount != iVisibleTiles) {
        for(int i=0; i < (m_iMapHeight*m_iMapWidth); i++) {
            // 1 percent chance that
            if((rand() % 250) <= 1
               && iVisibleTileCount < iVisibleTiles && *(p+i) == 0) {
                *(p+i) = 1;
                iVisibleTileCount++;
            }
        }
    }
    drawAllTiles(pEngine, pSurface);
}

void Psyhw5TileManager::checkMove(BaseEngine* pEngine, DrawingSurface* pSurface, Tank* pTank) {
    // check top
    activateTile(pEngine, pSurface, pTank->getScreenX()+(pTank->getDrawWidth()/2), pTank->getScreenY());
    // check bottom
    activateTile(pEngine, pSurface, pTank->getScreenX()+(pTank->getDrawWidth()/2), pTank->getScreenY()+pTank->getDrawHeight());
    // check left
    activateTile(pEngine, pSurface, pTank->getScreenX(), pTank->getScreenY()+(pTank->getDrawHeight()/2));
    // check right
    activateTile(pEngine, pSurface, pTank->getScreenX()+pTank->getDrawWidth(), pTank->getScreenY()+(pTank->getDrawHeight()/2));
}

bool Psyhw5TileManager::activateTile(BaseEngine* pEngine, DrawingSurface* pSurface, int iScreenX, int iScreenY) {
    if(isValidTilePosition(iScreenX, iScreenY)) {
        if(getMapValue(getMapXForScreenX(iScreenX),
                       getMapYForScreenY(iScreenY)) == 1) {

            setAndRedrawMapValueAt(getMapXForScreenX(iScreenX),
                                   getMapYForScreenY(iScreenY),
                                   2, pEngine, pSurface);
            iTilesActive++;
            return true;
        }
    }
    return false;
}
