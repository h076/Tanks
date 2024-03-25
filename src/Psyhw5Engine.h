#pragma once
#include "BaseEngine.h"
#include "MapTileManager.h"

#ifndef PSYHW5ENGINE_H
#define PSYHW5ENGINE_H

#include "Tank.h"

#include "UtilCollisionDetection.h"

enum gameState {PLAYING, END};

class Psyhw5Engine :
    public BaseEngine
{
    public:
        Psyhw5Engine() : BaseEngine()
        {
            eGameState = PLAYING;
        }

        virtual void virtSetupBackgroundBuffer() override;

        void virtDrawStringsUnderneath() override;
        void virtDrawStringsOnTop() override;
        int virtInitialiseObjects() override;

        // allows us to update objects every loop
        virtual void virtMainLoopPostUpdate() override;

        // Handle mouse input
        virtual void virtMouseDown(int iButton, int iX, int iY) override {
            notifyObjectsAboutMouse(true);
        }

        // implement proper clean up of all objects
        virtual void virtCleanUp(void) override;

        void handleTank(Tank pTank);

        // get and set game state
        const gameState getGameState() {return eGameState;}
        const void setGameState(gameState s) {eGameState = s;}

        // change game state to END and call clean up
        void endGame();

    protected:
        MapTileManager tm;
        static CollisionDetection collisions;

    private:
        gameState eGameState;
};

#endif /* PSYHW5ENGINE_H */
