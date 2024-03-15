#pragma once
#include "BaseEngine.h"
#ifndef MYDEMOB_H
#define MYDEMOB_H

#include "DisplayableObject.h"

class MyObjectB : public DisplayableObject
{
    public:
        MyObjectB(BaseEngine *pEngine)
            : DisplayableObject(pEngine)
        {
            m_iCurrentScreenX = 100;
            m_iCurrentScreenY = 200;
            m_iDrawHeight = 200;
            m_iDrawWidth = 100;
        }

        virtual void virtDraw();
        virtual void virtDoUpdate(int iCurrentTime);
};


#endif /* MYDEMOB_H */
