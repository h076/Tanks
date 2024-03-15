#include "header.h"

#include "PlayerTank.h"

void PlayerTank::virtDraw() {
    getEngine()->drawForegroundOval(m_iCurrentScreenX,
                                    m_iCurrentScreenY,
                                    m_iCurrentScreenX + m_iDrawWidth - 1,
                                    m_iCurrentScreenY + m_iDrawHeight - 1,
                                    0xf012ff);
}

void PlayerTank::virtDoUpdate(int iCurrentTime) {
    if(getEngine()->isKeyPressed(SDLK_UP))
        m_iCurrentScreenY -= 2;
    if(getEngine()->isKeyPressed(SDLK_DOWN))
        m_iCurrentScreenY += 2;
    if(getEngine()->isKeyPressed(SDLK_LEFT))
        m_iCurrentScreenX -= 2;
    if(getEngine()->isKeyPressed(SDLK_RIGHT))
        m_iCurrentScreenX += 2;

    // prevent object from moving off screen using bounds
    if(m_iCurrentScreenX < 50)
        m_iCurrentScreenX = 50;
    if(m_iCurrentScreenX >= getEngine()->getWindowWidth() - m_iDrawWidth - 50)
        m_iCurrentScreenX = getEngine()->getWindowWidth() - m_iDrawWidth - 50;
    if(m_iCurrentScreenY < 50)
        m_iCurrentScreenY = 50;
    if(m_iCurrentScreenY >= getEngine()->getWindowHeight() - m_iDrawHeight - 50)
        m_iCurrentScreenY = getEngine()->getWindowHeight() - m_iDrawHeight - 50;

    this->redrawDisplay();
}
