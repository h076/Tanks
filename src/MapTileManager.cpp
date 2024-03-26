#include "MapTileManager.h"
#include "BaseEngine.h"
#include "header.h"

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
        /*wall.renderImage(pSurface, 0, 0,
                         iStartPositionScreenX, iStartPositionScreenY,
                         wall.getWidth(), wall.getHeight());

        pSurface->drawRectangle(iStartPositionScreenX - 2,
                                iStartPositionScreenY - 2,
                                iStartPositionScreenX + getTileWidth() + 1,
                                iStartPositionScreenY + getTileHeight() + 1,
                                0x00ff00);
                                */
        wall.renderImage(pSurface, 0, 0,
                         iStartPositionScreenX, iStartPositionScreenY,
                         wall.getWidth(), wall.getHeight());

        // create border around wall facing open space
        if(getMapValue(iMapX, iMapY-1)==0) {
            pSurface->drawRectangle(iStartPositionScreenX,
                                    iStartPositionScreenY,
                                    iStartPositionScreenX + getTileWidth(),
                                    iStartPositionScreenY + 2,
                                    0x964B00);
        }
        if(getMapValue(iMapX, iMapY+1) == 0) {
            pSurface->drawRectangle(iStartPositionScreenX,
                                    iStartPositionScreenY + getTileHeight() - 2,
                                    iStartPositionScreenX + getTileWidth(),
                                    iStartPositionScreenY + getTileHeight(),
                                    0x964B00);
        }
        if(getMapValue(iMapX-1, iMapY) == 0) {
            pSurface->drawRectangle(iStartPositionScreenX,
                                    iStartPositionScreenY,
                                    iStartPositionScreenX + 2,
                                    iStartPositionScreenY + getTileHeight(),
                                    0x964B00);
        }
        if(getMapValue(iMapX+1, iMapY) == 0) {
            pSurface->drawRectangle(iStartPositionScreenX + getTileWidth() - 2,
                                    iStartPositionScreenY,
                                    iStartPositionScreenX + getTileWidth(),
                                    iStartPositionScreenY + getTileHeight(),
                                    0x964B00);
        }
    }
}

void MapTileManager::loadMap(BaseEngine* pEngine, DrawingSurface* pSurface) {
    int iMapWidth, iMapHeight;

    // set map we want to load
    mg.setMapTemp1();
    iMapHeight = mg.getMapHeight();
    iMapWidth = mg.getMapWidth();

    // get pointer to map data
    int * i_pMap = mg.getMapData();

    // check tile manager map size matches map to load size
    if(iMapHeight != getMapHeight() || iMapWidth != getMapWidth())
        setMapSize(iMapWidth, iMapHeight);

    // copy map to be loaded to tile manager map
    std::memcpy(m_pData, i_pMap, iMapHeight*iMapWidth*sizeof(int));

    // redraw map
    drawAllTiles(pEngine, pSurface);
}
