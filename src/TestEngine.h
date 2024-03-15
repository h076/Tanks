#pragma once
#ifndef TESTENGINE_H
#define TESTENGINE_H

#include "BaseEngine.h"
#include "Psyhw5TileManager.h"

#include "Tank.h"

#include "UtilCollisionDetection.h"

//enum gameState {PLAYING, END};

class TestEngine :
    public BaseEngine
{
    public:
        TestEngine() : BaseEngine()
        {
        }

        virtual void virtSetupBackgroundBuffer() override;


};

#endif /* TESTENGINE_H */
