#include "gMove.h"

#include "gTransform.h"

DEFINE_GADGET_WRITER(gMove, setDirX, iDir.x)
DEFINE_GADGET_WRITER(gMove, setDirY, iDir.y)
DEFINE_GADGET_WRITER(gMove, setSpeed, iSpeed)

DEFINE_GADGET_API(gMove)
{
    REGISTER_GADGET_WRITER(setDirX)
    REGISTER_GADGET_WRITER(setDirY)
    REGISTER_GADGET_WRITER(setSpeed)
    {0, 0}
};

DEFINE_GADGET_CLASS(gMove)

gMove::gMove():
    iDir(0, 1),
    iSpeed(5),
    iTransform(0)
{
    iTransform = static_cast<gTransform*>(getActor()->findGadgetByClass("gTransform"));
    if (! iTransform) throw std::runtime_error(getActor()->getScript() + ", gMove: 'gTransform' not found.");
}

gMove::~gMove()
{

}

int gMove::update(lua_State* /* aLua */, float aDelta)
{
    const auto& oldPos = iTransform->getPos();
    iTransform->setPos(oldPos + iDir * iSpeed * aDelta);

    return 0;
}
