#include "ImageManager.h"
#include "SimpleImage.h"
#include "header.h"

#include "Psyhw5Engine.h"
#include "ResetBtn.h"

#include "PlayerTank.h"
#include "AutoTank.h"

#include <cstdio>

void Psyhw5Engine::virtSetupBackgroundBuffer() {
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

    // set up tiles
    tm.setTopLeftPositionOnScreen(50, 50);
    tm.newTileLayout(this, getBackgroundSurface(), 6);
}

void Psyhw5Engine::virtDrawStringsUnderneath() {
    if(getGameState() == PLAYING) {
        drawBackgroundString(getBackgroundSurface()->getSurfaceWidth()/2,
                             getBackgroundSurface()->getSurfaceHeight()/2 + 100,
                             "TANKS", 0x00ffff);
    }
}

void Psyhw5Engine::virtDrawStringsOnTop() {
    if(getGameState() == PLAYING) {
        int tilesPressed = tm.getTilesActive();
        char buf[128];
        snprintf(buf, 128, "Tiles pressed : %d", tilesPressed);
        drawForegroundString(getBackgroundSurface()->getSurfaceWidth()/2,
                             getBackgroundSurface()->getSurfaceHeight()/2,
                             buf, 0x00ffff);
    }
}

int Psyhw5Engine::virtInitialiseObjects()
{
	// alert that we are about to change the array of drawn objects
	drawableObjectsChanged();

	// remove all drawn objects
	destroyOldObjects(true);

	// create an object array big enough
	createObjectArray(3);

	// store out new object in the array
	storeObjectInArray(0, new PlayerTank(this));
    storeObjectInArray(1, new AutoTank(this));
    storeObjectInArray(2, new ResetBtn(this, &tm));

    getDisplayableObject(2)->setPosition(0, 0);

	setAllObjectsVisible(true);

	return 0;
}

void Psyhw5Engine::virtMainLoopPostUpdate() {
    if(getGameState() == PLAYING) {
        Tank * pPlayerTank = (Tank *) getDisplayableObject(0);
        tm.checkMove(this, getBackgroundSurface(), pPlayerTank);
        Tank * pAutoTank = (Tank *) getDisplayableObject(1);
        bool collision = collisions.checkCircles(pPlayerTank->getXCentre(), pPlayerTank->getYCentre(),
                                                 pAutoTank->getXCentre(), pAutoTank->getYCentre(), 100);
        if(collision)
            endGame();
    }
}

void Psyhw5Engine::endGame() {
    setGameState(END);
    // calls clean up
    // deinitialise gives malloc error
    deinitialise();
    //virtCleanUp();
}

void Psyhw5Engine::virtCleanUp() {
    // alert that all displayable objects are to be deleted
    drawableObjectsChanged();
    // delete all objects
    destroyOldObjects(true);

    fillBackground(0x000000);
    drawBackgroundString(getBackgroundSurface()->getSurfaceWidth()/2,
                         getBackgroundSurface()->getSurfaceHeight()/2,
                         "Game Over ...", 0xffffff);
}
