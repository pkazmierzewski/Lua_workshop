#include "gadget.h"

const struct luaL_Reg eGadget::iCommonMethods[] = 
{ 
    {"enable", eGadget::enable},
    {"disable", eGadget::disable},
    {NULL, NULL} 
};

eGadget::eGadget():
    iIsEnabled(false)
{
}

void eGadget::registerCommonMethods(lua_State* aLua)
{
    luaL_setfuncs(aLua, eGadget::iCommonMethods, 0);
}

int eGadget::enable(lua_State* aLua)
{
    eGadget* me = static_cast<eGadget*>(lua_touserdata(aLua, 1));
    me->iIsEnabled = true;
    me->enable();
    return 0;
}

int eGadget::disable(lua_State* aLua)
{
    eGadget* me = static_cast<eGadget*>(lua_touserdata(aLua, 1));
    me->disable();
    me->iIsEnabled = false;
    return 0;
}