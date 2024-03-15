#include "ImageManager.h"
#include "SimpleImage.h"
#include "header.h"

#include "TestEngine.h"
#include "ResetBtn.h"

#include "PlayerTank.h"
#include "AutoTank.h"

#include <cstdio>

void TestEngine::virtSetupBackgroundBuffer() {
    // set base for the back ground
    SimpleImage woodImg = ImageManager::loadImage("woodFloor.png", true);
    woodImg.renderImage(getBackgroundSurface(), 0, 0, 0, 0,
                        getBackgroundSurface()->getSurfaceWidth(),
                        getBackgroundSurface()->getSurfaceHeight());

    // draw border consisting of blocks 50x50 pixels
    drawBackgroundRectangle(0, 0, 50, 50,0x00ff00);
    for(int x=0; x<getBackgroundSurface()->getSurfaceWidth(); x+=50) {
        for(int y=0; y<getBackgroundSurface()->getSurfaceHeight(); y+=50) {
            //drawBackgroundRectangle(x, y,x+50, y+50, 0x00ff00);
            if(x==0 || x==(getBackgroundSurface()->getSurfaceWidth()-50)) {
                drawBackgroundRectangle(x, y, x+50, y+50, 0x000000);
                drawBackgroundRectangle(x+2, y+2, x+48, y+48, 0x00ff01);
            }else if(y==0 || y==(getBackgroundSurface()->getSurfaceHeight()-50)) {
                drawBackgroundRectangle(x, y, x+50, y+50, 0x000000);
                drawBackgroundRectangle(x+2, y+2, x+48, y+48, 0x00ff01);
            }
        }
    }
}
