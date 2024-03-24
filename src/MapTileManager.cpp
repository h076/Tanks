#include "MapTileManager.h"
#include "BaseEngine.h"

void MapTileManager::virtDrawTileAt(BaseEngine *pEngine, DrawingSurface *pSurface,
                                    int iMapX, int iMapY,
                                    int iStartPositionScreenX, int iStartPositionScreenY) const {
    /**
     * 0 : clear space
     * 1 : wall
     * ...
     */

    if(getMapValue(iMapX, iMapY) == 1) {
        SimpleImage wall = mt.getRandomWall();
        wall.renderImage(pSurface, iStartPositionScreenX, iStartPositionScreenY, int iXTarget, int iYTarget, int iWidth, int iHeight)
    }
}
