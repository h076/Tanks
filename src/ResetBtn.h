#pragma once
#include "Psyhw5TileManager.h"
#ifndef RESETBTN_H
#define RESETBTN_H

#include "Button.h"

class ResetBtn
    : public Button
{
    public:
        ResetBtn(BaseEngine* pEngine, Psyhw5TileManager* pTileManager)
            : Button(pEngine)
        {
            m_pTileManager = pTileManager;
        }

        Psyhw5TileManager* getTileManager() const {return m_pTileManager;}

        virtual void virtDraw() override;
        virtual void pressed() override;

    private:
        Psyhw5TileManager* m_pTileManager;
};

#endif /* RESETBTN_H */
