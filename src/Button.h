#pragma once
#include "DisplayableObject.h"
#ifndef BUTTON_H
#define BUTTON_H

#include "BaseEngine.h"

class Button
    : public DisplayableObject
{
    public:
        Button(BaseEngine* pEngine)
            : DisplayableObject(pEngine)
        {
            m_iCurrentScreenX = 100;
            m_iCurrentScreenY = 100;
            m_iDrawWidth = 100;
            m_iDrawHeight = 100;
            btnID++;
        }

        virtual void virtDraw() override;

        virtual void virtMouseDown(int iButton, int iX, int iY) override;

    private:
        static int btnID;

    public:
        virtual void pressed();
};

#endif /* BUTTON_H */
